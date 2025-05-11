#include <llvm/IR/LegacyPassManager.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>

#include <getopt.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <fstream>

#include "CodeGenVisitor.h"
#include "PascalSLexer.h"
#include "PascalSParser.h"
#include "StandardProcedure.h"

using namespace antlr4;

std::string get_base_name_without_ext(const std::string& path) {
    size_t last_slash = path.find_last_of("/\\\\");
    std::string filename = (last_slash == std::string::npos) ? path : path.substr(last_slash + 1);
    size_t last_dot = filename.find_last_of('.');
    return (last_dot == std::string::npos) ? filename : filename.substr(0, last_dot);
}

int run_command(const std::string& cmd) {
    std::cout << "Executing: " << cmd << std::endl;
    int ret = system(cmd.c_str());
    if (ret != 0) {
        std::cerr << "Command failed with exit code " << ret << ": " << cmd << std::endl;
    }
    return ret;
}

int main(int argc, char* argv[]) {
    int opt;
    std::string input_pas_file;
    std::string output_c_file_arg;

    struct option long_options[] = {
        { "help", no_argument, nullptr, 'h' },
        { "output", required_argument, nullptr, 'o' },
        { "input", required_argument, nullptr, 'i' },
        { nullptr, 0, nullptr, 0 }
    };

    while ((opt = getopt_long(argc, argv, "ho:i:", long_options, nullptr)) != -1) {
        switch (opt) {
        case 'h':
            printf("passcal - Pascal to C Converter\n");
            printf("Version: 0.2\n");
            printf("Usage: %s [<input.pas> | -i <input.pas>] [-o <output.c>]\n", argv[0]);
            printf("Options:\n");
            printf("  -h, --help            Display this information.\n");
            printf("  -o, --output <file>   Place the C output into <file>.\n");
            printf("  -i, --input <file>    Specify the input Pascal file.\n");
            return 0;
        case 'o':
            output_c_file_arg = optarg;
            break;
        case 'i':
            input_pas_file = optarg;
            break;
        case '?':
            fprintf(stderr, "Unknown option or missing argument.\n");
            return 1;
        default:
            return 1;
        }
    }

    if (input_pas_file.empty()) { 
        if (optind < argc) { 
            input_pas_file = argv[optind];
        } else {
            fprintf(stderr, "Error: No input Pascal file specified.\n");
            printf("Usage: %s [<input.pas> | -i <input.pas>] [-o <output.c>]\n", argv[0]);
            return 1;
        }
    } else if (optind < argc && !std::string(argv[optind]).empty()) {
        
        fprintf(stderr, "Warning: Input file specified with -i option ('%s') and as a positional argument ('%s'). Using the one from -i.\n", input_pas_file.c_str(), argv[optind]);
        
    }

    if (input_pas_file.length() <= 4 || input_pas_file.substr(input_pas_file.length() - 4) != ".pas") {
        std::cerr << "Error: Input file must be a .pas file (e.g., input.pas)." << std::endl;
        return 1;
    }

    std::string base_name = get_base_name_without_ext(input_pas_file);
    std::string intermediate_ll_file = base_name + ".ll";
    std::string final_c_file = output_c_file_arg.empty() ? (base_name + ".c") : output_c_file_arg;

    std::cout << "Compiling " << input_pas_file << " to " << intermediate_ll_file << "..." << std::endl;
    std::ifstream stream;
    stream.open(input_pas_file);
    if (!stream.is_open()) {
        llvm::errs() << "Could not open input file: " << input_pas_file << "\n";
        return 1;
    }

    ANTLRInputStream antlr_input(stream);
    PascalSLexer lexer(&antlr_input);
    CommonTokenStream tokens(&lexer);
    PascalSParser parser(&tokens);

    tree::ParseTree* tree = parser.program();

    StandardProcedure::init();
    CodeGenVisitor codeGen(input_pas_file);

    try {
        codeGen.visit(tree);
    } catch (const std::exception& e) {
        llvm::errs() << "CodeGenVisitor error: " << e.what() << "\n";
        return 1;
    }

    std::error_code EC_ll;
    llvm::raw_fd_ostream ll_out_stream(intermediate_ll_file, EC_ll, llvm::sys::fs::OF_None);
    if (EC_ll) {
        llvm::errs() << "Could not open intermediate LLVM IR file: " << intermediate_ll_file << " - " << EC_ll.message() << "\n";
        return 1;
    }
    codeGen.module->print(ll_out_stream, nullptr);
    ll_out_stream.flush();
    ll_out_stream.close();
    std::cout << "Successfully generated LLVM IR: " << intermediate_ll_file << std::endl;

    std::string llvm_cbe_exe = "/data/workspace/myshixun/bin/llvm-cbe/build/tools/llvm-cbe/llvm-cbe";
    std::string cmd_llvm_cbe = llvm_cbe_exe + " " + intermediate_ll_file + " -o " + final_c_file;
    
    std::cout << "Converting " << intermediate_ll_file << " to " << final_c_file << " using llvm-cbe..." << std::endl;
    if (run_command(cmd_llvm_cbe) != 0) {
        std::cerr << "Error: llvm-cbe conversion failed." << std::endl;
        remove(intermediate_ll_file.c_str());
        return 1;
    }
    std::cout << "Successfully generated C file: " << final_c_file << std::endl;

    if (remove(intermediate_ll_file.c_str()) != 0) {
        std::cerr << "Warning: Could not remove intermediate file " << intermediate_ll_file << std::endl;
    }

    std::cout << "Pascal to C conversion successful: " << input_pas_file << " -> " << final_c_file << std::endl;
    return 0;
}
