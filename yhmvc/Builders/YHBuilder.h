#ifndef YHMVC_BUILDERS_YHBUILDER_H_
#define YHMVC_BUILDERS_YHBUILDER_H_

#include "Builder.h"

NS_CC_YHMVC_BEGIN

class YHBuilder : public yhmvc::Builder
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

#endif // YHMVC_BUILDERS_YHBUILDER_H_
