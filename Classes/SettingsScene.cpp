
#include "SettingsScene.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

Scene* SettingsScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = SettingsScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SettingsScene::init()
{

	if ( !Layer::init() )
		return false;

	setBackground();
	setTouchSoundEffect();
	createGameTitle();
	createMenu();

	return true;
}

void SettingsScene::setBackground()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("Settings_menu/bg_settings.png");
	sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(sprite, 0);
}

void SettingsScene::setTouchSoundEffect()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Music/mouse_click.mp3"); 
}


void SettingsScene::createGameTitle()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/// Colocar la imagen estatica con el titulo o nombre del juego en la pantalla
	auto gameTitle = Sprite::create("Settings_menu/Settings_title1.png");
	gameTitle->setPosition(Point(visibleSize.width/2 * 1 + origin.x, visibleSize.height - gameTitle->getContentSize().height +30.0f));
	this->addChild(gameTitle, 0);

	auto animation = Animation::create();
	for ( int i = 0; i < 3; ++i )
		animation->addSpriteFrameWithFile( String::createWithFormat("Settings_menu/Settings_title%i.png", i)->getCString() );

	/// Y luego regresarla a su estado inicial
	for ( int i = 2; i >= 0; --i )
		animation->addSpriteFrameWithFile( String::createWithFormat("Settings_menu/Settings_title%i.png", i)->getCString() );

	/// Indicarle que muestre cada una de las imagenes que la componen por 0.1333 segundos
	animation->setDelayPerUnit( 0.1333f );

	/// Lo anterior construye una unica animacion, repetirla siempre y cuando la pantalla de
	/// menu del juego este visible
	auto repeatAnimation = RepeatForever::create( Animate::create(animation) );
	gameTitle->runAction(repeatAnimation);

}

void SettingsScene::createMenu()
{
	setHomeButton();
	setMusicLabel();
	setMusicButton();
	setSoundEffectsLabel();
	setSoundEffectsButton();
}

void SettingsScene::setHomeButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/// Boton de la casita, para retornar al menu del juego, ubicado en la esquina superior izquierda
	auto homeButton = MenuItemImage::create("Settings_menu/return_button.png", "Settings_menu/return_button.png", CC_CALLBACK_1(SettingsScene::returnGameMenu, this));
	homeButton->setPosition(Point(origin.x + homeButton->getContentSize().width / 2.0f + 5.0f, origin.y + visibleSize.height - homeButton->getContentSize().height / 2.0f - 5.0f));
	auto homeMenuButton = Menu::create(homeButton, NULL);
	homeMenuButton->setPosition(Point::ZERO);
	this->addChild(homeMenuButton, 2);
}

void SettingsScene::setMusicLabel()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/// Etiqueta de musica, hace referencia a la activacion o desactivacion de la musica de fondo del juego
	// Esta etiqueta no debe regresar al menu principal, no debe realizar ninguna accion, simplemente se esta utilizando como prueba
	auto musicLabel = MenuItemImage::create("Settings_menu/music_button1.png", "Settings_menu/music_button2.png", CC_CALLBACK_1(SettingsScene::returnGameMenu, this));
	musicLabel->setPosition(Point(origin.x + visibleSize.width / 2.0f * 0.9 , origin.y + visibleSize.height / 2 * 1.2));
	auto musicMenuLabel = Menu::create(musicLabel, NULL);
	musicMenuLabel->setPosition(Point::ZERO);
	this->addChild(musicMenuLabel, 2);
}

void SettingsScene::setMusicButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/// Boton de musica, permite la activacion o desactivacion de la musica de fondo del juego
	auto musicButton = MenuItemImage::create("Settings_menu/onoffmusic_button0.png", "Settings_menu/onoffmusic_button1.png", CC_CALLBACK_1(SettingsScene::turnOnOffMusic, this));
	musicButton->setPosition(Point(origin.x + visibleSize.width / 2.0f * 1.3, origin.y + visibleSize.height / 2 * 1.2));
	auto musicMenuButton = Menu::create(musicButton, NULL);
	musicMenuButton->setPosition(Point::ZERO);
	this->addChild(musicMenuButton, 2);
}

void SettingsScene::setSoundEffectsLabel()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/// Etiqueta de sonido, hace referencia a la activacion o desactivacion de los efectos de sonido del juego
	// Esta etiqueta no debe regresar al menu principal, no debe realizar ninguna accion, simplemente se esta utilizando como prueba
	auto labelSound = MenuItemImage::create("Settings_menu/sounds_button1.png", "Settings_menu/sounds_button2.png", CC_CALLBACK_1(SettingsScene::returnGameMenu, this));
	labelSound->setPosition(Point(origin.x + visibleSize.width / 2.0f * 0.9, origin.y + visibleSize.height / 2 * 0.7));
	auto labelSoundMenu = Menu::create(labelSound, NULL);
	labelSoundMenu->setPosition(Point::ZERO);
	this->addChild(labelSoundMenu, 2);
}

void SettingsScene::setSoundEffectsButton()
{
	
}

#include "HelloWorldScene.h"
void SettingsScene::returnGameMenu(Ref* pSender)
{
	SettingsScene::setTouchSoundEffect();
	Director::getInstance()->popScene();
}

void SettingsScene::turnOnOffMusic(cocos2d::Ref* pSender)
{
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
}

void SettingsScene::turnOnOffSound(cocos2d::Ref* pSender)
{
}