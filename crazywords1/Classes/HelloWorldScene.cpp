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

     auto label = LabelTTF::create("2014 LeBeam", "Arial", 11); 
    
    //position the label on the center of the screen
    label->setPosition(Point(origin.x + 50.0f ,origin.y + 15.0f));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("Menu/background.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	createGameTitle();
    createGameMenu();

	// Reproducir la musica del menu principal
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/Song_menu.mp3", true);
    
    return true;
}

void HelloWorld::createGameTitle()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    // Colocar la imagen estatica con el titulo o nombre del juego en la pantalla
    auto gameTitle = Sprite::create("Menu/main_title0.png");
    gameTitle->setPosition(Point(visibleSize.width/2 * 0.5 + origin.x, visibleSize.height - gameTitle->getContentSize().height +100.0f));
    this->addChild(gameTitle, 0);

	auto animation = Animation::create();
	for ( int i = 0; i < 4; ++i )
		animation->addSpriteFrameWithFile( String::createWithFormat("Menu/main_title%i.png", i)->getCString() );
	
	// Y luego regresarla a su estado inicial
	for ( int i = 3; i >= 0; --i )
		animation->addSpriteFrameWithFile( String::createWithFormat("Menu/main_title%i.png", i)->getCString() );
	
	// Indicarle que muestre cada una de las imagenes que la componen por 0.1333 segundos
	animation->setDelayPerUnit( 0.1333f );
	
	// Lo anterior construye una unica animacion, repetirla siempre y cuando la pantalla de
	// menu del juego este visible
	auto repeatAnimation = RepeatForever::create( Animate::create(animation) );
	gameTitle->runAction(repeatAnimation);

}

void HelloWorld::createGameMenu()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	//Boton Jugar
    auto jugarButton = MenuItemImage::create("Menu/game_button1.png","Menu/game_button2.png",CC_CALLBACK_1(HelloWorld::startGame, this));
    jugarButton->setPosition(Point(origin.x + visibleSize.width/2 * 1.5 ,origin.y+ visibleSize.height/2 * 1.5));
    auto buttonJugarMenu = Menu::create(jugarButton, NULL);
    buttonJugarMenu->setPosition(Point::ZERO);
    this->addChild(buttonJugarMenu, 2);

	//Boton Ajustes
    auto ajustesButton = MenuItemImage::create("Menu/settings_button1.png","Menu/settings_button2.png",CC_CALLBACK_1(HelloWorld::showSettings, this));
    ajustesButton->setPosition(Point(origin.x + visibleSize.width/2 * 1.5 ,origin.y+ visibleSize.height/2 * 1.0));
    auto buttonAjustesMenu = Menu::create(ajustesButton, NULL);
    buttonAjustesMenu->setPosition(Point::ZERO);
    this->addChild(buttonAjustesMenu, 2);

	//Boton Instrucciones
    auto instruccionesButton = MenuItemImage::create("Menu/instructions_button1.png","Menu/instructions_button2.png",CC_CALLBACK_1(HelloWorld::showInstructions, this));
    instruccionesButton->setPosition(Point(origin.x + visibleSize.width/2 * 1.5 ,origin.y+ visibleSize.height/2 * 0.5));
    auto buttonInstruccionesMenu = Menu::create(instruccionesButton, NULL);
    buttonInstruccionesMenu->setPosition(Point::ZERO);
    this->addChild(buttonInstruccionesMenu, 2);

	//Boton Salir
    auto exitButton = MenuItemImage::create("Menu/exit_button1.png","Menu/exit_button2.png",CC_CALLBACK_1(HelloWorld::exit, this));
    exitButton->setPosition(Point(origin.x + visibleSize.width/2 * 0.6 ,origin.y+ visibleSize.height/2 * 0.5));
    auto buttonExitMenu = Menu::create(exitButton, NULL);
    buttonExitMenu->setPosition(Point::ZERO);
    this->addChild(buttonExitMenu, 2);
    
}

void HelloWorld::startGame(Ref* pSender)
{
}


#include "InstructionsScene.h"
void HelloWorld::showInstructions(Ref* pSender)
{
	auto newScene = InstructionsScene::createScene();
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
}


void HelloWorld::showSettings(cocos2d::Ref* pSender)
{
}


void HelloWorld::exit(cocos2d::Ref* pSender)
{
}