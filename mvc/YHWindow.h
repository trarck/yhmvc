#ifndef COCOS_YHMVC_YHWINDOW_H_
#define COCOS_YHMVC_YHWINDOW_H_

#include "cocos2d.h"
#include "YHScene.h"

NS_CC_YHMVC_BEGIN

class YHLayerController;

class YHWindow : public YHScene
{
    
public:
    
    YHWindow();
    
    ~YHWindow();
      
    CREATE_FUNC(YHWindow);
   
    /**
     * 加载场景内容。
     * 一般是添加layer controller。由layer controller管理实际的显示内容。
     * 默认从描述文件中加载。也可以覆盖，手动创建。
     */
    virtual void loadContents();

	void setRootLayerController(YHLayerController* rootLayerController);

	inline YHLayerController* getRootLayerController()
	{
		return m_rootLayerController;
	}

private:
	YHLayerController* m_rootLayerController;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_YHWINDOW_H_
