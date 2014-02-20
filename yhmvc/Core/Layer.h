#ifndef YHMVC_CORE_LAYER_H_
#define YHMVC_CORE_LAYER_H_

#include "cocos2d.h"
#include "../YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class Controller;

class Layer : public cocos2d::CCLayer
{
public:

	Layer();

	~Layer();
    
	bool init();  
	
	/**
	 * layer将要显示。
	 * 由于cocos2d没有实现显示动画，即onEnterTransitionDidFinish没有实际意义。
	 * 如果要自己实现显示动画，则可以忽略onEnterTransitionDidFinish。
	 */
	void onEnter();

	void onExit();

    CREATE_FUNC(Layer);

	inline void setController(Controller* controller)
	{
		m_controller = controller;
	}

	inline Controller* getController()
	{
		return m_controller;
	}

protected:
	Controller* m_controller;

};

NS_CC_YHMVC_END

#endif // YHMVC_CORE_LAYER_H_
