//
//  Game.h
//  CCMVC
//
//  Created by duanhouhai on 13-11-1.
//
//

#ifndef __CCMVC__Game__
#define __CCMVC__Game__

#include "cocos2d.h"
#include "GameMacros.h"

NS_MYGAME_BEGIN

class Game:public CCObject
{
public:
    
    
    static Game* getInstance();
    
    void setupSceneDirector();
};

NS_MYGAME_END



#endif /* defined(__CCMVC__Game__) */
