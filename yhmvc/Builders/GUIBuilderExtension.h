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
    
    virtual CCNode * createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ControllerCreator,creator);

protected:
    
    yhmvc::View* createView(const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder);
    
};

/**
 * @brief controller 结点创建
 */
class MvcViewCreator:public yhgui::ElementCreator
{
public:
    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(yhmvc::View);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MvcViewCreator,creator);
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
 * @brief 控制器大小处理
 */
class ControllerPreferredContentSizePropertyParser:public yhgui::PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ControllerPreferredContentSizePropertyParser,create);
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

//==================element parser==================//

/**
 * @brief Scene的处理器
 */
class SceneParser:public yhgui::NodeParser
{
public:
    
    virtual void setupPropertyParser();
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(SceneParser,create);
};

/**
 * @brief Controller的处理器
 */
class ControllerParser:public yhgui::NodeParser
{
public:
    
    virtual void setupPropertyParser();
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(ControllerParser,create);
};

/**
 * @brief View的处理器
 */
class MvcViewParser:public yhgui::NodeParser
{
public:
    
    virtual void setupPropertyParser();
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MvcViewParser,create);
};


NS_CC_YHMVC_END

#endif // YHMVC_BUILDERS_GUIBUILDEREXTENSION_H_
