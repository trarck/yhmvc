#include "ThreeSegmentScene.h"
#include "Controllers/HeaderController.h"
#include "Controllers/FooterController.h"

using namespace cocos2d;

NS_MYGAME_BEGIN

void ThreeSegmentScene::loadContents()
{
    BaseScene::loadContents();
    
    HeaderController* headerController=new HeaderController();
	headerController->init();
	this->addChild(headerController->getLayer());
    
    FooterController* footerController=new FooterController();
	footerController->init();
	this->addChild(footerController->getLayer());
}

NS_MYGAME_END