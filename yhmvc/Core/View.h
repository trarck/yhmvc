#ifndef YHMVC_CORE_VIEW_H_
#define YHMVC_CORE_VIEW_H_

#include "cocos2d.h"
#include "../YHMVCMacros.h"
#include <yhgui/Component.h>

NS_CC_YHMVC_BEGIN

class Controller;

//#ifdef USE_VIEW_FOR_COMMON
class View : public cocos2d::CCNode
//#else
//class View : public yhgui::Component
//#endif
{
public:

	View();

	~View();
    
	bool init();  
	
	/**
	 * view将要显示。
	 * 由于cocos2d没有实现显示动画，即onEnterTransitionDidFinish没有实际意义。
	 * 如果要自己实现显示动画，则可以忽略onEnterTransitionDidFinish。
	 */
	void onEnter();

	void onExit();

    CREATE_FUNC(View);

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

#endif // YHMVC_CORE_VIEW_H_
