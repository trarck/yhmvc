#include "View.h"
#include "Controller.h"

NS_CC_YHMVC_BEGIN

View::View()
:m_controller(NULL)
{

}

View::~View()
{
	
}

bool View::init()
{
    if ( !CCNode::init() )
    {
        return false;
    }

    return true;
}

void View::onEnter()
{
	cocos2d::CCNode::onEnter();
	if(m_controller){
		m_controller->onViewEnter();
	}
}

void View::onExit()
{
	cocos2d::CCNode::onExit();
	if(m_controller){
		m_controller->onViewExit();
	}
}

NS_CC_YHMVC_END