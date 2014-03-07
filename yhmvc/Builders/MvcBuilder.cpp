#include "MvcBuilder.h"
#include "MvcBuilderConsts.h"
#include "GUIBuilderExtension.h"

NS_CC_YHMVC_BEGIN

MvcBuilder::MvcBuilder()
:m_rootController(NULL)
{
    
}

MvcBuilder::~MvcBuilder()
{
    CC_SAFE_RELEASE_NULL(m_rootController);
}

bool MvcBuilder::init()
{
    if(UIBuilder::init()){
        
        setupExtend();
        
        return true;
    }
    
    return false;
}

void MvcBuilder::setupExtend()
{
    //set creator
    m_elementCreatorFactory->registerElementCreator(kElementTypeScene, SceneCreator::creator());
    m_elementCreatorFactory->registerElementCreator(kElementTypeController, ControllerCreator::creator());
    m_elementCreatorFactory->registerElementCreator(kElementTypeView, MvcViewCreator::creator());
    
    //set property parser
    m_elementParserFactory->registerElementParser(kElementTypeScene, SceneParser::create());
    m_elementParserFactory->registerElementParser(kElementTypeController, ControllerParser::create());
    m_elementParserFactory->registerElementParser(kElementTypeView, MvcViewParser::create());
}

void MvcBuilder::buildChildren(const yhge::Json::Value& children,CCNode* parent)
{
    if (!children.isNull() && parent) {
        CCNode* child=NULL;
        for (int i=0; i<children.size(); ++i) {
            child=this->buildElement(children[i],parent);
//            if (child) {
////                parent->addChild(child);
//                
//                View* view=dynamic_cast<View*>(child);
//                if (view) {
//                    if (m_rootController) {
//                        m_rootController->addChildController(view->getController());
//                    }
//                }
//            }
        }
    }
}

MvcBuilder* MvcBuilder::clone()
{
    MvcBuilder* newBuilder=new MvcBuilder();
    
    cloneProperties(newBuilder);
    
    newBuilder->autorelease();
    return newBuilder;
}

/**
 * @brief 复制属性
 */
void MvcBuilder::cloneProperties(MvcBuilder* builder)
{
    UIBuilder::cloneProperties(builder);
}

NS_CC_YHMVC_END