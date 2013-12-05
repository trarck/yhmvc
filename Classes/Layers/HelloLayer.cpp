//
//  HelloLayer.cpp
//  CCMVC
//
//  Created by duanhouhai on 13-10-16.
//
//

#include "HelloLayer.h"
#include "cocos2d.h"

using namespace cocos2d;

USING_NS_CC;

NS_MYGAME_BEGIN

HelloLayer::HelloLayer()
{
    
}

HelloLayer::~HelloLayer()
{
    CCLOG("HelloLayer destroy");
}

bool HelloLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    createBody();
    
    return true;
}

void HelloLayer::createBody()
{
    CCLabelTTF* helloLabel=new CCLabelTTF();
    helloLabel->initWithString("hello world", "Arial", 24);
    helloLabel->setPosition(ccp(240, 320));
    
    this->addChild(helloLabel);
    
    helloLabel->release();
}

NS_MYGAME_END