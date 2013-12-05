#include "TwoScene.h"
#include "Controllers/ThreeSegmentController2.h"
#include "Controllers/TwoController.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN
// on "init" you need to initialize your instance
void TwoScene::loadContents()
{
    ThreeSegmentScene2::loadContents();
    
    ThreeSegmentController2* threeSegmentController=static_cast<ThreeSegmentController2*>(getLayerControllerByName("ThreeSegmentController"));
    
	TwoController* twoController=new TwoController();
	twoController->init();
    twoController->setPreferredContentSize(threeSegmentController->getBodyLayer()->getContentSize());
    
	threeSegmentController->getBodyLayer()->addChild(twoController->getLayer());
    addLayerController(twoController);
    twoController->release();
    
}

NS_MYGAME_END