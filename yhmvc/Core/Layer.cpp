#include "Layer.h"
#include "Controller.h"

NS_CC_YHMVC_BEGIN

Layer::Layer()
:m_controller(NULL)
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
	if(m_controller){
		m_controller->onLayerEnter();
	}
}

void Layer::onExit()
{
	cocos2d::CCLayer::onExit();
	if(m_controller){
		m_controller->onLayerExit();
	}
}

NS_CC_YHMVC_END