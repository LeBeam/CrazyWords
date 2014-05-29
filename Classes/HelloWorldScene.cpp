#include "HelloWorldScene.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	//'scene' is an autorelease object
	auto scene = Scene::create();	/** \var  */

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
	if ( !Layer::init() )
		return false;

	setPersonalLabel();
	setBackground();
	createGameTitle();
	createGameMenu();
	setMenuMusic();

	return true;
}

void HelloWorld::setPersonalLabel()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto label = LabelTTF::create("2014 LeBeam", "Arial", 11); 
	label->setPosition(Point(origin.x + 50.0f ,origin.y + 15.0f));
	this->addChild(label, 1);
}

void HelloWorld::setBackground()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("Menu/background.png");
	sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(sprite, 0);
}

void HelloWorld::setMenuMusic()
{
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/mariachi_snooze.mp3", true);
}

void HelloWorld::createGameTitle()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto gameTitle = Sprite::create("Menu/main_title0.png");
	gameTitle->setPosition(Point(visibleSize.width/2 * 0.5 + origin.x, visibleSize.height - gameTitle->getContentSize().height -05.0f));
	this->addChild(gameTitle, 0);   

	auto animation = Animation::create();
	for ( int i = 0; i < 4; ++i )
		animation->addSpriteFrameWithFile( String::createWithFormat("Menu/main_title%i.png", i)->getCString() );

	// Y luego regresarla a su estado inicial
	for ( int i = 3; i >= 0; --i )
		animation->addSpriteFrameWithFile( String::createWithFormat("Menu/main_title%i.png", i)->getCString() );

	// Indicarle que muestre cada una de las imagenes que la componen por 0.1333 segundos
	animation->setDelayPerUnit( 0.1333f );

	// Lo anterior construye una unica animacion, repetirla siempre y cuando la pantalla de menu del juego este visible
	auto repeatAnimation = RepeatForever::create( Animate::create(animation) );
	gameTitle->runAction(repeatAnimation);

}

void HelloWorld::createGameMenu()
{
	setPlayButton();
	setSettingsButton();
	setInstructionsButton();
	if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		setExitButton();
}

void HelloWorld::setPlayButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto playButton = MenuItemImage::create("Menu/username_button.png","Menu/username_button.png",CC_CALLBACK_1(HelloWorld::startGame, this));
	playButton->setPosition(Point(origin.x + visibleSize.width/2 * 1.5 ,origin.y+ visibleSize.height/2 * 1.2));
	auto playMenuButton = Menu::create(playButton, NULL);
	playMenuButton->setPosition(Point::ZERO);
	this->addChild(playMenuButton, 2);
}

void HelloWorld::setSettingsButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto settingsButton = MenuItemImage::create("Menu/settings_button0.png","Menu/settings_button1.png",CC_CALLBACK_1(HelloWorld::showSettings, this));
	settingsButton->setPosition(Point(origin.x + visibleSize.width/2 * 1.9 ,origin.y+ visibleSize.height/2 * 1.85));
	auto settingsMenuButton = Menu::create(settingsButton, NULL);
	settingsMenuButton->setPosition(Point::ZERO);
	this->addChild(settingsMenuButton, 2);
}

void HelloWorld::setInstructionsButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto instructionsButton = MenuItemImage::create("Menu/instructions_button0.png","Menu/instructions_button1.png",CC_CALLBACK_1(HelloWorld::showInstructions, this));
	instructionsButton->setPosition(Point(origin.x + visibleSize.width/2 * 1.5 ,origin.y+ visibleSize.height/2 * 0.7));
	auto instructionsMenuButton = Menu::create(instructionsButton, NULL);
	instructionsMenuButton->setPosition(Point::ZERO);
	this->addChild(instructionsMenuButton, 2);
}

void HelloWorld::setExitButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto exitButton = MenuItemImage::create("Menu/exit_button1.png","Menu/exit_button2.png",CC_CALLBACK_1(HelloWorld::exit, this));
	exitButton->setPosition(Point(origin.x + visibleSize.width/2 * 0.6 ,origin.y+ visibleSize.height/2 * 0.7));
	auto exitMenuButton = Menu::create(exitButton, NULL);
	exitMenuButton->setPosition(Point::ZERO);
	this->addChild(exitMenuButton, 2);
}

#include "StartGameScene.h"
void HelloWorld::startGame(Ref* pSender)
{
	// Se crea la escena y la transicion para la pantalla de iniciar el juego
	auto newScene = StartGameScene::createScene();
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
}


#include "InstructionsScene.h"
void HelloWorld::showInstructions(Ref* pSender)
{
	// Se crea la escena y la transicion para la pantalla de Instrucciones
	auto newScene = InstructionsScene::createScene();
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
}

#include "SettingsScene.h"
void HelloWorld::showSettings(Ref* pSender)
{
	// Se crea la escena y la transicion para la pantalla de Configuraciones
	auto newScene = SettingsScene::createScene();
	Director::getInstance()->pushScene(CCTransitionFade::create(0.75f, newScene));
}


void HelloWorld::exit(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();
}

