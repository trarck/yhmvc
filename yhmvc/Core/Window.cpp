#include "Window.h"
#include "Controller.h"
#include "Layer.h"

NS_CC_YHMVC_BEGIN

Window* Window::s_currentWindow=NULL;

Window::Window()
:m_rootController(NULL)
{
    
}

Window::~Window()
{
    CC_SAFE_RELEASE_NULL(m_rootController);
}

void Window::loadContents()
{

}

void Window::setRootController(Controller* rootController)
{
	if(m_rootController){
		this->removeChild(m_rootController->getLayer(),true);
	}

	CC_SAFE_RETAIN(rootController);
	CC_SAFE_RELEASE(m_rootController);
	m_rootController = rootController;
	this->addChild(m_rootController->getLayer());
}

NS_CC_YHMVC_END