#include "FooterController.h"
#include "mvc/Layer.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

FooterController::FooterController(void)
{
    
}


FooterController::~FooterController(void)
{
    
}

void FooterController::layerDidLoad()
{
    
    CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
    
    CCMenuItemLabel *homeItem=CCMenuItemLabel::create(CCLabelTTF::create("home", "Arial", 20),
                                                      this,
                                                      menu_selector(FooterController::homeCallback));
    homeItem->setPosition(ccp(60,20));
    
    CCMenuItemLabel *battleItem=CCMenuItemLabel::create(CCLabelTTF::create("battle", "Arial", 20),
                                                      this,
                                                      menu_selector(FooterController::battleCallback));
    battleItem->setPosition(ccp(160,20));
    
    
    CCMenuItemLabel *helpItem=CCMenuItemLabel::create(CCLabelTTF::create("help", "Arial", 20),
                                                        this,
                                                        menu_selector(FooterController::helpCallback));
    helpItem->setPosition(ccp(screenSize.width-100,20));
    
    CCMenu* menu=CCMenu::create(homeItem,battleItem,helpItem,NULL);
    
    menu->setPosition( CCPointZero );
    
    m_layer->addChild(menu);
}

void FooterController::homeCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->replaceScene(kMainScene);
}

void FooterController::battleCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->replaceScene(kMainScene);
}

void FooterController::helpCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->replaceScene(kMainScene);
}

NS_MYGAME_END