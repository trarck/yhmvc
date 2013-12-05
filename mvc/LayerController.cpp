#include "LayerController.h"
#include "Layer.h"

NS_CC_YHMVC_BEGIN

static const LayerControllerFlag kDefaultLayerControllerFlag={0};

LayerController::LayerController()
:m_sDefineDataName("")
,m_layer(NULL)
,m_childLayerControllers(NULL)
,m_parent(NULL)
,m_sName("")
,m_tState(kDefaultLayerControllerFlag)
,m_preferredContentSize(CCSizeZero)
{
    
}

LayerController::~LayerController()
{
    CC_SAFE_RELEASE_NULL(m_layer);
    CC_SAFE_RELEASE_NULL(m_childLayerControllers);
    m_parent=NULL;
}

// on "init" you need to initialize your instance
bool LayerController::init()
{
    m_childLayerControllers=new CCArray();
    m_childLayerControllers->init();
    return true;
}

bool LayerController::init(const std::string& name)
{
    m_sName=name;
    
    this->init();
    
    return true;
}

//默认从描述文件中加载
void LayerController::loadLayer()
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

bool LayerController::isLayerLoaded()
{
    return m_tState.isLoaded;
}

void LayerController::setLayer(Layer* layer)
{
    CC_SAFE_RETAIN(layer);
	if(m_layer) m_layer->setLayerController(NULL);
    CC_SAFE_RELEASE(m_layer);
    m_layer = layer;
	if(m_layer) m_layer->setLayerController(this);
}

Layer* LayerController::getLayer()
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
void LayerController::layerDidLoad()
{
    
}

/**
 * 当layer的onEnter事件执行时调用
 */
void LayerController::onLayerEnter()
{

}

/**
 * 当layer的onExit事件执行时调用
 */
void LayerController::onLayerExit()
{

}

void LayerController::layerWillAppear()
{
    
}

void LayerController::layerDidAppear()
{
    
}

void LayerController::layerWillDisappear()
{
    
}

void LayerController::layerDidDisappear()
{
    
}

//==================child layer controller=================//

/**
 * 添加一个子controller
 */
void LayerController::addChildLayerController(LayerController* layerController)
{
    layerController->willAddToParentLayerController(this);
    m_childLayerControllers->addObject(layerController);
    layerController->setParent(this);
    layerController->didAddToParentLayerController(this);
}

/**
 * 移除一个子controller
 */
void LayerController::removeChildLayerController(LayerController* layerController)
{
    layerController->willRemoveFromParentLayerController();
    m_childLayerControllers->removeObject(layerController);
    layerController->setParent(NULL);
    layerController->didRemoveFromParentLayerController();
}

/**
 * 把自己从父controller中去除
 */
void LayerController::removeFromParentLayerController()
{
    if (m_parent!=NULL){
        m_parent->removeChildLayerController(this);
    }
}

/**
 * 按名子取得一个子controller
 */
LayerController* LayerController::getLayerControllerByName(const std::string& name)
{
    CCObject* pObj=NULL;
    LayerController* layerController=NULL;
    CCARRAY_FOREACH(m_childLayerControllers, pObj){
        layerController=static_cast<LayerController*>(pObj);
        if (name.compare(layerController->getName())==0) {
            return layerController;
        }
    }
    return NULL;
}

/**
 * 按名子取得一个后代controller
 */
LayerController* LayerController::getDescendantLayerControllerByName(const std::string& name)
{
    CCArray* controllers=CCArray::create();
    controllers->addObjectsFromArray(m_childLayerControllers);
    
    LayerController* layerController=NULL;
    
    int i=0;
    for (; i<controllers->count(); ++i) {
        layerController=static_cast<LayerController*>(controllers->objectAtIndex(i));
        if (name.compare(layerController->getName())==0) {
            break;
        }
        
        if (layerController->getChildLayerControllers()) {
            controllers->addObjectsFromArray(layerController->getChildLayerControllers());
        }
    }
    
    return i < controllers->count() ? layerController:NULL;
}

/**
 * 按名子取得子controller
 */
CCArray* LayerController::getLayerControllersByName(const std::string& name)
{
    CCArray* controllers=CCArray::create();
    
    CCObject* pObj=NULL;
    LayerController* layerController=NULL;
    CCARRAY_FOREACH(m_childLayerControllers, pObj){
        layerController=static_cast<LayerController*>(pObj);
        if (name.compare(layerController->getName())==0) {
            controllers->addObject(layerController);
        }
    }
    return controllers;
}

/**
 * 按名子取得后代controller
 */
CCArray* LayerController::getDescendantLayerControllersByName(const std::string& name)
{
    CCArray* findControllers=CCArray::create();
    
    
    CCArray* controllers=CCArray::create();
    controllers->addObjectsFromArray(m_childLayerControllers);

    LayerController* layerController=NULL;
    
    int i=0;
    for (; i<controllers->count(); ++i) {
        layerController=static_cast<LayerController*>(controllers->objectAtIndex(i));
        if (name.compare(layerController->getName())==0) {
            findControllers->addObject(layerController);
        }
        
        if (layerController->getChildLayerControllers()) {
            controllers->addObjectsFromArray(layerController->getChildLayerControllers());
        }
    }
    
    return findControllers;
}

void LayerController::willAddToParentLayerController(LayerController* parent)
{
    
}

void LayerController::didAddToParentLayerController(LayerController* parent)
{
    
}

void LayerController::willRemoveFromParentLayerController()
{
    
}

void LayerController::didRemoveFromParentLayerController()
{
    
}

NS_CC_YHMVC_END