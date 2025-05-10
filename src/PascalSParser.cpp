
// Generated from src/PascalS.g4 by ANTLR 4.13.2


#include "PascalSVisitor.h"

#include "PascalSParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PascalSParserStaticData final {
  PascalSParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PascalSParserStaticData(const PascalSParserStaticData&) = delete;
  PascalSParserStaticData(PascalSParserStaticData&&) = delete;
  PascalSParserStaticData& operator=(const PascalSParserStaticData&) = delete;
  PascalSParserStaticData& operator=(PascalSParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag pascalsParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PascalSParserStaticData> pascalsParserStaticData = nullptr;

void pascalsParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (pascalsParserStaticData != nullptr) {
    return;
  }
#else
  assert(pascalsParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PascalSParserStaticData>(
    std::vector<std::string>{
      "program", "programHead", "programBody", "identifierList", "constDeclarations", 
      "constDeclaration", "constVariable", "typeDeclarations", "typeDeclaration", 
      "type", "standardType", "recordBody", "periods", "period", "varDeclarations", 
      "varDeclaration", "subprogramDeclarations", "subprogramDeclaration", 
      "subprogramHead", "formalParameter", "parameterLists", "parameterList", 
      "varParameter", "valueParameter", "compoundStatement", "statementList", 
      "statement", "variable", "idVarparts", "idVarpart", "elsePart", "caseBody", 
      "branchList", "branch", "constList", "updown", "callProcedureStatement", 
      "expressionList", "expression", "simpleExpression", "term", "boolean", 
      "factor", "unsignConstVariable", "relationalOpreator", "addOperator", 
      "multiplyOperator"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "'='", "'<>'", "'<'", "'<='", "'>'", 
      "'>='", "'+'", "'-'", "'*'", "'/'", "':='", "'..'", "'.'", "','", 
      "':'", "';'", "'''", "'('", "')'", "'['", "']'"
    },
    std::vector<std::string>{
      "", "AND", "OR", "NOT", "INTEGER", "REAL", "BOOLEAN", "CHAR", "ARRAY", 
      "BEGIN", "CASE", "CONST", "DIV", "DO", "DOWNTO", "ELSE", "END", "FALSE", 
      "FOR", "FUNCTION", "IF", "MOD", "OF", "PROCEDURE", "PROGRAM", "RECORD", 
      "REPEAT", "THEN", "TO", "TRUE", "TYPE", "UNTIL", "VAR", "WHILE", "CHARLITERAL", 
      "ID", "LETTER", "NUM", "EXPONENT", "FRAC", "DIGITS", "DIGIT", "EQUAL", 
      "NEQUAL", "LT", "LE", "GT", "GE", "PLUS", "MINUS", "MULT", "DIVIDE", 
      "ASSIGNOP", "PERIODOP", "DOT", "COMMA", "COLON", "SEMICOLON", "QUOTE", 
      "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "NEWLINE", "WS", "COMMENT_CURLY", 
      "LINE_COMMENT", "COMMENT_PAREN_STAR"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,67,490,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,1,0,1,0,1,0,1,0,1,1,1,1,1,
  	1,1,1,1,1,1,1,3,1,105,8,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,
  	1,3,1,3,1,3,5,3,121,8,3,10,3,12,3,124,9,3,1,4,1,4,1,4,1,4,1,4,3,4,131,
  	8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,143,8,5,10,5,12,5,146,
  	9,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,159,8,6,1,7,1,7,1,
  	7,1,7,1,7,3,7,166,8,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,8,178,
  	8,8,10,8,12,8,181,9,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	3,9,195,8,9,1,10,1,10,1,11,1,11,3,11,201,8,11,1,12,1,12,1,12,1,12,1,12,
  	1,12,5,12,209,8,12,10,12,12,12,212,9,12,1,13,1,13,1,13,1,13,1,14,1,14,
  	1,14,1,14,1,14,3,14,223,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,5,15,236,8,15,10,15,12,15,239,9,15,1,16,1,16,1,16,5,16,
  	244,8,16,10,16,12,16,247,9,16,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,
  	1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,3,18,265,8,18,1,19,1,19,1,19,
  	1,19,1,19,3,19,272,8,19,1,20,1,20,1,20,1,20,1,20,1,20,5,20,280,8,20,10,
  	20,12,20,283,9,20,1,21,1,21,3,21,287,8,21,1,22,1,22,1,22,1,23,1,23,1,
  	23,1,23,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,5,25,306,8,
  	25,10,25,12,25,309,9,25,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,
  	1,26,3,26,349,8,26,1,27,1,27,1,27,1,28,1,28,1,28,5,28,357,8,28,10,28,
  	12,28,360,9,28,1,29,1,29,1,29,1,29,1,29,1,29,3,29,368,8,29,1,30,1,30,
  	1,30,3,30,373,8,30,1,31,1,31,3,31,377,8,31,1,32,1,32,1,32,1,32,1,32,1,
  	32,5,32,385,8,32,10,32,12,32,388,9,32,1,33,1,33,1,33,1,33,1,34,1,34,1,
  	34,1,34,1,34,1,34,5,34,400,8,34,10,34,12,34,403,9,34,1,35,1,35,1,36,1,
  	36,1,36,1,36,1,36,3,36,412,8,36,1,37,1,37,1,37,1,37,1,37,1,37,5,37,420,
  	8,37,10,37,12,37,423,9,37,1,38,1,38,1,38,1,38,1,38,3,38,430,8,38,1,39,
  	1,39,1,39,1,39,1,39,1,39,3,39,438,8,39,1,39,1,39,1,39,1,39,5,39,444,8,
  	39,10,39,12,39,447,9,39,1,40,1,40,1,40,1,40,1,40,1,40,1,40,5,40,456,8,
  	40,10,40,12,40,459,9,40,1,41,1,41,1,42,1,42,1,42,1,42,1,42,1,42,1,42,
  	1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,3,42,480,8,42,1,43,
  	1,43,1,44,1,44,1,45,1,45,1,46,1,46,1,46,0,14,6,10,16,24,30,32,40,50,56,
  	64,68,74,78,80,47,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,
  	38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,
  	84,86,88,90,92,0,7,1,0,4,7,2,0,14,14,28,28,2,0,17,17,29,29,2,0,34,35,
  	37,37,1,0,42,47,2,0,2,2,48,49,4,0,1,1,12,12,21,21,50,51,493,0,94,1,0,
  	0,0,2,98,1,0,0,0,4,108,1,0,0,0,6,114,1,0,0,0,8,130,1,0,0,0,10,132,1,0,
  	0,0,12,158,1,0,0,0,14,165,1,0,0,0,16,167,1,0,0,0,18,194,1,0,0,0,20,196,
  	1,0,0,0,22,200,1,0,0,0,24,202,1,0,0,0,26,213,1,0,0,0,28,222,1,0,0,0,30,
  	224,1,0,0,0,32,240,1,0,0,0,34,248,1,0,0,0,36,264,1,0,0,0,38,271,1,0,0,
  	0,40,273,1,0,0,0,42,286,1,0,0,0,44,288,1,0,0,0,46,291,1,0,0,0,48,295,
  	1,0,0,0,50,299,1,0,0,0,52,348,1,0,0,0,54,350,1,0,0,0,56,353,1,0,0,0,58,
  	367,1,0,0,0,60,372,1,0,0,0,62,376,1,0,0,0,64,378,1,0,0,0,66,389,1,0,0,
  	0,68,393,1,0,0,0,70,404,1,0,0,0,72,406,1,0,0,0,74,413,1,0,0,0,76,429,
  	1,0,0,0,78,437,1,0,0,0,80,448,1,0,0,0,82,460,1,0,0,0,84,479,1,0,0,0,86,
  	481,1,0,0,0,88,483,1,0,0,0,90,485,1,0,0,0,92,487,1,0,0,0,94,95,3,2,1,
  	0,95,96,3,4,2,0,96,97,5,54,0,0,97,1,1,0,0,0,98,99,5,24,0,0,99,104,5,35,
  	0,0,100,101,5,59,0,0,101,102,3,6,3,0,102,103,5,60,0,0,103,105,1,0,0,0,
  	104,100,1,0,0,0,104,105,1,0,0,0,105,106,1,0,0,0,106,107,5,57,0,0,107,
  	3,1,0,0,0,108,109,3,8,4,0,109,110,3,14,7,0,110,111,3,28,14,0,111,112,
  	3,32,16,0,112,113,3,48,24,0,113,5,1,0,0,0,114,115,6,3,-1,0,115,116,5,
  	35,0,0,116,122,1,0,0,0,117,118,10,2,0,0,118,119,5,55,0,0,119,121,5,35,
  	0,0,120,117,1,0,0,0,121,124,1,0,0,0,122,120,1,0,0,0,122,123,1,0,0,0,123,
  	7,1,0,0,0,124,122,1,0,0,0,125,126,5,11,0,0,126,127,3,10,5,0,127,128,5,
  	57,0,0,128,131,1,0,0,0,129,131,1,0,0,0,130,125,1,0,0,0,130,129,1,0,0,
  	0,131,9,1,0,0,0,132,133,6,5,-1,0,133,134,5,35,0,0,134,135,5,42,0,0,135,
  	136,3,12,6,0,136,144,1,0,0,0,137,138,10,2,0,0,138,139,5,57,0,0,139,140,
  	5,35,0,0,140,141,5,42,0,0,141,143,3,12,6,0,142,137,1,0,0,0,143,146,1,
  	0,0,0,144,142,1,0,0,0,144,145,1,0,0,0,145,11,1,0,0,0,146,144,1,0,0,0,
  	147,148,5,48,0,0,148,159,5,35,0,0,149,150,5,49,0,0,150,159,5,35,0,0,151,
  	159,5,35,0,0,152,153,5,48,0,0,153,159,5,37,0,0,154,155,5,49,0,0,155,159,
  	5,37,0,0,156,159,5,37,0,0,157,159,5,34,0,0,158,147,1,0,0,0,158,149,1,
  	0,0,0,158,151,1,0,0,0,158,152,1,0,0,0,158,154,1,0,0,0,158,156,1,0,0,0,
  	158,157,1,0,0,0,159,13,1,0,0,0,160,161,5,30,0,0,161,162,3,16,8,0,162,
  	163,5,57,0,0,163,166,1,0,0,0,164,166,1,0,0,0,165,160,1,0,0,0,165,164,
  	1,0,0,0,166,15,1,0,0,0,167,168,6,8,-1,0,168,169,5,35,0,0,169,170,5,42,
  	0,0,170,171,3,18,9,0,171,179,1,0,0,0,172,173,10,2,0,0,173,174,5,57,0,
  	0,174,175,5,35,0,0,175,176,5,42,0,0,176,178,3,18,9,0,177,172,1,0,0,0,
  	178,181,1,0,0,0,179,177,1,0,0,0,179,180,1,0,0,0,180,17,1,0,0,0,181,179,
  	1,0,0,0,182,195,3,20,10,0,183,184,5,25,0,0,184,185,3,22,11,0,185,186,
  	5,16,0,0,186,195,1,0,0,0,187,188,5,8,0,0,188,189,5,61,0,0,189,190,3,24,
  	12,0,190,191,5,62,0,0,191,192,5,22,0,0,192,193,3,18,9,0,193,195,1,0,0,
  	0,194,182,1,0,0,0,194,183,1,0,0,0,194,187,1,0,0,0,195,19,1,0,0,0,196,
  	197,7,0,0,0,197,21,1,0,0,0,198,201,3,30,15,0,199,201,1,0,0,0,200,198,
  	1,0,0,0,200,199,1,0,0,0,201,23,1,0,0,0,202,203,6,12,-1,0,203,204,3,26,
  	13,0,204,210,1,0,0,0,205,206,10,2,0,0,206,207,5,55,0,0,207,209,3,26,13,
  	0,208,205,1,0,0,0,209,212,1,0,0,0,210,208,1,0,0,0,210,211,1,0,0,0,211,
  	25,1,0,0,0,212,210,1,0,0,0,213,214,3,12,6,0,214,215,5,53,0,0,215,216,
  	3,12,6,0,216,27,1,0,0,0,217,218,5,32,0,0,218,219,3,30,15,0,219,220,5,
  	57,0,0,220,223,1,0,0,0,221,223,1,0,0,0,222,217,1,0,0,0,222,221,1,0,0,
  	0,223,29,1,0,0,0,224,225,6,15,-1,0,225,226,3,6,3,0,226,227,5,56,0,0,227,
  	228,3,18,9,0,228,237,1,0,0,0,229,230,10,2,0,0,230,231,5,57,0,0,231,232,
  	3,6,3,0,232,233,5,56,0,0,233,234,3,18,9,0,234,236,1,0,0,0,235,229,1,0,
  	0,0,236,239,1,0,0,0,237,235,1,0,0,0,237,238,1,0,0,0,238,31,1,0,0,0,239,
  	237,1,0,0,0,240,245,6,16,-1,0,241,242,10,2,0,0,242,244,3,34,17,0,243,
  	241,1,0,0,0,244,247,1,0,0,0,245,243,1,0,0,0,245,246,1,0,0,0,246,33,1,
  	0,0,0,247,245,1,0,0,0,248,249,3,36,18,0,249,250,3,4,2,0,250,251,5,57,
  	0,0,251,35,1,0,0,0,252,253,5,19,0,0,253,254,5,35,0,0,254,255,3,38,19,
  	0,255,256,5,56,0,0,256,257,3,20,10,0,257,258,5,57,0,0,258,265,1,0,0,0,
  	259,260,5,23,0,0,260,261,5,35,0,0,261,262,3,38,19,0,262,263,5,57,0,0,
  	263,265,1,0,0,0,264,252,1,0,0,0,264,259,1,0,0,0,265,37,1,0,0,0,266,267,
  	5,59,0,0,267,268,3,40,20,0,268,269,5,60,0,0,269,272,1,0,0,0,270,272,1,
  	0,0,0,271,266,1,0,0,0,271,270,1,0,0,0,272,39,1,0,0,0,273,274,6,20,-1,
  	0,274,275,3,42,21,0,275,281,1,0,0,0,276,277,10,2,0,0,277,278,5,57,0,0,
  	278,280,3,42,21,0,279,276,1,0,0,0,280,283,1,0,0,0,281,279,1,0,0,0,281,
  	282,1,0,0,0,282,41,1,0,0,0,283,281,1,0,0,0,284,287,3,44,22,0,285,287,
  	3,46,23,0,286,284,1,0,0,0,286,285,1,0,0,0,287,43,1,0,0,0,288,289,5,32,
  	0,0,289,290,3,46,23,0,290,45,1,0,0,0,291,292,3,6,3,0,292,293,5,56,0,0,
  	293,294,3,20,10,0,294,47,1,0,0,0,295,296,5,9,0,0,296,297,3,50,25,0,297,
  	298,5,16,0,0,298,49,1,0,0,0,299,300,6,25,-1,0,300,301,3,52,26,0,301,307,
  	1,0,0,0,302,303,10,2,0,0,303,304,5,57,0,0,304,306,3,52,26,0,305,302,1,
  	0,0,0,306,309,1,0,0,0,307,305,1,0,0,0,307,308,1,0,0,0,308,51,1,0,0,0,
  	309,307,1,0,0,0,310,311,3,54,27,0,311,312,5,52,0,0,312,313,3,76,38,0,
  	313,349,1,0,0,0,314,349,3,72,36,0,315,349,3,48,24,0,316,317,5,20,0,0,
  	317,318,3,76,38,0,318,319,5,27,0,0,319,320,3,52,26,0,320,321,3,60,30,
  	0,321,349,1,0,0,0,322,323,5,10,0,0,323,324,3,76,38,0,324,325,5,22,0,0,
  	325,326,3,62,31,0,326,327,5,16,0,0,327,349,1,0,0,0,328,329,5,33,0,0,329,
  	330,3,76,38,0,330,331,5,13,0,0,331,332,3,52,26,0,332,349,1,0,0,0,333,
  	334,5,26,0,0,334,335,3,50,25,0,335,336,5,31,0,0,336,337,3,76,38,0,337,
  	349,1,0,0,0,338,339,5,18,0,0,339,340,5,35,0,0,340,341,5,52,0,0,341,342,
  	3,76,38,0,342,343,3,70,35,0,343,344,3,76,38,0,344,345,5,13,0,0,345,346,
  	3,52,26,0,346,349,1,0,0,0,347,349,1,0,0,0,348,310,1,0,0,0,348,314,1,0,
  	0,0,348,315,1,0,0,0,348,316,1,0,0,0,348,322,1,0,0,0,348,328,1,0,0,0,348,
  	333,1,0,0,0,348,338,1,0,0,0,348,347,1,0,0,0,349,53,1,0,0,0,350,351,5,
  	35,0,0,351,352,3,56,28,0,352,55,1,0,0,0,353,358,6,28,-1,0,354,355,10,
  	2,0,0,355,357,3,58,29,0,356,354,1,0,0,0,357,360,1,0,0,0,358,356,1,0,0,
  	0,358,359,1,0,0,0,359,57,1,0,0,0,360,358,1,0,0,0,361,362,5,61,0,0,362,
  	363,3,74,37,0,363,364,5,62,0,0,364,368,1,0,0,0,365,366,5,54,0,0,366,368,
  	5,35,0,0,367,361,1,0,0,0,367,365,1,0,0,0,368,59,1,0,0,0,369,370,5,15,
  	0,0,370,373,3,52,26,0,371,373,1,0,0,0,372,369,1,0,0,0,372,371,1,0,0,0,
  	373,61,1,0,0,0,374,377,3,64,32,0,375,377,1,0,0,0,376,374,1,0,0,0,376,
  	375,1,0,0,0,377,63,1,0,0,0,378,379,6,32,-1,0,379,380,3,66,33,0,380,386,
  	1,0,0,0,381,382,10,2,0,0,382,383,5,57,0,0,383,385,3,66,33,0,384,381,1,
  	0,0,0,385,388,1,0,0,0,386,384,1,0,0,0,386,387,1,0,0,0,387,65,1,0,0,0,
  	388,386,1,0,0,0,389,390,3,68,34,0,390,391,5,56,0,0,391,392,3,52,26,0,
  	392,67,1,0,0,0,393,394,6,34,-1,0,394,395,3,12,6,0,395,401,1,0,0,0,396,
  	397,10,2,0,0,397,398,5,55,0,0,398,400,3,12,6,0,399,396,1,0,0,0,400,403,
  	1,0,0,0,401,399,1,0,0,0,401,402,1,0,0,0,402,69,1,0,0,0,403,401,1,0,0,
  	0,404,405,7,1,0,0,405,71,1,0,0,0,406,411,5,35,0,0,407,408,5,59,0,0,408,
  	409,3,74,37,0,409,410,5,60,0,0,410,412,1,0,0,0,411,407,1,0,0,0,411,412,
  	1,0,0,0,412,73,1,0,0,0,413,414,6,37,-1,0,414,415,3,76,38,0,415,421,1,
  	0,0,0,416,417,10,2,0,0,417,418,5,55,0,0,418,420,3,76,38,0,419,416,1,0,
  	0,0,420,423,1,0,0,0,421,419,1,0,0,0,421,422,1,0,0,0,422,75,1,0,0,0,423,
  	421,1,0,0,0,424,425,3,78,39,0,425,426,3,88,44,0,426,427,3,78,39,0,427,
  	430,1,0,0,0,428,430,3,78,39,0,429,424,1,0,0,0,429,428,1,0,0,0,430,77,
  	1,0,0,0,431,432,6,39,-1,0,432,438,3,80,40,0,433,434,5,48,0,0,434,438,
  	3,80,40,0,435,436,5,49,0,0,436,438,3,80,40,0,437,431,1,0,0,0,437,433,
  	1,0,0,0,437,435,1,0,0,0,438,445,1,0,0,0,439,440,10,1,0,0,440,441,3,90,
  	45,0,441,442,3,80,40,0,442,444,1,0,0,0,443,439,1,0,0,0,444,447,1,0,0,
  	0,445,443,1,0,0,0,445,446,1,0,0,0,446,79,1,0,0,0,447,445,1,0,0,0,448,
  	449,6,40,-1,0,449,450,3,84,42,0,450,457,1,0,0,0,451,452,10,2,0,0,452,
  	453,3,92,46,0,453,454,3,84,42,0,454,456,1,0,0,0,455,451,1,0,0,0,456,459,
  	1,0,0,0,457,455,1,0,0,0,457,458,1,0,0,0,458,81,1,0,0,0,459,457,1,0,0,
  	0,460,461,7,2,0,0,461,83,1,0,0,0,462,480,3,86,43,0,463,480,3,54,27,0,
  	464,465,5,35,0,0,465,466,5,59,0,0,466,467,3,74,37,0,467,468,5,60,0,0,
  	468,480,1,0,0,0,469,470,5,35,0,0,470,471,5,59,0,0,471,480,5,60,0,0,472,
  	473,5,59,0,0,473,474,3,76,38,0,474,475,5,60,0,0,475,480,1,0,0,0,476,477,
  	5,3,0,0,477,480,3,84,42,0,478,480,3,82,41,0,479,462,1,0,0,0,479,463,1,
  	0,0,0,479,464,1,0,0,0,479,469,1,0,0,0,479,472,1,0,0,0,479,476,1,0,0,0,
  	479,478,1,0,0,0,480,85,1,0,0,0,481,482,7,3,0,0,482,87,1,0,0,0,483,484,
  	7,4,0,0,484,89,1,0,0,0,485,486,7,5,0,0,486,91,1,0,0,0,487,488,7,6,0,0,
  	488,93,1,0,0,0,32,104,122,130,144,158,165,179,194,200,210,222,237,245,
  	264,271,281,286,307,348,358,367,372,376,386,401,411,421,429,437,445,457,
  	479
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  pascalsParserStaticData = std::move(staticData);
}

}

PascalSParser::PascalSParser(TokenStream *input) : PascalSParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

PascalSParser::PascalSParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  PascalSParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *pascalsParserStaticData->atn, pascalsParserStaticData->decisionToDFA, pascalsParserStaticData->sharedContextCache, options);
}

PascalSParser::~PascalSParser() {
  delete _interpreter;
}

const atn::ATN& PascalSParser::getATN() const {
  return *pascalsParserStaticData->atn;
}

std::string PascalSParser::getGrammarFileName() const {
  return "PascalS.g4";
}

const std::vector<std::string>& PascalSParser::getRuleNames() const {
  return pascalsParserStaticData->ruleNames;
}

const dfa::Vocabulary& PascalSParser::getVocabulary() const {
  return pascalsParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PascalSParser::getSerializedATN() const {
  return pascalsParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

PascalSParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::ProgramHeadContext* PascalSParser::ProgramContext::programHead() {
  return getRuleContext<PascalSParser::ProgramHeadContext>(0);
}

PascalSParser::ProgramBodyContext* PascalSParser::ProgramContext::programBody() {
  return getRuleContext<PascalSParser::ProgramBodyContext>(0);
}

tree::TerminalNode* PascalSParser::ProgramContext::DOT() {
  return getToken(PascalSParser::DOT, 0);
}


size_t PascalSParser::ProgramContext::getRuleIndex() const {
  return PascalSParser::RuleProgram;
}


std::any PascalSParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::ProgramContext* PascalSParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, PascalSParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    programHead();
    setState(95);
    programBody();
    setState(96);
    match(PascalSParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramHeadContext ------------------------------------------------------------------

PascalSParser::ProgramHeadContext::ProgramHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::ProgramHeadContext::PROGRAM() {
  return getToken(PascalSParser::PROGRAM, 0);
}

tree::TerminalNode* PascalSParser::ProgramHeadContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

tree::TerminalNode* PascalSParser::ProgramHeadContext::SEMICOLON() {
  return getToken(PascalSParser::SEMICOLON, 0);
}

tree::TerminalNode* PascalSParser::ProgramHeadContext::LPAREN() {
  return getToken(PascalSParser::LPAREN, 0);
}

PascalSParser::IdentifierListContext* PascalSParser::ProgramHeadContext::identifierList() {
  return getRuleContext<PascalSParser::IdentifierListContext>(0);
}

tree::TerminalNode* PascalSParser::ProgramHeadContext::RPAREN() {
  return getToken(PascalSParser::RPAREN, 0);
}


size_t PascalSParser::ProgramHeadContext::getRuleIndex() const {
  return PascalSParser::RuleProgramHead;
}


std::any PascalSParser::ProgramHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitProgramHead(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::ProgramHeadContext* PascalSParser::programHead() {
  ProgramHeadContext *_localctx = _tracker.createInstance<ProgramHeadContext>(_ctx, getState());
  enterRule(_localctx, 2, PascalSParser::RuleProgramHead);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    match(PascalSParser::PROGRAM);
    setState(99);
    match(PascalSParser::ID);
    setState(104);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalSParser::LPAREN) {
      setState(100);
      match(PascalSParser::LPAREN);
      setState(101);
      identifierList(0);
      setState(102);
      match(PascalSParser::RPAREN);
    }
    setState(106);
    match(PascalSParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramBodyContext ------------------------------------------------------------------

PascalSParser::ProgramBodyContext::ProgramBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::ConstDeclarationsContext* PascalSParser::ProgramBodyContext::constDeclarations() {
  return getRuleContext<PascalSParser::ConstDeclarationsContext>(0);
}

PascalSParser::TypeDeclarationsContext* PascalSParser::ProgramBodyContext::typeDeclarations() {
  return getRuleContext<PascalSParser::TypeDeclarationsContext>(0);
}

PascalSParser::VarDeclarationsContext* PascalSParser::ProgramBodyContext::varDeclarations() {
  return getRuleContext<PascalSParser::VarDeclarationsContext>(0);
}

PascalSParser::SubprogramDeclarationsContext* PascalSParser::ProgramBodyContext::subprogramDeclarations() {
  return getRuleContext<PascalSParser::SubprogramDeclarationsContext>(0);
}

PascalSParser::CompoundStatementContext* PascalSParser::ProgramBodyContext::compoundStatement() {
  return getRuleContext<PascalSParser::CompoundStatementContext>(0);
}


size_t PascalSParser::ProgramBodyContext::getRuleIndex() const {
  return PascalSParser::RuleProgramBody;
}


std::any PascalSParser::ProgramBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitProgramBody(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::ProgramBodyContext* PascalSParser::programBody() {
  ProgramBodyContext *_localctx = _tracker.createInstance<ProgramBodyContext>(_ctx, getState());
  enterRule(_localctx, 4, PascalSParser::RuleProgramBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    constDeclarations();
    setState(109);
    typeDeclarations();
    setState(110);
    varDeclarations();
    setState(111);
    subprogramDeclarations(0);
    setState(112);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

PascalSParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::IdentifierListContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::IdentifierListContext* PascalSParser::IdentifierListContext::identifierList() {
  return getRuleContext<PascalSParser::IdentifierListContext>(0);
}

tree::TerminalNode* PascalSParser::IdentifierListContext::COMMA() {
  return getToken(PascalSParser::COMMA, 0);
}


size_t PascalSParser::IdentifierListContext::getRuleIndex() const {
  return PascalSParser::RuleIdentifierList;
}


std::any PascalSParser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::IdentifierListContext* PascalSParser::identifierList() {
   return identifierList(0);
}

PascalSParser::IdentifierListContext* PascalSParser::identifierList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, parentState);
  PascalSParser::IdentifierListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, PascalSParser::RuleIdentifierList, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(PascalSParser::ID);
    _ctx->stop = _input->LT(-1);
    setState(122);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IdentifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIdentifierList);
        setState(117);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(118);
        match(PascalSParser::COMMA);
        setState(119);
        match(PascalSParser::ID); 
      }
      setState(124);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstDeclarationsContext ------------------------------------------------------------------

PascalSParser::ConstDeclarationsContext::ConstDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::ConstDeclarationsContext::CONST() {
  return getToken(PascalSParser::CONST, 0);
}

PascalSParser::ConstDeclarationContext* PascalSParser::ConstDeclarationsContext::constDeclaration() {
  return getRuleContext<PascalSParser::ConstDeclarationContext>(0);
}

tree::TerminalNode* PascalSParser::ConstDeclarationsContext::SEMICOLON() {
  return getToken(PascalSParser::SEMICOLON, 0);
}


size_t PascalSParser::ConstDeclarationsContext::getRuleIndex() const {
  return PascalSParser::RuleConstDeclarations;
}


std::any PascalSParser::ConstDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitConstDeclarations(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::ConstDeclarationsContext* PascalSParser::constDeclarations() {
  ConstDeclarationsContext *_localctx = _tracker.createInstance<ConstDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 8, PascalSParser::RuleConstDeclarations);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(125);
      match(PascalSParser::CONST);
      setState(126);
      constDeclaration(0);
      setState(127);
      match(PascalSParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclarationContext ------------------------------------------------------------------

PascalSParser::ConstDeclarationContext::ConstDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::ConstDeclarationContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

tree::TerminalNode* PascalSParser::ConstDeclarationContext::EQUAL() {
  return getToken(PascalSParser::EQUAL, 0);
}

PascalSParser::ConstVariableContext* PascalSParser::ConstDeclarationContext::constVariable() {
  return getRuleContext<PascalSParser::ConstVariableContext>(0);
}

PascalSParser::ConstDeclarationContext* PascalSParser::ConstDeclarationContext::constDeclaration() {
  return getRuleContext<PascalSParser::ConstDeclarationContext>(0);
}

tree::TerminalNode* PascalSParser::ConstDeclarationContext::SEMICOLON() {
  return getToken(PascalSParser::SEMICOLON, 0);
}


size_t PascalSParser::ConstDeclarationContext::getRuleIndex() const {
  return PascalSParser::RuleConstDeclaration;
}


std::any PascalSParser::ConstDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitConstDeclaration(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::ConstDeclarationContext* PascalSParser::constDeclaration() {
   return constDeclaration(0);
}

PascalSParser::ConstDeclarationContext* PascalSParser::constDeclaration(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::ConstDeclarationContext *_localctx = _tracker.createInstance<ConstDeclarationContext>(_ctx, parentState);
  PascalSParser::ConstDeclarationContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, PascalSParser::RuleConstDeclaration, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(PascalSParser::ID);
    setState(134);
    match(PascalSParser::EQUAL);
    setState(135);
    constVariable();
    _ctx->stop = _input->LT(-1);
    setState(144);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ConstDeclarationContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleConstDeclaration);
        setState(137);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(138);
        match(PascalSParser::SEMICOLON);
        setState(139);
        match(PascalSParser::ID);
        setState(140);
        match(PascalSParser::EQUAL);
        setState(141);
        constVariable(); 
      }
      setState(146);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstVariableContext ------------------------------------------------------------------

PascalSParser::ConstVariableContext::ConstVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::ConstVariableContext::PLUS() {
  return getToken(PascalSParser::PLUS, 0);
}

tree::TerminalNode* PascalSParser::ConstVariableContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

tree::TerminalNode* PascalSParser::ConstVariableContext::MINUS() {
  return getToken(PascalSParser::MINUS, 0);
}

tree::TerminalNode* PascalSParser::ConstVariableContext::NUM() {
  return getToken(PascalSParser::NUM, 0);
}

tree::TerminalNode* PascalSParser::ConstVariableContext::CHARLITERAL() {
  return getToken(PascalSParser::CHARLITERAL, 0);
}


size_t PascalSParser::ConstVariableContext::getRuleIndex() const {
  return PascalSParser::RuleConstVariable;
}


std::any PascalSParser::ConstVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitConstVariable(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::ConstVariableContext* PascalSParser::constVariable() {
  ConstVariableContext *_localctx = _tracker.createInstance<ConstVariableContext>(_ctx, getState());
  enterRule(_localctx, 12, PascalSParser::RuleConstVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(147);
      match(PascalSParser::PLUS);
      setState(148);
      match(PascalSParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(149);
      match(PascalSParser::MINUS);
      setState(150);
      match(PascalSParser::ID);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(151);
      match(PascalSParser::ID);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(152);
      match(PascalSParser::PLUS);
      setState(153);
      match(PascalSParser::NUM);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(154);
      match(PascalSParser::MINUS);
      setState(155);
      match(PascalSParser::NUM);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(156);
      match(PascalSParser::NUM);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(157);
      match(PascalSParser::CHARLITERAL);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclarationsContext ------------------------------------------------------------------

PascalSParser::TypeDeclarationsContext::TypeDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::TypeDeclarationsContext::TYPE() {
  return getToken(PascalSParser::TYPE, 0);
}

PascalSParser::TypeDeclarationContext* PascalSParser::TypeDeclarationsContext::typeDeclaration() {
  return getRuleContext<PascalSParser::TypeDeclarationContext>(0);
}

tree::TerminalNode* PascalSParser::TypeDeclarationsContext::SEMICOLON() {
  return getToken(PascalSParser::SEMICOLON, 0);
}


size_t PascalSParser::TypeDeclarationsContext::getRuleIndex() const {
  return PascalSParser::RuleTypeDeclarations;
}


std::any PascalSParser::TypeDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitTypeDeclarations(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::TypeDeclarationsContext* PascalSParser::typeDeclarations() {
  TypeDeclarationsContext *_localctx = _tracker.createInstance<TypeDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 14, PascalSParser::RuleTypeDeclarations);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(165);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(160);
      match(PascalSParser::TYPE);
      setState(161);
      typeDeclaration(0);
      setState(162);
      match(PascalSParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclarationContext ------------------------------------------------------------------

PascalSParser::TypeDeclarationContext::TypeDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::TypeDeclarationContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

tree::TerminalNode* PascalSParser::TypeDeclarationContext::EQUAL() {
  return getToken(PascalSParser::EQUAL, 0);
}

PascalSParser::TypeContext* PascalSParser::TypeDeclarationContext::type() {
  return getRuleContext<PascalSParser::TypeContext>(0);
}

PascalSParser::TypeDeclarationContext* PascalSParser::TypeDeclarationContext::typeDeclaration() {
  return getRuleContext<PascalSParser::TypeDeclarationContext>(0);
}

tree::TerminalNode* PascalSParser::TypeDeclarationContext::SEMICOLON() {
  return getToken(PascalSParser::SEMICOLON, 0);
}


size_t PascalSParser::TypeDeclarationContext::getRuleIndex() const {
  return PascalSParser::RuleTypeDeclaration;
}


std::any PascalSParser::TypeDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitTypeDeclaration(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::TypeDeclarationContext* PascalSParser::typeDeclaration() {
   return typeDeclaration(0);
}

PascalSParser::TypeDeclarationContext* PascalSParser::typeDeclaration(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::TypeDeclarationContext *_localctx = _tracker.createInstance<TypeDeclarationContext>(_ctx, parentState);
  PascalSParser::TypeDeclarationContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, PascalSParser::RuleTypeDeclaration, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(168);
    match(PascalSParser::ID);
    setState(169);
    match(PascalSParser::EQUAL);
    setState(170);
    type();
    _ctx->stop = _input->LT(-1);
    setState(179);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeDeclarationContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypeDeclaration);
        setState(172);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(173);
        match(PascalSParser::SEMICOLON);
        setState(174);
        match(PascalSParser::ID);
        setState(175);
        match(PascalSParser::EQUAL);
        setState(176);
        type(); 
      }
      setState(181);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

PascalSParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::StandardTypeContext* PascalSParser::TypeContext::standardType() {
  return getRuleContext<PascalSParser::StandardTypeContext>(0);
}

tree::TerminalNode* PascalSParser::TypeContext::RECORD() {
  return getToken(PascalSParser::RECORD, 0);
}

PascalSParser::RecordBodyContext* PascalSParser::TypeContext::recordBody() {
  return getRuleContext<PascalSParser::RecordBodyContext>(0);
}

tree::TerminalNode* PascalSParser::TypeContext::END() {
  return getToken(PascalSParser::END, 0);
}

tree::TerminalNode* PascalSParser::TypeContext::ARRAY() {
  return getToken(PascalSParser::ARRAY, 0);
}

tree::TerminalNode* PascalSParser::TypeContext::LBRACKET() {
  return getToken(PascalSParser::LBRACKET, 0);
}

PascalSParser::PeriodsContext* PascalSParser::TypeContext::periods() {
  return getRuleContext<PascalSParser::PeriodsContext>(0);
}

tree::TerminalNode* PascalSParser::TypeContext::RBRACKET() {
  return getToken(PascalSParser::RBRACKET, 0);
}

tree::TerminalNode* PascalSParser::TypeContext::OF() {
  return getToken(PascalSParser::OF, 0);
}

PascalSParser::TypeContext* PascalSParser::TypeContext::type() {
  return getRuleContext<PascalSParser::TypeContext>(0);
}


size_t PascalSParser::TypeContext::getRuleIndex() const {
  return PascalSParser::RuleType;
}


std::any PascalSParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::TypeContext* PascalSParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 18, PascalSParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(194);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::INTEGER:
      case PascalSParser::REAL:
      case PascalSParser::BOOLEAN:
      case PascalSParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(182);
        standardType();
        break;
      }

      case PascalSParser::RECORD: {
        enterOuterAlt(_localctx, 2);
        setState(183);
        match(PascalSParser::RECORD);
        setState(184);
        recordBody();
        setState(185);
        match(PascalSParser::END);
        break;
      }

      case PascalSParser::ARRAY: {
        enterOuterAlt(_localctx, 3);
        setState(187);
        match(PascalSParser::ARRAY);
        setState(188);
        match(PascalSParser::LBRACKET);
        setState(189);
        periods(0);
        setState(190);
        match(PascalSParser::RBRACKET);
        setState(191);
        match(PascalSParser::OF);
        setState(192);
        type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StandardTypeContext ------------------------------------------------------------------

PascalSParser::StandardTypeContext::StandardTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::StandardTypeContext::INTEGER() {
  return getToken(PascalSParser::INTEGER, 0);
}

tree::TerminalNode* PascalSParser::StandardTypeContext::BOOLEAN() {
  return getToken(PascalSParser::BOOLEAN, 0);
}

tree::TerminalNode* PascalSParser::StandardTypeContext::REAL() {
  return getToken(PascalSParser::REAL, 0);
}

tree::TerminalNode* PascalSParser::StandardTypeContext::CHAR() {
  return getToken(PascalSParser::CHAR, 0);
}


size_t PascalSParser::StandardTypeContext::getRuleIndex() const {
  return PascalSParser::RuleStandardType;
}


std::any PascalSParser::StandardTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitStandardType(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::StandardTypeContext* PascalSParser::standardType() {
  StandardTypeContext *_localctx = _tracker.createInstance<StandardTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, PascalSParser::RuleStandardType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 240) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecordBodyContext ------------------------------------------------------------------

PascalSParser::RecordBodyContext::RecordBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::VarDeclarationContext* PascalSParser::RecordBodyContext::varDeclaration() {
  return getRuleContext<PascalSParser::VarDeclarationContext>(0);
}


size_t PascalSParser::RecordBodyContext::getRuleIndex() const {
  return PascalSParser::RuleRecordBody;
}


std::any PascalSParser::RecordBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitRecordBody(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::RecordBodyContext* PascalSParser::recordBody() {
  RecordBodyContext *_localctx = _tracker.createInstance<RecordBodyContext>(_ctx, getState());
  enterRule(_localctx, 22, PascalSParser::RuleRecordBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(200);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(198);
        varDeclaration(0);
        break;
      }

      case PascalSParser::END: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PeriodsContext ------------------------------------------------------------------

PascalSParser::PeriodsContext::PeriodsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::PeriodContext* PascalSParser::PeriodsContext::period() {
  return getRuleContext<PascalSParser::PeriodContext>(0);
}

PascalSParser::PeriodsContext* PascalSParser::PeriodsContext::periods() {
  return getRuleContext<PascalSParser::PeriodsContext>(0);
}

tree::TerminalNode* PascalSParser::PeriodsContext::COMMA() {
  return getToken(PascalSParser::COMMA, 0);
}


size_t PascalSParser::PeriodsContext::getRuleIndex() const {
  return PascalSParser::RulePeriods;
}


std::any PascalSParser::PeriodsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitPeriods(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::PeriodsContext* PascalSParser::periods() {
   return periods(0);
}

PascalSParser::PeriodsContext* PascalSParser::periods(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::PeriodsContext *_localctx = _tracker.createInstance<PeriodsContext>(_ctx, parentState);
  PascalSParser::PeriodsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, PascalSParser::RulePeriods, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(203);
    period();
    _ctx->stop = _input->LT(-1);
    setState(210);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<PeriodsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RulePeriods);
        setState(205);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(206);
        match(PascalSParser::COMMA);
        setState(207);
        period(); 
      }
      setState(212);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PeriodContext ------------------------------------------------------------------

PascalSParser::PeriodContext::PeriodContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalSParser::ConstVariableContext *> PascalSParser::PeriodContext::constVariable() {
  return getRuleContexts<PascalSParser::ConstVariableContext>();
}

PascalSParser::ConstVariableContext* PascalSParser::PeriodContext::constVariable(size_t i) {
  return getRuleContext<PascalSParser::ConstVariableContext>(i);
}

tree::TerminalNode* PascalSParser::PeriodContext::PERIODOP() {
  return getToken(PascalSParser::PERIODOP, 0);
}


size_t PascalSParser::PeriodContext::getRuleIndex() const {
  return PascalSParser::RulePeriod;
}


std::any PascalSParser::PeriodContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitPeriod(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::PeriodContext* PascalSParser::period() {
  PeriodContext *_localctx = _tracker.createInstance<PeriodContext>(_ctx, getState());
  enterRule(_localctx, 26, PascalSParser::RulePeriod);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    constVariable();
    setState(214);
    match(PascalSParser::PERIODOP);
    setState(215);
    constVariable();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclarationsContext ------------------------------------------------------------------

PascalSParser::VarDeclarationsContext::VarDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::VarDeclarationsContext::VAR() {
  return getToken(PascalSParser::VAR, 0);
}

PascalSParser::VarDeclarationContext* PascalSParser::VarDeclarationsContext::varDeclaration() {
  return getRuleContext<PascalSParser::VarDeclarationContext>(0);
}

tree::TerminalNode* PascalSParser::VarDeclarationsContext::SEMICOLON() {
  return getToken(PascalSParser::SEMICOLON, 0);
}


size_t PascalSParser::VarDeclarationsContext::getRuleIndex() const {
  return PascalSParser::RuleVarDeclarations;
}


std::any PascalSParser::VarDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitVarDeclarations(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::VarDeclarationsContext* PascalSParser::varDeclarations() {
  VarDeclarationsContext *_localctx = _tracker.createInstance<VarDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 28, PascalSParser::RuleVarDeclarations);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(222);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(217);
      match(PascalSParser::VAR);
      setState(218);
      varDeclaration(0);
      setState(219);
      match(PascalSParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclarationContext ------------------------------------------------------------------

PascalSParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::IdentifierListContext* PascalSParser::VarDeclarationContext::identifierList() {
  return getRuleContext<PascalSParser::IdentifierListContext>(0);
}

tree::TerminalNode* PascalSParser::VarDeclarationContext::COLON() {
  return getToken(PascalSParser::COLON, 0);
}

PascalSParser::TypeContext* PascalSParser::VarDeclarationContext::type() {
  return getRuleContext<PascalSParser::TypeContext>(0);
}

PascalSParser::VarDeclarationContext* PascalSParser::VarDeclarationContext::varDeclaration() {
  return getRuleContext<PascalSParser::VarDeclarationContext>(0);
}

tree::TerminalNode* PascalSParser::VarDeclarationContext::SEMICOLON() {
  return getToken(PascalSParser::SEMICOLON, 0);
}


size_t PascalSParser::VarDeclarationContext::getRuleIndex() const {
  return PascalSParser::RuleVarDeclaration;
}


std::any PascalSParser::VarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitVarDeclaration(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::VarDeclarationContext* PascalSParser::varDeclaration() {
   return varDeclaration(0);
}

PascalSParser::VarDeclarationContext* PascalSParser::varDeclaration(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, parentState);
  PascalSParser::VarDeclarationContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, PascalSParser::RuleVarDeclaration, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(225);
    identifierList(0);
    setState(226);
    match(PascalSParser::COLON);
    setState(227);
    type();
    _ctx->stop = _input->LT(-1);
    setState(237);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<VarDeclarationContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleVarDeclaration);
        setState(229);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(230);
        match(PascalSParser::SEMICOLON);
        setState(231);
        identifierList(0);
        setState(232);
        match(PascalSParser::COLON);
        setState(233);
        type(); 
      }
      setState(239);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SubprogramDeclarationsContext ------------------------------------------------------------------

PascalSParser::SubprogramDeclarationsContext::SubprogramDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::SubprogramDeclarationsContext* PascalSParser::SubprogramDeclarationsContext::subprogramDeclarations() {
  return getRuleContext<PascalSParser::SubprogramDeclarationsContext>(0);
}

PascalSParser::SubprogramDeclarationContext* PascalSParser::SubprogramDeclarationsContext::subprogramDeclaration() {
  return getRuleContext<PascalSParser::SubprogramDeclarationContext>(0);
}


size_t PascalSParser::SubprogramDeclarationsContext::getRuleIndex() const {
  return PascalSParser::RuleSubprogramDeclarations;
}


std::any PascalSParser::SubprogramDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitSubprogramDeclarations(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::SubprogramDeclarationsContext* PascalSParser::subprogramDeclarations() {
   return subprogramDeclarations(0);
}

PascalSParser::SubprogramDeclarationsContext* PascalSParser::subprogramDeclarations(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::SubprogramDeclarationsContext *_localctx = _tracker.createInstance<SubprogramDeclarationsContext>(_ctx, parentState);
  PascalSParser::SubprogramDeclarationsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, PascalSParser::RuleSubprogramDeclarations, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _ctx->stop = _input->LT(-1);
    setState(245);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<SubprogramDeclarationsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleSubprogramDeclarations);
        setState(241);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(242);
        subprogramDeclaration(); 
      }
      setState(247);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SubprogramDeclarationContext ------------------------------------------------------------------

PascalSParser::SubprogramDeclarationContext::SubprogramDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::SubprogramHeadContext* PascalSParser::SubprogramDeclarationContext::subprogramHead() {
  return getRuleContext<PascalSParser::SubprogramHeadContext>(0);
}

PascalSParser::ProgramBodyContext* PascalSParser::SubprogramDeclarationContext::programBody() {
  return getRuleContext<PascalSParser::ProgramBodyContext>(0);
}

tree::TerminalNode* PascalSParser::SubprogramDeclarationContext::SEMICOLON() {
  return getToken(PascalSParser::SEMICOLON, 0);
}


size_t PascalSParser::SubprogramDeclarationContext::getRuleIndex() const {
  return PascalSParser::RuleSubprogramDeclaration;
}


std::any PascalSParser::SubprogramDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitSubprogramDeclaration(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::SubprogramDeclarationContext* PascalSParser::subprogramDeclaration() {
  SubprogramDeclarationContext *_localctx = _tracker.createInstance<SubprogramDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 34, PascalSParser::RuleSubprogramDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    subprogramHead();
    setState(249);
    programBody();
    setState(250);
    match(PascalSParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubprogramHeadContext ------------------------------------------------------------------

PascalSParser::SubprogramHeadContext::SubprogramHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::SubprogramHeadContext::FUNCTION() {
  return getToken(PascalSParser::FUNCTION, 0);
}

tree::TerminalNode* PascalSParser::SubprogramHeadContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::FormalParameterContext* PascalSParser::SubprogramHeadContext::formalParameter() {
  return getRuleContext<PascalSParser::FormalParameterContext>(0);
}

tree::TerminalNode* PascalSParser::SubprogramHeadContext::COLON() {
  return getToken(PascalSParser::COLON, 0);
}

PascalSParser::StandardTypeContext* PascalSParser::SubprogramHeadContext::standardType() {
  return getRuleContext<PascalSParser::StandardTypeContext>(0);
}

tree::TerminalNode* PascalSParser::SubprogramHeadContext::SEMICOLON() {
  return getToken(PascalSParser::SEMICOLON, 0);
}

tree::TerminalNode* PascalSParser::SubprogramHeadContext::PROCEDURE() {
  return getToken(PascalSParser::PROCEDURE, 0);
}


size_t PascalSParser::SubprogramHeadContext::getRuleIndex() const {
  return PascalSParser::RuleSubprogramHead;
}


std::any PascalSParser::SubprogramHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitSubprogramHead(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::SubprogramHeadContext* PascalSParser::subprogramHead() {
  SubprogramHeadContext *_localctx = _tracker.createInstance<SubprogramHeadContext>(_ctx, getState());
  enterRule(_localctx, 36, PascalSParser::RuleSubprogramHead);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(264);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::FUNCTION: {
        enterOuterAlt(_localctx, 1);
        setState(252);
        match(PascalSParser::FUNCTION);
        setState(253);
        match(PascalSParser::ID);
        setState(254);
        formalParameter();
        setState(255);
        match(PascalSParser::COLON);
        setState(256);
        standardType();
        setState(257);
        match(PascalSParser::SEMICOLON);
        break;
      }

      case PascalSParser::PROCEDURE: {
        enterOuterAlt(_localctx, 2);
        setState(259);
        match(PascalSParser::PROCEDURE);
        setState(260);
        match(PascalSParser::ID);
        setState(261);
        formalParameter();
        setState(262);
        match(PascalSParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterContext ------------------------------------------------------------------

PascalSParser::FormalParameterContext::FormalParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::FormalParameterContext::LPAREN() {
  return getToken(PascalSParser::LPAREN, 0);
}

PascalSParser::ParameterListsContext* PascalSParser::FormalParameterContext::parameterLists() {
  return getRuleContext<PascalSParser::ParameterListsContext>(0);
}

tree::TerminalNode* PascalSParser::FormalParameterContext::RPAREN() {
  return getToken(PascalSParser::RPAREN, 0);
}


size_t PascalSParser::FormalParameterContext::getRuleIndex() const {
  return PascalSParser::RuleFormalParameter;
}


std::any PascalSParser::FormalParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitFormalParameter(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::FormalParameterContext* PascalSParser::formalParameter() {
  FormalParameterContext *_localctx = _tracker.createInstance<FormalParameterContext>(_ctx, getState());
  enterRule(_localctx, 38, PascalSParser::RuleFormalParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(271);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(266);
        match(PascalSParser::LPAREN);
        setState(267);
        parameterLists(0);
        setState(268);
        match(PascalSParser::RPAREN);
        break;
      }

      case PascalSParser::COLON:
      case PascalSParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListsContext ------------------------------------------------------------------

PascalSParser::ParameterListsContext::ParameterListsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::ParameterListContext* PascalSParser::ParameterListsContext::parameterList() {
  return getRuleContext<PascalSParser::ParameterListContext>(0);
}

PascalSParser::ParameterListsContext* PascalSParser::ParameterListsContext::parameterLists() {
  return getRuleContext<PascalSParser::ParameterListsContext>(0);
}

tree::TerminalNode* PascalSParser::ParameterListsContext::SEMICOLON() {
  return getToken(PascalSParser::SEMICOLON, 0);
}


size_t PascalSParser::ParameterListsContext::getRuleIndex() const {
  return PascalSParser::RuleParameterLists;
}


std::any PascalSParser::ParameterListsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitParameterLists(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::ParameterListsContext* PascalSParser::parameterLists() {
   return parameterLists(0);
}

PascalSParser::ParameterListsContext* PascalSParser::parameterLists(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::ParameterListsContext *_localctx = _tracker.createInstance<ParameterListsContext>(_ctx, parentState);
  PascalSParser::ParameterListsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, PascalSParser::RuleParameterLists, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(274);
    parameterList();
    _ctx->stop = _input->LT(-1);
    setState(281);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterListsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterLists);
        setState(276);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(277);
        match(PascalSParser::SEMICOLON);
        setState(278);
        parameterList(); 
      }
      setState(283);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

PascalSParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::VarParameterContext* PascalSParser::ParameterListContext::varParameter() {
  return getRuleContext<PascalSParser::VarParameterContext>(0);
}

PascalSParser::ValueParameterContext* PascalSParser::ParameterListContext::valueParameter() {
  return getRuleContext<PascalSParser::ValueParameterContext>(0);
}


size_t PascalSParser::ParameterListContext::getRuleIndex() const {
  return PascalSParser::RuleParameterList;
}


std::any PascalSParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::ParameterListContext* PascalSParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 42, PascalSParser::RuleParameterList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(286);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(284);
        varParameter();
        break;
      }

      case PascalSParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(285);
        valueParameter();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarParameterContext ------------------------------------------------------------------

PascalSParser::VarParameterContext::VarParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::VarParameterContext::VAR() {
  return getToken(PascalSParser::VAR, 0);
}

PascalSParser::ValueParameterContext* PascalSParser::VarParameterContext::valueParameter() {
  return getRuleContext<PascalSParser::ValueParameterContext>(0);
}


size_t PascalSParser::VarParameterContext::getRuleIndex() const {
  return PascalSParser::RuleVarParameter;
}


std::any PascalSParser::VarParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitVarParameter(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::VarParameterContext* PascalSParser::varParameter() {
  VarParameterContext *_localctx = _tracker.createInstance<VarParameterContext>(_ctx, getState());
  enterRule(_localctx, 44, PascalSParser::RuleVarParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    match(PascalSParser::VAR);
    setState(289);
    valueParameter();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueParameterContext ------------------------------------------------------------------

PascalSParser::ValueParameterContext::ValueParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::IdentifierListContext* PascalSParser::ValueParameterContext::identifierList() {
  return getRuleContext<PascalSParser::IdentifierListContext>(0);
}

tree::TerminalNode* PascalSParser::ValueParameterContext::COLON() {
  return getToken(PascalSParser::COLON, 0);
}

PascalSParser::StandardTypeContext* PascalSParser::ValueParameterContext::standardType() {
  return getRuleContext<PascalSParser::StandardTypeContext>(0);
}


size_t PascalSParser::ValueParameterContext::getRuleIndex() const {
  return PascalSParser::RuleValueParameter;
}


std::any PascalSParser::ValueParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitValueParameter(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::ValueParameterContext* PascalSParser::valueParameter() {
  ValueParameterContext *_localctx = _tracker.createInstance<ValueParameterContext>(_ctx, getState());
  enterRule(_localctx, 46, PascalSParser::RuleValueParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    identifierList(0);
    setState(292);
    match(PascalSParser::COLON);
    setState(293);
    standardType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

PascalSParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::CompoundStatementContext::BEGIN() {
  return getToken(PascalSParser::BEGIN, 0);
}

PascalSParser::StatementListContext* PascalSParser::CompoundStatementContext::statementList() {
  return getRuleContext<PascalSParser::StatementListContext>(0);
}

tree::TerminalNode* PascalSParser::CompoundStatementContext::END() {
  return getToken(PascalSParser::END, 0);
}


size_t PascalSParser::CompoundStatementContext::getRuleIndex() const {
  return PascalSParser::RuleCompoundStatement;
}


std::any PascalSParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::CompoundStatementContext* PascalSParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 48, PascalSParser::RuleCompoundStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    match(PascalSParser::BEGIN);
    setState(296);
    statementList(0);
    setState(297);
    match(PascalSParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

PascalSParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::StatementContext* PascalSParser::StatementListContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}

PascalSParser::StatementListContext* PascalSParser::StatementListContext::statementList() {
  return getRuleContext<PascalSParser::StatementListContext>(0);
}

tree::TerminalNode* PascalSParser::StatementListContext::SEMICOLON() {
  return getToken(PascalSParser::SEMICOLON, 0);
}


size_t PascalSParser::StatementListContext::getRuleIndex() const {
  return PascalSParser::RuleStatementList;
}


std::any PascalSParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::StatementListContext* PascalSParser::statementList() {
   return statementList(0);
}

PascalSParser::StatementListContext* PascalSParser::statementList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, parentState);
  PascalSParser::StatementListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, PascalSParser::RuleStatementList, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(300);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(307);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStatementList);
        setState(302);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(303);
        match(PascalSParser::SEMICOLON);
        setState(304);
        statement(); 
      }
      setState(309);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

PascalSParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalSParser::StatementContext::getRuleIndex() const {
  return PascalSParser::RuleStatement;
}

void PascalSParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WhileStatementContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::WhileStatementContext::WHILE() {
  return getToken(PascalSParser::WHILE, 0);
}

PascalSParser::ExpressionContext* PascalSParser::WhileStatementContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalSParser::WhileStatementContext::DO() {
  return getToken(PascalSParser::DO, 0);
}

PascalSParser::StatementContext* PascalSParser::WhileStatementContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}

PascalSParser::WhileStatementContext::WhileStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any PascalSParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EmptyStatementContext ------------------------------------------------------------------

PascalSParser::EmptyStatementContext::EmptyStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any PascalSParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RepeatStatementContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::RepeatStatementContext::REPEAT() {
  return getToken(PascalSParser::REPEAT, 0);
}

PascalSParser::StatementListContext* PascalSParser::RepeatStatementContext::statementList() {
  return getRuleContext<PascalSParser::StatementListContext>(0);
}

tree::TerminalNode* PascalSParser::RepeatStatementContext::UNTIL() {
  return getToken(PascalSParser::UNTIL, 0);
}

PascalSParser::ExpressionContext* PascalSParser::RepeatStatementContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

PascalSParser::RepeatStatementContext::RepeatStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any PascalSParser::RepeatStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitRepeatStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CaseStatementContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::CaseStatementContext::CASE() {
  return getToken(PascalSParser::CASE, 0);
}

PascalSParser::ExpressionContext* PascalSParser::CaseStatementContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalSParser::CaseStatementContext::OF() {
  return getToken(PascalSParser::OF, 0);
}

PascalSParser::CaseBodyContext* PascalSParser::CaseStatementContext::caseBody() {
  return getRuleContext<PascalSParser::CaseBodyContext>(0);
}

tree::TerminalNode* PascalSParser::CaseStatementContext::END() {
  return getToken(PascalSParser::END, 0);
}

PascalSParser::CaseStatementContext::CaseStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any PascalSParser::CaseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitCaseStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentStatementContext ------------------------------------------------------------------

PascalSParser::VariableContext* PascalSParser::AssignmentStatementContext::variable() {
  return getRuleContext<PascalSParser::VariableContext>(0);
}

tree::TerminalNode* PascalSParser::AssignmentStatementContext::ASSIGNOP() {
  return getToken(PascalSParser::ASSIGNOP, 0);
}

PascalSParser::ExpressionContext* PascalSParser::AssignmentStatementContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

PascalSParser::AssignmentStatementContext::AssignmentStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any PascalSParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementCallProcedureStatementContext ------------------------------------------------------------------

PascalSParser::CallProcedureStatementContext* PascalSParser::StatementCallProcedureStatementContext::callProcedureStatement() {
  return getRuleContext<PascalSParser::CallProcedureStatementContext>(0);
}

PascalSParser::StatementCallProcedureStatementContext::StatementCallProcedureStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any PascalSParser::StatementCallProcedureStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitStatementCallProcedureStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForStatementContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::ForStatementContext::FOR() {
  return getToken(PascalSParser::FOR, 0);
}

tree::TerminalNode* PascalSParser::ForStatementContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

tree::TerminalNode* PascalSParser::ForStatementContext::ASSIGNOP() {
  return getToken(PascalSParser::ASSIGNOP, 0);
}

std::vector<PascalSParser::ExpressionContext *> PascalSParser::ForStatementContext::expression() {
  return getRuleContexts<PascalSParser::ExpressionContext>();
}

PascalSParser::ExpressionContext* PascalSParser::ForStatementContext::expression(size_t i) {
  return getRuleContext<PascalSParser::ExpressionContext>(i);
}

PascalSParser::UpdownContext* PascalSParser::ForStatementContext::updown() {
  return getRuleContext<PascalSParser::UpdownContext>(0);
}

tree::TerminalNode* PascalSParser::ForStatementContext::DO() {
  return getToken(PascalSParser::DO, 0);
}

PascalSParser::StatementContext* PascalSParser::ForStatementContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}

PascalSParser::ForStatementContext::ForStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any PascalSParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStatementContext ------------------------------------------------------------------

tree::TerminalNode* PascalSParser::IfStatementContext::IF() {
  return getToken(PascalSParser::IF, 0);
}

PascalSParser::ExpressionContext* PascalSParser::IfStatementContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalSParser::IfStatementContext::THEN() {
  return getToken(PascalSParser::THEN, 0);
}

PascalSParser::StatementContext* PascalSParser::IfStatementContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}

PascalSParser::ElsePartContext* PascalSParser::IfStatementContext::elsePart() {
  return getRuleContext<PascalSParser::ElsePartContext>(0);
}

PascalSParser::IfStatementContext::IfStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any PascalSParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementCompoundStatementContext ------------------------------------------------------------------

PascalSParser::CompoundStatementContext* PascalSParser::StatementCompoundStatementContext::compoundStatement() {
  return getRuleContext<PascalSParser::CompoundStatementContext>(0);
}

PascalSParser::StatementCompoundStatementContext::StatementCompoundStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any PascalSParser::StatementCompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitStatementCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}
PascalSParser::StatementContext* PascalSParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 52, PascalSParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(348);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PascalSParser::AssignmentStatementContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(310);
      variable();
      setState(311);
      match(PascalSParser::ASSIGNOP);
      setState(312);
      expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PascalSParser::StatementCallProcedureStatementContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(314);
      callProcedureStatement();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<PascalSParser::StatementCompoundStatementContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(315);
      compoundStatement();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<PascalSParser::IfStatementContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(316);
      match(PascalSParser::IF);
      setState(317);
      expression();
      setState(318);
      match(PascalSParser::THEN);
      setState(319);
      statement();
      setState(320);
      elsePart();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<PascalSParser::CaseStatementContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(322);
      match(PascalSParser::CASE);
      setState(323);
      expression();
      setState(324);
      match(PascalSParser::OF);
      setState(325);
      caseBody();
      setState(326);
      match(PascalSParser::END);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<PascalSParser::WhileStatementContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(328);
      match(PascalSParser::WHILE);
      setState(329);
      expression();
      setState(330);
      match(PascalSParser::DO);
      setState(331);
      statement();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<PascalSParser::RepeatStatementContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(333);
      match(PascalSParser::REPEAT);
      setState(334);
      statementList(0);
      setState(335);
      match(PascalSParser::UNTIL);
      setState(336);
      expression();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<PascalSParser::ForStatementContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(338);
      match(PascalSParser::FOR);
      setState(339);
      match(PascalSParser::ID);
      setState(340);
      match(PascalSParser::ASSIGNOP);
      setState(341);
      expression();
      setState(342);
      updown();
      setState(343);
      expression();
      setState(344);
      match(PascalSParser::DO);
      setState(345);
      statement();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<PascalSParser::EmptyStatementContext>(_localctx);
      enterOuterAlt(_localctx, 9);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

PascalSParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::VariableContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

PascalSParser::IdVarpartsContext* PascalSParser::VariableContext::idVarparts() {
  return getRuleContext<PascalSParser::IdVarpartsContext>(0);
}


size_t PascalSParser::VariableContext::getRuleIndex() const {
  return PascalSParser::RuleVariable;
}


std::any PascalSParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::VariableContext* PascalSParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 54, PascalSParser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    match(PascalSParser::ID);
    setState(351);
    idVarparts(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdVarpartsContext ------------------------------------------------------------------

PascalSParser::IdVarpartsContext::IdVarpartsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::IdVarpartsContext* PascalSParser::IdVarpartsContext::idVarparts() {
  return getRuleContext<PascalSParser::IdVarpartsContext>(0);
}

PascalSParser::IdVarpartContext* PascalSParser::IdVarpartsContext::idVarpart() {
  return getRuleContext<PascalSParser::IdVarpartContext>(0);
}


size_t PascalSParser::IdVarpartsContext::getRuleIndex() const {
  return PascalSParser::RuleIdVarparts;
}


std::any PascalSParser::IdVarpartsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitIdVarparts(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::IdVarpartsContext* PascalSParser::idVarparts() {
   return idVarparts(0);
}

PascalSParser::IdVarpartsContext* PascalSParser::idVarparts(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::IdVarpartsContext *_localctx = _tracker.createInstance<IdVarpartsContext>(_ctx, parentState);
  PascalSParser::IdVarpartsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, PascalSParser::RuleIdVarparts, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _ctx->stop = _input->LT(-1);
    setState(358);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IdVarpartsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIdVarparts);
        setState(354);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(355);
        idVarpart(); 
      }
      setState(360);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IdVarpartContext ------------------------------------------------------------------

PascalSParser::IdVarpartContext::IdVarpartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::IdVarpartContext::LBRACKET() {
  return getToken(PascalSParser::LBRACKET, 0);
}

PascalSParser::ExpressionListContext* PascalSParser::IdVarpartContext::expressionList() {
  return getRuleContext<PascalSParser::ExpressionListContext>(0);
}

tree::TerminalNode* PascalSParser::IdVarpartContext::RBRACKET() {
  return getToken(PascalSParser::RBRACKET, 0);
}

tree::TerminalNode* PascalSParser::IdVarpartContext::DOT() {
  return getToken(PascalSParser::DOT, 0);
}

tree::TerminalNode* PascalSParser::IdVarpartContext::ID() {
  return getToken(PascalSParser::ID, 0);
}


size_t PascalSParser::IdVarpartContext::getRuleIndex() const {
  return PascalSParser::RuleIdVarpart;
}


std::any PascalSParser::IdVarpartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitIdVarpart(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::IdVarpartContext* PascalSParser::idVarpart() {
  IdVarpartContext *_localctx = _tracker.createInstance<IdVarpartContext>(_ctx, getState());
  enterRule(_localctx, 58, PascalSParser::RuleIdVarpart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(367);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::LBRACKET: {
        enterOuterAlt(_localctx, 1);
        setState(361);
        match(PascalSParser::LBRACKET);
        setState(362);
        expressionList(0);
        setState(363);
        match(PascalSParser::RBRACKET);
        break;
      }

      case PascalSParser::DOT: {
        enterOuterAlt(_localctx, 2);
        setState(365);
        match(PascalSParser::DOT);
        setState(366);
        match(PascalSParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElsePartContext ------------------------------------------------------------------

PascalSParser::ElsePartContext::ElsePartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::ElsePartContext::ELSE() {
  return getToken(PascalSParser::ELSE, 0);
}

PascalSParser::StatementContext* PascalSParser::ElsePartContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}


size_t PascalSParser::ElsePartContext::getRuleIndex() const {
  return PascalSParser::RuleElsePart;
}


std::any PascalSParser::ElsePartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitElsePart(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::ElsePartContext* PascalSParser::elsePart() {
  ElsePartContext *_localctx = _tracker.createInstance<ElsePartContext>(_ctx, getState());
  enterRule(_localctx, 60, PascalSParser::RuleElsePart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(372);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(369);
      match(PascalSParser::ELSE);
      setState(370);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseBodyContext ------------------------------------------------------------------

PascalSParser::CaseBodyContext::CaseBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::BranchListContext* PascalSParser::CaseBodyContext::branchList() {
  return getRuleContext<PascalSParser::BranchListContext>(0);
}


size_t PascalSParser::CaseBodyContext::getRuleIndex() const {
  return PascalSParser::RuleCaseBody;
}


std::any PascalSParser::CaseBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitCaseBody(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::CaseBodyContext* PascalSParser::caseBody() {
  CaseBodyContext *_localctx = _tracker.createInstance<CaseBodyContext>(_ctx, getState());
  enterRule(_localctx, 62, PascalSParser::RuleCaseBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(376);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::CHARLITERAL:
      case PascalSParser::ID:
      case PascalSParser::NUM:
      case PascalSParser::PLUS:
      case PascalSParser::MINUS: {
        enterOuterAlt(_localctx, 1);
        setState(374);
        branchList(0);
        break;
      }

      case PascalSParser::END: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BranchListContext ------------------------------------------------------------------

PascalSParser::BranchListContext::BranchListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::BranchContext* PascalSParser::BranchListContext::branch() {
  return getRuleContext<PascalSParser::BranchContext>(0);
}

PascalSParser::BranchListContext* PascalSParser::BranchListContext::branchList() {
  return getRuleContext<PascalSParser::BranchListContext>(0);
}

tree::TerminalNode* PascalSParser::BranchListContext::SEMICOLON() {
  return getToken(PascalSParser::SEMICOLON, 0);
}


size_t PascalSParser::BranchListContext::getRuleIndex() const {
  return PascalSParser::RuleBranchList;
}


std::any PascalSParser::BranchListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitBranchList(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::BranchListContext* PascalSParser::branchList() {
   return branchList(0);
}

PascalSParser::BranchListContext* PascalSParser::branchList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::BranchListContext *_localctx = _tracker.createInstance<BranchListContext>(_ctx, parentState);
  PascalSParser::BranchListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, PascalSParser::RuleBranchList, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(379);
    branch();
    _ctx->stop = _input->LT(-1);
    setState(386);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BranchListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBranchList);
        setState(381);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(382);
        match(PascalSParser::SEMICOLON);
        setState(383);
        branch(); 
      }
      setState(388);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BranchContext ------------------------------------------------------------------

PascalSParser::BranchContext::BranchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::ConstListContext* PascalSParser::BranchContext::constList() {
  return getRuleContext<PascalSParser::ConstListContext>(0);
}

tree::TerminalNode* PascalSParser::BranchContext::COLON() {
  return getToken(PascalSParser::COLON, 0);
}

PascalSParser::StatementContext* PascalSParser::BranchContext::statement() {
  return getRuleContext<PascalSParser::StatementContext>(0);
}


size_t PascalSParser::BranchContext::getRuleIndex() const {
  return PascalSParser::RuleBranch;
}


std::any PascalSParser::BranchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitBranch(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::BranchContext* PascalSParser::branch() {
  BranchContext *_localctx = _tracker.createInstance<BranchContext>(_ctx, getState());
  enterRule(_localctx, 66, PascalSParser::RuleBranch);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(389);
    constList(0);
    setState(390);
    match(PascalSParser::COLON);
    setState(391);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstListContext ------------------------------------------------------------------

PascalSParser::ConstListContext::ConstListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::ConstVariableContext* PascalSParser::ConstListContext::constVariable() {
  return getRuleContext<PascalSParser::ConstVariableContext>(0);
}

PascalSParser::ConstListContext* PascalSParser::ConstListContext::constList() {
  return getRuleContext<PascalSParser::ConstListContext>(0);
}

tree::TerminalNode* PascalSParser::ConstListContext::COMMA() {
  return getToken(PascalSParser::COMMA, 0);
}


size_t PascalSParser::ConstListContext::getRuleIndex() const {
  return PascalSParser::RuleConstList;
}


std::any PascalSParser::ConstListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitConstList(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::ConstListContext* PascalSParser::constList() {
   return constList(0);
}

PascalSParser::ConstListContext* PascalSParser::constList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::ConstListContext *_localctx = _tracker.createInstance<ConstListContext>(_ctx, parentState);
  PascalSParser::ConstListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, PascalSParser::RuleConstList, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(394);
    constVariable();
    _ctx->stop = _input->LT(-1);
    setState(401);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ConstListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleConstList);
        setState(396);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(397);
        match(PascalSParser::COMMA);
        setState(398);
        constVariable(); 
      }
      setState(403);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UpdownContext ------------------------------------------------------------------

PascalSParser::UpdownContext::UpdownContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::UpdownContext::TO() {
  return getToken(PascalSParser::TO, 0);
}

tree::TerminalNode* PascalSParser::UpdownContext::DOWNTO() {
  return getToken(PascalSParser::DOWNTO, 0);
}


size_t PascalSParser::UpdownContext::getRuleIndex() const {
  return PascalSParser::RuleUpdown;
}


std::any PascalSParser::UpdownContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitUpdown(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::UpdownContext* PascalSParser::updown() {
  UpdownContext *_localctx = _tracker.createInstance<UpdownContext>(_ctx, getState());
  enterRule(_localctx, 70, PascalSParser::RuleUpdown);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(404);
    _la = _input->LA(1);
    if (!(_la == PascalSParser::DOWNTO

    || _la == PascalSParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallProcedureStatementContext ------------------------------------------------------------------

PascalSParser::CallProcedureStatementContext::CallProcedureStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::CallProcedureStatementContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

tree::TerminalNode* PascalSParser::CallProcedureStatementContext::LPAREN() {
  return getToken(PascalSParser::LPAREN, 0);
}

PascalSParser::ExpressionListContext* PascalSParser::CallProcedureStatementContext::expressionList() {
  return getRuleContext<PascalSParser::ExpressionListContext>(0);
}

tree::TerminalNode* PascalSParser::CallProcedureStatementContext::RPAREN() {
  return getToken(PascalSParser::RPAREN, 0);
}


size_t PascalSParser::CallProcedureStatementContext::getRuleIndex() const {
  return PascalSParser::RuleCallProcedureStatement;
}


std::any PascalSParser::CallProcedureStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitCallProcedureStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::CallProcedureStatementContext* PascalSParser::callProcedureStatement() {
  CallProcedureStatementContext *_localctx = _tracker.createInstance<CallProcedureStatementContext>(_ctx, getState());
  enterRule(_localctx, 72, PascalSParser::RuleCallProcedureStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(406);
    match(PascalSParser::ID);
    setState(411);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(407);
      match(PascalSParser::LPAREN);
      setState(408);
      expressionList(0);
      setState(409);
      match(PascalSParser::RPAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionListContext ------------------------------------------------------------------

PascalSParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::ExpressionContext* PascalSParser::ExpressionListContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

PascalSParser::ExpressionListContext* PascalSParser::ExpressionListContext::expressionList() {
  return getRuleContext<PascalSParser::ExpressionListContext>(0);
}

tree::TerminalNode* PascalSParser::ExpressionListContext::COMMA() {
  return getToken(PascalSParser::COMMA, 0);
}


size_t PascalSParser::ExpressionListContext::getRuleIndex() const {
  return PascalSParser::RuleExpressionList;
}


std::any PascalSParser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::ExpressionListContext* PascalSParser::expressionList() {
   return expressionList(0);
}

PascalSParser::ExpressionListContext* PascalSParser::expressionList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, parentState);
  PascalSParser::ExpressionListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 74;
  enterRecursionRule(_localctx, 74, PascalSParser::RuleExpressionList, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(414);
    expression();
    _ctx->stop = _input->LT(-1);
    setState(421);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpressionList);
        setState(416);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(417);
        match(PascalSParser::COMMA);
        setState(418);
        expression(); 
      }
      setState(423);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

PascalSParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalSParser::SimpleExpressionContext *> PascalSParser::ExpressionContext::simpleExpression() {
  return getRuleContexts<PascalSParser::SimpleExpressionContext>();
}

PascalSParser::SimpleExpressionContext* PascalSParser::ExpressionContext::simpleExpression(size_t i) {
  return getRuleContext<PascalSParser::SimpleExpressionContext>(i);
}

PascalSParser::RelationalOpreatorContext* PascalSParser::ExpressionContext::relationalOpreator() {
  return getRuleContext<PascalSParser::RelationalOpreatorContext>(0);
}


size_t PascalSParser::ExpressionContext::getRuleIndex() const {
  return PascalSParser::RuleExpression;
}


std::any PascalSParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::ExpressionContext* PascalSParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 76, PascalSParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(429);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(424);
      simpleExpression(0);
      setState(425);
      relationalOpreator();
      setState(426);
      simpleExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(428);
      simpleExpression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleExpressionContext ------------------------------------------------------------------

PascalSParser::SimpleExpressionContext::SimpleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::TermContext* PascalSParser::SimpleExpressionContext::term() {
  return getRuleContext<PascalSParser::TermContext>(0);
}

tree::TerminalNode* PascalSParser::SimpleExpressionContext::PLUS() {
  return getToken(PascalSParser::PLUS, 0);
}

tree::TerminalNode* PascalSParser::SimpleExpressionContext::MINUS() {
  return getToken(PascalSParser::MINUS, 0);
}

PascalSParser::SimpleExpressionContext* PascalSParser::SimpleExpressionContext::simpleExpression() {
  return getRuleContext<PascalSParser::SimpleExpressionContext>(0);
}

PascalSParser::AddOperatorContext* PascalSParser::SimpleExpressionContext::addOperator() {
  return getRuleContext<PascalSParser::AddOperatorContext>(0);
}


size_t PascalSParser::SimpleExpressionContext::getRuleIndex() const {
  return PascalSParser::RuleSimpleExpression;
}


std::any PascalSParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::SimpleExpressionContext* PascalSParser::simpleExpression() {
   return simpleExpression(0);
}

PascalSParser::SimpleExpressionContext* PascalSParser::simpleExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, parentState);
  PascalSParser::SimpleExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 78;
  enterRecursionRule(_localctx, 78, PascalSParser::RuleSimpleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(437);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalSParser::NOT:
      case PascalSParser::FALSE:
      case PascalSParser::TRUE:
      case PascalSParser::CHARLITERAL:
      case PascalSParser::ID:
      case PascalSParser::NUM:
      case PascalSParser::LPAREN: {
        setState(432);
        term(0);
        break;
      }

      case PascalSParser::PLUS: {
        setState(433);
        match(PascalSParser::PLUS);
        setState(434);
        term(0);
        break;
      }

      case PascalSParser::MINUS: {
        setState(435);
        match(PascalSParser::MINUS);
        setState(436);
        term(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(445);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<SimpleExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleSimpleExpression);
        setState(439);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(440);
        addOperator();
        setState(441);
        term(0); 
      }
      setState(447);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

PascalSParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::FactorContext* PascalSParser::TermContext::factor() {
  return getRuleContext<PascalSParser::FactorContext>(0);
}

PascalSParser::TermContext* PascalSParser::TermContext::term() {
  return getRuleContext<PascalSParser::TermContext>(0);
}

PascalSParser::MultiplyOperatorContext* PascalSParser::TermContext::multiplyOperator() {
  return getRuleContext<PascalSParser::MultiplyOperatorContext>(0);
}


size_t PascalSParser::TermContext::getRuleIndex() const {
  return PascalSParser::RuleTerm;
}


std::any PascalSParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}


PascalSParser::TermContext* PascalSParser::term() {
   return term(0);
}

PascalSParser::TermContext* PascalSParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PascalSParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  PascalSParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 80;
  enterRecursionRule(_localctx, 80, PascalSParser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(449);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(457);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(451);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(452);
        multiplyOperator();
        setState(453);
        factor(); 
      }
      setState(459);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BooleanContext ------------------------------------------------------------------

PascalSParser::BooleanContext::BooleanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::BooleanContext::TRUE() {
  return getToken(PascalSParser::TRUE, 0);
}

tree::TerminalNode* PascalSParser::BooleanContext::FALSE() {
  return getToken(PascalSParser::FALSE, 0);
}


size_t PascalSParser::BooleanContext::getRuleIndex() const {
  return PascalSParser::RuleBoolean;
}


std::any PascalSParser::BooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitBoolean(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::BooleanContext* PascalSParser::boolean() {
  BooleanContext *_localctx = _tracker.createInstance<BooleanContext>(_ctx, getState());
  enterRule(_localctx, 82, PascalSParser::RuleBoolean);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    _la = _input->LA(1);
    if (!(_la == PascalSParser::FALSE

    || _la == PascalSParser::TRUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

PascalSParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalSParser::UnsignConstVariableContext* PascalSParser::FactorContext::unsignConstVariable() {
  return getRuleContext<PascalSParser::UnsignConstVariableContext>(0);
}

PascalSParser::VariableContext* PascalSParser::FactorContext::variable() {
  return getRuleContext<PascalSParser::VariableContext>(0);
}

tree::TerminalNode* PascalSParser::FactorContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

tree::TerminalNode* PascalSParser::FactorContext::LPAREN() {
  return getToken(PascalSParser::LPAREN, 0);
}

PascalSParser::ExpressionListContext* PascalSParser::FactorContext::expressionList() {
  return getRuleContext<PascalSParser::ExpressionListContext>(0);
}

tree::TerminalNode* PascalSParser::FactorContext::RPAREN() {
  return getToken(PascalSParser::RPAREN, 0);
}

PascalSParser::ExpressionContext* PascalSParser::FactorContext::expression() {
  return getRuleContext<PascalSParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalSParser::FactorContext::NOT() {
  return getToken(PascalSParser::NOT, 0);
}

PascalSParser::FactorContext* PascalSParser::FactorContext::factor() {
  return getRuleContext<PascalSParser::FactorContext>(0);
}

PascalSParser::BooleanContext* PascalSParser::FactorContext::boolean() {
  return getRuleContext<PascalSParser::BooleanContext>(0);
}


size_t PascalSParser::FactorContext::getRuleIndex() const {
  return PascalSParser::RuleFactor;
}


std::any PascalSParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::FactorContext* PascalSParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 84, PascalSParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(479);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(462);
      unsignConstVariable();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(463);
      variable();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(464);
      match(PascalSParser::ID);
      setState(465);
      match(PascalSParser::LPAREN);
      setState(466);
      expressionList(0);
      setState(467);
      match(PascalSParser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(469);
      match(PascalSParser::ID);
      setState(470);
      match(PascalSParser::LPAREN);
      setState(471);
      match(PascalSParser::RPAREN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(472);
      match(PascalSParser::LPAREN);
      setState(473);
      expression();
      setState(474);
      match(PascalSParser::RPAREN);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(476);
      match(PascalSParser::NOT);
      setState(477);
      factor();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(478);
      boolean();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignConstVariableContext ------------------------------------------------------------------

PascalSParser::UnsignConstVariableContext::UnsignConstVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::UnsignConstVariableContext::ID() {
  return getToken(PascalSParser::ID, 0);
}

tree::TerminalNode* PascalSParser::UnsignConstVariableContext::NUM() {
  return getToken(PascalSParser::NUM, 0);
}

tree::TerminalNode* PascalSParser::UnsignConstVariableContext::CHARLITERAL() {
  return getToken(PascalSParser::CHARLITERAL, 0);
}


size_t PascalSParser::UnsignConstVariableContext::getRuleIndex() const {
  return PascalSParser::RuleUnsignConstVariable;
}


std::any PascalSParser::UnsignConstVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitUnsignConstVariable(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::UnsignConstVariableContext* PascalSParser::unsignConstVariable() {
  UnsignConstVariableContext *_localctx = _tracker.createInstance<UnsignConstVariableContext>(_ctx, getState());
  enterRule(_localctx, 86, PascalSParser::RuleUnsignConstVariable);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(481);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 188978561024) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationalOpreatorContext ------------------------------------------------------------------

PascalSParser::RelationalOpreatorContext::RelationalOpreatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::RelationalOpreatorContext::EQUAL() {
  return getToken(PascalSParser::EQUAL, 0);
}

tree::TerminalNode* PascalSParser::RelationalOpreatorContext::NEQUAL() {
  return getToken(PascalSParser::NEQUAL, 0);
}

tree::TerminalNode* PascalSParser::RelationalOpreatorContext::LT() {
  return getToken(PascalSParser::LT, 0);
}

tree::TerminalNode* PascalSParser::RelationalOpreatorContext::LE() {
  return getToken(PascalSParser::LE, 0);
}

tree::TerminalNode* PascalSParser::RelationalOpreatorContext::GT() {
  return getToken(PascalSParser::GT, 0);
}

tree::TerminalNode* PascalSParser::RelationalOpreatorContext::GE() {
  return getToken(PascalSParser::GE, 0);
}


size_t PascalSParser::RelationalOpreatorContext::getRuleIndex() const {
  return PascalSParser::RuleRelationalOpreator;
}


std::any PascalSParser::RelationalOpreatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitRelationalOpreator(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::RelationalOpreatorContext* PascalSParser::relationalOpreator() {
  RelationalOpreatorContext *_localctx = _tracker.createInstance<RelationalOpreatorContext>(_ctx, getState());
  enterRule(_localctx, 88, PascalSParser::RuleRelationalOpreator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(483);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 277076930199552) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddOperatorContext ------------------------------------------------------------------

PascalSParser::AddOperatorContext::AddOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::AddOperatorContext::PLUS() {
  return getToken(PascalSParser::PLUS, 0);
}

tree::TerminalNode* PascalSParser::AddOperatorContext::MINUS() {
  return getToken(PascalSParser::MINUS, 0);
}

tree::TerminalNode* PascalSParser::AddOperatorContext::OR() {
  return getToken(PascalSParser::OR, 0);
}


size_t PascalSParser::AddOperatorContext::getRuleIndex() const {
  return PascalSParser::RuleAddOperator;
}


std::any PascalSParser::AddOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitAddOperator(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::AddOperatorContext* PascalSParser::addOperator() {
  AddOperatorContext *_localctx = _tracker.createInstance<AddOperatorContext>(_ctx, getState());
  enterRule(_localctx, 90, PascalSParser::RuleAddOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(485);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 844424930131972) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplyOperatorContext ------------------------------------------------------------------

PascalSParser::MultiplyOperatorContext::MultiplyOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalSParser::MultiplyOperatorContext::MULT() {
  return getToken(PascalSParser::MULT, 0);
}

tree::TerminalNode* PascalSParser::MultiplyOperatorContext::DIVIDE() {
  return getToken(PascalSParser::DIVIDE, 0);
}

tree::TerminalNode* PascalSParser::MultiplyOperatorContext::DIV() {
  return getToken(PascalSParser::DIV, 0);
}

tree::TerminalNode* PascalSParser::MultiplyOperatorContext::MOD() {
  return getToken(PascalSParser::MOD, 0);
}

tree::TerminalNode* PascalSParser::MultiplyOperatorContext::AND() {
  return getToken(PascalSParser::AND, 0);
}


size_t PascalSParser::MultiplyOperatorContext::getRuleIndex() const {
  return PascalSParser::RuleMultiplyOperator;
}


std::any PascalSParser::MultiplyOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalSVisitor*>(visitor))
    return parserVisitor->visitMultiplyOperator(this);
  else
    return visitor->visitChildren(this);
}

PascalSParser::MultiplyOperatorContext* PascalSParser::multiplyOperator() {
  MultiplyOperatorContext *_localctx = _tracker.createInstance<MultiplyOperatorContext>(_ctx, getState());
  enterRule(_localctx, 92, PascalSParser::RuleMultiplyOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(487);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3377699722629122) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool PascalSParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return identifierListSempred(antlrcpp::downCast<IdentifierListContext *>(context), predicateIndex);
    case 5: return constDeclarationSempred(antlrcpp::downCast<ConstDeclarationContext *>(context), predicateIndex);
    case 8: return typeDeclarationSempred(antlrcpp::downCast<TypeDeclarationContext *>(context), predicateIndex);
    case 12: return periodsSempred(antlrcpp::downCast<PeriodsContext *>(context), predicateIndex);
    case 15: return varDeclarationSempred(antlrcpp::downCast<VarDeclarationContext *>(context), predicateIndex);
    case 16: return subprogramDeclarationsSempred(antlrcpp::downCast<SubprogramDeclarationsContext *>(context), predicateIndex);
    case 20: return parameterListsSempred(antlrcpp::downCast<ParameterListsContext *>(context), predicateIndex);
    case 25: return statementListSempred(antlrcpp::downCast<StatementListContext *>(context), predicateIndex);
    case 28: return idVarpartsSempred(antlrcpp::downCast<IdVarpartsContext *>(context), predicateIndex);
    case 32: return branchListSempred(antlrcpp::downCast<BranchListContext *>(context), predicateIndex);
    case 34: return constListSempred(antlrcpp::downCast<ConstListContext *>(context), predicateIndex);
    case 37: return expressionListSempred(antlrcpp::downCast<ExpressionListContext *>(context), predicateIndex);
    case 39: return simpleExpressionSempred(antlrcpp::downCast<SimpleExpressionContext *>(context), predicateIndex);
    case 40: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool PascalSParser::identifierListSempred(IdentifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::constDeclarationSempred(ConstDeclarationContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::typeDeclarationSempred(TypeDeclarationContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::periodsSempred(PeriodsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::varDeclarationSempred(VarDeclarationContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::subprogramDeclarationsSempred(SubprogramDeclarationsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::parameterListsSempred(ParameterListsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::statementListSempred(StatementListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::idVarpartsSempred(IdVarpartsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::branchListSempred(BranchListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::constListSempred(ConstListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::expressionListSempred(ExpressionListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PascalSParser::simpleExpressionSempred(SimpleExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool PascalSParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 13: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void PascalSParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  pascalsParserInitialize();
#else
  ::antlr4::internal::call_once(pascalsParserOnceFlag, pascalsParserInitialize);
#endif
}
