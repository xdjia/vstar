
// Generated from ./micro-benchmarks/lisp/cpp-build/g_lisp.g4 by ANTLR 4.13.1


#include "g_lispLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct G_lispLexerStaticData final {
  G_lispLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  G_lispLexerStaticData(const G_lispLexerStaticData&) = delete;
  G_lispLexerStaticData(G_lispLexerStaticData&&) = delete;
  G_lispLexerStaticData& operator=(const G_lispLexerStaticData&) = delete;
  G_lispLexerStaticData& operator=(G_lispLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag g_lisplexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
G_lispLexerStaticData *g_lisplexerLexerStaticData = nullptr;

void g_lisplexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (g_lisplexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(g_lisplexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<G_lispLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "LETTER", "NUMBER", "EMPTY"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'('", "'.'", "')'", "", "", "' '"
    },
    std::vector<std::string>{
      "", "", "", "", "LETTER", "NUMBER", "EMPTY"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,6,25,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,1,0,
  	1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,0,0,6,1,1,3,2,5,3,7,4,9,5,11,
  	6,1,0,0,24,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,
  	0,0,11,1,0,0,0,1,13,1,0,0,0,3,15,1,0,0,0,5,17,1,0,0,0,7,19,1,0,0,0,9,
  	21,1,0,0,0,11,23,1,0,0,0,13,14,5,40,0,0,14,2,1,0,0,0,15,16,5,46,0,0,16,
  	4,1,0,0,0,17,18,5,41,0,0,18,6,1,0,0,0,19,20,2,97,122,0,20,8,1,0,0,0,21,
  	22,2,48,57,0,22,10,1,0,0,0,23,24,5,32,0,0,24,12,1,0,0,0,1,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  g_lisplexerLexerStaticData = staticData.release();
}

}

g_lispLexer::g_lispLexer(CharStream *input) : Lexer(input) {
  g_lispLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *g_lisplexerLexerStaticData->atn, g_lisplexerLexerStaticData->decisionToDFA, g_lisplexerLexerStaticData->sharedContextCache);
}

g_lispLexer::~g_lispLexer() {
  delete _interpreter;
}

std::string g_lispLexer::getGrammarFileName() const {
  return "g_lisp.g4";
}

const std::vector<std::string>& g_lispLexer::getRuleNames() const {
  return g_lisplexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& g_lispLexer::getChannelNames() const {
  return g_lisplexerLexerStaticData->channelNames;
}

const std::vector<std::string>& g_lispLexer::getModeNames() const {
  return g_lisplexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& g_lispLexer::getVocabulary() const {
  return g_lisplexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView g_lispLexer::getSerializedATN() const {
  return g_lisplexerLexerStaticData->serializedATN;
}

const atn::ATN& g_lispLexer::getATN() const {
  return *g_lisplexerLexerStaticData->atn;
}




void g_lispLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  g_lisplexerLexerInitialize();
#else
  ::antlr4::internal::call_once(g_lisplexerLexerOnceFlag, g_lisplexerLexerInitialize);
#endif
}
