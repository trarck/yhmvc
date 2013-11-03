#include "ShopScene.h"
#include "Controllers/ShopController.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN
// on "init" you need to initialize your instance
void ShopScene::loadContents()
{
    BaseScene::loadContents();
    
	ShopController* shopController=new ShopController();
	shopController->init();
	this->addChild(shopController->getLayer());
    
}

NS_MYGAME_END