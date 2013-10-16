#ifndef COCOS_YHMVC_WINDOW_H_
#define COCOS_YHMVC_WINDOW_H_

#include "cocos2d.h"
#include "Scene.h"

NS_CC_YHMVC_BEGIN

class LayerController;

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

	void setRootLayerController(LayerController* rootLayerController);

	inline LayerController* getRootLayerController()
	{
		return m_rootLayerController;
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
    
	LayerController* m_rootLayerController;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_WINDOW_H_
