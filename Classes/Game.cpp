//
//  Game.cpp
//  CCMVC
//
//  Created by duanhouhai on 13-11-1.
//
//

#include "Game.h"

#include "mvc/SceneDirector.h"

#include "Scenes/InitializeScene.h"
#include "Scenes/MainScene.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

static Game* s_gameInstance=NULL;
Game* Game::getInstance()
{
    if (!s_gameInstance) {
        s_gameInstance=new Game();
    }
    return s_gameInstance;
}

void Game::setupSceneDirector()
{
    SceneDirector::getInstance()->registerSceneCreate("initialize",SCENE_CREATE_SELECTOR(InitializeScene::create));
    SceneDirector::getInstance()->registerSceneCreate("main",SCENE_CREATE_SELECTOR(MainScene::create));
}


NS_MYGAME_END
