#ifndef COCOS_YHMVC_SCENEDIRECTOR_H_
#define COCOS_YHMVC_SCENEDIRECTOR_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class Scene;

class SceneDirector : public CCObject
{
    
public:
    
    SceneDirector();
    
    ~SceneDirector();
      
    static SceneDirector* getInstance();
   
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

#endif // COCOS_YHMVC_SCENEDIRECTOR_H_
