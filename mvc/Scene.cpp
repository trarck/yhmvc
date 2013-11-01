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
    m_layerControllers=new CCDictionary();
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

void Scene::addLayerController(LayerController* layerController)
{
//	addLayerController(layerController,layerController->getName().c_str());
	m_layerControllers->setObject(layerController,layerController->getName());
//    addChild(layerController->getLayer());
//    m_layerControllers->addObject(layerController);
//	layerController->layerWillAppear();
//    layerController->layerDidAppear();
}

void Scene::addLayerController(LayerController* layerController,const std::string& name)
{
	layerController->setName(name);
	addLayerController(layerController);
}

void Scene::removeLayerController(LayerController* layerController)
{
	removeLayerControllerByName(layerController->getName());
//	layerController->layerWillDisappear();
//    removeChild(layerController->getLayer());
//    m_layerControllers->removeObject(layerController);
//    layerController->layerDidDisappear();
}

void Scene::removeLayerControllerByName(const std::string& name)
{
	m_layerControllers->removeObjectForKey(name);
}

LayerController* Scene::getLayerControllerByName(const std::string& name)
{
    return static_cast<LayerController*>(m_layerControllers->objectForKey(name));
}

NS_CC_YHMVC_END