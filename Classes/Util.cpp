#include "Util.h"
#include "GameObject.h"

#include <cstdlib>
#include <cocos2d.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

Util::~Util()
{
	for (size_t i = 0; i < animals.size(); ++i )
		delete animals[i];
}

bool Util::loadAnimals()
{
	const std::string& filename = cocos2d::FileUtils::getInstance()->fullPathForFilename("objects/animals.txt");
	std::ifstream file( filename.c_str() );

	while ( true )
	{
		GameObject* object = new GameObject();
		if ( ! object->loadFile(file) )
		{
			break;
		}
		animals.push_back(object);
	}

	file.close();
	return true;
}

std::string Util::getRandomAnimalName()
{
	loadAnimals();
	size_t azar = rand() % animals.size();
	return animals[azar]->getText();
}


