#include "Layer.h"
#include "LayerController.h"

NS_CC_YHMVC_BEGIN

Layer::Layer()
:m_layerController(NULL)
{

}

Layer::~Layer()
{
	
}

bool Layer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

    return true;
}

void Layer::onEnter()
{
	cocos2d::CCLayer::onEnter();
	if(m_layerController){
		m_layerController->onLayerEnter();
	}
}

void Layer::onExit()
{
	cocos2d::CCLayer::onExit();
	if(m_layerController){
		m_layerController->onLayerExit();
	}
}

NS_CC_YHMVC_END