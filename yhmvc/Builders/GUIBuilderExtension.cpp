#include "GUIBuilderExtension.h"
#include "../Core/View.h"
#include "MvcBuilderConsts.h"

NS_CC_YHMVC_BEGIN

//==================element creator==================//

CCNode* ControllerCreator::createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent)
{
    return loadView(createController(), defineData, parent, builder);
}

yhmvc::View*
ControllerCreator::loadView(
                            yhmvc::Controller* controller,
                            const yhge::Json::Value& defineData,
                            CCNode* parent,yhgui::UIBuilder* builder)
{
    yhmvc::View* view=createView(defineData[yhgui::kPropertyNameProperties], parent, builder);//yhmvc::View::create(); //createView(defineData[yhgui::kPropertyNameProperties], NULL, builder);
    controller->setView(view);
    controller->viewDidLoad();
    return view;
}

yhmvc::View* ControllerCreator::createView(const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder)
{
    yhmvc::View* view=NULL;
    
    yhge::Json::Value viewValue=properties[kElementPropertyView];
    if (!viewValue.isNull()) {
        //build from define data
        //不需要加入渲染树
        view=static_cast<yhmvc::View*>(builder->buildElement(viewValue,parent,false));
        
        
    }else{
        yhge::Json::Value viewFileValue=properties[kElementPropertyViewFile];
        if (!viewFileValue.isNull()) {
            //build from include file
            //不需要加入渲染树
            view=static_cast<yhmvc::View*>(builder->buildWithJSONFile(builder->getRelationPath(viewFileValue.asString()),parent,false));
        }
    }
    
    return view;
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
            
            view=static_cast<yhmvc::View*>(builder->buildElement(controllersValue[i],node));
            scene->addController(view->getController());
            //创建的时候没有添加，这里添加
            scene->addChild(view);
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

void ControllerPreferredContentSizePropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder)
{
    float width=0.0f,height=0.0f;
    
    yhge::Json::Value preferredContentWidthValue=properties[kElementPropertyPreferredContentWidth];
    if (!preferredContentWidthValue.isNull()) {
        width=preferredContentWidthValue.asDouble();
    }
    
    yhge::Json::Value preferredContentHeightValue=properties[kElementPropertyPreferredContentHeight];
    if (!preferredContentHeightValue.isNull()) {
        height=preferredContentHeightValue.asDouble();
    }
    
    yhmvc::View* view=static_cast<yhmvc::View*>(node);
    yhmvc::Controller* controller=view->getController();
    controller->setPreferredContentSize(CCSizeMake(width, height));
}

void ControllerViewPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder)
{
//    yhmvc::View* view=NULL;
//    
//    yhge::Json::Value viewValue=properties[kElementPropertyView];
//    if (!viewValue.isNull()) {
//        //build from define data
//        view=static_cast<yhmvc::View*>(builder->buildElement(viewValue,parent));
//        //已经加入渲染树中，不需要添加
//        
//    }else{
//        yhge::Json::Value viewFileValue=properties[kElementPropertyViewFile];
//        if (!viewFileValue.isNull()) {
//            //build from include file
//            view=static_cast<yhmvc::View*>(builder->buildWithJSONFile(builder->getRelationPath(viewFileValue.asString())));
//            //由于没有加入渲染树中，则加入。
//            parent->addChild(view);
//        }
//    }
//    
//    if (view) {
//        //由于node是controller零时创建的view，如果有定义view，则使用定义的view
//        yhmvc::View* tempView=static_cast<yhmvc::View*>(node);
//        yhmvc::Controller* controller=tempView->getController();
//        
//        tempView->getParent()->addChild(view);
//        
//        tempView->removeFromParent();
//        
//        controller->setView(view);
//        controller->viewDidLoad();
//    }
}

void SubControllerPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder)
{
    yhge::Json::Value controllersValue=properties[kElementPropertyController];
    if (!controllersValue.isNull()) {
        yhmvc::View* view=static_cast<yhmvc::View*>(node);
        yhmvc::Controller* controller=view->getController();
        
        yhge::Json::Value::UInt count=controllersValue.size();
        for (int i=0;i<count;i++) {
            view=static_cast<yhmvc::View*>(builder->buildElement(controllersValue[i],node));
            controller->addChildController(view->getController());
            //已经加入渲染树
        }
    }
}

//==================element parser==================//
void SceneParser::setupPropertyParser()
{
    yhgui::NodeParser::setupPropertyParser();
    
    registerPropertyParser(kElementPropertyController, SceneControllerPropertyParser::create());
}

void ControllerParser::setupPropertyParser()
{
    yhgui::NodeParser::setupPropertyParser();
    
    registerPropertyParser(kElementPropertyName, ControllerNamePropertyParser::create());
    registerPropertyParser(kElementPropertyPreferredContentSize, ControllerPreferredContentSizePropertyParser::create());
    registerPropertyParser(kElementPropertyView, ControllerViewPropertyParser::create());
    registerPropertyParser(kElementPropertyController, SubControllerPropertyParser::create());
}

void MvcViewParser::setupPropertyParser()
{
    yhgui::NodeParser::setupPropertyParser();
}


NS_CC_YHMVC_END