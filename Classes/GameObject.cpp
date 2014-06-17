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
	listener->onTouchBegan = [](Touch* touch, Event* event)
	{
		// event->getCurrentTarget() returns the *listener's* sceneGraphPriority node.
		auto target = static_cast<GameObject*>(event->getCurrentTarget());
		target->playSound();

		return true;
	};

	//Add listener
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameObject::playSound()
{   
	  CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(("objects/"+name+".mp3").c_str());
}



