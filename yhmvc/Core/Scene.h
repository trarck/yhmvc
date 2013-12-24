#ifndef COCOS_YHMVC_SCENE_H_
#define COCOS_YHMVC_SCENE_H_

#include "cocos2d.h"
#include "../YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class LayerController;

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
    void addLayerController(LayerController* layerController);
    
    /**
     * 添加一个controller
     * 没有事件仅仅作为以后用到controller做个容器
     */
	void addLayerController(LayerController* layerController,const std::string& name);

    /**
     * 移除一个controller
     */
    void removeLayerController(LayerController* layerController);

    /**
     * 移除所有controller名子和name相同
     */
	void removeLayerControllerByName(const std::string& name);
    
    /**
     * 按名子取得一个controller
     */
    LayerController* getLayerControllerByName(const std::string& name);

    /**
     * 按名子取得一个后代controller
     */
    LayerController* getDescendantLayerControllerByName(const std::string& name);
    
    /**
     * 按名子取得controller
     */
    CCArray* getLayerControllersByName(const std::string& name);
    
    /**
     * 按名子取得后代controller
     */
    CCArray* getDescendantLayerControllersByName(const std::string& name);
    
private:
        
    CCArray* m_layerControllers;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_SCENE_H_
