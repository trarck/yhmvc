#ifndef COCOS_YHMVC_LAYERCONTROLLER_H_
#define COCOS_YHMVC_LAYERCONTROLLER_H_

#include "cocos2d.h"
#include "../YHMVCMacros.h"

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
    
    virtual bool init(const std::string& name);
     
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
    
    /**
     * 添加一个子controller
     */
    virtual void addChildLayerController(LayerController* layerController);

    /**
     * 移除一个子controller
     */
    virtual void removeChildLayerController(LayerController* layerController);
    
    /**
     * 把自己从父controller中去除
     */
    virtual void removeFromParentLayerController();
    
    /**
     * 按名子取得一个子controller
     */
    virtual LayerController* getLayerControllerByName(const std::string& name);
    
    /**
     * 按名子取得一个后代controller
     */
    virtual LayerController* getDescendantLayerControllerByName(const std::string& name);
    
    /**
     * 按名子取得子controller
     */
    virtual CCArray* getLayerControllersByName(const std::string& name);
    
    /**
     * 按名子取得后代controller
     */
    virtual CCArray* getDescendantLayerControllersByName(const std::string& name);

    virtual void willAddToParentLayerController(LayerController* parent);

    virtual void didAddToParentLayerController(LayerController* parent);
    
    virtual void willRemoveFromParentLayerController();
    
    virtual void didRemoveFromParentLayerController();
    
    //==================get set=================//
    
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
    
    inline CCArray* getChildLayerControllers()
    {
        return m_childLayerControllers;
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
    
    LayerControllerFlag m_tState;
    
    std::string m_sDefineDataName;

	std::string m_sName;
    
    Layer* m_layer;

    CCArray* m_childLayerControllers;
    
    LayerController* m_parent;
    
    //controller希望的大小。主要用于controller相关联的layer的大小。
    CCSize m_preferredContentSize;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_LAYERCONTROLLER_H_
