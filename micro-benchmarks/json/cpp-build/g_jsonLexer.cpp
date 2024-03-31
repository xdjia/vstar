
// Generated from ./micro-benchmarks/json/cpp-build/g_json.g4 by ANTLR 4.13.1


#include "g_jsonLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct G_jsonLexerStaticData final {
  G_jsonLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  G_jsonLexerStaticData(const G_jsonLexerStaticData&) = delete;
  G_jsonLexerStaticData(G_jsonLexerStaticData&&) = delete;
  G_jsonLexerStaticData& operator=(const G_jsonLexerStaticData&) = delete;
  G_jsonLexerStaticData& operator=(G_jsonLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag g_jsonlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
G_jsonLexerStaticData *g_jsonlexerLexerStaticData = nullptr;

void g_jsonlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (g_jsonlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(g_jsonlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<G_jsonLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "NUMBER", "STRING", "QUOTE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'true'", "'false'", "'null'", "'['", "']'", "','", "'{'", "'}'", 
      "':'", "", "", "'\\u0022'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "NUMBER", "STRING", "QUOTE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,12,84,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,1,0,1,0,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,
  	6,1,7,1,7,1,8,1,8,1,9,1,9,3,9,56,8,9,1,9,1,9,5,9,60,8,9,10,9,12,9,63,
  	9,9,3,9,65,8,9,1,9,1,9,4,9,69,8,9,11,9,12,9,70,3,9,73,8,9,1,10,1,10,4,
  	10,77,8,10,11,10,12,10,78,1,10,1,10,1,11,1,11,0,0,12,1,1,3,2,5,3,7,4,
  	9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,1,0,1,3,0,48,57,65,90,97,122,
  	89,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,
  	0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,
  	0,0,23,1,0,0,0,1,25,1,0,0,0,3,30,1,0,0,0,5,36,1,0,0,0,7,41,1,0,0,0,9,
  	43,1,0,0,0,11,45,1,0,0,0,13,47,1,0,0,0,15,49,1,0,0,0,17,51,1,0,0,0,19,
  	64,1,0,0,0,21,74,1,0,0,0,23,82,1,0,0,0,25,26,5,116,0,0,26,27,5,114,0,
  	0,27,28,5,117,0,0,28,29,5,101,0,0,29,2,1,0,0,0,30,31,5,102,0,0,31,32,
  	5,97,0,0,32,33,5,108,0,0,33,34,5,115,0,0,34,35,5,101,0,0,35,4,1,0,0,0,
  	36,37,5,110,0,0,37,38,5,117,0,0,38,39,5,108,0,0,39,40,5,108,0,0,40,6,
  	1,0,0,0,41,42,5,91,0,0,42,8,1,0,0,0,43,44,5,93,0,0,44,10,1,0,0,0,45,46,
  	5,44,0,0,46,12,1,0,0,0,47,48,5,123,0,0,48,14,1,0,0,0,49,50,5,125,0,0,
  	50,16,1,0,0,0,51,52,5,58,0,0,52,18,1,0,0,0,53,65,5,48,0,0,54,56,5,45,
  	0,0,55,54,1,0,0,0,55,56,1,0,0,0,56,57,1,0,0,0,57,61,2,49,57,0,58,60,2,
  	48,57,0,59,58,1,0,0,0,60,63,1,0,0,0,61,59,1,0,0,0,61,62,1,0,0,0,62,65,
  	1,0,0,0,63,61,1,0,0,0,64,53,1,0,0,0,64,55,1,0,0,0,65,72,1,0,0,0,66,68,
  	5,46,0,0,67,69,2,48,57,0,68,67,1,0,0,0,69,70,1,0,0,0,70,68,1,0,0,0,70,
  	71,1,0,0,0,71,73,1,0,0,0,72,66,1,0,0,0,72,73,1,0,0,0,73,20,1,0,0,0,74,
  	76,3,23,11,0,75,77,7,0,0,0,76,75,1,0,0,0,77,78,1,0,0,0,78,76,1,0,0,0,
  	78,79,1,0,0,0,79,80,1,0,0,0,80,81,3,23,11,0,81,22,1,0,0,0,82,83,5,34,
  	0,0,83,24,1,0,0,0,7,0,55,61,64,70,72,78,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  g_jsonlexerLexerStaticData = staticData.release();
}

}

g_jsonLexer::g_jsonLexer(CharStream *input) : Lexer(input) {
  g_jsonLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *g_jsonlexerLexerStaticData->atn, g_jsonlexerLexerStaticData->decisionToDFA, g_jsonlexerLexerStaticData->sharedContextCache);
}

g_jsonLexer::~g_jsonLexer() {
  delete _interpreter;
}

std::string g_jsonLexer::getGrammarFileName() const {
  return "g_json.g4";
}

const std::vector<std::string>& g_jsonLexer::getRuleNames() const {
  return g_jsonlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& g_jsonLexer::getChannelNames() const {
  return g_jsonlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& g_jsonLexer::getModeNames() const {
  return g_jsonlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& g_jsonLexer::getVocabulary() const {
  return g_jsonlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView g_jsonLexer::getSerializedATN() const {
  return g_jsonlexerLexerStaticData->serializedATN;
}

const atn::ATN& g_jsonLexer::getATN() const {
  return *g_jsonlexerLexerStaticData->atn;
}




void g_jsonLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  g_jsonlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(g_jsonlexerLexerOnceFlag, g_jsonlexerLexerInitialize);
#endif
}
