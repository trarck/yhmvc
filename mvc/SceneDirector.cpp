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

/**
 * 使用注册的Scene创建函数，创建一个Scene
 */
yhmvc::Scene* SceneDirector::createScene(const std::string& name,CCObject* parameter)
{
    std::map<std::string, SceneCreate>::iterator iter=m_sceneCreateMap.find(name);
    if (iter!=m_sceneCreateMap.end()) {
        SceneCreate sceneCreate=(*iter).second;
        
        return sceneCreate();//the same as (*sceneCreate)();
    }
    
    return NULL;
    
}


/**
 * 开始运行一个Scene,使用注册的名子
 */
void SceneDirector::runWithScene(const std::string& name)
{
    //保存scene的名子
    m_scenes.push_back(name);
    
    yhmvc::Scene* scene=this->createScene(name);
    
    CCDirector::sharedDirector()->runWithScene(scene);
}

/**
 * 叠加一个Scene。
 * 这个Scene,使用name创建一个新的Scene，并显示在最上方
 */
void SceneDirector::pushScene(const std::string& name)
{
    //保存scene的名子
    m_scenes.push_back(name);
    
    yhmvc::Scene* scene=this->createScene(name);
    
    CCDirector::sharedDirector()->replaceScene(scene);
}

/**
 * 替换一个Scene。
 * 这个Scene,使用name创建一个新的Scene，并替换当前运行的Scene
 */
void SceneDirector::replaceScene(const std::string& name)
{
    //保存scene的名子
    m_scenes.pop_back();
    m_scenes.push_back(name);
    
    yhmvc::Scene* scene=this->createScene(name);
    CCDirector::sharedDirector()->replaceScene(scene);
}


/**
 * 退出当前Scene栈上的最上面的Scene,并把下面的显示出来
 */
void SceneDirector::popScene()
{
    m_scenes.pop_back();
    
    CCAssert(m_scenes.size()>0, "SceneDirector::popScene the root poped");
    //TODO game end
    
    std::string name=m_scenes.back();
    yhmvc::Scene* scene=this->createScene(name);
    CCDirector::sharedDirector()->replaceScene(scene);
}

/**
 * 退出到栈底,并把栈底的Scene显示出来
 */
void SceneDirector::popToRootScene()
{
    popToSceneStackLevel(1);
}

/**
 * 弹出栈元素，直到栈还个level个元素,并把栈顶的Scene显示出来
 */
void SceneDirector::popToSceneStackLevel(int level)
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
    yhmvc::Scene* scene=this->createScene(name);
    CCDirector::sharedDirector()->replaceScene(scene);
}

//=====================以下直接操作Scene==============//

/**
 * 开始运行一个Scene
 */
void SceneDirector::runWithSceneDirectly(yhmvc::Scene *scene)
{
    CCDirector::sharedDirector()->runWithScene(scene);
}

/**
 * 叠加一个Scene。
 */
void SceneDirector::pushSceneDirectly(yhmvc::Scene* scene)
{
    CCDirector::sharedDirector()->pushScene(scene);
}

/**
 * 替换一个Scene。
 */
void SceneDirector::replaceSceneDirectly(yhmvc::Scene *scene)
{
    CCDirector::sharedDirector()->replaceScene(scene);
}

/**
 * 退出当前Scene栈上的最上面的Scene,并把下面的显示出来
 */
void SceneDirector::popSceneDirectly()
{
    CCDirector::sharedDirector()->popScene();
}

/**
 * 退出到栈底,并把栈底的Scene显示出来
 */
void SceneDirector::popToRootSceneDirectly()
{
    popToSceneStackLevel(1);
}

/**
 * 弹出栈元素，直到栈还个level个元素,并把栈顶的Scene显示出来
 */
void SceneDirector::popToSceneStackLevelDirectly(int level)
{
    
    CCDirector::sharedDirector()->popToSceneStackLevel(level);
}


NS_CC_YHMVC_END