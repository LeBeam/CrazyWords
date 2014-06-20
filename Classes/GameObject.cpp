#include "GameObject.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

bool GameObject::loadFile(std::ifstream& file)
{
	if ( ! std::getline(file, name) ) return false;
	setTexture("objects/"+name+".png");
	return true;
}

GameObject* GameObject::create()
{
	GameObject *gameObject = new GameObject();
	if (gameObject && gameObject->init())
	{
		gameObject->autorelease();
		return gameObject;
	}
	CC_SAFE_DELETE(gameObject);
	return nullptr;
}

void GameObject::setEventHandlers()
{
	//Create a "one by one" touch event listener (processes one touch at a time)
	auto listener = EventListenerTouchOneByOne::create();
	// When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
	listener->setSwallowTouches(true);

	// Example of using a lambda expression to implement onTouchBegan event callback function
	listener->onTouchBegan = CC_CALLBACK_2(GameObject::onTouchBegan, this);

	//Add listener
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool GameObject::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto target = static_cast<GameObject*>(event->getCurrentTarget());

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
}

void GameObject::playSound()
{   
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(("objects/"+name+".mp3").c_str());
}





