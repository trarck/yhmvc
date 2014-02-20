#include "Scene.h"
#include "Controller.h"

NS_CC_YHMVC_BEGIN

Scene::Scene()
:m_controllers(NULL)
{
    
}

Scene::~Scene()
{
    CC_SAFE_RELEASE_NULL(m_controllers);
}

bool Scene::init()
{
    if (!CCScene::init()){
        return false;
    }
    m_controllers=new CCArray();
    m_controllers->init();
    
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

//==================child view controller=================//

/**
 * 添加一个controller
 * 没有事件仅仅作为以后用到controller做个容器
 */
void Scene::addController(Controller* controller)
{
	m_controllers->addObject(controller);
}

/**
 * 添加一个controller
 * 没有事件仅仅作为以后用到controller做个容器
 */
void Scene::addController(Controller* controller,const std::string& name)
{
	controller->setName(name);
	addController(controller);
}

/**
 * 移除一个controller
 */
void Scene::removeController(Controller* controller)
{
	m_controllers->removeObject(controller);
}

/**
 * 移除一个controller名子和name相同
 */
void Scene::removeControllerByName(const std::string& name)
{
    Controller* controller=NULL;
    
    for (int i=m_controllers->count()-1; i>=0; --i) {
        controller=static_cast<Controller*>(m_controllers->objectAtIndex(i));
        if (name.compare(controller->getName())==0) {
            m_controllers->removeObjectAtIndex(i);
        }
    }
}

/**
 * 按名子取得一个controller
 */
Controller* Scene::getControllerByName(const std::string& name)
{
    CCObject* pObj=NULL;
    Controller* controller=NULL;
    CCARRAY_FOREACH(m_controllers, pObj){
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
Controller* Scene::getDescendantControllerByName(const std::string& name)
{
    CCArray* controllers=CCArray::create();
    controllers->addObjectsFromArray(m_controllers);
    
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
 * 按名子取得controller
 */
CCArray* Scene::getControllersByName(const std::string& name)
{
    CCArray* controllers=CCArray::create();
    
    CCObject* pObj=NULL;
    Controller* controller=NULL;
    CCARRAY_FOREACH(m_controllers, pObj){
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
CCArray* Scene::getDescendantControllersByName(const std::string& name)
{
    CCArray* findControllers=CCArray::create();
    
    
    CCArray* controllers=CCArray::create();
    controllers->addObjectsFromArray(m_controllers);
    
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

NS_CC_YHMVC_END