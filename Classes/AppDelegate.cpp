#include "AppDelegate.h"
#include "StarrySkyController.h"
#include "SimpleAudioEngine.h"
#include <thread>

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    //------------------  shipei -------
    Size screenSize = glview->getFrameSize();
    Size designSize = Size(640, 1136);
    
    FileUtils* pFileUtils = CCFileUtils::getInstance();
    std::vector<std::string> searchPaths;
    
    if ( Platform::OS_IPAD == this->getTargetPlatform() ) {
        designSize = Size(2048, 1536);
        searchPaths.push_back("iPad");
    }else{
        designSize = Size(640, 1136);
        searchPaths.push_back("iPhone");
    }
    searchPaths.push_back("Particle");
    searchPaths.push_back("constellations");
    searchPaths.push_back("Sound");
    searchPaths.push_back("Weather");
    
    
    pFileUtils->setSearchPaths(searchPaths);
    
    director->setContentScaleFactor(screenSize.height/screenSize.height);
    glview->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::EXACT_FIT );
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = StarrySkyController::createScene();

    // run
    director->runWithScene(scene);

    std::thread t1(&AppDelegate::loadResources,this);//创建一个分支线程，回调到myThread函数里
    t1.join();
//  t1.detach();
//    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::fullPathFromRelativeFile( "Explo.mp3") );
    
    CCLOG("主线程");
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AppDelegate::loadResources(){
    CCLOG("子线程");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect( "Explo.mp3" );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect( "rush.mp3" );
}
