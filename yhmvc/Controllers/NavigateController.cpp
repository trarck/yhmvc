#include "NavigateController.h"
#include "../Core/View.h"

NS_CC_YHMVC_BEGIN

NavigateController::NavigateController()
:m_constrollersStack(NULL)
,m_currentController(NULL)
,m_nextController(NULL)
{
    
}

NavigateController::~NavigateController()
{
	CC_SAFE_RELEASE_NULL(m_constrollersStack);
	CC_SAFE_RELEASE_NULL(m_currentController);
	m_nextController=NULL;
}

bool NavigateController::init()
{
	if(!Controller::init()){
		return false;
	}
	m_constrollersStack=new CCArray();
	m_constrollersStack->init();
	return true;
}

void NavigateController::pushController(Controller* controller)
{
	m_constrollersStack->addObject(controller);
	m_nextController=controller;
	setNextController();
}

void NavigateController::popController()
{
	int size=m_constrollersStack->count();
	//退到root controller则不能在退
	if(size>1){
		m_constrollersStack->removeLastObject();
		m_nextController=static_cast<Controller*>(m_constrollersStack->lastObject());
		setNextController();
	}
}

void NavigateController::popToRootController()
{
	int size=m_constrollersStack->count();
	if(size<=1) return;
	//退到root controller则不能在退
	while(size-->1){
		m_constrollersStack->removeLastObject();
	}
	m_nextController=static_cast<Controller*>(m_constrollersStack->lastObject());
	setNextController();
}

void NavigateController::replaceController(Controller *controller)
{
	int size=m_constrollersStack->count();
	m_constrollersStack->replaceObjectAtIndex(size-1,controller);
	m_nextController=controller;
	setNextController();
}

void NavigateController::setNextController()
{
	if(m_currentController) m_currentController->viewWillDisappear();
	m_nextController->viewWillAppear();

	//can't use m_pView，becase m_pView may be non't create
	View* selfView=getView();
	
	if(m_currentController) selfView->removeChild(m_currentController->getView());
	selfView->addChild(m_nextController->getView());

	if(m_currentController) m_currentController->viewDidDisappear();
	m_nextController->viewDidAppear();

	m_currentController=m_nextController;
	m_currentController->retain();
	m_nextController=NULL;
}

NS_CC_YHMVC_END