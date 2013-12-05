#include "HeaderController.h"
#include "mvc/Layer.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

HeaderController::HeaderController(void)
{
    
}


HeaderController::~HeaderController(void)
{
    
}

void HeaderController::layerDidLoad()
{
    CCSize contentSize=getPreferredContentSize();
    
    CCMenuItemLabel *startGameItem=CCMenuItemLabel::create(CCLabelTTF::create("user", "Arial", 20),
                                                      this,
                                                      menu_selector(HeaderController::showUserInfoCallback));
    startGameItem->setPosition(ccp(contentSize.width/2,contentSize.height/2));
    
    CCMenu* menu=CCMenu::create(startGameItem, NULL);
    menu->setPosition( CCPointZero );
    
    m_layer->addChild(menu);
    
//    CCLayerColor* layer1=CCLayerColor::create(ccc4(128, 255, 128, 255), contentSize.width, contentSize.height);
//    m_layer->addChild(layer1);
//
//    CCLayerColor* layer2=CCLayerColor::create(ccc4(128, 255, 255, 255), screenSize.width, 160);
//    layer2->setPosition(ccp(0.0, -160));
//    m_layer->addChild(layer2);
//    
//    CCLayerColor* layer3=CCLayerColor::create(ccc4(255, 255, 128, 255), screenSize.width, 160);
//    layer3->setPosition(ccp(0.0, -320));
//    m_layer->addChild(layer3);
//    
//    CCLayerColor* layer4=CCLayerColor::create(ccc4(128, 128, 128, 255), screenSize.width, 160);
//    layer4->setPosition(ccp(0.0, -480));
//    m_layer->addChild(layer4);
}

void HeaderController::showUserInfoCallback(CCObject* pSender)
{
    
//    GameSceneDirector::getInstance()->popScene();
}

NS_MYGAME_END