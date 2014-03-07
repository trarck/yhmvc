﻿#include "MvcBuilder.h"
#include "MvcBuilderConsts.h"
#include "GUIBuilderExtension.h"

NS_CC_YHMVC_BEGIN

MvcBuilder::MvcBuilder()
{
    
}

MvcBuilder::~MvcBuilder()
{

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