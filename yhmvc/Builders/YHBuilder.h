#ifndef COCOS_YHMVC_YHBuilder_H_
#define COCOS_YHMVC_YHBuilder_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class YHBuilder : public cocos2d::CCObject
{
    
public:
    
    YHBuilder();
    
    ~YHBuilder();

    virtual bool init();
    
    virtual CCNode* buildFromFile(const std::string& filename);
    
    virtual CCNode* buildFromFile(const std::string& filename,CCObject* parameter);
    
    virtual CCNode* buildFromData(CCDictionary* data);

    virtual CCNode* buildFromData(CCDictionary* data,CCObject* parameter);
    
protected:

    
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_YHBuilder_H_
