#ifndef YHMVC_CONTROLLERS_NAVIGATECONTROLLER_H_
#define YHMVC_CONTROLLERS_NAVIGATECONTROLLER_H_

#include "cocos2d.h"
#include "../Core/Controller.h"

NS_CC_YHMVC_BEGIN

/**
 * controller切换
 * 用于任意controller切换
 * 可被扩展带有nav bar.
 */
class NavigateController : public Controller
{
public:
    
    NavigateController();
    
    ~NavigateController();

	bool init();

    void pushController(Controller* controller);
    void popController();
    void popToRootController();
    void replaceController(Controller *controller);

	void setNextController();

	inline Controller* getCurrentController()
	{
		return m_currentController;
	}
private:
	CCArray* m_constrollersStack;

	Controller* m_currentController;
	Controller* m_nextController;
};

NS_CC_YHMVC_END

#endif // YHMVC_CONTROLLERS_NAVIGATECONTROLLER_H_
