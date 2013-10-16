#ifndef __HELLOWORLD_HELLOWORLDCONTROLLER_H__
#define __HELLOWORLD_HELLOWORLDCONTROLLER_H__

#include "mvc/LayerController.h"
#include "mvc/Layer.h"

class HelloWorldController:public cocos2d::yhmvc::LayerController
{
public:
	HelloWorldController(void);
	~HelloWorldController(void);

	void loadLayer();

	void menuCloseCallback(cocos2d::CCObject* pSender);
    
    void menuRunCallback(cocos2d::CCObject* pSender);
    void menuStopCallback(cocos2d::CCObject* pSender);
    void menuMoveToCallback(cocos2d::CCObject* pSender);
};
#endif //__HELLOWORLD_HELLOWORLDCONTROLLER_H__
