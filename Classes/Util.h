#ifndef Util_h
#define Util_h

#include <vector>
#include "GameObject.h"

class Util
{
protected:
	std::vector<GameObject*> animals;

private:

public:	bool loadAnimals();

public:
	std::string getRandomAnimalName();
	~Util();
};

#endif



/*
#ifndef UTIL_H
#define UTIL_H

#include <fstream>
#include <vector>

class Util
{
private:
std::vector<char*> animals;

protected:
const char* animal;

public:
Util();

private:
bool loadFile(std::ifstream& file);
bool loadAnimals();

protected:
const char* getAnimal(int random);

};

#endif

*/

