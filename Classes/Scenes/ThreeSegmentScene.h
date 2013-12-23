#ifndef __ThreeSegmentScene_SCENE_H__
#define __ThreeSegmentScene_SCENE_H__

#include "BaseScene.h"

NS_MYGAME_BEGIN

class ThreeSegmentScene : public BaseScene
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone

    void loadContents();

	// implement the "static node()" method manually
    CREATE_FUNC(ThreeSegmentScene);
private:

    
};

NS_MYGAME_END

#endif // __ThreeSegmentScene_SCENE_H__
