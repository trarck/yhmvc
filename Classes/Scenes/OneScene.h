#ifndef __HELLOWORLD_OneScene_H__
#define __HELLOWORLD_OneScene_H__

#include "ThreeSegmentScene.h"

NS_MYGAME_BEGIN

class OneScene : public ThreeSegmentScene
{
public:

    void loadContents();

    CREATE_FUNC(OneScene);
    
private:
    
};
NS_MYGAME_END

#endif // __HELLOWORLD_SCENE_H__
