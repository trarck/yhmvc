#ifndef COCOS_YHMVC_CONTROLLERS_NAVIGATECONTROLLER_H_
#define COCOS_YHMVC_CONTROLLERS_NAVIGATECONTROLLER_H_

#include "cocos2d.h"
#include "../Core/LayerController.h"

NS_CC_YHMVC_BEGIN

/**
 * controller切换
 * 用于任意controller切换
 * 可被扩展带有nav bar.
 */
class NavigateController : public LayerController
{
public:
    
    NavigateController();
    
    ~NavigateController();

	bool init();

    void pushController(LayerController* controller);
    void popController();
    void popToRootController();
    void replaceController(LayerController *controller);

	void setNextController();

	inline LayerController* getCurrentController()
	{
		return m_currentController;
	}
private:
	CCArray* m_constrollersStack;

	LayerController* m_currentController;
	LayerController* m_nextController;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_CONTROLLERS_NAVIGATECONTROLLER_H_
