#ifndef GameObjectManager_h
#define GameObjectManager_h

#include <vector>
#include "GameObject.h"
//#include "String.h"

class GameObjectManager
{
protected:
	
	/**
	@brief This vector will save the objects that will be used then
	*/
	std::vector<GameObject*> objects;

	/**
	@brief A index to access to another object in the vector
	*/
	size_t nextObjectIndex;

 public:

	/**
	@brief This method will load the objects and save them in the vector
	*/
	bool loadObjects();

public:

	/**
	@brief This method will take an object out of the vector, randomly
	return The address of the object that was taken out
	*/
	GameObject* getNextRandomObject();

	/**
	@brief This method will take randomly an object out of the vector
	@param position This value will be used to calculate the position of the object that is going to be taken out
	return The address of the object that was taken out
	*/
	GameObject* getRandomObject(int position);

	/**
	@brief This method will take randomly an object out of the vector
	@param position This value is the position of the object that is going to be taken out
	return The address of the object that was taken out
	*/
	GameObject* getObject(int position);

	/**
	@brief The destructor of this class, this will delete the objects inside the vector and the vector itself
	*/
	~GameObjectManager();

	/**
	@brief This method randomly shuffle the objects inside the vector
	*/
	void shuffleAnimals();

	/**
	@brief This method randomly shuffle the objects inside the vector
	*/
	void shuffleFruits();
};

#endif
