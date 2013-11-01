//
//  GameMacros.h
//  CCMVC
//
//  Created by duanhouhai on 13-11-1.
//
//

#ifndef CCMVC_GameMacros_h
#define CCMVC_GameMacros_h

#ifdef __cplusplus
#define NS_MYGAME_BEGIN                     namespace cocos2d { namespace mygame {
#define NS_MYGAME_END                       }}
#define USING_NS_MYGAME                     using namespace cocos2d::mygame
#else
#define NS_MYGAME_BEGIN
#define NS_MYGAME_END
#define USING_NS_MYGAME
#endif

#endif
