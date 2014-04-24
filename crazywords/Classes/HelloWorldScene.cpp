#include "HelloWorldScene.h"
<<<<<<< HEAD
#include <SimpleAudioEngine.h>
=======
<<<<<<< HEAD
#include <SimpleAudioEngine.h>
=======
>>>>>>> dbb879cdaa0498ea5226cf7d144475efe5dbfe30
>>>>>>> d59c670b8667257ad050cdd5bbc4a67881dacd76

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
>>>>>>> dbb879cdaa0498ea5226cf7d144475efe5dbfe30
>>>>>>> d59c670b8667257ad050cdd5bbc4a67881dacd76
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> d59c670b8667257ad050cdd5bbc4a67881dacd76
     auto label = LabelTTF::create("2014 LeBeam", "Arial", 11); 
    
    //position the label on the center of the screen
    label->setPosition(Point(origin.x + 50.0f ,origin.y + 15.0f));
<<<<<<< HEAD
=======
=======
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
>>>>>>> dbb879cdaa0498ea5226cf7d144475efe5dbfe30
>>>>>>> d59c670b8667257ad050cdd5bbc4a67881dacd76

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> d59c670b8667257ad050cdd5bbc4a67881dacd76
    auto sprite = Sprite::create("Menu/BackgroundMenu.png");

    // position the sprite on the center of the screen
   sprite->setPosition(Point(visibleSize.width + origin.x - sprite->getContentSize().width/2.1 , visibleSize.height + origin.y - sprite->getContentSize().height/3));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	createGameTitle();
    createGameMenu();

	// Reproducir la musica del menu principal
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/SongMenu.mp3", true);
<<<<<<< HEAD
=======
=======
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
>>>>>>> dbb879cdaa0498ea5226cf7d144475efe5dbfe30
>>>>>>> d59c670b8667257ad050cdd5bbc4a67881dacd76
    
    return true;
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> d59c670b8667257ad050cdd5bbc4a67881dacd76
void HelloWorld::createGameTitle()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    // Colocar la imagen estatica con el titulo o nombre del juego en la pantalla
    auto gameTitle = Sprite::create("Menu/Titulo1.png");
    gameTitle->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height - gameTitle->getContentSize().height +40.0f));
    this->addChild(gameTitle, 0);

}

void HelloWorld::createGameMenu()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	//Boton Jugar, situado 1/4 de la pantalla
    auto jugarButton = MenuItemImage::create("Menu/Boton1.png","Menu/Boton2.png",CC_CALLBACK_1(HelloWorld::startGame, this));
    jugarButton->setPosition(Point(origin.x + visibleSize.width/2,origin.y+ visibleSize.height/2 * 1.2));
    auto buttonJugarMenu = Menu::create(jugarButton, NULL);
    buttonJugarMenu->setPosition(Point::ZERO);
    this->addChild(buttonJugarMenu, 2);


}


void HelloWorld::startGame(Ref* pSender)
{

}

void HelloWorld::showAwards(Ref* pSender)
{
}

void HelloWorld::showOptions(cocos2d::Ref* pSender)
{
<<<<<<< HEAD
}
=======
}
=======

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
>>>>>>> dbb879cdaa0498ea5226cf7d144475efe5dbfe30
>>>>>>> d59c670b8667257ad050cdd5bbc4a67881dacd76
