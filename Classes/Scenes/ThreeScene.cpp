#include "ThreeScene.h"
#include "Controllers/ThreeController.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN
// on "init" you need to initialize your instance
void ThreeScene::loadContents()
{
	ThreeController* threeController=new ThreeController();
	threeController->init();
    addLayerController(threeController);
    threeController->release();
    
    addChild(threeController->getLayer());
}

NS_MYGAME_END