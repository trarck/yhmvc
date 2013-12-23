#include "ThreeSegmentScene2.h"
#include "Controllers/ThreeSegmentController2.h"

using namespace cocos2d;

NS_MYGAME_BEGIN

void ThreeSegmentScene2::loadContents()
{
    BaseScene::loadContents();
    
    ThreeSegmentController2* threeSegmentController2=new ThreeSegmentController2();
    threeSegmentController2->init("ThreeSegmentController");
    addLayerController(threeSegmentController2);
    threeSegmentController2->release();
    addChild(threeSegmentController2->getLayer());
}

NS_MYGAME_END