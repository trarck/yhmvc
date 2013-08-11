#ifndef COCOS_YHMVC_YHSCENEDIRECTOR_H_
#define COCOS_YHMVC_YHSCENEDIRECTOR_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class Scene;

class YHSceneDirector : public CCObject
{
    
public:
    
    YHSceneDirector();
    
    ~YHSceneDirector();
      
    static YHSceneDirector* getInstance();
   
    void runWithScene(Scene *pScene);
    void pushScene(Scene* scene);
    void popScene();
    void popToRootScene();
	void popToSceneStackLevel(int level);
    void replaceScene(Scene *pScene);
protected:
    
    CCArray* m_scenesStack;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_YHSCENEDIRECTOR_H_
