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

void HeaderController::loadLayer()
{
	yhmvc::Layer* layer=new yhmvc::Layer();
    layer->init();
    
	setLayer(layer);
	layer->release();
    
    CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
    
    CCMenuItemLabel *startGameItem=CCMenuItemLabel::create(CCLabelTTF::create("user", "Arial", 20),
                                                      this,
                                                      menu_selector(HeaderController::showUserInfoCallback));
    startGameItem->setPosition(ccp(20,screenSize.height-20));
    
    CCMenu* menu=CCMenu::create(startGameItem, NULL);
    menu->setPosition( CCPointZero );
    
    layer->addChild(menu);

}

void HeaderController::showUserInfoCallback(CCObject* pSender)
{
    
//    GameSceneDirector::getInstance()->popScene();
}

NS_MYGAME_END