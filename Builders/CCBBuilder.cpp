#include "CCBBuilder.h"
#include "../Core/LayerController.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

NS_CC_YHMVC_BEGIN

CCBBuilder::CCBBuilder()
{
    
}

CCBBuilder::~CCBBuilder()
{

}

CCNode* CCBBuilder::buildFromFile(const std::string& filename)
{
    CCBReader* reader=createReader(CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary());
    return reader->readNodeGraphFromFile(filename.c_str());
    
    return NULL;
}

CCNode* CCBBuilder::buildFromFile(const std::string& filename,CCObject* parameter)
{
    CCDictionary*  parameterDict=dynamic_cast<CCDictionary*>(parameter);
    CCBReader* reader=NULL;
    CCObject* owner=NULL;
    
    if (parameterDict) {
        //check reader
        CCBReader* reader=static_cast<CCBReader*>(parameterDict->objectForKey("Reader"));
        
        if (reader==NULL) {
            //check LoaderLibrary
            CCNodeLoaderLibrary* loaderLibrary=static_cast<CCNodeLoaderLibrary*>(parameterDict->objectForKey("LoaderLibrary"));
            if (loaderLibrary==NULL) {
                loaderLibrary=CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
                
                //create register node loader data
                CCString* className=NULL;
                CCNodeLoader* nodeLoader=NULL;
                CCArray* nodeLoaders=static_cast<CCArray*>(parameterDict->objectForKey("NodeLoaders"));
                if (nodeLoaders) {
                    //group node loaders;
                    CCObject* pObj=NULL;
                    CCDictionary* nodeLoaderData=NULL;
                    CCARRAY_FOREACH(nodeLoaders, pObj){
                        nodeLoaderData=static_cast<CCDictionary*>(pObj);
                        className=static_cast<CCString*>(nodeLoaderData->objectForKey("ClassName"));
                        nodeLoader=static_cast<CCNodeLoader*>(nodeLoaderData->objectForKey("NodeLoader"));
                        loaderLibrary->registerCCNodeLoader(className->getCString(), nodeLoader);
                    }
                    
                }else{
                    //sigle node loader
                    className=static_cast<CCString*>(parameterDict->objectForKey("ClassName"));
                    nodeLoader=static_cast<CCNodeLoader*>(parameterDict->objectForKey("NodeLoader"));
                    loaderLibrary->registerCCNodeLoader(className->getCString(), nodeLoader);
                }
            }
            
            //set root path
            CCString* rootPath=static_cast<CCString*>(parameterDict->objectForKey("RootPath"));
            if (rootPath) {
                reader=createReader(loaderLibrary,rootPath->getCString());
            }else{
                reader=createReader(loaderLibrary);
            }
        }
        
        owner=parameterDict->objectForKey("Owner");
        
    }else{
        reader=createReader(CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary());
    }
    
    return reader->readNodeGraphFromFile(filename.c_str(), owner);
}

cocos2d::extension::CCBReader* CCBBuilder::createReader(cocos2d::extension::CCNodeLoaderLibrary* loaderLibrary)
{
    return createReader(loaderLibrary, "");
}

cocos2d::extension::CCBReader* CCBBuilder::createReader(cocos2d::extension::CCNodeLoaderLibrary* loaderLibrary,const char* rootPath)
{
    CCBReader * reader = new CCBReader(loaderLibrary);
    //默认不播放动画
    reader->getAnimationManager()->setAutoPlaySequenceId(-1);
    //设置图片加载位置
    reader->setCCBRootPath(rootPath);
    reader->autorelease();
    return reader;
}

NS_CC_YHMVC_END