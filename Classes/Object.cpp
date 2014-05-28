#include "Object.h"

bool Object::loadFile(std::ifstream& file)
{
	if ( ! std::getline(file, text) ) return false;

	return true;
}

std::string Object::getObject()
{
	return text;
}