#ifndef Util_h
#define Util_h

#include <vector>
#include "Object.h"

class Util
{
protected:
	std::vector<Object::Object*> animals;

private:
	bool loadAnimals();

public:
	std::string getAnimals();
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

