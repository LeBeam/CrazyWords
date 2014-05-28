#include "Util.h"
#include "Object.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

bool Util::loadAnimals()
{
	std::ifstream file("animalsFile.txt");

	while ( true )
	{
		Object* object = new Object();
		if ( ! object->loadFile(file) )
		{ 
			break;
		}
		animals.push_back(object);
	}
	file.close();
	return true;
}

std::string Util::getAnimals()
{
	std::string charChosenAnimal;
	srand( time(nullptr) );
	while ( true )
	{
		int azar = (signed int)rand() % animals.size();
		charChosenAnimal = animals[azar]->getObject();
	}
	return charChosenAnimal;
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