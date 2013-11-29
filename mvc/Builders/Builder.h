#ifndef COCOS_YHMVC_Builder_H_
#define COCOS_YHMVC_Builder_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class Builder : public cocos2d::CCObject
{
    
public:
    
    Builder();
    
    ~Builder();

    virtual bool init();
    
    virtual CCNode* buildFromFile(const std::string& filename);
    
    virtual CCNode* buildFromFile(const std::string& filename,CCObject* parameter);
    
    virtual CCNode* buildFromData(CCDictionary* data);

    virtual CCNode* buildFromData(CCDictionary* data,CCObject* parameter);
    
    /**
     * 设置默认构建器
     */
    static void setDefaultBuilder(Builder* builder){
        s_defaultBuilder=builder;
    }
    
    static Builder* getDefaultBuilder(){
        
        return s_defaultBuilder;
    }
    
protected:
    
    static Builder* s_defaultBuilder;
    
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_Builder_H_
