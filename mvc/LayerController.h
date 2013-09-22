#ifndef COCOS_YHMVC_YHLAYERCONTROLLER_H_
#define COCOS_YHMVC_YHLAYERCONTROLLER_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

typedef struct {
    
    unsigned int appearState:2;
    unsigned int loadFromDefineData:1;
    unsigned int isLoaded:1;
    
    unsigned int revert:4;//just for 8 int times
    
    
} LayerControllerFlag;

class Layer;

class LayerController : public CCObject
{

public:
    
    LayerController();
    
    ~LayerController();
    
    virtual bool init();
     
   	/**
	 * 默认从描述文件中加载
	 */
    virtual void loadLayer();
    	    
	/**
	 * layer是否已经加载成功
	 */
    bool isLayerLoaded();
       
    void setLayer(Layer* layer);
    
    Layer* getLayer();

    /**
	 * layer.已经加载。如果是从配置文件中加载。此处提供而外操作
     * 比如绑定事件，修改文体内容
	 */
    virtual void layerDidLoad();    
    
	/**
	 * 当layer的onEnter事件执行时调用
	 */
	virtual void onLayerEnter();

	/**
	 * 当layer的onExit事件执行时调用
	 */
	virtual void onLayerExit();

	/**
	 * layer将要显示
	 * 主要用于显示动画前的回调
	 * 如果不是直接做为scene的子结点，不会调用这4种事件。
	 * 这4种事件用法待定
	 */
    virtual void layerWillAppear();
	
	/**
	 * layer显示完成
	 * 主要用于显示动画结束回调
	 * 如果没有使用动画，则会和will appear一起调用
	 */
    virtual void layerDidAppear();

	/**
	 * layer将要隐藏
	 * 主要用于隐藏动画开始前回调
	 */
    virtual void layerWillDisappear();

	/**
	 * layer已经被隐藏
	 * 主要用于显示动画结束回调
	 * 如果没有使用动画，则会和will disappear一起调用
	 */
    virtual void layerDidDisappear();

    //==================child layer controller=================//
    virtual void addChildLayerController(LayerController* layerController);

    virtual void removeChildLayerController(LayerController* layerController);
    
    virtual void removeFromParentLayerController();
    
    virtual LayerController* getLayerControllerByName(const std::string& name);

    virtual void willAddToParentLayerController(LayerController* parent);

    virtual void didAddToParentLayerController(LayerController* parent);
    
    virtual void willRemoveFromParentLayerController();
    
    virtual void didRemoveFromParentLayerController();
    
	inline void setDefineDataName(const std::string& defineDataName)
	{
		m_sDefineDataName = defineDataName;
	}

	inline const std::string& getDefineDataName()
	{
		return m_sDefineDataName;
	}

	inline void setName(const std::string& name)
	{
		m_sName = name;
	}

	inline const std::string& getName()
	{
		return m_sName;
	}

    inline void setParent(LayerController* parent)
    {
        m_parent = parent;
    }
    
    inline LayerController* getParent()
    {
        return m_parent;
    }

protected:
    
    LayerControllerFlag m_tState;
    
    std::string m_sDefineDataName;

	std::string m_sName;
    
    Layer* m_pLayer;

    CCArray* m_childLayerControllers;
    
    LayerController* m_parent;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_YHLAYERCONTROLLER_H_
