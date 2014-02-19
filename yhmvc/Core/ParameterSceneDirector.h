#ifndef YHMVC_CORE_PARAMETERSCENEDIRECTOR_H_
#define YHMVC_CORE_PARAMETERSCENEDIRECTOR_H_

#include "cocos2d.h"
#include "SceneDirector.h"

NS_CC_YHMVC_BEGIN

typedef yhmvc::Scene* (*ParameterSceneCreate)(CCObject* param) ;
#define PARAMETER_SCENE_CREATE_SELECTOR(_SELECTOR) (cocos2d::yhmvc::ParameterSceneCreate)(&_SELECTOR)

class ParameterSceneDirector : public SceneDirector
{
    
public:
    
    ParameterSceneDirector();
    
    ~ParameterSceneDirector();
      
    static ParameterSceneDirector* getInstance();
    
    //=====================使用名子操作Scene==============//
    //使用名子只是一种对直接操作的一种实现，具体项目中可以被覆盖。
	
    /**
     * 注册一个Scene创建函数
     */
    virtual void registerSceneCreate(const std::string& name,ParameterSceneCreate create);
    
    /**
     * 移除一个Scene创建函数
     */
    virtual void removeSceneCreate(const std::string& name);
    
    /**
     * 开始运行一个Scene,使用注册的名子
     */
    void runWithScene(const std::string& name,CCObject* parameter);
	
   /**
    * 开始运行一个Scene,使用注册的名子
    */
   void runWithScene(const std::string& name);
    
    /**
     * 叠加一个Scene。
     * 这个Scene,使用name创建一个新的Scene，并显示在最上方
     */
    void pushScene(const std::string& name,CCObject* parameter);
	
   /**
    * 叠加一个Scene。
    * 这个Scene,使用name创建一个新的Scene，并显示在最上方
    */
   void pushScene(const std::string& name);
    
    /**
     * 替换一个Scene。
     * 这个Scene,使用name创建一个新的Scene，并替换当前运行的Scene
     */
    void replaceScene(const std::string& name,CCObject* parameter);
	
   /**
    * 替换一个Scene。
    * 这个Scene,使用name创建一个新的Scene，并替换当前运行的Scene
    */
   void replaceScene(const std::string& name);
    
    /**
     * 退出当前Scene栈上的最上面的Scene,并把下面的显示出来
     */
    void popScene(CCObject* parameter);
	
   /**
    * 退出当前Scene栈上的最上面的Scene,并把下面的显示出来
    */
   void popScene();
    
    /**
     * 退出到栈底,并把栈底的Scene显示出来
     */
    void popToRootScene(,CCObject* parameter);
	
   /**
    * 退出到栈底,并把栈底的Scene显示出来
    */
   void popToRootScene();
    
    /**
     * 弹出栈元素，直到栈还有level个元素,并把栈顶的Scene显示出来
     */
	void popToSceneStackLevel(int level,CCObject* parameter);

   /**
    * 弹出栈元素，直到栈还有level个元素,并把栈顶的Scene显示出来
    */
	void popToSceneStackLevel(int level);


protected:
    
    /**
     * 使用注册的Scene创建函数，创建一个Scene
     */
    virtual yhmvc::Scene* createScene(const std::string& name);
    
    virtual yhmvc::Scene* createScene(const std::string& name,CCObject* parameter);
    
protected:
    
    std::map<std::string, ParameterSceneCreate> m_parameterSceneCreateMap;
};

NS_CC_YHMVC_END

#endif // YHMVC_CORE_PARAMETERSCENEDIRECTOR_H_
