#include <cocos2d.h>
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
	setHomeButton();
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

void StartGameScene::setHomeButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto homeButton = MenuItemImage::create("game_scenes/home_button.png", "game_scenes/home_button.png", CC_CALLBACK_1(StartGameScene::returnGameMenu, this));
	homeButton->setPosition(Point(origin.x + homeButton->getContentSize().width / 2.0f + 5.0f, origin.y + visibleSize.height - homeButton->getContentSize().height / 2.0f - 5.0f));
	auto homeMenuButton = Menu::create(homeButton, NULL);
	homeMenuButton->setPosition(Point::ZERO);
	this->addChild(homeMenuButton, 2);
}

void StartGameScene::setTouchSoundEffect()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Music/mouse_click.mp3"); 
}

void StartGameScene::showAnimals()
{
	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			setChosenAnimal(i, j);
			
			
		}
	}
	
	
		
}

std::string StartGameScene::setSelectedAnimal()
{
	Util* animal = new Util();
	std::string& cAnimal = animal->getRandomAnimalName();
	return cAnimal;
	animal->~Util();

}

void StartGameScene::setChosenAnimal(int i, int j)
{
	pAnimal = setSelectedAnimal();
	int hPosition = i;
	int vPosition = j;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	const std::string& animalLocation = cocos2d::FileUtils::getInstance()->fullPathForFilename("objects/"+pAnimal+".png");

	animalSprite = Sprite::create(animalLocation);
	animalSprite->setPosition(Point(origin.x + (hPosition *175), origin.y + (vPosition *130) + 110));
	this->addChild(animalSprite, 3);
	setEventHandlers();
	
	
}

void StartGameScene::setAnimalPronunciation()

{   
	  CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(("objects/"+pAnimal+".mp3").c_str());
}

void StartGameScene::setEventHandlers()
{
	//Create a "one by one" touch event listener (processes one touch at a time)
	auto listener = EventListenerTouchOneByOne::create();
	// When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
	listener->setSwallowTouches(true);

	// Example of using a lambda expression to implement onTouchBegan event callback function
	listener->onTouchBegan = [](Touch* touch, Event* event)
	{
		// event->getCurrentTarget() returns the *listener's* sceneGraphPriority node.
		auto target = static_cast<StartGameScene*>(event->getCurrentTarget());

		//Get the position of the current point relative to the button
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		//Check the click area
		if (rect.containsPoint(locationInNode))
		{
			target->stopAllActions();
			target->setAnimalPronunciation();
			return true;
		}
		return false;
	};

	//Add listener
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, animalSprite);
}

#include "SettingsScene.h"
void StartGameScene::showSettings(Ref* pSender)
{
	auto newScene = SettingsScene::createScene();
	Director::getInstance()->pushScene(CCTransitionFade::create(0.75f, newScene));
}

#include "HelloWorldScene.h"
void StartGameScene::returnGameMenu(Ref* pSender)
{
	StartGameScene::setTouchSoundEffect();
	auto newScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));

}


