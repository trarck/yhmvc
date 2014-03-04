﻿#ifndef YHMVC_BUILDERS_GUIBUILDEREXTENSION_H_
#define YHMVC_BUILDERS_GUIBUILDEREXTENSION_H_

#include "cocos2d.h"
#include <yhgui/yhgui.h>
#include "../YHMVCMacros.h"
#include "../Core/Controller.h"
#include "../Core/Scene.h"

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
    
    virtual CCNode * createElement(const yhge::Json::Value& defineData);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ControllerCreator,creator);
};

//==================element property parser==================//
/**
 * @brief 子控制器属性处理
 */
class SceneControllerPropertyParser:public yhgui::PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SceneControllerPropertyParser,create);
};



NS_CC_YHMVC_END

#endif // YHMVC_BUILDERS_GUIBUILDEREXTENSION_H_
