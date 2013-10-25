#include "SceneDirector.h"

NS_CC_YHMVC_BEGIN

SceneDirector::SceneDirector()
:m_scenesStack(NULL)
{
    
    
}

SceneDirector::~SceneDirector()
{

}

bool SceneDirector::init()
{
    return true;
}

static SceneDirector* s_sceneDirectorInstance=NULL;

SceneDirector* SceneDirector::getInstance()
{
    if (!s_sceneDirectorInstance) {
        s_sceneDirectorInstance=new SceneDirector();
        s_sceneDirectorInstance->init();
    }
    
    return s_sceneDirectorInstance;
}

/**
 * 注册一个Scene创建函数
 */
void SceneDirector::registerSceneCreate(const std::string& name,SceneCreate create)
{
    m_sceneCreateMap[name]=create;
}

/**
 * 移除一个Scene创建函数
 */
void SceneDirector::removeSceneCreate(const std::string& name)
{
    std::map<std::string, SceneCreate>::iterator iter=m_sceneCreateMap.find(name);
    if (iter!=m_sceneCreateMap.end()) {
        m_sceneCreateMap.erase(iter);
    }
}


/**
 * 使用注册的Scene创建函数，创建一个Scene
 */
yhmvc::Scene* SceneDirector::createScene(const std::string& name)
{
    std::map<std::string, SceneCreate>::iterator iter=m_sceneCreateMap.find(name);
    if (iter!=m_sceneCreateMap.end()) {
        SceneCreate sceneCreate=(*iter).second;
        
        return sceneCreate();//the same as (*sceneCreate)();
    }
    
    return NULL;
    
}


NS_CC_YHMVC_END