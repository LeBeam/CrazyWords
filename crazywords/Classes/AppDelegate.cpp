#include "AppDelegate.h"
#include "HelloWorldScene.h"

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
<<<<<<< HEAD
        glview = GLView::create("CrazyWords");
=======
<<<<<<< HEAD
        glview = GLView::create("CrazyWords");
=======
        glview = GLView::create("My Game");
>>>>>>> dbb879cdaa0498ea5226cf7d144475efe5dbfe30
>>>>>>> d59c670b8667257ad050cdd5bbc4a67881dacd76
        director->setOpenGLView(glview);
    }

    // turn on display FPS
<<<<<<< HEAD
    director->setDisplayStats(false);
=======
<<<<<<< HEAD
    director->setDisplayStats(false);
=======
    director->setDisplayStats(true);
>>>>>>> dbb879cdaa0498ea5226cf7d144475efe5dbfe30
>>>>>>> d59c670b8667257ad050cdd5bbc4a67881dacd76

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
