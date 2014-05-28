#include "StartGameScene.h"
#include <SimpleAudioEngine.h>
#include "Util.h"

USING_NS_CC;

Scene* StartGameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = StartGameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool StartGameScene::init()
{
	if ( !Layer::init() )
		return false;

	setBackground();
	setSettingsButton();
	showAnimals();

	return true;
}

void StartGameScene::setBackground()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("game_scenes/bg_level1.png");
	sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(sprite, 0);
}

void StartGameScene::setSettingsButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto settingsButton = MenuItemImage::create("Menu/settings_button0.png","Menu/settings_button1.png",CC_CALLBACK_1(StartGameScene::showSettings, this));
	settingsButton->setPosition(Point(origin.x + visibleSize.width/2 * 1.9 ,origin.y+ visibleSize.height/2 * 1.85));
	auto settingsMenuButton = Menu::create(settingsButton, NULL);
	settingsMenuButton->setPosition(Point::ZERO);
	this->addChild(settingsMenuButton, 2);
}

void StartGameScene::showAnimals()
{
	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			std::string chosenAnimal = "dog";

			Size visibleSize = Director::getInstance()->getVisibleSize();
			Point origin = Director::getInstance()->getVisibleOrigin();

			auto animalSprite = Sprite::create("objects/"+chosenAnimal+".png");
			animalSprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
			this->addChild(animalSprite, 3);
		}

	}

}

/*
void StartGameScene::showAnimals()
{
for(int i = 0; i < 5; i++)
{
for(int j = 0; j < 4; j++)
{
for(int k = 0; k<(i*j); k++)
{
int random = rand() % 20;
std::string randomAnimal = Util::getAnimal(random);

Size visibleSize = Director::getInstance()->getVisibleSize();
Point origin = Director::getInstance()->getVisibleOrigin();

auto animalSprite = Sprite::create("Resources/objects/"+randomAnimal+".png");
}

}

}

}
*/
#include "SettingsScene.h"
void StartGameScene::showSettings(Ref* pSender)
{
	auto newScene = SettingsScene::createScene();
	Director::getInstance()->pushScene(CCTransitionFade::create(0.75f, newScene));
}



