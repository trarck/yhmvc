#include "Window.h"
#include "LayerController.h"
#include "Layer.h"

NS_CC_YHMVC_BEGIN

Window* Window::s_currentWindow=NULL;

Window::Window()
:m_rootLayerController(NULL)
{
    
}

Window::~Window()
{
    CC_SAFE_RELEASE_NULL(m_rootLayerController);
}

void Window::loadContents()
{

}

void Window::setRootLayerController(LayerController* rootLayerController)
{
	if(m_rootLayerController){
		this->removeChild(m_rootLayerController->getLayer(),true);
	}

	CC_SAFE_RETAIN(rootLayerController);
	CC_SAFE_RELEASE(m_rootLayerController);
	m_rootLayerController = rootLayerController;
	this->addChild(m_rootLayerController->getLayer());
}

NS_CC_YHMVC_END