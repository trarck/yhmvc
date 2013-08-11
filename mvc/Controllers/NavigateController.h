#ifndef COCOS_YHMVC_CONTROLLERS_NAVIGATECONTROLLER_H_
#define COCOS_YHMVC_CONTROLLERS_NAVIGATECONTROLLER_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

typedef struct {
    
    unsigned int appearState:2;
    unsigned int loadFromDefineData:1;
    unsigned int isLoaded:1;
    
    unsigned int revert:4;//just for 8 int times
    
    
} LayerControllerFlag;

class YHLayer;

class NavigateController : public CCObject
{

public:
    
    NavigateController();
    
    ~NavigateController();
     
   	/**
	 * 默认从描述文件中加载
	 */
    virtual void loadLayer();



};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_CONTROLLERS_NAVIGATECONTROLLER_H_
