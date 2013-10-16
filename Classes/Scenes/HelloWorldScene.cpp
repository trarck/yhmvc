#include "HelloWorldScene.h"
#include "HelloWorldController.h"

using namespace cocos2d;

// on "init" you need to initialize your instance
void HelloWorld::loadContents()
{
    BaseScene::loadContents();
    
	HelloWorldController* helloWorldController=new HelloWorldController();
	this->addChild(helloWorldController->getLayer());
       
}
