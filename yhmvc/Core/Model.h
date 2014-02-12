#ifndef COCOS_YHMVC_MODEL_H_
#define COCOS_YHMVC_MODEL_H_

#include "cocos2d.h"
#include "../YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class Model : public CCObject
{
public:

	Model();

	~Model();
    
	bool init();

};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_MODEL_H_
