#include "MainScene.h"
#include "Controllers/MainController.h"

using namespace cocos2d;

NS_MYGAME_BEGIN

// on "init" you need to initialize your instance
void MainScene::loadContents()
{
    BaseScene::loadContents();
    
	MainController* mainController=new MainController();
	this->addChild(mainController->getLayer());
}

NS_MYGAME_END