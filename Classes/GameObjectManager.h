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
	bool loadObjects();

public:
	GameObject* getNextRandomObject();

	GameObject* getRandomObject(int position);

	GameObject* getObject(int position);

	~GameObjectManager();

	void shuffleAnimals();

	void shuffleFruits();
};

#endif
