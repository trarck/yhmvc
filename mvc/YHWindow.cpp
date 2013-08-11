#include "YHWindow.h"
#include "YHLayerController.h"
#include "YHLayer.h"

NS_CC_YHMVC_BEGIN

YHWindow::YHWindow()
:m_rootLayerController(NULL)
{
    
}

YHWindow::~YHWindow()
{
    CC_SAFE_RELEASE_NULL(m_rootLayerController);
}

void YHWindow::loadContents()
{

}

void YHWindow::setRootLayerController(YHLayerController* rootLayerController)
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