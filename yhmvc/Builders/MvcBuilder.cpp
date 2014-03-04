#include "MvcBuilder.h"

NS_CC_YHMVC_BEGIN

MvcBuilder::MvcBuilder()
{
    
}

MvcBuilder::~MvcBuilder()
{

}

bool MvcBuilder::init()
{
    return true;
}

CCNode* MvcBuilder::buildFromFile(const std::string& filename)
{
    return NULL;
}

CCNode* MvcBuilder::buildFromFile(const std::string& filename,CCObject* parameter)
{
    return NULL;
}

CCNode* MvcBuilder::buildFromData(CCDictionary* data)
{
    return NULL;
}

CCNode* MvcBuilder::buildFromData(CCDictionary* data,CCObject* parameter)
{
    return NULL;
}

CCNode* MvcBuilder::buildFromJson(void* jsonData)
{
    return NULL;
}

CCNode* MvcBuilder::buildFromJson(void* jsonData,CCObject* parameter)
{
    return NULL;
}

NS_CC_YHMVC_END