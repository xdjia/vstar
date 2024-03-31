
// Generated from ./micro-benchmarks/while/cpp-build/g_while.g4 by ANTLR 4.13.1


#include "g_whileLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct G_whileLexerStaticData final {
  G_whileLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  G_whileLexerStaticData(const G_whileLexerStaticData&) = delete;
  G_whileLexerStaticData(G_whileLexerStaticData&&) = delete;
  G_whileLexerStaticData& operator=(const G_whileLexerStaticData&) = delete;
  G_whileLexerStaticData& operator=(G_whileLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag g_whilelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
G_whileLexerStaticData *g_whilelexerLexerStaticData = nullptr;

void g_whilelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (g_whilelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(g_whilelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<G_whileLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "SPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'L'", "'='", "'if'", "'then'", "'else'", "';'", "'while'", "'do'", 
      "'skip'", "'true'", "'false'", "'=='", "'&'", "'~'", "'n'", "'('", 
      "'+'", "')'", "' '"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "SPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,19,100,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,
  	10,1,10,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,
  	15,1,16,1,16,1,17,1,17,1,18,1,18,0,0,19,1,1,3,2,5,3,7,4,9,5,11,6,13,7,
  	15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,
  	1,0,0,99,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,
  	0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,
  	1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,
  	0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,1,39,1,0,0,0,3,41,1,0,0,0,
  	5,43,1,0,0,0,7,46,1,0,0,0,9,51,1,0,0,0,11,56,1,0,0,0,13,58,1,0,0,0,15,
  	64,1,0,0,0,17,67,1,0,0,0,19,72,1,0,0,0,21,77,1,0,0,0,23,83,1,0,0,0,25,
  	86,1,0,0,0,27,88,1,0,0,0,29,90,1,0,0,0,31,92,1,0,0,0,33,94,1,0,0,0,35,
  	96,1,0,0,0,37,98,1,0,0,0,39,40,5,76,0,0,40,2,1,0,0,0,41,42,5,61,0,0,42,
  	4,1,0,0,0,43,44,5,105,0,0,44,45,5,102,0,0,45,6,1,0,0,0,46,47,5,116,0,
  	0,47,48,5,104,0,0,48,49,5,101,0,0,49,50,5,110,0,0,50,8,1,0,0,0,51,52,
  	5,101,0,0,52,53,5,108,0,0,53,54,5,115,0,0,54,55,5,101,0,0,55,10,1,0,0,
  	0,56,57,5,59,0,0,57,12,1,0,0,0,58,59,5,119,0,0,59,60,5,104,0,0,60,61,
  	5,105,0,0,61,62,5,108,0,0,62,63,5,101,0,0,63,14,1,0,0,0,64,65,5,100,0,
  	0,65,66,5,111,0,0,66,16,1,0,0,0,67,68,5,115,0,0,68,69,5,107,0,0,69,70,
  	5,105,0,0,70,71,5,112,0,0,71,18,1,0,0,0,72,73,5,116,0,0,73,74,5,114,0,
  	0,74,75,5,117,0,0,75,76,5,101,0,0,76,20,1,0,0,0,77,78,5,102,0,0,78,79,
  	5,97,0,0,79,80,5,108,0,0,80,81,5,115,0,0,81,82,5,101,0,0,82,22,1,0,0,
  	0,83,84,5,61,0,0,84,85,5,61,0,0,85,24,1,0,0,0,86,87,5,38,0,0,87,26,1,
  	0,0,0,88,89,5,126,0,0,89,28,1,0,0,0,90,91,5,110,0,0,91,30,1,0,0,0,92,
  	93,5,40,0,0,93,32,1,0,0,0,94,95,5,43,0,0,95,34,1,0,0,0,96,97,5,41,0,0,
  	97,36,1,0,0,0,98,99,5,32,0,0,99,38,1,0,0,0,1,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  g_whilelexerLexerStaticData = staticData.release();
}

}

g_whileLexer::g_whileLexer(CharStream *input) : Lexer(input) {
  g_whileLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *g_whilelexerLexerStaticData->atn, g_whilelexerLexerStaticData->decisionToDFA, g_whilelexerLexerStaticData->sharedContextCache);
}

g_whileLexer::~g_whileLexer() {
  delete _interpreter;
}

std::string g_whileLexer::getGrammarFileName() const {
  return "g_while.g4";
}

const std::vector<std::string>& g_whileLexer::getRuleNames() const {
  return g_whilelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& g_whileLexer::getChannelNames() const {
  return g_whilelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& g_whileLexer::getModeNames() const {
  return g_whilelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& g_whileLexer::getVocabulary() const {
  return g_whilelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView g_whileLexer::getSerializedATN() const {
  return g_whilelexerLexerStaticData->serializedATN;
}

const atn::ATN& g_whileLexer::getATN() const {
  return *g_whilelexerLexerStaticData->atn;
}




void g_whileLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  g_whilelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(g_whilelexerLexerOnceFlag, g_whilelexerLexerInitialize);
#endif
}
