#include "GameObjectManager.h"
#include "GameObject.h"
#include "String.h"

#include <cstdlib>
#include <cocos2d.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

GameObjectManager::~GameObjectManager()
{
	for (size_t i = 0; i < objects.size(); ++i )
		 objects[i]->release();
}

bool GameObjectManager::loadObjects()
{
	const std::string& filename = cocos2d::FileUtils::getInstance()->fullPathForFilename("objects/objects.txt");
	std::ifstream file( filename.c_str() );

	while ( true )
	{
		GameObject* object = GameObject::create();
		if ( ! object->loadFile(file) )
		{
			break;
		}
		objects.push_back(object);
	    object->retain();
	}

	file.close();
	nextObjectIndex = 0;
	return true;
}

GameObject* GameObjectManager::getRandomObject(int position)
{
	size_t azar = rand() % position;
	return objects[azar];
}

GameObject* GameObjectManager::getNextRandomObject()
{
	return objects[nextObjectIndex++];
}

GameObject* GameObjectManager::getObject(int position)
{
	return objects[position];
}

void GameObjectManager::shuffleAnimals()
{ 
	 std::random_shuffle(objects.begin(), (objects.begin()+21));
}

void GameObjectManager::shuffleFruits()
{ 
	std::random_shuffle((objects.begin()+22), objects.end());
}





