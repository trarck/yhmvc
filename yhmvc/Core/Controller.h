#ifndef YHMVC_CORE_CONTROLLER_H_
#define YHMVC_CORE_CONTROLLER_H_

#include "cocos2d.h"
#include "../YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

typedef struct {
    
    unsigned int appearState:2;
    unsigned int loadFromDefineData:1;
    unsigned int isLoaded:1;
    
    unsigned int revert:4;//just for 8 int times
    
    
} ControllerFlag;

class View;

class Controller : public CCObject
{

public:
    
    Controller();
    
    ~Controller();
    
    virtual bool init();
    
    virtual bool init(const std::string& name);
     
   	/**
	 * 默认从描述文件中加载
	 */
    virtual void loadView();
    	    
	/**
	 * view是否已经加载成功
	 */
    bool isViewLoaded();
       
    void setView(View* view);
    
    View* getView();

    /**
	 * view.已经加载。如果是从配置文件中加载。此处提供而外操作
     * 比如绑定事件，修改文体内容
	 */
    virtual void viewDidLoad();    
    
	/**
	 * 当view的onEnter事件执行时调用
	 */
	virtual void onViewEnter();

	/**
	 * 当view的onExit事件执行时调用
	 */
	virtual void onViewExit();

	/**
	 * view将要显示
	 * 主要用于显示动画前的回调
	 * 如果不是直接做为scene的子结点，不会调用这4种事件。
	 * 这4种事件用法待定
	 */
    virtual void viewWillAppear();
	
	/**
	 * view显示完成
	 * 主要用于显示动画结束回调
	 * 如果没有使用动画，则会和will appear一起调用
	 */
    virtual void viewDidAppear();

	/**
	 * view将要隐藏
	 * 主要用于隐藏动画开始前回调
	 */
    virtual void viewWillDisappear();

	/**
	 * view已经被隐藏
	 * 主要用于显示动画结束回调
	 * 如果没有使用动画，则会和will disappear一起调用
	 */
    virtual void viewDidDisappear();

    //==================child view controller=================//
    
    /**
     * 添加一个子controller
     */
    virtual void addChildController(Controller* controller);

    /**
     * 移除一个子controller
     */
    virtual void removeChildController(Controller* controller);
    
    /**
     * 把自己从父controller中去除
     */
    virtual void removeFromParentController();
    
    /**
     * 按名子取得一个子controller
     */
    virtual Controller* getControllerByName(const std::string& name);
    
    /**
     * 按名子取得一个后代controller
     */
    virtual Controller* getDescendantControllerByName(const std::string& name);
    
    /**
     * 按名子取得子controller
     */
    virtual CCArray* getControllersByName(const std::string& name);
    
    /**
     * 按名子取得后代controller
     */
    virtual CCArray* getDescendantControllersByName(const std::string& name);

    virtual void willAddToParentController(Controller* parent);

    virtual void didAddToParentController(Controller* parent);
    
    virtual void willRemoveFromParentController();
    
    virtual void didRemoveFromParentController();
    
    CREATE_FUNC(Controller);
    
    //==================get set=================//
    
    inline void setViewFile(std::string viewFile)
    {
        m_viewFile = viewFile;
    }
    
    inline std::string getViewFile()
    {
        return m_viewFile;
    }

	inline void setName(const std::string& name)
	{
		m_sName = name;
	}

	inline const std::string& getName()
	{
		return m_sName;
	}

    inline void setParent(Controller* parent)
    {
        m_parent = parent;
    }
    
    inline Controller* getParent()
    {
        return m_parent;
    }
    
    inline CCArray* getChildControllers()
    {
        return m_childControllers;
    }
    
    inline void setPreferredContentSize(CCSize preferredContentSize)
    {
        m_preferredContentSize = preferredContentSize;
    }
    
    inline CCSize getPreferredContentSize()
    {
        return m_preferredContentSize;
    }

protected:
    
    ControllerFlag m_tState;
    
    std::string m_viewFile;

	std::string m_sName;
    
    View* m_view;

    CCArray* m_childControllers;
    
    Controller* m_parent;
    
    //controller希望的大小。主要用于controller相关联的view的大小。
    CCSize m_preferredContentSize;
};

NS_CC_YHMVC_END

#endif // YHMVC_CORE_CONTROLLER_H_
