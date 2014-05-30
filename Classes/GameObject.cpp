#include "GameObject.h"

bool GameObject::loadFile(std::ifstream& file)
{
	if ( ! std::getline(file, text) ) return false;

	return true;
}
