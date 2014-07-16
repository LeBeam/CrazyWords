#include <cocos2d.h>
#include "Level1Scene.h"
#include <SimpleAudioEngine.h>
#include "GameObjectManager.h"

USING_NS_CC;

Scene* Level1Scene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Level1Scene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Level1Scene::init()
{
	if ( !Layer::init() )
		return false;

	setPlayingMusic();
	setBackground();
	setSettingsButton();
	setHomeButton();
	showAnimals();
	showHost();
	setInstructionLabel();
	
	return true;
}

void Level1Scene::setBackground()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("game_scenes/bg_level1.png");
	sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(sprite, 0);
}

void Level1Scene::setSettingsButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto settingsButton = MenuItemImage::create("Menu/settings_button0.png","Menu/settings_button1.png",CC_CALLBACK_1(Level1Scene::showSettings, this));
	settingsButton->setPosition(Point(origin.x + visibleSize.width/2 * 1.9 ,origin.y+ visibleSize.height/2 * 1.85));
	auto settingsMenuButton = Menu::create(settingsButton, NULL);
	settingsMenuButton->setPosition(Point::ZERO);
	this->addChild(settingsMenuButton, 4);
}

void Level1Scene::setHomeButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto homeButton = MenuItemImage::create("game_scenes/home_button.png", "game_scenes/home_button.png", CC_CALLBACK_1(Level1Scene::returnGameMenu, this));
	homeButton->setPosition(Point(origin.x + homeButton->getContentSize().width / 2.0f + 5.0f, origin.y + visibleSize.height - homeButton->getContentSize().height / 2.0f - 5.0f));
	auto homeMenuButton = Menu::create(homeButton, NULL);
	homeMenuButton->setPosition(Point::ZERO);
	this->addChild(homeMenuButton, 4);
}

void Level1Scene::setTouchSoundEffect()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Music/mouse_click.mp3"); 
}

void Level1Scene::setPlayingMusic()
{
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->setBackgroundMusicVolume(0.5f);
	sound->playBackgroundMusic("Music/game_general_music.mp3", true);

}

void Level1Scene::showAnimals()
{
	gameObjectManager.loadObjects("animals");
	gameObjectManager.shuffle();

	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			showRandomAnimalForCell(i, j);
	    }
	}
			
}

void Level1Scene::showRandomAnimalForCell(int row, int col)
{
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	GameObject* gameObject = gameObjectManager.getNextRandomObject();
	gameObject->setPosition(Point(origin.x + (row *175), origin.y + (col *130) + 110));
	this->addChild(gameObject, 2);
	gameObject->setEventHandlers();
}

void Level1Scene::showHost()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto gameObject = GameObject::create();
	gameObject->setPosition(Point(origin.x + 100, origin.y + 100));
	gameObject->setScale(0.5f);
	this->addChild(gameObject, 3);
	gameObject->setTexture("other_images/host.png");
	
}

void Level1Scene::setInstructionLabel()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	
	GameObject* animalObject = gameObjectManager.getRandomObject();
    std::string animalName = animalObject->getName();

    const std::string& instruction = "Touch the " + animalName + "!";
	
	LabelTTF* label = LabelTTF::create(instruction, "Arial", 60, CCSizeMake(1000, 100), kCCTextAlignmentCenter);
	label->setColor(ccc3(51,255,255));
	label->setPosition(Point(origin.x + 400, origin.y + 70));
	this->addChild(label, 3);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(("objects/"+animalName+".mp3").c_str());
}

/*
void Level1Scene::playSound()

{   
	  //CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(("objects/"+pAnimal+".mp3").c_str());
}

void Level1Scene::setEventHandlers()
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
			target->playSound();
			return true;
		}
		return false;
	};

	//Add listener
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}*/

#include "SettingsScene.h"
void Level1Scene::showSettings(Ref* pSender)
{
	auto newScene = SettingsScene::createScene();
	Director::getInstance()->pushScene(CCTransitionFade::create(0.75f, newScene));
}

#include "MenuScene.h"
void Level1Scene::returnGameMenu(Ref* pSender)
{
	Level1Scene::setTouchSoundEffect();
	auto newScene = MenuScene::createScene();
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));

}


