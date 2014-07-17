#include <cocos2d.h>
#include "Level2Scene.h"
#include <SimpleAudioEngine.h>
#include "GameObjectManager.h"

USING_NS_CC;

Scene* Level2Scene::createScene()
{
	auto scene = Scene::create();
	auto layer = Level2Scene::create();

	scene->addChild(layer);

	return scene;
}

bool Level2Scene::init()
{
	if ( !Layer::init() )
		return false;

	gameObjectManager.loadObjects();
	gameObjectManager.shuffleFruits();

	setBackground();
	setTouchSoundEffect();
	setSettingsButton();
	setHomeButton();
	showHost();
	showFruits();
	setInstructionLabel();
	setColorButtons();
	
	return true;
}

void Level2Scene::setBackground()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("game_scenes/bg_level2.png");
	sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(sprite, 0);
}

void Level2Scene::setSettingsButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto settingsButton = MenuItemImage::create("Menu/settings_button0.png","Menu/settings_button1.png",CC_CALLBACK_1(Level2Scene::showSettings, this));
	settingsButton->setPosition(Point(origin.x + visibleSize.width/2 * 1.9 ,origin.y+ visibleSize.height/2 * 1.85));
	auto settingsMenuButton = Menu::create(settingsButton, NULL);
	settingsMenuButton->setPosition(Point::ZERO);
	this->addChild(settingsMenuButton, 4);
}

void Level2Scene::setHomeButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto homeButton = MenuItemImage::create("game_scenes/home_button.png", "game_scenes/home_button.png", CC_CALLBACK_1(Level2Scene::returnGameMenu, this));
	homeButton->setPosition(Point(origin.x + homeButton->getContentSize().width / 2.0f + 5.0f, origin.y + visibleSize.height - homeButton->getContentSize().height / 2.0f - 5.0f));
	auto homeMenuButton = Menu::create(homeButton, NULL);
	homeMenuButton->setPosition(Point::ZERO);
	this->addChild(homeMenuButton, 4);
}

void Level2Scene::setTouchSoundEffect()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Music/mouse_click.mp3"); 
}

void Level2Scene::showHost()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto gameObject = GameObject::create();
	gameObject->setPosition(Point(origin.x + 250, origin.y + 600));
	gameObject->setScale(0.5f);
	this->addChild(gameObject, 3);
	gameObject->setTexture("other_images/host.png");
}

void Level2Scene::setInstructionLabel()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	
	GameObject* fruitObject = gameObjectManager.getObject(25);
    std::string fruitName = fruitObject->getName();

	setFruitColor();
    const std::string& instruction = "Touch the "+ fruitColor +"\n to paint the " + fruitName + "!";
	
	LabelTTF* label = LabelTTF::create(instruction, "Arial", 45, CCSizeMake(700, 200), kCCTextAlignmentCenter);
	label->setColor(ccc3(0,25,50));
	label->setPosition(Point(origin.x + 250, origin.y + 400));
	this->addChild(label, 3);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(("objects/"+fruitColor+".mp3").c_str());
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(("objects/"+fruitName+".mp3").c_str());
}

void Level2Scene::showFruits()
{
//	gameObjectManager.loadObjects();
//	gameObjectManager.shuffleFruits();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	GameObject* gameObject = gameObjectManager.getObject(25);
	gameObject->setPosition(Point(origin.x + 740, origin.y + 384));
	gameObject->setScale(0.5f);
	this->addChild(gameObject, 2);
	gameObject->setEventHandlers();
}

void Level2Scene::setFruitColor()
{
	 GameObject* gameObject = gameObjectManager.getObject(25);
     std::string fruit = gameObject->getName();

	if( (fruit == "banana") || (fruit == "lemon") )
		fruitColor = "blue color";
	if( fruit == "grape" )
		fruitColor = "orange color";
    if( fruit == "orange")	
		fruitColor = "purple color";
    if( fruit == "pear")
        fruitColor = "red color";
    if( (fruit == "strawberry") || (fruit == "watermelon") )
        fruitColor = "yellow";
}

void Level2Scene::setRedColorButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	GameObject* gameObject = gameObjectManager.getObject(32);
	gameObject->setPosition(Point(origin.x + 190, origin.y + 280));
	this->addChild(gameObject, 3);

	gameObject->setEventHandlers();
}

void Level2Scene::setYellowColorButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	GameObject* gameObject = gameObjectManager.getObject(33);
	gameObject->setPosition(Point(origin.x + 170, origin.y + 120));
	this->addChild(gameObject, 3);

	gameObject->setEventHandlers();
}

void Level2Scene::setPurpleColorButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	GameObject* gameObject = gameObjectManager.getObject(31);
	gameObject->setPosition(Point(origin.x + 320, origin.y + 210));
	this->addChild(gameObject, 3);

	gameObject->setEventHandlers();
}

void Level2Scene::setBlueColorButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	GameObject* gameObject = gameObjectManager.getObject(29);
	gameObject->setPosition(Point(origin.x + 140, origin.y + 200));
	this->addChild(gameObject, 3);

	gameObject->setEventHandlers();
}

void Level2Scene::setOrangeColorButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	GameObject* gameObject = gameObjectManager.getObject(30);
	gameObject->setPosition(Point(origin.x + 260, origin.y + 150));
	this->addChild(gameObject, 3);

	gameObject->setEventHandlers();
}

void Level2Scene::setColorButtons()
{
	setRedColorButton();
	setBlueColorButton();
	setPurpleColorButton();
	setYellowColorButton();
	setOrangeColorButton();
}

void Level2Scene::setPaintedFruit()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	GameObject* fruitObject = gameObjectManager.getObject(25);
    paintedFruit = fruitObject->getName();

	auto homeButton = MenuItemImage::create("objects/"+paintedFruit+"2.png", "objects/"+paintedFruit+"2.png");
	homeButton->setPosition(Point(origin.x + 740, origin.y + 384));
	homeButton->setScale(0.5f);
	auto homeMenuButton = Menu::create(homeButton, NULL);
	homeMenuButton->setPosition(Point::ZERO);
	this->addChild(homeMenuButton, 4);
}

#include "SettingsScene.h"
void Level2Scene::showSettings(Ref* pSender)
{
	auto newScene = SettingsScene::createScene();
	Director::getInstance()->pushScene(CCTransitionFade::create(0.75f, newScene));
}

#include "MenuScene.h"
void Level2Scene::returnGameMenu(Ref* pSender)
{
	Level2Scene::setTouchSoundEffect();
	auto newScene = MenuScene::createScene();
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));
}