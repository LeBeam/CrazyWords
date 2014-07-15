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

	setBackground();
	setSettingsButton();
	setHomeButton();
	showHost();
	setInstructionLabel();
	
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

#include "SettingsScene.h"
void Level2Scene::showSettings(Ref* pSender)
{
	auto newScene = SettingsScene::createScene();
	Director::getInstance()->pushScene(CCTransitionFade::create(0.75f, newScene));
}

#include "HelloWorldScene.h"
void Level2Scene::returnGameMenu(Ref* pSender)
{
	Level2Scene::setTouchSoundEffect();
	auto newScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));

}

void Level2Scene::showHost()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto gameObject = GameObject::create();
	gameObject->setPosition(Point(origin.x + 100, origin.y + 600));
	gameObject->setScale(0.5f);
	this->addChild(gameObject, 3);
	gameObject->setTexture("other_images/host.png");
	
}

void Level2Scene::setInstructionLabel()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	
	//GameObject* animalObject = gameObjectManager.getRandomObject();
    //std::string animalName = animalObject->getName();

    const std::string& instruction = "Touch the red color\n to paint the apple !";
	
	LabelTTF* label = LabelTTF::create(instruction, "Arial", 60, CCSizeMake(1000, 100), kCCTextAlignmentCenter);
	label->setColor(ccc3(51,255,255));
	label->setPosition(Point(origin.x + 100, origin.y + 550));
	this->addChild(label, 3);
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(("objects/"+animalName+".mp3").c_str());
}
