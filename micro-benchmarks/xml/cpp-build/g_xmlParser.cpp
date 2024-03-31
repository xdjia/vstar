
// Generated from ./micro-benchmarks/xml/cpp-build/g_xml.g4 by ANTLR 4.13.1


#include "g_xmlListener.h"

#include "g_xmlParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct G_xmlParserStaticData final {
  G_xmlParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  G_xmlParserStaticData(const G_xmlParserStaticData&) = delete;
  G_xmlParserStaticData(G_xmlParserStaticData&&) = delete;
  G_xmlParserStaticData& operator=(const G_xmlParserStaticData&) = delete;
  G_xmlParserStaticData& operator=(G_xmlParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag g_xmlParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
G_xmlParserStaticData *g_xmlParserStaticData = nullptr;

void g_xmlParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (g_xmlParserStaticData != nullptr) {
    return;
  }
#else
  assert(g_xmlParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<G_xmlParserStaticData>(
    std::vector<std::string>{
      "start", "xml", "body", "attrlist", "attr", "text", "space"
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
  	4,1,16,106,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,
  	0,1,0,1,0,1,1,1,1,3,1,20,8,1,1,1,1,1,1,1,1,1,1,1,3,1,27,8,1,1,1,1,1,3,
  	1,31,8,1,1,1,1,1,1,1,1,1,1,1,3,1,38,8,1,1,1,1,1,3,1,42,8,1,1,1,1,1,1,
  	1,1,1,1,1,3,1,49,8,1,1,1,1,1,3,1,53,8,1,1,1,1,1,1,1,1,1,1,1,3,1,60,8,
  	1,1,1,1,1,3,1,64,8,1,1,1,1,1,1,1,1,1,1,1,3,1,71,8,1,3,1,73,8,1,1,2,1,
  	2,3,2,77,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,86,8,3,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,5,1,5,1,5,1,5,1,5,5,5,99,8,5,10,5,12,5,102,9,5,1,6,1,6,1,6,0,
  	1,10,7,0,2,4,6,8,10,12,0,0,115,0,14,1,0,0,0,2,72,1,0,0,0,4,76,1,0,0,0,
  	6,85,1,0,0,0,8,87,1,0,0,0,10,93,1,0,0,0,12,103,1,0,0,0,14,15,3,2,1,0,
  	15,16,5,0,0,1,16,1,1,0,0,0,17,26,5,5,0,0,18,20,3,6,3,0,19,18,1,0,0,0,
  	19,20,1,0,0,0,20,21,1,0,0,0,21,22,5,1,0,0,22,23,3,4,2,0,23,24,5,6,0,0,
  	24,27,1,0,0,0,25,27,5,2,0,0,26,19,1,0,0,0,26,25,1,0,0,0,27,73,1,0,0,0,
  	28,37,5,7,0,0,29,31,3,6,3,0,30,29,1,0,0,0,30,31,1,0,0,0,31,32,1,0,0,0,
  	32,33,5,1,0,0,33,34,3,4,2,0,34,35,5,8,0,0,35,38,1,0,0,0,36,38,5,2,0,0,
  	37,30,1,0,0,0,37,36,1,0,0,0,38,73,1,0,0,0,39,48,5,9,0,0,40,42,3,6,3,0,
  	41,40,1,0,0,0,41,42,1,0,0,0,42,43,1,0,0,0,43,44,5,1,0,0,44,45,3,4,2,0,
  	45,46,5,10,0,0,46,49,1,0,0,0,47,49,5,2,0,0,48,41,1,0,0,0,48,47,1,0,0,
  	0,49,73,1,0,0,0,50,59,5,11,0,0,51,53,3,6,3,0,52,51,1,0,0,0,52,53,1,0,
  	0,0,53,54,1,0,0,0,54,55,5,1,0,0,55,56,3,4,2,0,56,57,5,12,0,0,57,60,1,
  	0,0,0,58,60,5,2,0,0,59,52,1,0,0,0,59,58,1,0,0,0,60,73,1,0,0,0,61,70,5,
  	13,0,0,62,64,3,6,3,0,63,62,1,0,0,0,63,64,1,0,0,0,64,65,1,0,0,0,65,66,
  	5,1,0,0,66,67,3,4,2,0,67,68,5,14,0,0,68,71,1,0,0,0,69,71,5,2,0,0,70,63,
  	1,0,0,0,70,69,1,0,0,0,71,73,1,0,0,0,72,17,1,0,0,0,72,28,1,0,0,0,72,39,
  	1,0,0,0,72,50,1,0,0,0,72,61,1,0,0,0,73,3,1,0,0,0,74,77,3,2,1,0,75,77,
  	3,10,5,0,76,74,1,0,0,0,76,75,1,0,0,0,77,5,1,0,0,0,78,79,3,12,6,0,79,80,
  	3,8,4,0,80,86,1,0,0,0,81,82,3,12,6,0,82,83,3,8,4,0,83,84,3,6,3,0,84,86,
  	1,0,0,0,85,78,1,0,0,0,85,81,1,0,0,0,86,7,1,0,0,0,87,88,3,10,5,0,88,89,
  	5,3,0,0,89,90,5,16,0,0,90,91,3,10,5,0,91,92,5,16,0,0,92,9,1,0,0,0,93,
  	94,6,5,-1,0,94,95,5,15,0,0,95,100,1,0,0,0,96,97,10,2,0,0,97,99,5,15,0,
  	0,98,96,1,0,0,0,99,102,1,0,0,0,100,98,1,0,0,0,100,101,1,0,0,0,101,11,
  	1,0,0,0,102,100,1,0,0,0,103,104,5,4,0,0,104,13,1,0,0,0,14,19,26,30,37,
  	41,48,52,59,63,70,72,76,85,100
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  g_xmlParserStaticData = staticData.release();
}

}

g_xmlParser::g_xmlParser(TokenStream *input) : g_xmlParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

g_xmlParser::g_xmlParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  g_xmlParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *g_xmlParserStaticData->atn, g_xmlParserStaticData->decisionToDFA, g_xmlParserStaticData->sharedContextCache, options);
}

g_xmlParser::~g_xmlParser() {
  delete _interpreter;
}

const atn::ATN& g_xmlParser::getATN() const {
  return *g_xmlParserStaticData->atn;
}

std::string g_xmlParser::getGrammarFileName() const {
  return "g_xml.g4";
}

const std::vector<std::string>& g_xmlParser::getRuleNames() const {
  return g_xmlParserStaticData->ruleNames;
}

const dfa::Vocabulary& g_xmlParser::getVocabulary() const {
  return g_xmlParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView g_xmlParser::getSerializedATN() const {
  return g_xmlParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

g_xmlParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_xmlParser::XmlContext* g_xmlParser::StartContext::xml() {
  return getRuleContext<g_xmlParser::XmlContext>(0);
}

tree::TerminalNode* g_xmlParser::StartContext::EOF() {
  return getToken(g_xmlParser::EOF, 0);
}


size_t g_xmlParser::StartContext::getRuleIndex() const {
  return g_xmlParser::RuleStart;
}

void g_xmlParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void g_xmlParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

g_xmlParser::StartContext* g_xmlParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, g_xmlParser::RuleStart);

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
    xml();
    setState(15);
    match(g_xmlParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- XmlContext ------------------------------------------------------------------

g_xmlParser::XmlContext::XmlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_xmlParser::XmlContext::ASTART() {
  return getToken(g_xmlParser::ASTART, 0);
}

g_xmlParser::BodyContext* g_xmlParser::XmlContext::body() {
  return getRuleContext<g_xmlParser::BodyContext>(0);
}

tree::TerminalNode* g_xmlParser::XmlContext::AEND() {
  return getToken(g_xmlParser::AEND, 0);
}

g_xmlParser::AttrlistContext* g_xmlParser::XmlContext::attrlist() {
  return getRuleContext<g_xmlParser::AttrlistContext>(0);
}

tree::TerminalNode* g_xmlParser::XmlContext::BSTART() {
  return getToken(g_xmlParser::BSTART, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::BEND() {
  return getToken(g_xmlParser::BEND, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::CSTART() {
  return getToken(g_xmlParser::CSTART, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::CEND() {
  return getToken(g_xmlParser::CEND, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::DSTART() {
  return getToken(g_xmlParser::DSTART, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::DEND() {
  return getToken(g_xmlParser::DEND, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::ESTART() {
  return getToken(g_xmlParser::ESTART, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::EEND() {
  return getToken(g_xmlParser::EEND, 0);
}


size_t g_xmlParser::XmlContext::getRuleIndex() const {
  return g_xmlParser::RuleXml;
}

void g_xmlParser::XmlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXml(this);
}

void g_xmlParser::XmlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXml(this);
}

g_xmlParser::XmlContext* g_xmlParser::xml() {
  XmlContext *_localctx = _tracker.createInstance<XmlContext>(_ctx, getState());
  enterRule(_localctx, 2, g_xmlParser::RuleXml);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(72);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_xmlParser::ASTART: {
        enterOuterAlt(_localctx, 1);
        setState(17);
        match(g_xmlParser::ASTART);
        setState(26);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case g_xmlParser::T__0:
          case g_xmlParser::T__3: {
            setState(19);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == g_xmlParser::T__3) {
              setState(18);
              attrlist();
            }
            setState(21);
            match(g_xmlParser::T__0);
            setState(22);
            body();
            setState(23);
            match(g_xmlParser::AEND);
            break;
          }

          case g_xmlParser::T__1: {
            setState(25);
            match(g_xmlParser::T__1);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case g_xmlParser::BSTART: {
        enterOuterAlt(_localctx, 2);
        setState(28);
        match(g_xmlParser::BSTART);
        setState(37);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case g_xmlParser::T__0:
          case g_xmlParser::T__3: {
            setState(30);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == g_xmlParser::T__3) {
              setState(29);
              attrlist();
            }
            setState(32);
            match(g_xmlParser::T__0);
            setState(33);
            body();
            setState(34);
            match(g_xmlParser::BEND);
            break;
          }

          case g_xmlParser::T__1: {
            setState(36);
            match(g_xmlParser::T__1);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case g_xmlParser::CSTART: {
        enterOuterAlt(_localctx, 3);
        setState(39);
        match(g_xmlParser::CSTART);
        setState(48);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case g_xmlParser::T__0:
          case g_xmlParser::T__3: {
            setState(41);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == g_xmlParser::T__3) {
              setState(40);
              attrlist();
            }
            setState(43);
            match(g_xmlParser::T__0);
            setState(44);
            body();
            setState(45);
            match(g_xmlParser::CEND);
            break;
          }

          case g_xmlParser::T__1: {
            setState(47);
            match(g_xmlParser::T__1);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case g_xmlParser::DSTART: {
        enterOuterAlt(_localctx, 4);
        setState(50);
        match(g_xmlParser::DSTART);
        setState(59);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case g_xmlParser::T__0:
          case g_xmlParser::T__3: {
            setState(52);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == g_xmlParser::T__3) {
              setState(51);
              attrlist();
            }
            setState(54);
            match(g_xmlParser::T__0);
            setState(55);
            body();
            setState(56);
            match(g_xmlParser::DEND);
            break;
          }

          case g_xmlParser::T__1: {
            setState(58);
            match(g_xmlParser::T__1);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case g_xmlParser::ESTART: {
        enterOuterAlt(_localctx, 5);
        setState(61);
        match(g_xmlParser::ESTART);
        setState(70);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case g_xmlParser::T__0:
          case g_xmlParser::T__3: {
            setState(63);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == g_xmlParser::T__3) {
              setState(62);
              attrlist();
            }
            setState(65);
            match(g_xmlParser::T__0);
            setState(66);
            body();
            setState(67);
            match(g_xmlParser::EEND);
            break;
          }

          case g_xmlParser::T__1: {
            setState(69);
            match(g_xmlParser::T__1);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
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

//----------------- BodyContext ------------------------------------------------------------------

g_xmlParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_xmlParser::XmlContext* g_xmlParser::BodyContext::xml() {
  return getRuleContext<g_xmlParser::XmlContext>(0);
}

g_xmlParser::TextContext* g_xmlParser::BodyContext::text() {
  return getRuleContext<g_xmlParser::TextContext>(0);
}


size_t g_xmlParser::BodyContext::getRuleIndex() const {
  return g_xmlParser::RuleBody;
}

void g_xmlParser::BodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody(this);
}

void g_xmlParser::BodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody(this);
}

g_xmlParser::BodyContext* g_xmlParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 4, g_xmlParser::RuleBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_xmlParser::ASTART:
      case g_xmlParser::BSTART:
      case g_xmlParser::CSTART:
      case g_xmlParser::DSTART:
      case g_xmlParser::ESTART: {
        enterOuterAlt(_localctx, 1);
        setState(74);
        xml();
        break;
      }

      case g_xmlParser::CHAR: {
        enterOuterAlt(_localctx, 2);
        setState(75);
        text(0);
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

//----------------- AttrlistContext ------------------------------------------------------------------

g_xmlParser::AttrlistContext::AttrlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_xmlParser::SpaceContext* g_xmlParser::AttrlistContext::space() {
  return getRuleContext<g_xmlParser::SpaceContext>(0);
}

g_xmlParser::AttrContext* g_xmlParser::AttrlistContext::attr() {
  return getRuleContext<g_xmlParser::AttrContext>(0);
}

g_xmlParser::AttrlistContext* g_xmlParser::AttrlistContext::attrlist() {
  return getRuleContext<g_xmlParser::AttrlistContext>(0);
}


size_t g_xmlParser::AttrlistContext::getRuleIndex() const {
  return g_xmlParser::RuleAttrlist;
}

void g_xmlParser::AttrlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttrlist(this);
}

void g_xmlParser::AttrlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttrlist(this);
}

g_xmlParser::AttrlistContext* g_xmlParser::attrlist() {
  AttrlistContext *_localctx = _tracker.createInstance<AttrlistContext>(_ctx, getState());
  enterRule(_localctx, 6, g_xmlParser::RuleAttrlist);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(85);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(78);
      space();
      setState(79);
      attr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(81);
      space();
      setState(82);
      attr();
      setState(83);
      attrlist();
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

//----------------- AttrContext ------------------------------------------------------------------

g_xmlParser::AttrContext::AttrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<g_xmlParser::TextContext *> g_xmlParser::AttrContext::text() {
  return getRuleContexts<g_xmlParser::TextContext>();
}

g_xmlParser::TextContext* g_xmlParser::AttrContext::text(size_t i) {
  return getRuleContext<g_xmlParser::TextContext>(i);
}

std::vector<tree::TerminalNode *> g_xmlParser::AttrContext::QUOTE() {
  return getTokens(g_xmlParser::QUOTE);
}

tree::TerminalNode* g_xmlParser::AttrContext::QUOTE(size_t i) {
  return getToken(g_xmlParser::QUOTE, i);
}


size_t g_xmlParser::AttrContext::getRuleIndex() const {
  return g_xmlParser::RuleAttr;
}

void g_xmlParser::AttrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttr(this);
}

void g_xmlParser::AttrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttr(this);
}

g_xmlParser::AttrContext* g_xmlParser::attr() {
  AttrContext *_localctx = _tracker.createInstance<AttrContext>(_ctx, getState());
  enterRule(_localctx, 8, g_xmlParser::RuleAttr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    text(0);
    setState(88);
    match(g_xmlParser::T__2);
    setState(89);
    match(g_xmlParser::QUOTE);
    setState(90);
    text(0);
    setState(91);
    match(g_xmlParser::QUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TextContext ------------------------------------------------------------------

g_xmlParser::TextContext::TextContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_xmlParser::TextContext::CHAR() {
  return getToken(g_xmlParser::CHAR, 0);
}

g_xmlParser::TextContext* g_xmlParser::TextContext::text() {
  return getRuleContext<g_xmlParser::TextContext>(0);
}


size_t g_xmlParser::TextContext::getRuleIndex() const {
  return g_xmlParser::RuleText;
}

void g_xmlParser::TextContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterText(this);
}

void g_xmlParser::TextContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitText(this);
}


g_xmlParser::TextContext* g_xmlParser::text() {
   return text(0);
}

g_xmlParser::TextContext* g_xmlParser::text(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  g_xmlParser::TextContext *_localctx = _tracker.createInstance<TextContext>(_ctx, parentState);
  g_xmlParser::TextContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, g_xmlParser::RuleText, precedence);

    

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
    setState(94);
    match(g_xmlParser::CHAR);
    _ctx->stop = _input->LT(-1);
    setState(100);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TextContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleText);
        setState(96);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(97);
        match(g_xmlParser::CHAR); 
      }
      setState(102);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SpaceContext ------------------------------------------------------------------

g_xmlParser::SpaceContext::SpaceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t g_xmlParser::SpaceContext::getRuleIndex() const {
  return g_xmlParser::RuleSpace;
}

void g_xmlParser::SpaceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpace(this);
}

void g_xmlParser::SpaceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<g_xmlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpace(this);
}

g_xmlParser::SpaceContext* g_xmlParser::space() {
  SpaceContext *_localctx = _tracker.createInstance<SpaceContext>(_ctx, getState());
  enterRule(_localctx, 12, g_xmlParser::RuleSpace);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(g_xmlParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool g_xmlParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return textSempred(antlrcpp::downCast<TextContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool g_xmlParser::textSempred(TextContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void g_xmlParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  g_xmlParserInitialize();
#else
  ::antlr4::internal::call_once(g_xmlParserOnceFlag, g_xmlParserInitialize);
#endif
}
