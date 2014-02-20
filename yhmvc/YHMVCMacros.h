#ifndef YHMVC_YHMVCMACROS_H_
#define YHMVC_YHMVCMACROS_H_

#ifdef __cplusplus
    #define NS_CC_YHMVC_BEGIN                     namespace cocos2d { namespace yhmvc {
    #define NS_CC_YHMVC_END                       }}
    #define USING_NS_CC_YHMVC                     using namespace cocos2d::yhmvc
#else
    #define NS_CC_YHMVC_BEGIN 
    #define NS_CC_YHMVC_END 
    #define USING_NS_CC_YHMVC
#endif 

#endif //YHMVC_YHMVCMACROS_H_