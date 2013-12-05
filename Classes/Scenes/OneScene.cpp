#include "OneScene.h"
#include "Controllers/ThreeSegmentController.h"
#include "Controllers/OneController.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN
// on "init" you need to initialize your instance
void OneScene::loadContents()
{
    ThreeSegmentScene::loadContents();
    
    ThreeSegmentController* threeSegmentController=static_cast<ThreeSegmentController*>(getLayerControllerByName("ThreeSegmentController"));
    
	OneController* oneController=new OneController();
	oneController->init();
    oneController->setPreferredContentSize(threeSegmentController->getBodyLayer()->getContentSize());
    
	threeSegmentController->getBodyLayer()->addChild(oneController->getLayer());
    addLayerController(oneController);
    oneController->release();
    
}

NS_MYGAME_END