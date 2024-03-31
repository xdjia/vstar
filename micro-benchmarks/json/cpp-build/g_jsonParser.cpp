
// Generated from ./micro-benchmarks/json/cpp-build/g_json.g4 by ANTLR 4.13.1


#include "g_jsonListener.h"

#include "g_jsonParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct G_jsonParserStaticData final {
  G_jsonParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  G_jsonParserStaticData(const G_jsonParserStaticData&) = delete;
  G_jsonParserStaticData(G_jsonParserStaticData&&) = delete;
  G_jsonParserStaticData& operator=(const G_jsonParserStaticData&) = delete;
  G_jsonParserStaticData& operator=(G_jsonParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag g_jsonParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
G_jsonParserStaticData *g_jsonParserStaticData = nullptr;

void g_jsonParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (g_jsonParserStaticData != nullptr) {
    return;
  }
#else
  assert(g_jsonParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<G_jsonParserStaticData>(
    std::vector<std::string>{
      "start", "value", "array", "list", "object", "objtuple", "objlist"
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
  	4,1,12,69,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,25,8,1,1,2,1,2,1,2,1,2,1,2,1,
  	2,3,2,33,8,2,1,3,1,3,1,3,1,3,1,3,1,3,5,3,41,8,3,10,3,12,3,44,9,3,1,4,
  	1,4,1,4,1,4,1,4,1,4,3,4,52,8,4,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,
  	6,5,6,64,8,6,10,6,12,6,67,9,6,1,6,0,2,6,12,7,0,2,4,6,8,10,12,0,0,71,0,
  	14,1,0,0,0,2,24,1,0,0,0,4,32,1,0,0,0,6,34,1,0,0,0,8,51,1,0,0,0,10,53,
  	1,0,0,0,12,57,1,0,0,0,14,15,3,2,1,0,15,16,5,0,0,1,16,1,1,0,0,0,17,25,
  	3,8,4,0,18,25,3,4,2,0,19,25,5,11,0,0,20,25,5,10,0,0,21,25,5,1,0,0,22,
  	25,5,2,0,0,23,25,5,3,0,0,24,17,1,0,0,0,24,18,1,0,0,0,24,19,1,0,0,0,24,
  	20,1,0,0,0,24,21,1,0,0,0,24,22,1,0,0,0,24,23,1,0,0,0,25,3,1,0,0,0,26,
  	27,5,4,0,0,27,33,5,5,0,0,28,29,5,4,0,0,29,30,3,6,3,0,30,31,5,5,0,0,31,
  	33,1,0,0,0,32,26,1,0,0,0,32,28,1,0,0,0,33,5,1,0,0,0,34,35,6,3,-1,0,35,
  	36,3,2,1,0,36,42,1,0,0,0,37,38,10,1,0,0,38,39,5,6,0,0,39,41,3,2,1,0,40,
  	37,1,0,0,0,41,44,1,0,0,0,42,40,1,0,0,0,42,43,1,0,0,0,43,7,1,0,0,0,44,
  	42,1,0,0,0,45,46,5,7,0,0,46,52,5,8,0,0,47,48,5,7,0,0,48,49,3,12,6,0,49,
  	50,5,8,0,0,50,52,1,0,0,0,51,45,1,0,0,0,51,47,1,0,0,0,52,9,1,0,0,0,53,
  	54,5,11,0,0,54,55,5,9,0,0,55,56,3,2,1,0,56,11,1,0,0,0,57,58,6,6,-1,0,
  	58,59,3,10,5,0,59,65,1,0,0,0,60,61,10,1,0,0,61,62,5,6,0,0,62,64,3,10,
  	5,0,63,60,1,0,0,0,64,67,1,0,0,0,65,63,1,0,0,0,65,66,1,0,0,0,66,13,1,0,
  	0,0,67,65,1,0,0,0,5,24,32,42,51,65
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  g_jsonParserStaticData = staticData.release();
}

}

g_jsonParser::g_jsonParser(TokenStream *input) : g_jsonParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

g_jsonParser::g_jsonParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  g_jsonParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *g_jsonParserStaticData->atn, g_jsonParserStaticData->decisionToDFA, g_jsonParserStaticData->sharedContextCache, options);
}

g_jsonParser::~g_jsonParser() {
  delete _interpreter;
}

const atn::ATN& g_jsonParser::getATN() const {
  return *g_jsonParserStaticData->atn;
}

std::string g_jsonParser::getGrammarFileName() const {
  return "g_json.g4";
}

const std::vector<std::string>& g_jsonParser::getRuleNames() const {
  return g_jsonParserStaticData->ruleNames;
}

const dfa::Vocabulary& g_jsonParser::getVocabulary() const {
  return g_jsonParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView g_jsonParser::getSerializedATN() const {
  return g_jsonParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

g_jsonParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_jsonParser::ValueContext* g_jsonParser::StartContext::value() {
  return getRuleContext<g_jsonParser::ValueContext>(0);
}

tree::TerminalNode* g_jsonParser::StartContext::EOF() {
  return getToken(g_jsonParser::EOF, 0);
}


size_t g_jsonParser::StartContext::getRuleIndex() const {
  return g_jsonParser::RuleStart;
}

void g_jsonParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void g_jsonParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

g_jsonParser::StartContext* g_jsonParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, g_jsonParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    value();
    setState(15);
    match(g_jsonParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

g_jsonParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_jsonParser::ObjectContext* g_jsonParser::ValueContext::object() {
  return getRuleContext<g_jsonParser::ObjectContext>(0);
}

g_jsonParser::ArrayContext* g_jsonParser::ValueContext::array() {
  return getRuleContext<g_jsonParser::ArrayContext>(0);
}

tree::TerminalNode* g_jsonParser::ValueContext::STRING() {
  return getToken(g_jsonParser::STRING, 0);
}

tree::TerminalNode* g_jsonParser::ValueContext::NUMBER() {
  return getToken(g_jsonParser::NUMBER, 0);
}


size_t g_jsonParser::ValueContext::getRuleIndex() const {
  return g_jsonParser::RuleValue;
}

void g_jsonParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void g_jsonParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}

g_jsonParser::ValueContext* g_jsonParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 2, g_jsonParser::RuleValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(24);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_jsonParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(17);
        object();
        break;
      }

      case g_jsonParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(18);
        array();
        break;
      }

      case g_jsonParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(19);
        match(g_jsonParser::STRING);
        break;
      }

      case g_jsonParser::NUMBER: {
        enterOuterAlt(_localctx, 4);
        setState(20);
        match(g_jsonParser::NUMBER);
        break;
      }

      case g_jsonParser::T__0: {
        enterOuterAlt(_localctx, 5);
        setState(21);
        match(g_jsonParser::T__0);
        break;
      }

      case g_jsonParser::T__1: {
        enterOuterAlt(_localctx, 6);
        setState(22);
        match(g_jsonParser::T__1);
        break;
      }

      case g_jsonParser::T__2: {
        enterOuterAlt(_localctx, 7);
        setState(23);
        match(g_jsonParser::T__2);
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

//----------------- ArrayContext ------------------------------------------------------------------

g_jsonParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_jsonParser::ListContext* g_jsonParser::ArrayContext::list() {
  return getRuleContext<g_jsonParser::ListContext>(0);
}


size_t g_jsonParser::ArrayContext::getRuleIndex() const {
  return g_jsonParser::RuleArray;
}

void g_jsonParser::ArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray(this);
}

void g_jsonParser::ArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray(this);
}

g_jsonParser::ArrayContext* g_jsonParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 4, g_jsonParser::RuleArray);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(32);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(26);
      match(g_jsonParser::T__3);
      setState(27);
      match(g_jsonParser::T__4);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(28);
      match(g_jsonParser::T__3);
      setState(29);
      list(0);
      setState(30);
      match(g_jsonParser::T__4);
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

g_jsonParser::ListContext::ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_jsonParser::ValueContext* g_jsonParser::ListContext::value() {
  return getRuleContext<g_jsonParser::ValueContext>(0);
}

g_jsonParser::ListContext* g_jsonParser::ListContext::list() {
  return getRuleContext<g_jsonParser::ListContext>(0);
}


size_t g_jsonParser::ListContext::getRuleIndex() const {
  return g_jsonParser::RuleList;
}

void g_jsonParser::ListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterList(this);
}

void g_jsonParser::ListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitList(this);
}


g_jsonParser::ListContext* g_jsonParser::list() {
   return list(0);
}

g_jsonParser::ListContext* g_jsonParser::list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  g_jsonParser::ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, parentState);
  g_jsonParser::ListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, g_jsonParser::RuleList, precedence);

    

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
    setState(35);
    value();
    _ctx->stop = _input->LT(-1);
    setState(42);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleList);
        setState(37);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(38);
        match(g_jsonParser::T__5);
        setState(39);
        value(); 
      }
      setState(44);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ObjectContext ------------------------------------------------------------------

g_jsonParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_jsonParser::ObjlistContext* g_jsonParser::ObjectContext::objlist() {
  return getRuleContext<g_jsonParser::ObjlistContext>(0);
}


size_t g_jsonParser::ObjectContext::getRuleIndex() const {
  return g_jsonParser::RuleObject;
}

void g_jsonParser::ObjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObject(this);
}

void g_jsonParser::ObjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObject(this);
}

g_jsonParser::ObjectContext* g_jsonParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 8, g_jsonParser::RuleObject);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(51);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(45);
      match(g_jsonParser::T__6);
      setState(46);
      match(g_jsonParser::T__7);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(47);
      match(g_jsonParser::T__6);
      setState(48);
      objlist(0);
      setState(49);
      match(g_jsonParser::T__7);
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

//----------------- ObjtupleContext ------------------------------------------------------------------

g_jsonParser::ObjtupleContext::ObjtupleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_jsonParser::ObjtupleContext::STRING() {
  return getToken(g_jsonParser::STRING, 0);
}

g_jsonParser::ValueContext* g_jsonParser::ObjtupleContext::value() {
  return getRuleContext<g_jsonParser::ValueContext>(0);
}


size_t g_jsonParser::ObjtupleContext::getRuleIndex() const {
  return g_jsonParser::RuleObjtuple;
}

void g_jsonParser::ObjtupleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjtuple(this);
}

void g_jsonParser::ObjtupleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjtuple(this);
}

g_jsonParser::ObjtupleContext* g_jsonParser::objtuple() {
  ObjtupleContext *_localctx = _tracker.createInstance<ObjtupleContext>(_ctx, getState());
  enterRule(_localctx, 10, g_jsonParser::RuleObjtuple);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(g_jsonParser::STRING);
    setState(54);
    match(g_jsonParser::T__8);
    setState(55);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjlistContext ------------------------------------------------------------------

g_jsonParser::ObjlistContext::ObjlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_jsonParser::ObjtupleContext* g_jsonParser::ObjlistContext::objtuple() {
  return getRuleContext<g_jsonParser::ObjtupleContext>(0);
}

g_jsonParser::ObjlistContext* g_jsonParser::ObjlistContext::objlist() {
  return getRuleContext<g_jsonParser::ObjlistContext>(0);
}


size_t g_jsonParser::ObjlistContext::getRuleIndex() const {
  return g_jsonParser::RuleObjlist;
}

void g_jsonParser::ObjlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjlist(this);
}

void g_jsonParser::ObjlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_jsonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjlist(this);
}


g_jsonParser::ObjlistContext* g_jsonParser::objlist() {
   return objlist(0);
}

g_jsonParser::ObjlistContext* g_jsonParser::objlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  g_jsonParser::ObjlistContext *_localctx = _tracker.createInstance<ObjlistContext>(_ctx, parentState);
  g_jsonParser::ObjlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, g_jsonParser::RuleObjlist, precedence);

    

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
    setState(58);
    objtuple();
    _ctx->stop = _input->LT(-1);
    setState(65);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ObjlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleObjlist);
        setState(60);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(61);
        match(g_jsonParser::T__5);
        setState(62);
        objtuple(); 
      }
      setState(67);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool g_jsonParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return listSempred(antlrcpp::downCast<ListContext *>(context), predicateIndex);
    case 6: return objlistSempred(antlrcpp::downCast<ObjlistContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool g_jsonParser::listSempred(ListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool g_jsonParser::objlistSempred(ObjlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void g_jsonParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  g_jsonParserInitialize();
#else
  ::antlr4::internal::call_once(g_jsonParserOnceFlag, g_jsonParserInitialize);
#endif
}
