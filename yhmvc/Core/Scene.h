#ifndef YHMVC_CORE_SCENE_H_
#define YHMVC_CORE_SCENE_H_

#include "cocos2d.h"
#include "../YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class Controller;

class Scene : public cocos2d::CCScene
{
    
public:
    
    Scene();
    
    ~Scene();

    bool init();
      
    CREATE_FUNC(Scene);
    
    virtual void onEnter();
    
    virtual void onExit();
    
    /**
     * 加载场景内容。
     * 一般是添加layer controller。由layer controller管理实际的显示内容。
     * 默认从描述文件中加载。也可以覆盖，手动创建。
     */
    virtual void loadContents();

    //==================child layer controller=================//
    
    /**
     * 添加一个controller
     * 没有事件仅仅作为以后用到controller做个容器
     */
    void addController(Controller* controller);
    
    /**
     * 添加一个controller
     * 没有事件仅仅作为以后用到controller做个容器
     */
	void addController(Controller* controller,const std::string& name);

    /**
     * 移除一个controller
     */
    void removeController(Controller* controller);

    /**
     * 移除所有controller名子和name相同
     */
	void removeControllerByName(const std::string& name);
    
    /**
     * 按名子取得一个controller
     */
    Controller* getControllerByName(const std::string& name);

    /**
     * 按名子取得一个后代controller
     */
    Controller* getDescendantControllerByName(const std::string& name);
    
    /**
     * 按名子取得controller
     */
    CCArray* getControllersByName(const std::string& name);
    
    /**
     * 按名子取得后代controller
     */
    CCArray* getDescendantControllersByName(const std::string& name);
    
    inline void setContext(CCObject* context)
    {
        CC_SAFE_RETAIN(context);
        CC_SAFE_RELEASE(m_context);
        m_context = context;
    }
    
    inline CCObject* getContext()
    {
        return m_context;
    }
    
private:
    
    /**
     * 包含的controllers
     */
    CCArray* m_controllers;
    
    /**
     * 上下文
     * 主要用于scene向scene传递数据。
     */
    CCObject* m_context;
};

NS_CC_YHMVC_END

#endif // YHMVC_CORE_SCENE_H_
