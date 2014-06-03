#ifndef GameObjectManager_h
#define GameObjectManager_h

#include <vector>
#include "GameObject.h"

class GameObjectManager
{
protected:
	std::vector<GameObject*> objects;

	size_t nextObjectIndex;

    public:	bool loadAnimals();

public:
	GameObject* getNextRandomObject();

	GameObject* getRandomObject();

	~GameObjectManager();

	void shuffle();
};

#endif
