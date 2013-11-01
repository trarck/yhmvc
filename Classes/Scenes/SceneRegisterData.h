//
//  SceneRegisterData.h
//  CCMVC
//
//  Created by duanhouhai on 13-11-1.
//
//

#ifndef CCMVC_SceneRegisterData_h
#define CCMVC_SceneRegisterData_h

#include "mvc/SceneDirector.h"

typedef struct SceneRegisterItem
{
    std::string name;
    cocos2d::yhmvc::SceneCreate createFun;
} SceneRegisterItem;

//TODO use generate tool to create this file
#include "SceneDefine.h"
#include "Scenes/InitializeScene.h"
#include "Scenes/MainScene.h"

static SceneRegisterItem kSceneRegisterData[]=
{
    {kInitializeScene,SCENE_CREATE_SELECTOR(InitializeScene::create)},
    {kMainScene,SCENE_CREATE_SELECTOR(MainScene::create)}
};


#endif
