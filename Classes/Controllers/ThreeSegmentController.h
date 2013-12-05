#ifndef __HELLOWORLD_ThreeSegmentController_H__
#define __HELLOWORLD_ThreeSegmentController_H__

#include "mvc/LayerController.h"
#include "mvc/Layer.h"
#include "GameMacros.h"

NS_MYGAME_BEGIN
class ThreeSegmentController:public cocos2d::yhmvc::LayerController
{
public:
	
    ThreeSegmentController(void);
    
	~ThreeSegmentController(void);

	void layerDidLoad();    
    
    //get setter
    
    inline yhmvc::Layer* getHeaderLayer()
    {
        return m_headerLayer;
    }
    
    inline yhmvc::Layer* getFooterLayer()
    {
        return m_footerLayer;
    }
    
    inline yhmvc::Layer* getBodyLayer()
    {
        return m_bodyLayer;
    }
    
protected:
    
    yhmvc::Layer* m_headerLayer;
    yhmvc::Layer* m_footerLayer;
    yhmvc::Layer* m_bodyLayer;
};

NS_MYGAME_END

#endif //__HELLOWORLD_ThreeSegmentController_H__
