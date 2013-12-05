#include "OneController.h"
#include "mvc/Layer.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

OneController::OneController(void)
{
    
}


OneController::~OneController(void)
{
    CCLOG("OneController destroy");
}

void OneController::layerDidLoad()
{
    CCSize contentSize=getPreferredContentSize();
    
    CCLabelTTF* label= CCLabelTTF::create("one scene", "Arial", 20);
    label->setPosition(ccp(contentSize.width/2,contentSize.height/2));
    m_layer->addChild(label);
    
    
    CCMenuItemLabel *startGameItem=CCMenuItemLabel::create(CCLabelTTF::create("back", "Arial", 20),
                                                      this,
                                                      menu_selector(OneController::backCallback));
    startGameItem->setPosition(ccp(contentSize.width-200,contentSize.height/2));
    
    
    CCMenuItemLabel *next=CCMenuItemLabel::create(CCLabelTTF::create("next", "Arial", 20),
                                                           this,
                                                           menu_selector(OneController::nextCallback));
    next->setPosition(ccp(contentSize.width-100,contentSize.height/2));
    
    CCMenu* menu=CCMenu::create(startGameItem,next, NULL);
    menu->setPosition( CCPointZero );
    
    m_layer->addChild(menu);

}

void OneController::backCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->popScene();
}

void OneController::nextCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->replaceScene(kTwoScene);
}

NS_MYGAME_END