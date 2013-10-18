#include "InitializeController.h"
#include "mvc/Layer.h"

using namespace cocos2d;
using namespace cocos2d::yhmvc;

InitializeController::InitializeController(void)
{

}


InitializeController::~InitializeController(void)
{
    
}

void InitializeController::loadLayer()
{
	yhmvc::Layer* layer=new yhmvc::Layer();
    layer->init();
    
	setLayer(layer);
	layer->release();

}

void InitializeController::startGameCallback(CCObject* pSender)
{
    
}