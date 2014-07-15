#ifndef GameObjectManager_h
#define GameObjectManager_h

#include <vector>
#include "GameObject.h"
#include "String.h"

class GameObjectManager
{
protected:
	std::vector<GameObject*> objects;

	size_t nextObjectIndex;

 public:	
	bool loadObjects(std::string nameFile);

public:
	GameObject* getNextRandomObject();

	GameObject* getRandomObject();

	~GameObjectManager();

	void shuffle();
};

#endif
