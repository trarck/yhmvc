#ifndef CONTROLLERS_SHOPCONTROLLER_H_
#define CONTROLLERS_SHOPCONTROLLER_H_

#include "mvc/LayerController.h"

class ShopController:public cocos2d::yhmvc::LayerController
{
public:
	ShopController(void);
	~ShopController(void);

	void loadLayer();

	void menuCloseCallback(CCObject* pSender);
    
    void menuRunCallback(CCObject* pSender);
    void menuStopCallback(CCObject* pSender);
    void menuMoveToCallback(CCObject* pSender);
};
#endif //CONTROLLERS_SHOPCONTROLLER_H_
