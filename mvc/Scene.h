#ifndef COCOS_YHMVC_YHSCENE_H_
#define COCOS_YHMVC_YHSCENE_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

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

    void addLayerController(LayerController* layerController);
    
	void addLayerController(LayerController* layerController,const std::string& name);

    void removeLayerController(LayerController* layerController);

	void removeLayerControllerByName(const std::string& name);
    
    LayerController* getLayerControllerByName(const std::string& name);

private:
        
    CCDictionary* m_layerControllers;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_YHSCENE_H_
