
// Generated from ./micro-benchmarks/mathexpr/cpp-build/g_mathexpr.g4 by ANTLR 4.13.1


#include "g_mathexprLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct G_mathexprLexerStaticData final {
  G_mathexprLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  G_mathexprLexerStaticData(const G_mathexprLexerStaticData&) = delete;
  G_mathexprLexerStaticData(G_mathexprLexerStaticData&&) = delete;
  G_mathexprLexerStaticData& operator=(const G_mathexprLexerStaticData&) = delete;
  G_mathexprLexerStaticData& operator=(G_mathexprLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag g_mathexprlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
G_mathexprLexerStaticData *g_mathexprlexerLexerStaticData = nullptr;

void g_mathexprlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (g_mathexprlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(g_mathexprlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<G_mathexprLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "FUNC", "CONSTANT", 
      "VAR", "FLOAT", "INTEGER", "SPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'('", "')'", "','", "'+'", "'-'", "'*'", "'/'", "", "", "", "", 
      "", "' '"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "FUNC", "CONSTANT", "VAR", "FLOAT", 
      "INTEGER", "SPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,13,207,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,1,0,1,0,1,1,1,
  	1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,151,8,7,
  	1,8,1,8,1,8,1,8,1,8,1,8,3,8,159,8,8,1,9,4,9,162,8,9,11,9,12,9,163,1,9,
  	4,9,167,8,9,11,9,12,9,168,1,9,3,9,172,8,9,1,10,3,10,175,8,10,1,10,1,10,
  	1,10,5,10,180,8,10,10,10,12,10,183,9,10,3,10,185,8,10,1,10,1,10,4,10,
  	189,8,10,11,10,12,10,190,1,11,1,11,3,11,195,8,11,1,11,1,11,5,11,199,8,
  	11,10,11,12,11,202,9,11,3,11,204,8,11,1,12,1,12,0,0,13,1,1,3,2,5,3,7,
  	4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,1,0,1,3,0,48,57,95,
  	95,97,122,243,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,
  	0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,
  	0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,1,27,1,0,0,0,3,29,1,0,0,0,5,31,
  	1,0,0,0,7,33,1,0,0,0,9,35,1,0,0,0,11,37,1,0,0,0,13,39,1,0,0,0,15,150,
  	1,0,0,0,17,158,1,0,0,0,19,161,1,0,0,0,21,174,1,0,0,0,23,203,1,0,0,0,25,
  	205,1,0,0,0,27,28,5,40,0,0,28,2,1,0,0,0,29,30,5,41,0,0,30,4,1,0,0,0,31,
  	32,5,44,0,0,32,6,1,0,0,0,33,34,5,43,0,0,34,8,1,0,0,0,35,36,5,45,0,0,36,
  	10,1,0,0,0,37,38,5,42,0,0,38,12,1,0,0,0,39,40,5,47,0,0,40,14,1,0,0,0,
  	41,42,5,97,0,0,42,43,5,98,0,0,43,151,5,115,0,0,44,45,5,97,0,0,45,46,5,
  	99,0,0,46,47,5,111,0,0,47,151,5,115,0,0,48,49,5,97,0,0,49,50,5,115,0,
  	0,50,51,5,105,0,0,51,151,5,110,0,0,52,53,5,97,0,0,53,54,5,116,0,0,54,
  	55,5,97,0,0,55,56,5,110,0,0,56,151,5,50,0,0,57,58,5,97,0,0,58,59,5,116,
  	0,0,59,60,5,97,0,0,60,151,5,110,0,0,61,62,5,99,0,0,62,63,5,101,0,0,63,
  	64,5,105,0,0,64,151,5,108,0,0,65,66,5,99,0,0,66,67,5,111,0,0,67,68,5,
  	115,0,0,68,151,5,104,0,0,69,70,5,99,0,0,70,71,5,111,0,0,71,151,5,115,
  	0,0,72,73,5,100,0,0,73,74,5,101,0,0,74,75,5,103,0,0,75,76,5,114,0,0,76,
  	77,5,101,0,0,77,78,5,101,0,0,78,151,5,115,0,0,79,80,5,101,0,0,80,81,5,
  	120,0,0,81,151,5,112,0,0,82,83,5,102,0,0,83,84,5,97,0,0,84,85,5,98,0,
  	0,85,151,5,115,0,0,86,87,5,102,0,0,87,88,5,108,0,0,88,89,5,111,0,0,89,
  	90,5,111,0,0,90,151,5,114,0,0,91,92,5,102,0,0,92,93,5,109,0,0,93,94,5,
  	111,0,0,94,151,5,100,0,0,95,96,5,102,0,0,96,97,5,114,0,0,97,98,5,101,
  	0,0,98,99,5,120,0,0,99,151,5,112,0,0,100,101,5,104,0,0,101,102,5,121,
  	0,0,102,103,5,112,0,0,103,104,5,111,0,0,104,151,5,116,0,0,105,106,5,108,
  	0,0,106,107,5,100,0,0,107,108,5,101,0,0,108,109,5,120,0,0,109,151,5,112,
  	0,0,110,111,5,108,0,0,111,112,5,111,0,0,112,113,5,103,0,0,113,114,5,49,
  	0,0,114,151,5,48,0,0,115,116,5,108,0,0,116,117,5,111,0,0,117,151,5,103,
  	0,0,118,119,5,109,0,0,119,120,5,111,0,0,120,121,5,100,0,0,121,151,5,102,
  	0,0,122,123,5,112,0,0,123,124,5,111,0,0,124,151,5,119,0,0,125,126,5,114,
  	0,0,126,127,5,97,0,0,127,128,5,100,0,0,128,129,5,105,0,0,129,130,5,97,
  	0,0,130,131,5,110,0,0,131,151,5,115,0,0,132,133,5,115,0,0,133,134,5,105,
  	0,0,134,135,5,110,0,0,135,151,5,104,0,0,136,137,5,115,0,0,137,138,5,105,
  	0,0,138,151,5,110,0,0,139,140,5,115,0,0,140,141,5,113,0,0,141,142,5,114,
  	0,0,142,151,5,116,0,0,143,144,5,116,0,0,144,145,5,97,0,0,145,146,5,110,
  	0,0,146,151,5,104,0,0,147,148,5,116,0,0,148,149,5,97,0,0,149,151,5,110,
  	0,0,150,41,1,0,0,0,150,44,1,0,0,0,150,48,1,0,0,0,150,52,1,0,0,0,150,57,
  	1,0,0,0,150,61,1,0,0,0,150,65,1,0,0,0,150,69,1,0,0,0,150,72,1,0,0,0,150,
  	79,1,0,0,0,150,82,1,0,0,0,150,86,1,0,0,0,150,91,1,0,0,0,150,95,1,0,0,
  	0,150,100,1,0,0,0,150,105,1,0,0,0,150,110,1,0,0,0,150,115,1,0,0,0,150,
  	118,1,0,0,0,150,122,1,0,0,0,150,125,1,0,0,0,150,132,1,0,0,0,150,136,1,
  	0,0,0,150,139,1,0,0,0,150,143,1,0,0,0,150,147,1,0,0,0,151,16,1,0,0,0,
  	152,153,5,112,0,0,153,159,5,105,0,0,154,155,5,112,0,0,155,156,5,104,0,
  	0,156,159,5,105,0,0,157,159,5,101,0,0,158,152,1,0,0,0,158,154,1,0,0,0,
  	158,157,1,0,0,0,159,18,1,0,0,0,160,162,2,97,122,0,161,160,1,0,0,0,162,
  	163,1,0,0,0,163,161,1,0,0,0,163,164,1,0,0,0,164,171,1,0,0,0,165,167,7,
  	0,0,0,166,165,1,0,0,0,167,168,1,0,0,0,168,166,1,0,0,0,168,169,1,0,0,0,
  	169,170,1,0,0,0,170,172,2,97,122,0,171,166,1,0,0,0,171,172,1,0,0,0,172,
  	20,1,0,0,0,173,175,5,45,0,0,174,173,1,0,0,0,174,175,1,0,0,0,175,184,1,
  	0,0,0,176,185,5,48,0,0,177,181,2,49,57,0,178,180,2,48,57,0,179,178,1,
  	0,0,0,180,183,1,0,0,0,181,179,1,0,0,0,181,182,1,0,0,0,182,185,1,0,0,0,
  	183,181,1,0,0,0,184,176,1,0,0,0,184,177,1,0,0,0,185,186,1,0,0,0,186,188,
  	5,46,0,0,187,189,2,48,57,0,188,187,1,0,0,0,189,190,1,0,0,0,190,188,1,
  	0,0,0,190,191,1,0,0,0,191,22,1,0,0,0,192,204,5,48,0,0,193,195,5,45,0,
  	0,194,193,1,0,0,0,194,195,1,0,0,0,195,196,1,0,0,0,196,200,2,49,57,0,197,
  	199,2,48,57,0,198,197,1,0,0,0,199,202,1,0,0,0,200,198,1,0,0,0,200,201,
  	1,0,0,0,201,204,1,0,0,0,202,200,1,0,0,0,203,192,1,0,0,0,203,194,1,0,0,
  	0,204,24,1,0,0,0,205,206,5,32,0,0,206,26,1,0,0,0,13,0,150,158,163,168,
  	171,174,181,184,190,194,200,203,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  g_mathexprlexerLexerStaticData = staticData.release();
}

}

g_mathexprLexer::g_mathexprLexer(CharStream *input) : Lexer(input) {
  g_mathexprLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *g_mathexprlexerLexerStaticData->atn, g_mathexprlexerLexerStaticData->decisionToDFA, g_mathexprlexerLexerStaticData->sharedContextCache);
}

g_mathexprLexer::~g_mathexprLexer() {
  delete _interpreter;
}

std::string g_mathexprLexer::getGrammarFileName() const {
  return "g_mathexpr.g4";
}

const std::vector<std::string>& g_mathexprLexer::getRuleNames() const {
  return g_mathexprlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& g_mathexprLexer::getChannelNames() const {
  return g_mathexprlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& g_mathexprLexer::getModeNames() const {
  return g_mathexprlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& g_mathexprLexer::getVocabulary() const {
  return g_mathexprlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView g_mathexprLexer::getSerializedATN() const {
  return g_mathexprlexerLexerStaticData->serializedATN;
}

const atn::ATN& g_mathexprLexer::getATN() const {
  return *g_mathexprlexerLexerStaticData->atn;
}




void g_mathexprLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  g_mathexprlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(g_mathexprlexerLexerOnceFlag, g_mathexprlexerLexerInitialize);
#endif
}
