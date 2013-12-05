#include "ThreeSegmentController2.h"
#include "mvc/Layer.h"
#include "Scenes/GameSceneDirector.h"
#include "HeaderController.h"
#include "FooterController.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

ThreeSegmentController2::ThreeSegmentController2(void)
:m_headerLayer(NULL)
,m_footerLayer(NULL)
,m_bodyLayer(NULL)
{
    m_sName="ThreeSegmentController2";
}


ThreeSegmentController2::~ThreeSegmentController2(void)
{
    
}

void ThreeSegmentController2::layerDidLoad()
{
    CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
    
    float headerHeight=60.0f,footerHeight=64.0f;
    
    float bodyHeight=screenSize.height-headerHeight-footerHeight;
    
    //create three layer

    //create header
    HeaderController* headerController=new HeaderController();
    headerController->init();
    this->addChildLayerController(headerController);
    headerController->release();
    headerController->setPreferredContentSize(CCSizeMake(screenSize.width, headerHeight));
    
    m_headerLayer=headerController->getLayer();
    m_headerLayer->setContentSize(CCSizeMake(screenSize.width, headerHeight));
    m_headerLayer->setPosition(ccp(0.0f, screenSize.height-headerHeight));
    m_layer->addChild(m_headerLayer);
    
    //create footer
    FooterController* footerController=new FooterController();
    footerController->init();
    this->addChildLayerController(footerController);
    footerController->release();
    footerController->setPreferredContentSize(CCSizeMake(screenSize.width,footerHeight));
    
    m_footerLayer=footerController->getLayer();
    m_footerLayer->setContentSize(CCSizeMake(screenSize.width,footerHeight));
    m_layer->addChild(m_footerLayer);
    
    //create body layer
    m_bodyLayer=yhmvc::Layer::create();
    m_bodyLayer->setContentSize(CCSizeMake(screenSize.width, bodyHeight));
    m_bodyLayer->setPosition(ccp(0.0f, footerHeight));
    m_layer->addChild(m_bodyLayer);

}

NS_MYGAME_END