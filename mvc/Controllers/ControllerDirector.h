#ifndef COCOS_YHMVC_CONTROLLERS_ControllerDirector_H_
#define COCOS_YHMVC_CONTROLLERS_ControllerDirector_H_

#include "cocos2d.h"
#include "../LayerController.h"

NS_CC_YHMVC_BEGIN

/**
 * controller切换
 * 主要用于场景级别的controller切换
 * 可能会被具体使用扩展
 */
class ControllerDirector : public LayerController
{
public:
    
    ControllerDirector();
    
    ~ControllerDirector();

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

#endif // COCOS_YHMVC_CONTROLLERS_ControllerDirector_H_
