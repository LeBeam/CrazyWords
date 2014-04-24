#include "HelloWorldScene.h"
#include <SimpleAudioEngine.h>

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
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
     auto label = LabelTTF::create("2014 LeBeam", "Arial", 11); 
    
    //position the label on the center of the screen
    label->setPosition(Point(origin.x + 50.0f ,origin.y + 15.0f));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
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
    
    return true;
}

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
}