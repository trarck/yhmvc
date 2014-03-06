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
    
    /**
     * @brief 安装扩展
     */
    virtual void setupExtend();
    
public:
    
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
