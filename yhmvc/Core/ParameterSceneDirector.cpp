#include "ParameterSceneDirector.h"

NS_CC_YHMVC_BEGIN

ParameterSceneDirector::ParameterSceneDirector()
{
      
}

ParameterSceneDirector::~ParameterSceneDirector()
{
}

static ParameterSceneDirector* s_ParameterSceneDirectorInstance=NULL;

ParameterSceneDirector* ParameterSceneDirector::getInstance()
{
    if (!s_ParameterSceneDirectorInstance) {
        s_ParameterSceneDirectorInstance=new ParameterSceneDirector();
        s_ParameterSceneDirectorInstance->init();
    }
    
    return s_ParameterSceneDirectorInstance;
}

/**
 * 注册一个Scene创建函数
 */
void ParameterSceneDirector::registerSceneCreate(const std::string& name,ParameterSceneCreate create)
{
    m_parameterSceneCreateMap[name]=create;
}

/**
 * 移除一个Scene创建函数
 */
void ParameterSceneDirector::removeSceneCreate(const std::string& name)
{
    std::map<std::string, ParameterSceneCreate>::iterator iter=m_parameterSceneCreateMap.find(name);
    if (iter!=m_parameterSceneCreateMap.end()) {
        m_parameterSceneCreateMap.erase(iter);
    }
}


/**
 * 使用注册的Scene创建函数，创建一个Scene
 */
yhmvc::Scene* ParameterSceneDirector::createScene(const std::string& name)
{
    std::map<std::string, ParameterSceneCreate>::iterator iter=m_parameterSceneCreateMap.find(name);
    if (iter!=m_parameterSceneCreateMap.end()) {
        ParameterSceneCreate sceneCreate=(*iter).second;
        
        return sceneCreate(NULL);//the same as (*sceneCreate)();
    }
    
    return NULL;
    
}

/**
 * 使用注册的Scene创建函数，创建一个Scene
 */
yhmvc::Scene* ParameterSceneDirector::createScene(const std::string& name,CCObject* parameter)
{
    std::map<std::string, ParameterSceneCreate>::iterator iter=m_parameterSceneCreateMap.find(name);
    if (iter!=m_parameterSceneCreateMap.end()) {
        ParameterSceneCreate sceneCreate=(*iter).second;
        
        return sceneCreate(parameter);//the same as (*sceneCreate)();
    }
    
    return NULL;
    
}


/**
 * 开始运行一个Scene,使用注册的名子
 */
void ParameterSceneDirector::runWithScene(const std::string& name,CCObject* parameter)
{
    //保存scene的名子
    m_scenes.push_back(name);
    
    m_runningScene=this->createScene(name,parameter);
    CCDirector::sharedDirector()->runWithScene(m_runningScene);
}

/**
 * 开始运行一个Scene,使用注册的名子
 */
void ParameterSceneDirector::runWithScene(const std::string& name)
{
    runWithScene(name,NULL);
}

/**
 * 叠加一个Scene。
 * 这个Scene,使用name创建一个新的Scene，并显示在最上方
 */
void ParameterSceneDirector::pushScene(const std::string& name,CCObject* parameter)
{
    //保存scene的名子
    m_scenes.push_back(name);
    
    m_runningScene=this->createScene(name,parameter);
    CCDirector::sharedDirector()->replaceScene(m_runningScene);
}

/**
 * 叠加一个Scene。
 * 这个Scene,使用name创建一个新的Scene，并显示在最上方
 */
void ParameterSceneDirector::pushScene(const std::string& name)
{
    pushScene(name,NULL);
}

/**
 * 替换一个Scene。
 * 这个Scene,使用name创建一个新的Scene，并替换当前运行的Scene
 */
void ParameterSceneDirector::replaceScene(const std::string& name,CCObject* parameter)
{
    //保存scene的名子
    m_scenes.pop_back();
    m_scenes.push_back(name);
    
    m_runningScene=this->createScene(name,parameter);
    CCDirector::sharedDirector()->replaceScene(m_runningScene);
}

/**
 * 替换一个Scene。
 * 这个Scene,使用name创建一个新的Scene，并替换当前运行的Scene
 */
void ParameterSceneDirector::replaceScene(const std::string& name)
{
    replaceScene(name,NULL);
}

/**
 * 退出当前Scene栈上的最上面的Scene,并把下面的显示出来
 */
void ParameterSceneDirector::popScene(CCObject* parameter)
{
    m_scenes.pop_back();
    
    CCAssert(m_scenes.size()>0, "ParameterSceneDirector::popScene the root poped");
    //TODO game end
    
    std::string name=m_scenes.back();
	
    m_runningScene=this->createScene(name,parameter);
    CCDirector::sharedDirector()->replaceScene(m_runningScene);
}

/**
 * 退出当前Scene栈上的最上面的Scene,并把下面的显示出来
 */
void ParameterSceneDirector::popScene()
{
    popScene(NULL);
}

/**
 * 退出到栈底,并把栈底的Scene显示出来
 */
void ParameterSceneDirector::popToRootScene(CCObject* parameter)
{
    popToSceneStackLevel(1,parameter);
}

/**
 * 退出到栈底,并把栈底的Scene显示出来
 */
void ParameterSceneDirector::popToRootScene()
{
    popToSceneStackLevel(1,NULL);
}

/**
 * 弹出栈元素，直到栈还有level个元素,并把栈顶的Scene显示出来
 */
void ParameterSceneDirector::popToSceneStackLevel(int level,CCObject* parameter)
{
    CCAssert(level>0,"ParameterSceneDirector::popToSceneStackLevel level must big zero");
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
	
    m_runningScene=this->createScene(name,parameter);
    CCDirector::sharedDirector()->replaceScene(m_runningScene);
}

/**
 * 弹出栈元素，直到栈还有level个元素,并把栈顶的Scene显示出来
 */
void ParameterSceneDirector::popToSceneStackLevel(int level)
{
    popToSceneStackLevel(level,NULL);
}

NS_CC_YHMVC_END