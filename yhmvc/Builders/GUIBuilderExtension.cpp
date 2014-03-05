#include "GUIBuilderExtension.h"
#include "../Core/View.h"
#include "MvcBuilderConsts.h"

NS_CC_YHMVC_BEGIN

//==================element creator==================//
CCNode* ControllerCreator::createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder)
{
    Controller* controller=Controller::create();
    
    return controller->getView();
}

//==================element property parser==================//

void SceneControllerPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder)
{
    yhge::Json::Value controllersValue=properties[kElementPropertyController];
    if (!controllersValue.isNull()) {
        yhmvc::Scene* scene=static_cast<yhmvc::Scene*>(node);
        yhmvc::View* view=NULL;
        
        yhge::Json::Value::UInt count=controllersValue.size();
        for (int i=0;i<count;i++) {
            view=static_cast<yhmvc::View*>(builder->buildElement(controllersValue[i]));
            scene->addController(view->getController());
        }
    }
    
}


void ControllerNamePropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder)
{
    yhge::Json::Value nameValue=properties[kElementPropertyName];
    if (!nameValue.isNull()) {
        yhmvc::View* view=static_cast<yhmvc::View*>(node);
        yhmvc::Controller* controller=view->getController();
        controller->setName(nameValue.asString());
    }
}

void ControllerViewPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder)
{
    yhmvc::View* view=NULL;
    
    yhge::Json::Value viewValue=properties[kElementPropertyView];
    if (!viewValue.isNull()) {
        //build from define data
        view=static_cast<yhmvc::View*>(builder->buildElement(viewValue));
        
    }else{
        yhge::Json::Value viewFileValue=properties[kElementPropertyViewFile];
        if (!viewFileValue.isNull()) {
            //build from include file
            view=static_cast<yhmvc::View*>(builder->buildWithJSONFile(viewFileValue.asCString()));
        }
    }
    
    if (view) {
        yhmvc::View* view=static_cast<yhmvc::View*>(node);
        yhmvc::Controller* controller=view->getController();
        controller->setView(view);
        controller->viewDidLoad();
    }
}

void SubControllerPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder)
{
    yhge::Json::Value controllersValue=properties[kElementPropertyController];
    if (!controllersValue.isNull()) {
        yhmvc::View* view=static_cast<yhmvc::View*>(node);
        yhmvc::Controller* controller=view->getController();
        
        yhge::Json::Value::UInt count=controllersValue.size();
        for (int i=0;i<count;i++) {
            view=static_cast<yhmvc::View*>(builder->buildElement(controllersValue[i]));
            controller->addChildController(view->getController());
        }
    }
}

NS_CC_YHMVC_END