#include "MainController.h"
#include "mvc/Layer.h"
#include "Layers/HelloLayer.h"

using namespace cocos2d;
using namespace cocos2d::yhmvc;

NS_MYGAME_BEGIN

MainController::MainController(void)
{

}


MainController::~MainController(void)
{
    
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
    pCloseItem->setPosition( ccp(screenSize.width - 20, 20) );
    
    CCMenuItemLabel *pRunItem=CCMenuItemLabel::create(CCLabelTTF::create("run", "Arial", 20),
                                                      this, 
                                                      menu_selector(MainController::menuRunCallback));
    pRunItem->setPosition(ccp(screenSize.width-100,20));
    
    CCMenuItemLabel *pStopItem=CCMenuItemLabel::create(CCLabelTTF::create("stop", "Arial", 20),
                                                      this, 
                                                      menu_selector(MainController::menuStopCallback));
    pStopItem->setPosition(ccp(screenSize.width-200,20));
    
    CCMenuItemLabel *pMoveToItem=CCMenuItemLabel::create(CCLabelTTF::create("moveTo", "Arial", 20),
                                                       this, 
                                                       menu_selector(MainController::menuMoveToCallback));
    pMoveToItem->setPosition(ccp(screenSize.width-300,20));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem,pRunItem,pStopItem,pMoveToItem, NULL);
    pMenu->setPosition( CCPointZero );
    layer->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...
    
}

void MainController::menuCloseCallback(CCObject* pSender)
{
    m_pLayer->removeAllChildrenWithCleanup(true);
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void MainController::menuRunCallback(CCObject* pSender)
{
//    CCDictionary* data=new CCDictionary();
//    data->setObject(CCString::create("move"), "name");
//    data->setObject(CCInteger::create(3), "direction");
//    
//    CCLOG("set begin action");
//    CCMessageManager::defaultManager()->dispatchMessageWithType(CHANGE_ANIMATION, NULL, m_player,data);
//    CCLOG("set begin action after");
    
}

void MainController::menuStopCallback(CCObject* pSender)
{
//    CCDictionary* data=new CCDictionary();
//    data->setObject(CCString::create("idle"), "name");
//    data->setObject(CCInteger::create(0), "direction");
//    
//    CCLOG("set begin action");
//    CCMessageManager::defaultManager()->dispatchMessageWithType(CHANGE_ANIMATION, NULL, m_player,data);
//    CCLOG("set begin action after");
}

void MainController::menuMoveToCallback(CCObject* pSender)
{
    CCSize screenSize= CCDirector::sharedDirector()->getWinSize();
    CCPoint to=ccp(screenSize.width/2+50,screenSize.height/2+50);
}

NS_MYGAME_END