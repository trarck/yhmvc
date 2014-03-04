#ifndef YHMVC_BUILDERS_MVCBUILDER_H_
#define YHMVC_BUILDERS_MVCBUILDER_H_

#include "cocos2d.h"
#include <yhgui/yhgui.h>
#include "../YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class MvcBuilder : public yhgui::UIBuilder
{
    
public:
    
    MvcBuilder();
    
    ~MvcBuilder();

    virtual bool init();
    
    virtual CCNode* buildFromFile(const std::string& filename);
    
    virtual CCNode* buildFromFile(const std::string& filename,CCObject* parameter);
    
    virtual CCNode* buildFromData(CCDictionary* data);

    virtual CCNode* buildFromData(CCDictionary* data,CCObject* parameter);
    
    virtual CCNode* buildFromJson(void* jsonData);
    
    virtual CCNode* buildFromJson(void* jsonData,CCObject* parameter);
    
    inline void setControllers(CCArray* controllers)
    {
        CC_SAFE_RETAIN(controllers);
        CC_SAFE_RELEASE(m_controllers);
        m_controllers = controllers;
    }
    
    inline CCArray* getControllers()
    {
        return m_controllers;
    }
    
protected:

    CCArray* m_controllers;
    
};

NS_CC_YHMVC_END

#endif // YHMVC_BUILDERS_MVCBUILDER_H_
