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
#include "GameMacros.h"

typedef struct SceneRegisterItem
{
    std::string name;
    cocos2d::yhmvc::SceneCreate createFun;
} SceneRegisterItem;

//TODO use generate tool to create this file
#include "SceneDefine.h"
#include "Scenes/InitializeScene.h"
#include "Scenes/MainScene.h"
#include "Scenes/ShopScene.h"
#include "Scenes/OneScene.h"
#include "Scenes/TwoScene.h"
#include "Scenes/ThreeScene.h"

NS_MYGAME_BEGIN

static SceneRegisterItem kSceneRegisterData[]=
{
    {kInitializeScene,SCENE_CREATE_SELECTOR(InitializeScene::create)},
    {kMainScene,SCENE_CREATE_SELECTOR(MainScene::create)},
    {kShopScene,SCENE_CREATE_SELECTOR(ShopScene::create)},
    {kOneScene,SCENE_CREATE_SELECTOR(OneScene::create)},
    {kTwoScene,SCENE_CREATE_SELECTOR(TwoScene::create)},
    {kThreeScene,SCENE_CREATE_SELECTOR(ThreeScene::create)}
};

NS_MYGAME_END

#endif
