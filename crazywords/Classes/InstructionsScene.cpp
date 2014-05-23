
#include "InstructionsScene.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

Scene* InstructionsScene::createScene()
{
    /// 'scene' is an autorelease object
    auto scene = Scene::create();

    /// 'layer' is an autorelease object
    auto layer = InstructionsScene::create();

    /// add layer as a child to scene
    scene->addChild(layer);

    /// return the scene
    return scene;
}

/// on "init" you need to initialize your instance
bool InstructionsScene::init()
{
    if ( !Layer::init() )
        return false;

	setBackgroundMenu();
	setMouseClickEffect();
	createGameTitle();
	setHomeButton();
    setBackgroundMusic();
	setSettingsButton();

    return true;
}

void InstructionsScene::setBackgroundMenu()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("Instructions_menu/bg_instructions.png");
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
}

void InstructionsScene::setMouseClickEffect()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Music/mouse_click.mp3"); 
}

/// Reproducir la musica de la seleccion del nivel: quiza sea mejor dejar la misma del menu
/// principal y cambiarla cuando se haya iniciado el nivel. Se deja aqui por propositos
/// ilustrativos
void InstructionsScene::setBackgroundMusic()
{
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/Game_general_music.mp3", true);
}

void InstructionsScene::createGameTitle()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /// Colocar la imagen estatica con el titulo o nombre del juego en la pantalla
    auto gameTitle = Sprite::create("Instructions_menu/instructions_title0.png");
    gameTitle->setPosition(Point(visibleSize.width/2 * 1 + origin.x, visibleSize.height - gameTitle->getContentSize().height +30.0f));
    this->addChild(gameTitle, 0);

	auto animation = Animation::create();
	for ( int i = 0; i < 12; ++i )
		animation->addSpriteFrameWithFile( String::createWithFormat("Instructions_menu/instructions_title%i.png", i)->getCString() );
	
	/// Y luego regresarla a su estado inicial
	for ( int i = 11; i >= 0; --i )
		animation->addSpriteFrameWithFile( String::createWithFormat("Instructions_menu/instructions_title%i.png", i)->getCString() );
	
	/// Indicarle que muestre cada una de las imagenes que la componen por 0.1333 segundos
	animation->setDelayPerUnit( 0.1333f );
	
	/// Lo anterior construye una unica animacion, repetirla siempre y cuando la pantalla de
	/// menu del juego este visible
	auto repeatAnimation = RepeatForever::create( Animate::create(animation) );
	gameTitle->runAction(repeatAnimation);

}

void InstructionsScene::setHomeButton()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	/// Boton de la casita, para retornar al menu del juego, ubicado en la esquina superior izquierda
	auto buttonHome = MenuItemImage::create("Instructions_menu/home_button.png", "Instructions_menu/home_button.png", CC_CALLBACK_1(InstructionsScene::returnGameMenu, this));
	buttonHome->setPosition(Point(origin.x + buttonHome->getContentSize().width / 2.0f + 5.0f, origin.y + visibleSize.height - buttonHome->getContentSize().height / 2.0f - 5.0f));
    auto buttonHomeMenu = Menu::create(buttonHome, NULL);
    buttonHomeMenu->setPosition(Point::ZERO);
    this->addChild(buttonHomeMenu, 2);
}

void InstructionsScene::setSettingsButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	auto ajustesButton = MenuItemImage::create("Menu/settings_button0.png","Menu/settings_button1.png",CC_CALLBACK_1(InstructionsScene::showSettings, this));
    ajustesButton->setPosition(Point(origin.x + visibleSize.width/2 * 1.9 ,origin.y+ visibleSize.height/2 * 1.85));
    auto buttonAjustesMenu = Menu::create(ajustesButton, NULL);
    buttonAjustesMenu->setPosition(Point::ZERO);
    this->addChild(buttonAjustesMenu, 2);
}

#include "SettingsScene.h"
void InstructionsScene::showSettings(Ref* pSender)
{
	/// Se crea la escena y la transicion para la pantalla de Configuraciones
	auto newScene = SettingsScene::createScene();
	Director::getInstance()->pushScene(CCTransitionFade::create(0.75f, newScene));
}


#include "HelloWorldScene.h"
void InstructionsScene::returnGameMenu(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Music/mouse_click.mp3"); 
	auto newScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));
}



