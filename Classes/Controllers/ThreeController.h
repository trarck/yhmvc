#ifndef __HELLOWORLD_ThreeController_H__
#define __HELLOWORLD_ThreeController_H__

#include "ThreeSegmentController2.h"

NS_MYGAME_BEGIN

/**
 * 直接继承结构化控制器。
 * 容易引起误用。父类的m_layer是结构化控制器其它layer的容器。当前类中不能使用m_layer。
 */
class ThreeController:public ThreeSegmentController2
{
public:
	
    ThreeController(void);
    
	~ThreeController(void);

	void layerDidLoad();

	void backCallback(cocos2d::CCObject* pSender);
    
    void nextCallback(cocos2d::CCObject* pSender);
};
NS_MYGAME_END

#endif //__HELLOWORLD_ThreeController_H__
