#include "MainController.h"
#include "mvc/Layer.h"
#include "Layers/HelloLayer.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

MainController::MainController(void)
{

}


MainController::~MainController(void)
{
    CCLOG("MainController destroy");
}

void MainController::loadLayer()
{
	HelloLayer* layer=new HelloLayer();
    layer->init();
    
	setLayer(layer);
	layer->release();

	CCSize screenSize= CCDirector::sharedDirector()->getWinSize();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(MainController::menuCloseCallback) );
    pCloseItem->setPosition( ccp(screenSize.width - 20, screenSize.height/2) );
    
    CCMenuItemLabel *pRunItem=CCMenuItemLabel::create(CCLabelTTF::create("shop", "Arial", 20),
                                                      this, 
                                                      menu_selector(MainController::menuRunCallback));
    pRunItem->setPosition(ccp(screenSize.width-100,screenSize.height/2));
    
    CCMenuItemLabel *pStopItem=CCMenuItemLabel::create(CCLabelTTF::create("one", "Arial", 20),
                                                      this, 
                                                      menu_selector(MainController::menuStopCallback));
    pStopItem->setPosition(ccp(screenSize.width-200,screenSize.height/2));
    
    CCMenuItemLabel *pMoveToItem=CCMenuItemLabel::create(CCLabelTTF::create("two", "Arial", 20),
                                                       this, 
                                                       menu_selector(MainController::menuMoveToCallback));
    pMoveToItem->setPosition(ccp(screenSize.width-300,screenSize.height/2));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem,pRunItem,pStopItem,pMoveToItem, NULL);
    pMenu->setPosition( CCPointZero );
    layer->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...
    
}

void MainController::menuCloseCallback(CCObject* pSender)
{
    m_layer->removeAllChildrenWithCleanup(true);
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void MainController::menuRunCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->pushScene(kShopScene);
}

void MainController::menuStopCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->pushScene(kOneScene);
}

void MainController::menuMoveToCallback(CCObject* pSender)
{
    
}

NS_MYGAME_END