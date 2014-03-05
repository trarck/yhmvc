#ifndef YHMVC_BUILDERS_GUIBUILDEREXTENSION_H_
#define YHMVC_BUILDERS_GUIBUILDEREXTENSION_H_

#include "cocos2d.h"
#include <yhgui/yhgui.h>
#include "../YHMVCMacros.h"
#include "../Core/Controller.h"
#include "../Core/Scene.h"
#include "../Core/View.h"

NS_CC_YHMVC_BEGIN

//==================element creator==================//

/**
 * @brief scene 结点创建
 */
class SceneCreator:public yhgui::ElementCreator
{
public:
    
    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(yhmvc::Scene);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SceneCreator,creator);
};

/**
 * @brief controller 结点创建
 */
class ControllerCreator:public yhgui::ElementCreator
{
public:
    
    virtual CCNode * createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ControllerCreator,creator);
};

//==================element property parser==================//
/**
 * @brief scene的子控制器属性处理
 */
class SceneControllerPropertyParser:public yhgui::PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SceneControllerPropertyParser,create);
};

/**
 * @brief 控制器名称处理
 */
class ControllerNamePropertyParser:public yhgui::PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ControllerNamePropertyParser,create);
};

/**
 * @brief 控制器视图处理
 */
class ControllerViewPropertyParser:public yhgui::PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ControllerViewPropertyParser,create);
};

/**
 * @brief controller的子控制器属性处理
 */
class SubControllerPropertyParser:public yhgui::PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SubControllerPropertyParser,create);
};

NS_CC_YHMVC_END

#endif // YHMVC_BUILDERS_GUIBUILDEREXTENSION_H_
