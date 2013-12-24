#include "YHBuilder.h"

NS_CC_YHMVC_BEGIN

YHBuilder::YHBuilder()
{
    
}

YHBuilder::~YHBuilder()
{

}

bool YHBuilder::init()
{
    return true;
}

CCNode* YHBuilder::buildFromFile(const std::string& filename)
{
    return NULL;
}

CCNode* YHBuilder::buildFromFile(const std::string& filename,CCObject* parameter)
{
    return NULL;
}

CCNode* YHBuilder::buildFromData(CCDictionary* data)
{
    return NULL;
}

CCNode* YHBuilder::buildFromData(CCDictionary* data,CCObject* parameter)
{
    return NULL;
}

NS_CC_YHMVC_END