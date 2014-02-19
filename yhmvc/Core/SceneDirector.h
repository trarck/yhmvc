#ifndef COCOS_YHMVC_SCENEDIRECTOR_H_
#define COCOS_YHMVC_SCENEDIRECTOR_H_

#include "cocos2d.h"
#include "Scene.h"

NS_CC_YHMVC_BEGIN

typedef yhmvc::Scene* (*SceneCreate)() ;
#define SCENE_CREATE_SELECTOR(_SELECTOR) (cocos2d::yhmvc::SceneCreate)(&_SELECTOR)

class SceneDirector : public CCObject
{
    
public:
    
    SceneDirector();
    
    ~SceneDirector();
    
    bool init();
      
    static SceneDirector* getInstance();
    
    //=====================使用名子操作Scene==============//
    //使用名子只是一种对直接操作的一种实现，具体项目中可以被覆盖。
	
    /**
     * 注册一个Scene创建函数
     */
    void registerSceneCreate(const std::string& name,SceneCreate create);
    
    /**
     * 移除一个Scene创建函数
     */
    void removeSceneCreate(const std::string& name);
    
    /**
     * 开始运行一个Scene,使用注册的名子
     */
    void runWithScene(const std::string& name);
    
    /**
     * 叠加一个Scene。
     * 这个Scene,使用name创建一个新的Scene，并显示在最上方
     */
    void pushScene(const std::string& name);
    
    /**
     * 替换一个Scene。
     * 这个Scene,使用name创建一个新的Scene，并替换当前运行的Scene
     */
    void replaceScene(const std::string& name);
    
    /**
     * 退出当前Scene栈上的最上面的Scene,并把下面的显示出来
     */
    void popScene();
    
    /**
     * 退出到栈底,并把栈底的Scene显示出来
     */
    void popToRootScene();
    
    /**
     * 弹出栈元素，直到栈还有level个元素,并把栈顶的Scene显示出来
     */
	void popToSceneStackLevel(int level);
    
	/**
     * 获取当前Scene栈的大小
     */
	inline int getSceneStackSize(){
		return m_scenes.size();
	}

    //=====================以下直接操作Scene==============//
    
    /**
     * 开始运行一个Scene
     */
    void runWithSceneDirectly(yhmvc::Scene *scene);
    
    /**
     * 叠加一个Scene。
     */
    void pushSceneDirectly(yhmvc::Scene* scene);
    
    /**
     * 替换一个Scene。
     */
    void replaceSceneDirectly(yhmvc::Scene *scene);
    
    /**
     * 退出当前Scene栈上的最上面的Scene,并把下面的显示出来
     */
    void popSceneDirectly();
    
    /**
     * 退出到栈底,并把栈底的Scene显示出来
     */
    void popToRootSceneDirectly();
    
    /**
     * 弹出栈元素，直到栈还有level个元素,并把栈顶的Scene显示出来
     */
	void popToSceneStackLevelDirectly(int level);

	/**
     * 获取当前直接的方式操作Scene栈的大小
	 * TODO 暂不实现
     */
	inline int getSceneStackSizeDirectly(){
		return 2;
	}

	/**
     * 取得当前正在运行的Scene
	 * 由于最终完全依赖CCDirector，直接取得CCDirector的runningScene
     */
	yhmvc::Scene* getRunningScene();

protected:
    
    /**
     * 使用注册的Scene创建函数，创建一个Scene
     */
    virtual yhmvc::Scene* createScene(const std::string& name);
    
    //为了保持scene创建的简洁性，不提供带参数的创建scene的方法。
    //如果提供了带参数的方法，在处理pop scene等方法时，不好处理。
    //如果要达到传参数的目的，可以使用上下文对象。
//    virtual yhmvc::Scene* createScene(const std::string& name,CCObject* parameter);
    
protected:
    
    CCArray* m_scenesStack;
    
    std::vector<std::string> m_scenes;
    
    std::map<std::string, SceneCreate> m_sceneCreateMap;

	/**
	 * 由于scene由CCDirector保持引用计数。这里使用弱引用。
	 * 这里只作为在name regiester中保存createScene的反回结果。
	 */
	yhmvc::Scene* m_runningScene;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_SCENEDIRECTOR_H_
