#include "GUIBuilderExtension.h"
#include "../Core/View.h"
#include "MvcBuilderConsts.h"

NS_CC_YHMVC_BEGIN

CCNode* ControllerCreator::createElement(const yhge::Json::Value& defineData)
{
    Controller* controller=Controller::create();
    
    return controller->getView();
}

void SceneControllerPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder)
{
    
}


NS_CC_YHMVC_END