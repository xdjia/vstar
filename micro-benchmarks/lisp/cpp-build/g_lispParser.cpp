
// Generated from ./micro-benchmarks/lisp/cpp-build/g_lisp.g4 by ANTLR 4.13.1


#include "g_lispListener.h"

#include "g_lispParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct G_lispParserStaticData final {
  G_lispParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  G_lispParserStaticData(const G_lispParserStaticData&) = delete;
  G_lispParserStaticData(G_lispParserStaticData&&) = delete;
  G_lispParserStaticData& operator=(const G_lispParserStaticData&) = delete;
  G_lispParserStaticData& operator=(G_lispParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag g_lispParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
G_lispParserStaticData *g_lispParserStaticData = nullptr;

void g_lispParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (g_lispParserStaticData != nullptr) {
    return;
  }
#else
  assert(g_lispParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<G_lispParserStaticData>(
    std::vector<std::string>{
      "start", "sexpression", "list", "atomicsymbol", "atompart"
    },
    std::vector<std::string>{
      "", "'('", "'.'", "')'", "", "", "' '"
    },
    std::vector<std::string>{
      "", "", "", "", "LETTER", "NUMBER", "EMPTY"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,6,50,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,1,0,1,0,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,24,8,1,1,2,1,2,1,2,1,2,5,2,30,8,2,
  	10,2,12,2,33,9,2,1,2,1,2,1,3,1,3,1,3,3,3,40,8,3,1,4,1,4,1,4,1,4,1,4,1,
  	4,3,4,48,8,4,1,4,0,0,5,0,2,4,6,8,0,0,51,0,10,1,0,0,0,2,23,1,0,0,0,4,25,
  	1,0,0,0,6,39,1,0,0,0,8,47,1,0,0,0,10,11,3,2,1,0,11,12,5,0,0,1,12,1,1,
  	0,0,0,13,24,3,6,3,0,14,15,5,1,0,0,15,16,3,2,1,0,16,17,5,6,0,0,17,18,5,
  	2,0,0,18,19,5,6,0,0,19,20,3,2,1,0,20,21,5,3,0,0,21,24,1,0,0,0,22,24,3,
  	4,2,0,23,13,1,0,0,0,23,14,1,0,0,0,23,22,1,0,0,0,24,3,1,0,0,0,25,26,5,
  	1,0,0,26,31,3,2,1,0,27,28,5,6,0,0,28,30,3,2,1,0,29,27,1,0,0,0,30,33,1,
  	0,0,0,31,29,1,0,0,0,31,32,1,0,0,0,32,34,1,0,0,0,33,31,1,0,0,0,34,35,5,
  	3,0,0,35,5,1,0,0,0,36,40,5,4,0,0,37,38,5,4,0,0,38,40,3,8,4,0,39,36,1,
  	0,0,0,39,37,1,0,0,0,40,7,1,0,0,0,41,48,5,4,0,0,42,48,5,5,0,0,43,44,5,
  	4,0,0,44,48,3,8,4,0,45,46,5,5,0,0,46,48,3,8,4,0,47,41,1,0,0,0,47,42,1,
  	0,0,0,47,43,1,0,0,0,47,45,1,0,0,0,48,9,1,0,0,0,4,23,31,39,47
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  g_lispParserStaticData = staticData.release();
}

}

g_lispParser::g_lispParser(TokenStream *input) : g_lispParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

g_lispParser::g_lispParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  g_lispParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *g_lispParserStaticData->atn, g_lispParserStaticData->decisionToDFA, g_lispParserStaticData->sharedContextCache, options);
}

g_lispParser::~g_lispParser() {
  delete _interpreter;
}

const atn::ATN& g_lispParser::getATN() const {
  return *g_lispParserStaticData->atn;
}

std::string g_lispParser::getGrammarFileName() const {
  return "g_lisp.g4";
}

const std::vector<std::string>& g_lispParser::getRuleNames() const {
  return g_lispParserStaticData->ruleNames;
}

const dfa::Vocabulary& g_lispParser::getVocabulary() const {
  return g_lispParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView g_lispParser::getSerializedATN() const {
  return g_lispParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

g_lispParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_lispParser::SexpressionContext* g_lispParser::StartContext::sexpression() {
  return getRuleContext<g_lispParser::SexpressionContext>(0);
}

tree::TerminalNode* g_lispParser::StartContext::EOF() {
  return getToken(g_lispParser::EOF, 0);
}


size_t g_lispParser::StartContext::getRuleIndex() const {
  return g_lispParser::RuleStart;
}

void g_lispParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_lispListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void g_lispParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_lispListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

g_lispParser::StartContext* g_lispParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, g_lispParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(10);
    sexpression();
    setState(11);
    match(g_lispParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SexpressionContext ------------------------------------------------------------------

g_lispParser::SexpressionContext::SexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_lispParser::AtomicsymbolContext* g_lispParser::SexpressionContext::atomicsymbol() {
  return getRuleContext<g_lispParser::AtomicsymbolContext>(0);
}

std::vector<g_lispParser::SexpressionContext *> g_lispParser::SexpressionContext::sexpression() {
  return getRuleContexts<g_lispParser::SexpressionContext>();
}

g_lispParser::SexpressionContext* g_lispParser::SexpressionContext::sexpression(size_t i) {
  return getRuleContext<g_lispParser::SexpressionContext>(i);
}

std::vector<tree::TerminalNode *> g_lispParser::SexpressionContext::EMPTY() {
  return getTokens(g_lispParser::EMPTY);
}

tree::TerminalNode* g_lispParser::SexpressionContext::EMPTY(size_t i) {
  return getToken(g_lispParser::EMPTY, i);
}

g_lispParser::ListContext* g_lispParser::SexpressionContext::list() {
  return getRuleContext<g_lispParser::ListContext>(0);
}


size_t g_lispParser::SexpressionContext::getRuleIndex() const {
  return g_lispParser::RuleSexpression;
}

void g_lispParser::SexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_lispListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSexpression(this);
}

void g_lispParser::SexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_lispListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSexpression(this);
}

g_lispParser::SexpressionContext* g_lispParser::sexpression() {
  SexpressionContext *_localctx = _tracker.createInstance<SexpressionContext>(_ctx, getState());
  enterRule(_localctx, 2, g_lispParser::RuleSexpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(23);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(13);
      atomicsymbol();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(14);
      match(g_lispParser::T__0);
      setState(15);
      sexpression();
      setState(16);
      match(g_lispParser::EMPTY);
      setState(17);
      match(g_lispParser::T__1);
      setState(18);
      match(g_lispParser::EMPTY);
      setState(19);
      sexpression();
      setState(20);
      match(g_lispParser::T__2);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(22);
      list();
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

//----------------- ListContext ------------------------------------------------------------------

g_lispParser::ListContext::ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<g_lispParser::SexpressionContext *> g_lispParser::ListContext::sexpression() {
  return getRuleContexts<g_lispParser::SexpressionContext>();
}

g_lispParser::SexpressionContext* g_lispParser::ListContext::sexpression(size_t i) {
  return getRuleContext<g_lispParser::SexpressionContext>(i);
}

std::vector<tree::TerminalNode *> g_lispParser::ListContext::EMPTY() {
  return getTokens(g_lispParser::EMPTY);
}

tree::TerminalNode* g_lispParser::ListContext::EMPTY(size_t i) {
  return getToken(g_lispParser::EMPTY, i);
}


size_t g_lispParser::ListContext::getRuleIndex() const {
  return g_lispParser::RuleList;
}

void g_lispParser::ListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_lispListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterList(this);
}

void g_lispParser::ListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_lispListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitList(this);
}

g_lispParser::ListContext* g_lispParser::list() {
  ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, getState());
  enterRule(_localctx, 4, g_lispParser::RuleList);
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
    setState(25);
    match(g_lispParser::T__0);
    setState(26);
    sexpression();
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == g_lispParser::EMPTY) {
      setState(27);
      match(g_lispParser::EMPTY);
      setState(28);
      sexpression();
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(34);
    match(g_lispParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomicsymbolContext ------------------------------------------------------------------

g_lispParser::AtomicsymbolContext::AtomicsymbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_lispParser::AtomicsymbolContext::LETTER() {
  return getToken(g_lispParser::LETTER, 0);
}

g_lispParser::AtompartContext* g_lispParser::AtomicsymbolContext::atompart() {
  return getRuleContext<g_lispParser::AtompartContext>(0);
}


size_t g_lispParser::AtomicsymbolContext::getRuleIndex() const {
  return g_lispParser::RuleAtomicsymbol;
}

void g_lispParser::AtomicsymbolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_lispListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtomicsymbol(this);
}

void g_lispParser::AtomicsymbolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_lispListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtomicsymbol(this);
}

g_lispParser::AtomicsymbolContext* g_lispParser::atomicsymbol() {
  AtomicsymbolContext *_localctx = _tracker.createInstance<AtomicsymbolContext>(_ctx, getState());
  enterRule(_localctx, 6, g_lispParser::RuleAtomicsymbol);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(39);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(36);
      match(g_lispParser::LETTER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(37);
      match(g_lispParser::LETTER);
      setState(38);
      atompart();
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

//----------------- AtompartContext ------------------------------------------------------------------

g_lispParser::AtompartContext::AtompartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_lispParser::AtompartContext::LETTER() {
  return getToken(g_lispParser::LETTER, 0);
}

tree::TerminalNode* g_lispParser::AtompartContext::NUMBER() {
  return getToken(g_lispParser::NUMBER, 0);
}

g_lispParser::AtompartContext* g_lispParser::AtompartContext::atompart() {
  return getRuleContext<g_lispParser::AtompartContext>(0);
}


size_t g_lispParser::AtompartContext::getRuleIndex() const {
  return g_lispParser::RuleAtompart;
}

void g_lispParser::AtompartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_lispListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtompart(this);
}

void g_lispParser::AtompartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_lispListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtompart(this);
}

g_lispParser::AtompartContext* g_lispParser::atompart() {
  AtompartContext *_localctx = _tracker.createInstance<AtompartContext>(_ctx, getState());
  enterRule(_localctx, 8, g_lispParser::RuleAtompart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(41);
      match(g_lispParser::LETTER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(42);
      match(g_lispParser::NUMBER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(43);
      match(g_lispParser::LETTER);
      setState(44);
      atompart();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(45);
      match(g_lispParser::NUMBER);
      setState(46);
      atompart();
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

void g_lispParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  g_lispParserInitialize();
#else
  ::antlr4::internal::call_once(g_lispParserOnceFlag, g_lispParserInitialize);
#endif
}
