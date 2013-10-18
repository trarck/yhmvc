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

class HelloLayer:public cocos2d::yhmvc::Layer
{
    
public:
    
    HelloLayer();
    
    ~HelloLayer();
    
    bool init();
    
    void createBody();
};


#endif /* defined(__CCMVC__HelloLayer__) */
