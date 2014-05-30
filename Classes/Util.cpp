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
	size_t azar = rand() % animals.size();
	return animals[azar]->getText();
}

/*
int Util::getAnimals()
{
srand( time(nullptr) );
while ( true )
{
size_t azar = rand() % animals.size();
animals[azar]->();
}

return 0;
}
/*
#include "Util.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

///using namespace std;

Util::Util(void)
{
}

bool Util::loadFile(std::ifstream& file)
{
if ( ! std::getline(file, animal) ) return false;

return true;
}

bool Util::loadAnimals()
{
std::ifstream file("animalsFile.txt");
char* animal = new char*;
if ( ! animal->loadFile(file) )
{
break;
}
animals.push_back(animal);

file.close();
return true;
}

std::string Util::getAnimal(int random)
{
std::string chosenAnimal = animals[random];

return chosenAnimal;
}

const char* Util::getAnimal(int random)
{
const char* chosenAnimal = animals[random];

return chosenAnimal;
}

*/
