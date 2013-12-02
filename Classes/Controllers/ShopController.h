#ifndef __HELLOWORLD_ShopController_H__
#define __HELLOWORLD_ShopController_H__

#include "mvc/LayerController.h"
#include "mvc/Layer.h"
#include "GameMacros.h"

NS_MYGAME_BEGIN
class ShopController:public cocos2d::yhmvc::LayerController
{
public:
	
    ShopController(void);
    
	~ShopController(void);

	void layerDidLoad();

	void backCallback(cocos2d::CCObject* pSender);
};
NS_MYGAME_END

#endif //__HELLOWORLD_ShopController_H__
