#ifndef __HELLOWORLD_TwoScene_H__
#define __HELLOWORLD_TwoScene_H__

#include "ThreeSegmentScene2.h"

NS_MYGAME_BEGIN

class TwoScene : public ThreeSegmentScene2
{
public:

    void loadContents();

    CREATE_FUNC(TwoScene);
    
private:
    
};
NS_MYGAME_END

#endif // __HELLOWORLD_SCENE_H__
