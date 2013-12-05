#include "TwoController.h"
#include "mvc/Layer.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

TwoController::TwoController(void)
{
    
}


TwoController::~TwoController(void)
{
    CCLOG("TwoController destroy");
}

void TwoController::layerDidLoad()
{
    CCSize contentSize=getPreferredContentSize();
    
    CCLabelTTF* label= CCLabelTTF::create("two scene", "Arial", 20);
    label->setPosition(ccp(contentSize.width/2,contentSize.height/2));
    m_layer->addChild(label);
    
    
    CCMenuItemLabel *startGameItem=CCMenuItemLabel::create(CCLabelTTF::create("back", "Arial", 20),
                                                      this,
                                                      menu_selector(TwoController::backCallback));
    startGameItem->setPosition(ccp(contentSize.width-200,contentSize.height/2));
    
    
    CCMenuItemLabel *next=CCMenuItemLabel::create(CCLabelTTF::create("next", "Arial", 20),
                                                  this,
                                                  menu_selector(TwoController::nextCallback));
    next->setPosition(ccp(contentSize.width-100,contentSize.height/2));
    
    CCMenu* menu=CCMenu::create(startGameItem,next,NULL);
    menu->setPosition( CCPointZero );
    
    m_layer->addChild(menu);

}

void TwoController::backCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->popScene();
}

void TwoController::nextCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->replaceScene(kThreeScene);
}

NS_MYGAME_END