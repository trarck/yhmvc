#ifndef __HELLOWORLD_MainController_H__
#define __HELLOWORLD_MainController_H__

#include "mvc/LayerController.h"
#include "mvc/Layer.h"

class MainController:public cocos2d::yhmvc::LayerController
{
public:
	MainController(void);
	~MainController(void);

	void loadLayer();

	void menuCloseCallback(cocos2d::CCObject* pSender);
    
    void menuRunCallback(cocos2d::CCObject* pSender);
    void menuStopCallback(cocos2d::CCObject* pSender);
    void menuMoveToCallback(cocos2d::CCObject* pSender);
};
#endif //__HELLOWORLD_MainController_H__
