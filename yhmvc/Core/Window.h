#ifndef YHMVC_CORE_WINDOW_H_
#define YHMVC_CORE_WINDOW_H_

#include "cocos2d.h"
#include "Scene.h"

NS_CC_YHMVC_BEGIN

class Controller;

class Window : public Scene
{
    
public:
    
    Window();
    
    ~Window();
      
    CREATE_FUNC(Window);
   
    /**
     * 加载场景内容。
     * 一般是添加layer controller。由layer controller管理实际的显示内容。
     * 默认从描述文件中加载。也可以覆盖，手动创建。
     */
    virtual void loadContents();

	void setRootController(Controller* rootController);

	inline Controller* getRootController()
	{
		return m_rootController;
	}

public:
    
    static inline void setCurrentWindow(Window* currentWindow)
    {
        s_currentWindow = currentWindow;
    }
    
    static inline Window* getCurrentWindow()
    {
        return s_currentWindow;
    }
    
private:
    
    static Window* s_currentWindow;
    
	Controller* m_rootController;
};

NS_CC_YHMVC_END

#endif // YHMVC_CORE_WINDOW_H_
