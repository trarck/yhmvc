#include "ShopController.h"
#include "mvc/Layer.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

ShopController::ShopController(void)
{
    
}


ShopController::~ShopController(void)
{
    
}

void ShopController::loadLayer()
{
	yhmvc::Layer* layer=new yhmvc::Layer();
    layer->init();
    
	setLayer(layer);
	layer->release();
    
    CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
    
    CCMenuItemLabel *startGameItem=CCMenuItemLabel::create(CCLabelTTF::create("back", "Arial", 20),
                                                      this,
                                                      menu_selector(ShopController::backCallback));
    startGameItem->setPosition(ccp(screenSize.width-100,screenSize.height/2));
    
    CCMenu* menu=CCMenu::create(startGameItem, NULL);
    menu->setPosition( CCPointZero );
    
    layer->addChild(menu);

}

void ShopController::backCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->popScene();
}

NS_MYGAME_END