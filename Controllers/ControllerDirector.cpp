#include "ControllerDirector.h"
#include "../Core/Layer.h"
#include "../Core/Window.h"

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
	m_constrollersStack=new CCArray();
	m_constrollersStack->init();
	return true;
}
/**
 * 注册一个Controller创建函数,主要用于Scene级别的controller
 */
void ControllerDirector::registerControllerCreate(const std::string& name,ControllerCreate create)
{
    m_controllerCreateMap[name]=create;
}

/**
 * 移除一个Controller创建函数
 */
void ControllerDirector::removeControllerCreate(const std::string& name)
{
    std::map<std::string, ControllerCreate>::iterator iter=m_controllerCreateMap.find(name);
    if (iter!=m_controllerCreateMap.end()) {
        m_controllerCreateMap.erase(iter);
    }
}

/**
 * 使用注册的Controller创建函数，创建一个Controller
 */
yhmvc::LayerController* ControllerDirector::createController(const std::string& name)
{
    std::map<std::string, ControllerCreate>::iterator iter=m_controllerCreateMap.find(name);
    if (iter!=m_controllerCreateMap.end()) {
        ControllerCreate controllerCreate=(*iter).second;
        
        return controllerCreate();//the same as (*sceneCreate)();
    }
    
    return NULL;
}

/**
 * 使用注册的Controller创建函数，创建一个Controller
 */
yhmvc::LayerController* ControllerDirector::createController(const std::string& name,CCObject* parameter)
{
    std::map<std::string, ControllerCreate>::iterator iter=m_controllerCreateMap.find(name);
    if (iter!=m_controllerCreateMap.end()) {
        ControllerCreate controllerCreate=(*iter).second;
        
        return controllerCreate();//the same as (*sceneCreate)();
    }
    
    return NULL;
}


/**
 * 开始运行一个Scene级controller,使用注册的名子
 */
void ControllerDirector::runWithScene(const std::string& name)
{
    m_scenes.push_back(name);
    
    yhmvc::LayerController* controller=this->createController(name);
    
   this->runWithController(controller);
}

/**
 * 叠加一个Scene级controller。
 * 这个Scene级controller是使用name创建的一个新的Scene级controller，并显示在最上方
 */
void ControllerDirector::pushScene(const std::string& name)
{
    //保存scene的名子
    m_scenes.push_back(name);
    
    yhmvc::LayerController* controller=this->createController(name);
    
    this->replaceController(controller);
}

/**
 * 替换一个Scene级controller。
 * 这个Scene级controller,使用name创建一个新的Scene级controller，并替换当前运行的Scene级controller
 */
void ControllerDirector::replaceScene(const std::string& name)
{
    //保存scene的名子
    m_scenes.pop_back();
    m_scenes.push_back(name);
    
    yhmvc::LayerController* controller=this->createController(name);
    this->replaceController(controller);
}

/**
 * 退出当前Scene级controller栈上的最上面的Scene级controller,并把下面的显示出来
 */
void ControllerDirector::popScene()
{
    m_scenes.pop_back();
    
    CCAssert(m_scenes.size()>0, "SceneDirector::popScene the root poped");
    //TODO game end
    
    std::string name=m_scenes.back();
    yhmvc::LayerController* controller=this->createController(name);
    this->replaceController(controller);
}

/**
 * 退出到栈底,并把栈底的Scene级controller显示出来
 */
void ControllerDirector::popToRootScene()
{
    popToSceneStackLevel(1);
}

/**
 * 弹出栈元素，直到栈还个level个元素,并把栈顶的Scene级controller显示出来
 */
void ControllerDirector::popToSceneStackLevel(int level)
{
    CCAssert(level>0,"SceneDirector::popToSceneStackLevel level must big zero");
    //TODO game end
    //if(level<=0){
    //
    //}
    
    int c = (int)m_scenes.size();
    
    // current level or lower -> nothing
    if (level >= c)
        return;
    
	// pop stack until reaching desired level
	while (c > level)
    {
        m_scenes.pop_back();
        c--;
    }
    
    std::string name=m_scenes.back();
    yhmvc::LayerController* controller=this->createController(name);
    this->replaceController(controller);
}


//=====================以下直接操作Scene级controller==============//

/**
 * 开始运行一个controller.各个程序运行生命周期最多只执行一次。
 */
void ControllerDirector::runWithController(LayerController* controller)
{
	pushController(controller);
}

/**
 * 新的controller位于当前controller之上。
 */
void ControllerDirector::pushController(LayerController* controller)
{
	m_constrollersStack->addObject(controller);
	m_nextController=controller;
	setNextController();
}

/**
 * 替换当前的controller用新的controller显示。
 */
void ControllerDirector::replaceController(LayerController *controller)
{
	int size=m_constrollersStack->count();
	m_constrollersStack->replaceObjectAtIndex(size-1,controller);
	m_nextController=controller;
	setNextController();
}

/**
 * 结束当前controller并用栈的下一个controller做为当前显示controller。
 */
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

/**
 * 消除controller栈内元素，直到最后一个controller，并把其显示。
 */
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

void ControllerDirector::setNextController()
{
    //下一个将要出现
    m_nextController->layerWillAppear();
    
    //当前将要消失
	if(m_currentController) m_currentController->layerWillDisappear();

	//set new root controller
	Window::getCurrentWindow()->setRootLayerController(m_nextController);

    //当前已经消失
	if(m_currentController) m_currentController->layerDidDisappear();
    
    //下一个已经出现
	m_nextController->layerDidAppear();

	m_currentController=m_nextController;
	m_currentController->retain();
	m_nextController=NULL;
}

NS_CC_YHMVC_END