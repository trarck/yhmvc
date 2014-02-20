#ifndef YHMVC_CORE_MODEL_H_
#define YHMVC_CORE_MODEL_H_

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

#endif // YHMVC_CORE_MODEL_H_
