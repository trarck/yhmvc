#include "Builder.h"

NS_CC_YHMVC_BEGIN

Builder::Builder()
{
    
}

Builder::~Builder()
{

}

bool Builder::init()
{
    return true;
}

CCNode* Builder::buildFromFile(const std::string& filename)
{
    return NULL;
}


CCNode* Builder::buildFromFile(const std::string& filename,CCObject* parameter)
{
    return NULL;
}

CCNode* Builder::buildFromData(CCDictionary* data)
{
    CCAssert(false, "CCBBuilder::buildFromData not support");
    return NULL;
}

CCNode* Builder::buildFromData(CCDictionary* data,CCObject* parameter)
{
    CCAssert(false, "CCBBuilder::buildFromData not support");
    return NULL;
}


CCNode* Builder::buildFromJson(void* jsonData)
{
    CCAssert(false, "CCBBuilder::buildFromJson not support");
    return NULL;
}

CCNode* Builder::buildFromJson(void* jsonData,CCObject* parameter)
{
    CCAssert(false, "CCBBuilder::buildFromJson not support");
    return NULL;
}

NS_CC_YHMVC_END