#include "Scene.h"
#include "LayerController.h"

NS_CC_YHMVC_BEGIN

Scene::Scene()
:m_layerControllers(NULL)
{
    
}

Scene::~Scene()
{
    CC_SAFE_RELEASE_NULL(m_layerControllers);
}

bool Scene::init()
{
    if (!CCScene::init()){
        return false;
    }
    m_layerControllers=new CCArray();
    m_layerControllers->init();
    
    return true;
}

void Scene::onEnter()
{
	cocos2d::CCScene::onEnter();
    loadContents();
}

void Scene::onExit()
{
	cocos2d::CCScene::onExit();
}

void Scene::loadContents()
{

}

//==================child layer controller=================//

/**
 * 添加一个controller
 * 没有事件仅仅作为以后用到controller做个容器
 */
void Scene::addLayerController(LayerController* layerController)
{
	m_layerControllers->addObject(layerController);
}

/**
 * 添加一个controller
 * 没有事件仅仅作为以后用到controller做个容器
 */
void Scene::addLayerController(LayerController* layerController,const std::string& name)
{
	layerController->setName(name);
	addLayerController(layerController);
}

/**
 * 移除一个controller
 */
void Scene::removeLayerController(LayerController* layerController)
{
	m_layerControllers->removeObject(layerController);
}

/**
 * 移除一个controller名子和name相同
 */
void Scene::removeLayerControllerByName(const std::string& name)
{
    LayerController* layerController=NULL;
    
    for (int i=m_layerControllers->count()-1; i>=0; --i) {
        layerController=static_cast<LayerController*>(m_layerControllers->objectAtIndex(i));
        if (name.compare(layerController->getName())==0) {
            m_layerControllers->removeObjectAtIndex(i);
        }
    }
}

/**
 * 按名子取得一个controller
 */
LayerController* Scene::getLayerControllerByName(const std::string& name)
{
    CCObject* pObj=NULL;
    LayerController* layerController=NULL;
    CCARRAY_FOREACH(m_layerControllers, pObj){
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
LayerController* Scene::getDescendantLayerControllerByName(const std::string& name)
{
    CCArray* controllers=CCArray::create();
    controllers->addObjectsFromArray(m_layerControllers);
    
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
 * 按名子取得controller
 */
CCArray* Scene::getLayerControllersByName(const std::string& name)
{
    CCArray* controllers=CCArray::create();
    
    CCObject* pObj=NULL;
    LayerController* layerController=NULL;
    CCARRAY_FOREACH(m_layerControllers, pObj){
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
CCArray* Scene::getDescendantLayerControllersByName(const std::string& name)
{
    CCArray* findControllers=CCArray::create();
    
    
    CCArray* controllers=CCArray::create();
    controllers->addObjectsFromArray(m_layerControllers);
    
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

NS_CC_YHMVC_END