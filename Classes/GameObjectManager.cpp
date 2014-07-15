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

bool GameObjectManager::loadObjects(std::string nameFile)
{
	const std::string& filename = cocos2d::FileUtils::getInstance()->fullPathForFilename("objects/"+nameFile+".txt");
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

GameObject* GameObjectManager::getRandomObject()
{
	size_t azar = rand() % objects.size();
	return objects[azar];
}

void GameObjectManager::shuffle()
{ 
   std::random_shuffle(objects.begin(), objects.end());
}

GameObject* GameObjectManager::getNextRandomObject()
{
	return objects[nextObjectIndex++];
}

