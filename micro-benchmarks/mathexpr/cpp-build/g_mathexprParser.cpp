
// Generated from ./micro-benchmarks/mathexpr/cpp-build/g_mathexpr.g4 by ANTLR 4.13.1


#include "g_mathexprListener.h"

#include "g_mathexprParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct G_mathexprParserStaticData final {
  G_mathexprParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  G_mathexprParserStaticData(const G_mathexprParserStaticData&) = delete;
  G_mathexprParserStaticData(G_mathexprParserStaticData&&) = delete;
  G_mathexprParserStaticData& operator=(const G_mathexprParserStaticData&) = delete;
  G_mathexprParserStaticData& operator=(G_mathexprParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag g_mathexprParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
G_mathexprParserStaticData *g_mathexprParserStaticData = nullptr;

void g_mathexprParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (g_mathexprParserStaticData != nullptr) {
    return;
  }
#else
  assert(g_mathexprParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<G_mathexprParserStaticData>(
    std::vector<std::string>{
      "start", "expr", "exprp", "funccall", "arglist", "op"
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
  	4,1,13,58,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,1,0,1,0,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,32,
  	8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,41,8,2,1,3,1,3,1,3,1,3,1,3,1,4,1,
  	4,1,4,1,4,1,4,1,4,3,4,54,8,4,1,5,1,5,1,5,0,0,6,0,2,4,6,8,10,0,1,1,0,4,
  	7,58,0,12,1,0,0,0,2,31,1,0,0,0,4,40,1,0,0,0,6,42,1,0,0,0,8,53,1,0,0,0,
  	10,55,1,0,0,0,12,13,3,2,1,0,13,14,5,0,0,1,14,1,1,0,0,0,15,16,3,6,3,0,
  	16,17,3,4,2,0,17,32,1,0,0,0,18,19,5,10,0,0,19,32,3,4,2,0,20,21,5,11,0,
  	0,21,32,3,4,2,0,22,23,5,12,0,0,23,32,3,4,2,0,24,25,5,9,0,0,25,32,3,4,
  	2,0,26,27,5,1,0,0,27,28,3,2,1,0,28,29,5,2,0,0,29,30,3,4,2,0,30,32,1,0,
  	0,0,31,15,1,0,0,0,31,18,1,0,0,0,31,20,1,0,0,0,31,22,1,0,0,0,31,24,1,0,
  	0,0,31,26,1,0,0,0,32,3,1,0,0,0,33,34,5,13,0,0,34,35,3,10,5,0,35,36,5,
  	13,0,0,36,37,3,2,1,0,37,38,3,4,2,0,38,41,1,0,0,0,39,41,1,0,0,0,40,33,
  	1,0,0,0,40,39,1,0,0,0,41,5,1,0,0,0,42,43,5,8,0,0,43,44,5,1,0,0,44,45,
  	3,8,4,0,45,46,5,2,0,0,46,7,1,0,0,0,47,54,3,2,1,0,48,49,3,2,1,0,49,50,
  	5,3,0,0,50,51,5,13,0,0,51,52,3,8,4,0,52,54,1,0,0,0,53,47,1,0,0,0,53,48,
  	1,0,0,0,54,9,1,0,0,0,55,56,7,0,0,0,56,11,1,0,0,0,3,31,40,53
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  g_mathexprParserStaticData = staticData.release();
}

}

g_mathexprParser::g_mathexprParser(TokenStream *input) : g_mathexprParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

g_mathexprParser::g_mathexprParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  g_mathexprParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *g_mathexprParserStaticData->atn, g_mathexprParserStaticData->decisionToDFA, g_mathexprParserStaticData->sharedContextCache, options);
}

g_mathexprParser::~g_mathexprParser() {
  delete _interpreter;
}

const atn::ATN& g_mathexprParser::getATN() const {
  return *g_mathexprParserStaticData->atn;
}

std::string g_mathexprParser::getGrammarFileName() const {
  return "g_mathexpr.g4";
}

const std::vector<std::string>& g_mathexprParser::getRuleNames() const {
  return g_mathexprParserStaticData->ruleNames;
}

const dfa::Vocabulary& g_mathexprParser::getVocabulary() const {
  return g_mathexprParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView g_mathexprParser::getSerializedATN() const {
  return g_mathexprParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

g_mathexprParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_mathexprParser::ExprContext* g_mathexprParser::StartContext::expr() {
  return getRuleContext<g_mathexprParser::ExprContext>(0);
}

tree::TerminalNode* g_mathexprParser::StartContext::EOF() {
  return getToken(g_mathexprParser::EOF, 0);
}


size_t g_mathexprParser::StartContext::getRuleIndex() const {
  return g_mathexprParser::RuleStart;
}

void g_mathexprParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_mathexprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void g_mathexprParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_mathexprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

g_mathexprParser::StartContext* g_mathexprParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, g_mathexprParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(12);
    expr();
    setState(13);
    match(g_mathexprParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

g_mathexprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_mathexprParser::FunccallContext* g_mathexprParser::ExprContext::funccall() {
  return getRuleContext<g_mathexprParser::FunccallContext>(0);
}

g_mathexprParser::ExprpContext* g_mathexprParser::ExprContext::exprp() {
  return getRuleContext<g_mathexprParser::ExprpContext>(0);
}

tree::TerminalNode* g_mathexprParser::ExprContext::VAR() {
  return getToken(g_mathexprParser::VAR, 0);
}

tree::TerminalNode* g_mathexprParser::ExprContext::FLOAT() {
  return getToken(g_mathexprParser::FLOAT, 0);
}

tree::TerminalNode* g_mathexprParser::ExprContext::INTEGER() {
  return getToken(g_mathexprParser::INTEGER, 0);
}

tree::TerminalNode* g_mathexprParser::ExprContext::CONSTANT() {
  return getToken(g_mathexprParser::CONSTANT, 0);
}

g_mathexprParser::ExprContext* g_mathexprParser::ExprContext::expr() {
  return getRuleContext<g_mathexprParser::ExprContext>(0);
}


size_t g_mathexprParser::ExprContext::getRuleIndex() const {
  return g_mathexprParser::RuleExpr;
}

void g_mathexprParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_mathexprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void g_mathexprParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_mathexprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}

g_mathexprParser::ExprContext* g_mathexprParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 2, g_mathexprParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(31);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_mathexprParser::FUNC: {
        enterOuterAlt(_localctx, 1);
        setState(15);
        funccall();
        setState(16);
        exprp();
        break;
      }

      case g_mathexprParser::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(18);
        match(g_mathexprParser::VAR);
        setState(19);
        exprp();
        break;
      }

      case g_mathexprParser::FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(20);
        match(g_mathexprParser::FLOAT);
        setState(21);
        exprp();
        break;
      }

      case g_mathexprParser::INTEGER: {
        enterOuterAlt(_localctx, 4);
        setState(22);
        match(g_mathexprParser::INTEGER);
        setState(23);
        exprp();
        break;
      }

      case g_mathexprParser::CONSTANT: {
        enterOuterAlt(_localctx, 5);
        setState(24);
        match(g_mathexprParser::CONSTANT);
        setState(25);
        exprp();
        break;
      }

      case g_mathexprParser::T__0: {
        enterOuterAlt(_localctx, 6);
        setState(26);
        match(g_mathexprParser::T__0);
        setState(27);
        expr();
        setState(28);
        match(g_mathexprParser::T__1);
        setState(29);
        exprp();
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

//----------------- ExprpContext ------------------------------------------------------------------

g_mathexprParser::ExprpContext::ExprpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> g_mathexprParser::ExprpContext::SPACE() {
  return getTokens(g_mathexprParser::SPACE);
}

tree::TerminalNode* g_mathexprParser::ExprpContext::SPACE(size_t i) {
  return getToken(g_mathexprParser::SPACE, i);
}

g_mathexprParser::OpContext* g_mathexprParser::ExprpContext::op() {
  return getRuleContext<g_mathexprParser::OpContext>(0);
}

g_mathexprParser::ExprContext* g_mathexprParser::ExprpContext::expr() {
  return getRuleContext<g_mathexprParser::ExprContext>(0);
}

g_mathexprParser::ExprpContext* g_mathexprParser::ExprpContext::exprp() {
  return getRuleContext<g_mathexprParser::ExprpContext>(0);
}


size_t g_mathexprParser::ExprpContext::getRuleIndex() const {
  return g_mathexprParser::RuleExprp;
}

void g_mathexprParser::ExprpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_mathexprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprp(this);
}

void g_mathexprParser::ExprpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_mathexprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprp(this);
}

g_mathexprParser::ExprpContext* g_mathexprParser::exprp() {
  ExprpContext *_localctx = _tracker.createInstance<ExprpContext>(_ctx, getState());
  enterRule(_localctx, 4, g_mathexprParser::RuleExprp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(40);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(33);
      match(g_mathexprParser::SPACE);
      setState(34);
      op();
      setState(35);
      match(g_mathexprParser::SPACE);
      setState(36);
      expr();
      setState(37);
      exprp();
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

//----------------- FunccallContext ------------------------------------------------------------------

g_mathexprParser::FunccallContext::FunccallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_mathexprParser::FunccallContext::FUNC() {
  return getToken(g_mathexprParser::FUNC, 0);
}

g_mathexprParser::ArglistContext* g_mathexprParser::FunccallContext::arglist() {
  return getRuleContext<g_mathexprParser::ArglistContext>(0);
}


size_t g_mathexprParser::FunccallContext::getRuleIndex() const {
  return g_mathexprParser::RuleFunccall;
}

void g_mathexprParser::FunccallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_mathexprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunccall(this);
}

void g_mathexprParser::FunccallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_mathexprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunccall(this);
}

g_mathexprParser::FunccallContext* g_mathexprParser::funccall() {
  FunccallContext *_localctx = _tracker.createInstance<FunccallContext>(_ctx, getState());
  enterRule(_localctx, 6, g_mathexprParser::RuleFunccall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    match(g_mathexprParser::FUNC);
    setState(43);
    match(g_mathexprParser::T__0);
    setState(44);
    arglist();
    setState(45);
    match(g_mathexprParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArglistContext ------------------------------------------------------------------

g_mathexprParser::ArglistContext::ArglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_mathexprParser::ExprContext* g_mathexprParser::ArglistContext::expr() {
  return getRuleContext<g_mathexprParser::ExprContext>(0);
}

tree::TerminalNode* g_mathexprParser::ArglistContext::SPACE() {
  return getToken(g_mathexprParser::SPACE, 0);
}

g_mathexprParser::ArglistContext* g_mathexprParser::ArglistContext::arglist() {
  return getRuleContext<g_mathexprParser::ArglistContext>(0);
}


size_t g_mathexprParser::ArglistContext::getRuleIndex() const {
  return g_mathexprParser::RuleArglist;
}

void g_mathexprParser::ArglistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_mathexprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArglist(this);
}

void g_mathexprParser::ArglistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_mathexprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArglist(this);
}

g_mathexprParser::ArglistContext* g_mathexprParser::arglist() {
  ArglistContext *_localctx = _tracker.createInstance<ArglistContext>(_ctx, getState());
  enterRule(_localctx, 8, g_mathexprParser::RuleArglist);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(53);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(47);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(48);
      expr();
      setState(49);
      match(g_mathexprParser::T__2);
      setState(50);
      match(g_mathexprParser::SPACE);
      setState(51);
      arglist();
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

//----------------- OpContext ------------------------------------------------------------------

g_mathexprParser::OpContext::OpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t g_mathexprParser::OpContext::getRuleIndex() const {
  return g_mathexprParser::RuleOp;
}

void g_mathexprParser::OpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_mathexprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp(this);
}

void g_mathexprParser::OpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_mathexprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp(this);
}

g_mathexprParser::OpContext* g_mathexprParser::op() {
  OpContext *_localctx = _tracker.createInstance<OpContext>(_ctx, getState());
  enterRule(_localctx, 10, g_mathexprParser::RuleOp);
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
    setState(55);
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

void g_mathexprParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  g_mathexprParserInitialize();
#else
  ::antlr4::internal::call_once(g_mathexprParserOnceFlag, g_mathexprParserInitialize);
#endif
}
