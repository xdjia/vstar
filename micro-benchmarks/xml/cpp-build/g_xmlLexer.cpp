
// Generated from ./micro-benchmarks/xml/cpp-build/g_xml.g4 by ANTLR 4.13.1


#include "g_xmlLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct G_xmlLexerStaticData final {
  G_xmlLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  G_xmlLexerStaticData(const G_xmlLexerStaticData&) = delete;
  G_xmlLexerStaticData(G_xmlLexerStaticData&&) = delete;
  G_xmlLexerStaticData& operator=(const G_xmlLexerStaticData&) = delete;
  G_xmlLexerStaticData& operator=(G_xmlLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag g_xmllexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
G_xmlLexerStaticData *g_xmllexerLexerStaticData = nullptr;

void g_xmllexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (g_xmllexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(g_xmllexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<G_xmlLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "ASTART", "AEND", "BSTART", "BEND", 
      "CSTART", "CEND", "DSTART", "DEND", "ESTART", "EEND", "CHAR", "QUOTE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'>'", "'/>'", "'='", "' '", "'<a'", "'</a>'", "'<b'", "'</b>'", 
      "'<c'", "'</c>'", "'<d'", "'</d>'", "'<e'", "'</e>'", "", "'\\u0022'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "ASTART", "AEND", "BSTART", "BEND", "CSTART", 
      "CEND", "DSTART", "DEND", "ESTART", "EEND", "CHAR", "QUOTE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,16,86,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,1,0,1,0,1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,4,1,5,1,
  	5,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,
  	1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,13,1,
  	13,1,13,1,13,1,13,1,14,1,14,1,15,1,15,0,0,16,1,1,3,2,5,3,7,4,9,5,11,6,
  	13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,1,0,1,2,0,65,
  	90,97,122,85,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,
  	0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,
  	0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,
  	1,0,0,0,1,33,1,0,0,0,3,35,1,0,0,0,5,38,1,0,0,0,7,40,1,0,0,0,9,42,1,0,
  	0,0,11,45,1,0,0,0,13,50,1,0,0,0,15,53,1,0,0,0,17,58,1,0,0,0,19,61,1,0,
  	0,0,21,66,1,0,0,0,23,69,1,0,0,0,25,74,1,0,0,0,27,77,1,0,0,0,29,82,1,0,
  	0,0,31,84,1,0,0,0,33,34,5,62,0,0,34,2,1,0,0,0,35,36,5,47,0,0,36,37,5,
  	62,0,0,37,4,1,0,0,0,38,39,5,61,0,0,39,6,1,0,0,0,40,41,5,32,0,0,41,8,1,
  	0,0,0,42,43,5,60,0,0,43,44,5,97,0,0,44,10,1,0,0,0,45,46,5,60,0,0,46,47,
  	5,47,0,0,47,48,5,97,0,0,48,49,5,62,0,0,49,12,1,0,0,0,50,51,5,60,0,0,51,
  	52,5,98,0,0,52,14,1,0,0,0,53,54,5,60,0,0,54,55,5,47,0,0,55,56,5,98,0,
  	0,56,57,5,62,0,0,57,16,1,0,0,0,58,59,5,60,0,0,59,60,5,99,0,0,60,18,1,
  	0,0,0,61,62,5,60,0,0,62,63,5,47,0,0,63,64,5,99,0,0,64,65,5,62,0,0,65,
  	20,1,0,0,0,66,67,5,60,0,0,67,68,5,100,0,0,68,22,1,0,0,0,69,70,5,60,0,
  	0,70,71,5,47,0,0,71,72,5,100,0,0,72,73,5,62,0,0,73,24,1,0,0,0,74,75,5,
  	60,0,0,75,76,5,101,0,0,76,26,1,0,0,0,77,78,5,60,0,0,78,79,5,47,0,0,79,
  	80,5,101,0,0,80,81,5,62,0,0,81,28,1,0,0,0,82,83,7,0,0,0,83,30,1,0,0,0,
  	84,85,5,34,0,0,85,32,1,0,0,0,1,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  g_xmllexerLexerStaticData = staticData.release();
}

}

g_xmlLexer::g_xmlLexer(CharStream *input) : Lexer(input) {
  g_xmlLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *g_xmllexerLexerStaticData->atn, g_xmllexerLexerStaticData->decisionToDFA, g_xmllexerLexerStaticData->sharedContextCache);
}

g_xmlLexer::~g_xmlLexer() {
  delete _interpreter;
}

std::string g_xmlLexer::getGrammarFileName() const {
  return "g_xml.g4";
}

const std::vector<std::string>& g_xmlLexer::getRuleNames() const {
  return g_xmllexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& g_xmlLexer::getChannelNames() const {
  return g_xmllexerLexerStaticData->channelNames;
}

const std::vector<std::string>& g_xmlLexer::getModeNames() const {
  return g_xmllexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& g_xmlLexer::getVocabulary() const {
  return g_xmllexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView g_xmlLexer::getSerializedATN() const {
  return g_xmllexerLexerStaticData->serializedATN;
}

const atn::ATN& g_xmlLexer::getATN() const {
  return *g_xmllexerLexerStaticData->atn;
}




void g_xmlLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  g_xmllexerLexerInitialize();
#else
  ::antlr4::internal::call_once(g_xmllexerLexerOnceFlag, g_xmllexerLexerInitialize);
#endif
}
