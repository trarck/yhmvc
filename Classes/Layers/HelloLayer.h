//
//  HelloLayer.h
//  CCMVC
//
//  Created by duanhouhai on 13-10-16.
//
//

#ifndef __CCMVC__HelloLayer__
#define __CCMVC__HelloLayer__

#include "mvc/Layer.h"
#include "GameMacros.h"

NS_MYGAME_BEGIN
class HelloLayer:public cocos2d::yhmvc::Layer
{
    
public:
    
    HelloLayer();
    
    ~HelloLayer();
    
    bool init();
    
    void createBody();
};

NS_MYGAME_END

#endif /* defined(__CCMVC__HelloLayer__) */
