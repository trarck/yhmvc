#include "MainScene.h"
#include "Controllers/MainController.h"

using namespace cocos2d;

// on "init" you need to initialize your instance
void MainScene::loadContents()
{
    BaseScene::loadContents();
    
	MainController* mainController=new MainController();
	this->addChild(mainController->getLayer());
}
