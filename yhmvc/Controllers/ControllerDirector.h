#ifndef COCOS_YHMVC_CONTROLLERS_ControllerDirector_H_
#define COCOS_YHMVC_CONTROLLERS_ControllerDirector_H_

#include "cocos2d.h"
#include "../Core/LayerController.h"

NS_CC_YHMVC_BEGIN

typedef yhmvc::LayerController* (*ControllerCreate)() ;
#define CONTROLLER_CREATE_SELECTOR(_SELECTOR) (cocos2d::yhmvc::ControllerCreate)(&_SELECTOR)

/**
 * controller切换
 * 主要用于场景级别的controller切换。即current window的root controller
 * 可能会被具体使用扩展
 */
class ControllerDirector : public CCObject
{
public:
    
    ControllerDirector();
    
    ~ControllerDirector();

	bool init();

    //=====================使用名子操作Scene级controller==============//
    //使用名子只是一种对直接操作controller的一种实现，具体项目中可以被覆盖。
    
    /**
     * 注册一个Controller创建函数,主要用于Scene级别的controller
     */
    void registerControllerCreate(const std::string& name,ControllerCreate create);
    
    /**
     * 移除一个Controller创建函数
     */
    void removeControllerCreate(const std::string& name);

    /**
     * 开始运行一个Scene级controller,使用注册的名子
     */
    void runWithScene(const std::string& name);
    
    /**
     * 叠加一个Scene级controller。
     * 这个Scene级controller是使用name创建的一个新的Scene级controller，并显示在最上方
     */
    void pushScene(const std::string& name);
    
    /**
     * 替换一个Scene级controller。
     * 这个Scene级controller,使用name创建一个新的Scene级controller，并替换当前运行的Scene级controller
     */
    void replaceScene(const std::string& name);
    
    /**
     * 退出当前Scene级controller栈上的最上面的Scene级controller,并把下面的显示出来
     */
    void popScene();
    
    /**
     * 退出到栈底,并把栈底的Scene级controller显示出来
     */
    void popToRootScene();
    
    /**
     * 弹出栈元素，直到栈还个level个元素,并把栈顶的Scene级controller显示出来
     */
	void popToSceneStackLevel(int level);
    
    //=====================以下直接操作Scene级controller==============//
    
	/**
     * 开始运行一个controller.各个程序运行生命周期最多只执行一次。
     */
    void runWithController(LayerController* controller);
	
	/**
     * 新的controller位于当前controller之上。
     */
    void pushController(LayerController* controller);

	/**
     * 结束当前controller并用栈的下一个controller做为当前显示controller。
     */
    void popController();

	/**
     * 替换当前的controller用新的controller显示。
     */
    void replaceController(LayerController *controller);

	/**
     * 消除controller栈内元素，直到最后一个controller，并把其显示。
     */
    void popToRootController();

	void setNextController();

	inline LayerController* getCurrentController()
	{
		return m_currentController;
	}
    
protected:
    
    /**
     * 使用注册的Controller创建函数，创建一个Controller
     */
    yhmvc::LayerController* createController(const std::string& name);
    
    yhmvc::LayerController* createController(const std::string& name,CCObject* parameter);
    
private:
	CCArray* m_constrollersStack;

	LayerController* m_currentController;
	LayerController* m_nextController;
    
    std::vector<std::string> m_scenes;
    
    std::map<std::string, ControllerCreate> m_controllerCreateMap;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_CONTROLLERS_ControllerDirector_H_
