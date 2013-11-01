#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "BaseScene.h"

NS_MYGAME_BEGIN
class InitializeScene : public BaseScene
{
public:

    void loadContents();

    CREATE_FUNC(InitializeScene);
    
private:
    
};
NS_MYGAME_END

#endif // __HELLOWORLD_SCENE_H__
