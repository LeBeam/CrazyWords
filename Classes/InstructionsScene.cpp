
#include "InstructionsScene.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

Scene* InstructionsScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = InstructionsScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool InstructionsScene::init()
{
	if ( !Layer::init() )
		return false;

	setBackground();
	setTouchSoundEffect();
	createGameTitle();
	setHomeButton();
	setBackgroundMusic();
	setSettingsButton();
	setMainInstructions();
	showHost();

	return true;
}

void InstructionsScene::setBackground()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("Instructions_menu/bg_instructions.png");
	sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(sprite, 0);
}

void InstructionsScene::setTouchSoundEffect()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Music/mouse_click.mp3"); 
}

void InstructionsScene::setBackgroundMusic()
{
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->resumeBackgroundMusic();
}

void InstructionsScene::createGameTitle()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Colocar la imagen estatica con el titulo o nombre del juego en la pantalla
	auto gameTitle = Sprite::create("Instructions_menu/instructions_title0.png");
	gameTitle->setPosition(Point(visibleSize.width/2 * 1 + origin.x, visibleSize.height - gameTitle->getContentSize().height +30.0f));
	this->addChild(gameTitle, 0);

	auto animation = Animation::create();
	for ( int i = 0; i < 12; ++i )
		animation->addSpriteFrameWithFile( String::createWithFormat("Instructions_menu/instructions_title%i.png", i)->getCString() );

	// Y luego regresarla a su estado inicial
	for ( int i = 11; i >= 0; --i )
		animation->addSpriteFrameWithFile( String::createWithFormat("Instructions_menu/instructions_title%i.png", i)->getCString() );

	// Indicarle que muestre cada una de las imagenes que la componen por 0.1333 segundos
	animation->setDelayPerUnit( 0.1333f );

	// Lo anterior construye una unica animacion, repetirla siempre y cuando la pantalla de
	// menu del juego este visible
	auto repeatAnimation = RepeatForever::create( Animate::create(animation) );
	gameTitle->runAction(repeatAnimation);

}

void InstructionsScene::setHomeButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto homeButton = MenuItemImage::create("Instructions_menu/home_button.png", "Instructions_menu/home_button.png", CC_CALLBACK_1(InstructionsScene::returnGameMenu, this));
	homeButton->setPosition(Point(origin.x + homeButton->getContentSize().width / 2.0f + 5.0f, origin.y + visibleSize.height - homeButton->getContentSize().height / 2.0f - 5.0f));
	auto homeMenuButton = Menu::create(homeButton, NULL);
	homeMenuButton->setPosition(Point::ZERO);
	this->addChild(homeMenuButton, 2);
}

void InstructionsScene::setSettingsButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto settingsButton = MenuItemImage::create("Menu/settings_button0.png","Menu/settings_button1.png",CC_CALLBACK_1(InstructionsScene::showSettings, this));
	settingsButton->setPosition(Point(origin.x + visibleSize.width/2 * 1.9 ,origin.y+ visibleSize.height/2 * 1.85));
	auto settingsMenuButton = Menu::create(settingsButton, NULL);
	settingsMenuButton->setPosition(Point::ZERO);
	this->addChild(settingsMenuButton, 2);
}

void InstructionsScene::setMainInstructions()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	
	std::string instructionMessage;
	instructionMessage = "Hi!!! I am Professor Lenguin, and I am going to help you on the game. ";
	instructionMessage += "\nOn every level you will have to complete some crazy tasks that I going to assign you. ";
	instructionMessage += "\nI hope you enjoy the funny stuff we are going to do, because I really like having fun when learning!!! ";
	instructionMessage += "";

	LabelTTF* label = LabelTTF::create(instructionMessage, "Arial", 30, CCSizeMake(800, 700), kCCTextAlignmentLeft);
	label->setColor(ccc3(0,80,150));
	label->setPosition(Point(origin.x + 510, origin.y + 60));
	this->addChild(label, 3);
}

void InstructionsScene::showHost()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto host = Sprite::create("other_images/host.png");
	host->setPosition(Point(origin.x + 500, origin.y + 500));
	host->setScale(0.5f);
	this->addChild(host, 3);
}

#include "SettingsScene.h"
void InstructionsScene::showSettings(Ref* pSender)
{
	auto newScene = SettingsScene::createScene();
	Director::getInstance()->pushScene(CCTransitionFade::create(0.75f, newScene));
}


#include "MenuScene.h"
void InstructionsScene::returnGameMenu(Ref* pSender)
{
	InstructionsScene::setTouchSoundEffect();
	auto newScene = MenuScene::createScene();
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));
}



