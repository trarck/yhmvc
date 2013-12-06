#ifndef COCOS_YHMVC_CCBBuilder_H_
#define COCOS_YHMVC_CCBBuilder_H_

#include "Builder.h"
#include "cocos-ext.h"

NS_CC_YHMVC_BEGIN

/**
 * 
 * 由于没有支持controller,目前只适用分离View的管理方式
 */
 
class CCBBuilder : public yhmvc::Builder
{
    
public:
    
    CCBBuilder();
    
    ~CCBBuilder();
    
    virtual CCNode* buildFromFile(const std::string& filename);
    
    virtual CCNode* buildFromFile(const std::string& filename,CCObject* parameter);
    
protected:
    
    cocos2d::extension::CCBReader* createReader(cocos2d::extension::CCNodeLoaderLibrary* loaderLibrary);
    
    cocos2d::extension::CCBReader* createReader(cocos2d::extension::CCNodeLoaderLibrary* loaderLibrary,const char* rootPath);
    
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_CCBBuilder_H_
