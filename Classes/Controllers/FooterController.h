#ifndef __HELLOWORLD_FooterController_H__
#define __HELLOWORLD_FooterController_H__

#include "mvc/LayerController.h"
#include "mvc/Layer.h"
#include "GameMacros.h"

NS_MYGAME_BEGIN
class FooterController:public cocos2d::yhmvc::LayerController
{
public:
	
    FooterController(void);
    
	~FooterController(void);

	void layerDidLoad();

	void homeCallback(cocos2d::CCObject* pSender);
    
    void battleCallback(cocos2d::CCObject* pSender);
    
    void helpCallback(cocos2d::CCObject* pSender);
};
NS_MYGAME_END

#endif //__HELLOWORLD_FooterController_H__
