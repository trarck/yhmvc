#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "BaseScene.h"

class HelloWorld : public BaseScene
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone

    void loadContents();

	// implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
private:

};

#endif // __HELLOWORLD_SCENE_H__
