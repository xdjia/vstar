
// Generated from ./micro-benchmarks/while/cpp-build/g_while.g4 by ANTLR 4.13.1


#include "g_whileListener.h"

#include "g_whileParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct G_whileParserStaticData final {
  G_whileParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  G_whileParserStaticData(const G_whileParserStaticData&) = delete;
  G_whileParserStaticData(G_whileParserStaticData&&) = delete;
  G_whileParserStaticData& operator=(const G_whileParserStaticData&) = delete;
  G_whileParserStaticData& operator=(G_whileParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag g_whileParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
G_whileParserStaticData *g_whileParserStaticData = nullptr;

void g_whileParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (g_whileParserStaticData != nullptr) {
    return;
  }
#else
  assert(g_whileParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<G_whileParserStaticData>(
    std::vector<std::string>{
      "start", "stmt", "boolexpr", "numexpr"
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
  	4,1,19,84,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,1,0,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,3,1,39,8,1,1,1,1,1,1,1,1,1,1,1,5,1,46,8,1,10,1,
  	12,1,49,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,62,8,2,1,
  	2,1,2,1,2,1,2,1,2,5,2,69,8,2,10,2,12,2,72,9,2,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,3,3,82,8,3,1,3,0,2,2,4,4,0,2,4,6,0,0,89,0,8,1,0,0,0,2,38,1,0,
  	0,0,4,61,1,0,0,0,6,81,1,0,0,0,8,9,3,2,1,0,9,10,5,0,0,1,10,1,1,0,0,0,11,
  	12,6,1,-1,0,12,13,5,1,0,0,13,14,5,19,0,0,14,15,5,2,0,0,15,16,5,19,0,0,
  	16,39,3,6,3,0,17,18,5,3,0,0,18,19,5,19,0,0,19,20,3,4,2,0,20,21,5,19,0,
  	0,21,22,5,4,0,0,22,23,5,19,0,0,23,24,3,2,1,0,24,25,5,19,0,0,25,26,5,5,
  	0,0,26,27,5,19,0,0,27,28,3,2,1,4,28,39,1,0,0,0,29,30,5,7,0,0,30,31,5,
  	19,0,0,31,32,3,4,2,0,32,33,5,19,0,0,33,34,5,8,0,0,34,35,5,19,0,0,35,36,
  	3,2,1,2,36,39,1,0,0,0,37,39,5,9,0,0,38,11,1,0,0,0,38,17,1,0,0,0,38,29,
  	1,0,0,0,38,37,1,0,0,0,39,47,1,0,0,0,40,41,10,3,0,0,41,42,5,19,0,0,42,
  	43,5,6,0,0,43,44,5,19,0,0,44,46,3,2,1,4,45,40,1,0,0,0,46,49,1,0,0,0,47,
  	45,1,0,0,0,47,48,1,0,0,0,48,3,1,0,0,0,49,47,1,0,0,0,50,51,6,2,-1,0,51,
  	62,5,10,0,0,52,62,5,11,0,0,53,54,3,6,3,0,54,55,5,19,0,0,55,56,5,12,0,
  	0,56,57,5,19,0,0,57,58,3,6,3,0,58,62,1,0,0,0,59,60,5,14,0,0,60,62,3,4,
  	2,1,61,50,1,0,0,0,61,52,1,0,0,0,61,53,1,0,0,0,61,59,1,0,0,0,62,70,1,0,
  	0,0,63,64,10,2,0,0,64,65,5,19,0,0,65,66,5,13,0,0,66,67,5,19,0,0,67,69,
  	3,4,2,3,68,63,1,0,0,0,69,72,1,0,0,0,70,68,1,0,0,0,70,71,1,0,0,0,71,5,
  	1,0,0,0,72,70,1,0,0,0,73,82,5,1,0,0,74,82,5,15,0,0,75,76,5,16,0,0,76,
  	77,3,6,3,0,77,78,5,17,0,0,78,79,3,6,3,0,79,80,5,18,0,0,80,82,1,0,0,0,
  	81,73,1,0,0,0,81,74,1,0,0,0,81,75,1,0,0,0,82,7,1,0,0,0,5,38,47,61,70,
  	81
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  g_whileParserStaticData = staticData.release();
}

}

g_whileParser::g_whileParser(TokenStream *input) : g_whileParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

g_whileParser::g_whileParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  g_whileParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *g_whileParserStaticData->atn, g_whileParserStaticData->decisionToDFA, g_whileParserStaticData->sharedContextCache, options);
}

g_whileParser::~g_whileParser() {
  delete _interpreter;
}

const atn::ATN& g_whileParser::getATN() const {
  return *g_whileParserStaticData->atn;
}

std::string g_whileParser::getGrammarFileName() const {
  return "g_while.g4";
}

const std::vector<std::string>& g_whileParser::getRuleNames() const {
  return g_whileParserStaticData->ruleNames;
}

const dfa::Vocabulary& g_whileParser::getVocabulary() const {
  return g_whileParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView g_whileParser::getSerializedATN() const {
  return g_whileParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

g_whileParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_whileParser::StmtContext* g_whileParser::StartContext::stmt() {
  return getRuleContext<g_whileParser::StmtContext>(0);
}

tree::TerminalNode* g_whileParser::StartContext::EOF() {
  return getToken(g_whileParser::EOF, 0);
}


size_t g_whileParser::StartContext::getRuleIndex() const {
  return g_whileParser::RuleStart;
}

void g_whileParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_whileListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void g_whileParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_whileListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

g_whileParser::StartContext* g_whileParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, g_whileParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    stmt(0);
    setState(9);
    match(g_whileParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

g_whileParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> g_whileParser::StmtContext::SPACE() {
  return getTokens(g_whileParser::SPACE);
}

tree::TerminalNode* g_whileParser::StmtContext::SPACE(size_t i) {
  return getToken(g_whileParser::SPACE, i);
}

g_whileParser::NumexprContext* g_whileParser::StmtContext::numexpr() {
  return getRuleContext<g_whileParser::NumexprContext>(0);
}

g_whileParser::BoolexprContext* g_whileParser::StmtContext::boolexpr() {
  return getRuleContext<g_whileParser::BoolexprContext>(0);
}

std::vector<g_whileParser::StmtContext *> g_whileParser::StmtContext::stmt() {
  return getRuleContexts<g_whileParser::StmtContext>();
}

g_whileParser::StmtContext* g_whileParser::StmtContext::stmt(size_t i) {
  return getRuleContext<g_whileParser::StmtContext>(i);
}


size_t g_whileParser::StmtContext::getRuleIndex() const {
  return g_whileParser::RuleStmt;
}

void g_whileParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_whileListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void g_whileParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_whileListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


g_whileParser::StmtContext* g_whileParser::stmt() {
   return stmt(0);
}

g_whileParser::StmtContext* g_whileParser::stmt(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  g_whileParser::StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, parentState);
  g_whileParser::StmtContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, g_whileParser::RuleStmt, precedence);

    

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
    setState(38);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_whileParser::T__0: {
        setState(12);
        match(g_whileParser::T__0);
        setState(13);
        match(g_whileParser::SPACE);
        setState(14);
        match(g_whileParser::T__1);
        setState(15);
        match(g_whileParser::SPACE);
        setState(16);
        numexpr();
        break;
      }

      case g_whileParser::T__2: {
        setState(17);
        match(g_whileParser::T__2);
        setState(18);
        match(g_whileParser::SPACE);
        setState(19);
        boolexpr(0);
        setState(20);
        match(g_whileParser::SPACE);
        setState(21);
        match(g_whileParser::T__3);
        setState(22);
        match(g_whileParser::SPACE);
        setState(23);
        stmt(0);
        setState(24);
        match(g_whileParser::SPACE);
        setState(25);
        match(g_whileParser::T__4);
        setState(26);
        match(g_whileParser::SPACE);
        setState(27);
        stmt(4);
        break;
      }

      case g_whileParser::T__6: {
        setState(29);
        match(g_whileParser::T__6);
        setState(30);
        match(g_whileParser::SPACE);
        setState(31);
        boolexpr(0);
        setState(32);
        match(g_whileParser::SPACE);
        setState(33);
        match(g_whileParser::T__7);
        setState(34);
        match(g_whileParser::SPACE);
        setState(35);
        stmt(2);
        break;
      }

      case g_whileParser::T__8: {
        setState(37);
        match(g_whileParser::T__8);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(47);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StmtContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStmt);
        setState(40);

        if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
        setState(41);
        match(g_whileParser::SPACE);
        setState(42);
        match(g_whileParser::T__5);
        setState(43);
        match(g_whileParser::SPACE);
        setState(44);
        stmt(4); 
      }
      setState(49);
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

//----------------- BoolexprContext ------------------------------------------------------------------

g_whileParser::BoolexprContext::BoolexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<g_whileParser::NumexprContext *> g_whileParser::BoolexprContext::numexpr() {
  return getRuleContexts<g_whileParser::NumexprContext>();
}

g_whileParser::NumexprContext* g_whileParser::BoolexprContext::numexpr(size_t i) {
  return getRuleContext<g_whileParser::NumexprContext>(i);
}

std::vector<tree::TerminalNode *> g_whileParser::BoolexprContext::SPACE() {
  return getTokens(g_whileParser::SPACE);
}

tree::TerminalNode* g_whileParser::BoolexprContext::SPACE(size_t i) {
  return getToken(g_whileParser::SPACE, i);
}

std::vector<g_whileParser::BoolexprContext *> g_whileParser::BoolexprContext::boolexpr() {
  return getRuleContexts<g_whileParser::BoolexprContext>();
}

g_whileParser::BoolexprContext* g_whileParser::BoolexprContext::boolexpr(size_t i) {
  return getRuleContext<g_whileParser::BoolexprContext>(i);
}


size_t g_whileParser::BoolexprContext::getRuleIndex() const {
  return g_whileParser::RuleBoolexpr;
}

void g_whileParser::BoolexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_whileListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolexpr(this);
}

void g_whileParser::BoolexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_whileListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolexpr(this);
}


g_whileParser::BoolexprContext* g_whileParser::boolexpr() {
   return boolexpr(0);
}

g_whileParser::BoolexprContext* g_whileParser::boolexpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  g_whileParser::BoolexprContext *_localctx = _tracker.createInstance<BoolexprContext>(_ctx, parentState);
  g_whileParser::BoolexprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, g_whileParser::RuleBoolexpr, precedence);

    

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
    setState(61);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_whileParser::T__9: {
        setState(51);
        match(g_whileParser::T__9);
        break;
      }

      case g_whileParser::T__10: {
        setState(52);
        match(g_whileParser::T__10);
        break;
      }

      case g_whileParser::T__0:
      case g_whileParser::T__14:
      case g_whileParser::T__15: {
        setState(53);
        numexpr();
        setState(54);
        match(g_whileParser::SPACE);
        setState(55);
        match(g_whileParser::T__11);
        setState(56);
        match(g_whileParser::SPACE);
        setState(57);
        numexpr();
        break;
      }

      case g_whileParser::T__13: {
        setState(59);
        match(g_whileParser::T__13);
        setState(60);
        boolexpr(1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(70);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BoolexprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBoolexpr);
        setState(63);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(64);
        match(g_whileParser::SPACE);
        setState(65);
        match(g_whileParser::T__12);
        setState(66);
        match(g_whileParser::SPACE);
        setState(67);
        boolexpr(3); 
      }
      setState(72);
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

//----------------- NumexprContext ------------------------------------------------------------------

g_whileParser::NumexprContext::NumexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<g_whileParser::NumexprContext *> g_whileParser::NumexprContext::numexpr() {
  return getRuleContexts<g_whileParser::NumexprContext>();
}

g_whileParser::NumexprContext* g_whileParser::NumexprContext::numexpr(size_t i) {
  return getRuleContext<g_whileParser::NumexprContext>(i);
}


size_t g_whileParser::NumexprContext::getRuleIndex() const {
  return g_whileParser::RuleNumexpr;
}

void g_whileParser::NumexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_whileListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumexpr(this);
}

void g_whileParser::NumexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_whileListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumexpr(this);
}

g_whileParser::NumexprContext* g_whileParser::numexpr() {
  NumexprContext *_localctx = _tracker.createInstance<NumexprContext>(_ctx, getState());
  enterRule(_localctx, 6, g_whileParser::RuleNumexpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(81);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_whileParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(73);
        match(g_whileParser::T__0);
        break;
      }

      case g_whileParser::T__14: {
        enterOuterAlt(_localctx, 2);
        setState(74);
        match(g_whileParser::T__14);
        break;
      }

      case g_whileParser::T__15: {
        enterOuterAlt(_localctx, 3);
        setState(75);
        match(g_whileParser::T__15);
        setState(76);
        numexpr();
        setState(77);
        match(g_whileParser::T__16);
        setState(78);
        numexpr();
        setState(79);
        match(g_whileParser::T__17);
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

bool g_whileParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return stmtSempred(antlrcpp::downCast<StmtContext *>(context), predicateIndex);
    case 2: return boolexprSempred(antlrcpp::downCast<BoolexprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool g_whileParser::stmtSempred(StmtContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool g_whileParser::boolexprSempred(BoolexprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void g_whileParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  g_whileParserInitialize();
#else
  ::antlr4::internal::call_once(g_whileParserOnceFlag, g_whileParserInitialize);
#endif
}
