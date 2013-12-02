#ifndef __HELLOWORLD_HeaderController_H__
#define __HELLOWORLD_HeaderController_H__

#include "mvc/LayerController.h"
#include "mvc/Layer.h"
#include "GameMacros.h"

NS_MYGAME_BEGIN
class HeaderController:public cocos2d::yhmvc::LayerController
{
public:
	
    HeaderController(void);
    
	~HeaderController(void);

	void layerDidLoad();

	void showUserInfoCallback(cocos2d::CCObject* pSender);
};
NS_MYGAME_END

#endif //__HELLOWORLD_HeaderController_H__
