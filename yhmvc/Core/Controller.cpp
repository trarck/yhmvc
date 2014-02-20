#include "Controller.h"
#include "Layer.h"

NS_CC_YHMVC_BEGIN

static const ControllerFlag kDefaultControllerFlag={0};

Controller::Controller()
:m_sDefineDataName("")
,m_layer(NULL)
,m_childControllers(NULL)
,m_parent(NULL)
,m_sName("")
,m_tState(kDefaultControllerFlag)
,m_preferredContentSize(CCSizeZero)
{
    
}

Controller::~Controller()
{
    CC_SAFE_RELEASE_NULL(m_layer);
    CC_SAFE_RELEASE_NULL(m_childControllers);
    m_parent=NULL;
}

// on "init" you need to initialize your instance
bool Controller::init()
{
    m_childControllers=new CCArray();
    m_childControllers->init();
    return true;
}

bool Controller::init(const std::string& name)
{
    m_sName=name;
    
    this->init();
    
    return true;
}

//默认从描述文件中加载
void Controller::loadLayer()
{
    if(m_sDefineDataName==""){
        //create a empty layer
        Layer* layer=new Layer();
        layer->init();
        setLayer(layer);
		layer->release();
    }else{
        //TODO load from define file

    }
}

bool Controller::isLayerLoaded()
{
    return m_tState.isLoaded;
}

void Controller::setLayer(Layer* layer)
{
    CC_SAFE_RETAIN(layer);
	if(m_layer) m_layer->setController(NULL);
    CC_SAFE_RELEASE(m_layer);
    m_layer = layer;
	if(m_layer) m_layer->setController(this);
}

Layer* Controller::getLayer()
{
    if (!m_layer) {
        this->loadLayer();
        m_tState.isLoaded=true;
        this->layerDidLoad();
    }
    return m_layer;
}

//layer.已经加载。如果是从配置文件中加载。此处提供而外操作
//比如绑定事件，修改文体内容
void Controller::layerDidLoad()
{
    
}

/**
 * 当layer的onEnter事件执行时调用
 */
void Controller::onLayerEnter()
{

}

/**
 * 当layer的onExit事件执行时调用
 */
void Controller::onLayerExit()
{

}

void Controller::layerWillAppear()
{
    
}

void Controller::layerDidAppear()
{
    
}

void Controller::layerWillDisappear()
{
    
}

void Controller::layerDidDisappear()
{
    
}

//==================child layer controller=================//

/**
 * 添加一个子controller
 */
void Controller::addChildController(Controller* controller)
{
    controller->willAddToParentController(this);
    m_childControllers->addObject(controller);
    controller->setParent(this);
    controller->didAddToParentController(this);
}

/**
 * 移除一个子controller
 */
void Controller::removeChildController(Controller* controller)
{
    controller->willRemoveFromParentController();
    m_childControllers->removeObject(controller);
    controller->setParent(NULL);
    controller->didRemoveFromParentController();
}

/**
 * 把自己从父controller中去除
 */
void Controller::removeFromParentController()
{
    if (m_parent!=NULL){
        m_parent->removeChildController(this);
    }
}

/**
 * 按名子取得一个子controller
 */
Controller* Controller::getControllerByName(const std::string& name)
{
    CCObject* pObj=NULL;
    Controller* controller=NULL;
    CCARRAY_FOREACH(m_childControllers, pObj){
        controller=static_cast<Controller*>(pObj);
        if (name.compare(controller->getName())==0) {
            return controller;
        }
    }
    return NULL;
}

/**
 * 按名子取得一个后代controller
 */
Controller* Controller::getDescendantControllerByName(const std::string& name)
{
    CCArray* controllers=CCArray::create();
    controllers->addObjectsFromArray(m_childControllers);
    
    Controller* controller=NULL;
    
    int i=0;
    for (; i<controllers->count(); ++i) {
        controller=static_cast<Controller*>(controllers->objectAtIndex(i));
        if (name.compare(controller->getName())==0) {
            break;
        }
        
        if (controller->getChildControllers()) {
            controllers->addObjectsFromArray(controller->getChildControllers());
        }
    }
    
    return i < controllers->count() ? controller:NULL;
}

/**
 * 按名子取得子controller
 */
CCArray* Controller::getControllersByName(const std::string& name)
{
    CCArray* controllers=CCArray::create();
    
    CCObject* pObj=NULL;
    Controller* controller=NULL;
    CCARRAY_FOREACH(m_childControllers, pObj){
        controller=static_cast<Controller*>(pObj);
        if (name.compare(controller->getName())==0) {
            controllers->addObject(controller);
        }
    }
    return controllers;
}

/**
 * 按名子取得后代controller
 */
CCArray* Controller::getDescendantControllersByName(const std::string& name)
{
    CCArray* findControllers=CCArray::create();
    
    
    CCArray* controllers=CCArray::create();
    controllers->addObjectsFromArray(m_childControllers);

    Controller* controller=NULL;
    
    int i=0;
    for (; i<controllers->count(); ++i) {
        controller=static_cast<Controller*>(controllers->objectAtIndex(i));
        if (name.compare(controller->getName())==0) {
            findControllers->addObject(controller);
        }
        
        if (controller->getChildControllers()) {
            controllers->addObjectsFromArray(controller->getChildControllers());
        }
    }
    
    return findControllers;
}

void Controller::willAddToParentController(Controller* parent)
{
    
}

void Controller::didAddToParentController(Controller* parent)
{
    
}

void Controller::willRemoveFromParentController()
{
    
}

void Controller::didRemoveFromParentController()
{
    
}

NS_CC_YHMVC_END