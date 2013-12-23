#include "ThreeController.h"
#include "mvc/Layer.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

ThreeController::ThreeController(void)
{
    
}


ThreeController::~ThreeController(void)
{
    CCLOG("ThreeController destroy");
}

void ThreeController::layerDidLoad()
{
    ThreeSegmentController2::layerDidLoad();
    
    //注意。layer与bodyLayer不要用混。
    
    
    CCSize contentSize=m_bodyLayer->getContentSize();
    
    CCLabelTTF* label= CCLabelTTF::create("three scene", "Arial", 20);
    label->setPosition(ccp(contentSize.width/2,contentSize.height/2));
    m_bodyLayer->addChild(label);
    
    
    CCMenuItemLabel *startGameItem=CCMenuItemLabel::create(CCLabelTTF::create("back", "Arial", 20),
                                                      this,
                                                      menu_selector(ThreeController::backCallback));
    startGameItem->setPosition(ccp(contentSize.width-200,contentSize.height/2));
    
    
    CCMenuItemLabel *next=CCMenuItemLabel::create(CCLabelTTF::create("next", "Arial", 20),
                                                  this,
                                                  menu_selector(ThreeController::nextCallback));
    next->setPosition(ccp(contentSize.width-100,contentSize.height/2));
    
    CCMenu* menu=CCMenu::create(startGameItem,next, NULL);
    menu->setPosition( CCPointZero );
    
    m_bodyLayer->addChild(menu);

}

void ThreeController::backCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->popScene();
}

void ThreeController::nextCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->replaceScene(kOneScene);
}

NS_MYGAME_END