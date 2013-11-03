#include "ControllerDirector.h"
#include "../Layer.h"

NS_CC_YHMVC_BEGIN

ControllerDirector::ControllerDirector()
:m_constrollersStack(NULL)
,m_currentController(NULL)
,m_nextController(NULL)
{
    
}

ControllerDirector::~ControllerDirector()
{
	CC_SAFE_RELEASE_NULL(m_constrollersStack);
	CC_SAFE_RELEASE_NULL(m_currentController);
	m_nextController=NULL;
}

bool ControllerDirector::init()
{
	if(!LayerController::init()){
		return false;
	}
	m_constrollersStack=new CCArray();
	m_constrollersStack->init();
	return true;
}

void ControllerDirector::pushController(LayerController* controller)
{
	m_constrollersStack->addObject(controller);
	m_nextController=controller;
	setNextController();
}

void ControllerDirector::popController()
{
	int size=m_constrollersStack->count();
	//退到root controller则不能在退
	if(size>1){
		m_constrollersStack->removeLastObject();
		m_nextController=static_cast<LayerController*>(m_constrollersStack->lastObject());
		setNextController();
	}
}

void ControllerDirector::popToRootController()
{
	int size=m_constrollersStack->count();
	if(size<=1) return;
	//退到root controller则不能在退
	while(size-->1){
		m_constrollersStack->removeLastObject();
	}
	m_nextController=static_cast<LayerController*>(m_constrollersStack->lastObject());
	setNextController();
}

void ControllerDirector::replaceController(LayerController *controller)
{
	int size=m_constrollersStack->count();
	m_constrollersStack->replaceObjectAtIndex(size-1,controller);
	m_nextController=controller;
	setNextController();
}

void ControllerDirector::setNextController()
{
	if(m_currentController) m_currentController->layerWillDisappear();
	m_nextController->layerWillAppear();

	//can't use m_pLayer，becase m_pLayer may be non't create
	Layer* selfLayer=getLayer();
	
	if(m_currentController) selfLayer->removeChild(m_currentController->getLayer());
	selfLayer->addChild(m_nextController->getLayer());

	if(m_currentController) m_currentController->layerDidDisappear();
	m_nextController->layerDidAppear();

	m_currentController=m_nextController;
	m_currentController->retain();
	m_nextController=NULL;
}

NS_CC_YHMVC_END