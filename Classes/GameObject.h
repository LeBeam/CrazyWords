#ifndef Object_h
#define Object_h

#include <fstream>
#include <string>
#include <cocos2d.h>

class GameObject : public cocos2d::Sprite
{
public:
	class Delegate
	{
	public:
		virtual bool gameObjectTouched(GameObject* touchedObject) = 0;

	};

public:

	GameObject();

	/**
	@brief Creates the scene that will be used to place all the objects
	*/
	static GameObject* create();

	/**
	@brief  This method receives a file that is going to be loaded and then it will take every line from the file
			and save it in a variable.
	@param file  the file contains the name of every object that is going to be used in the game.
	*/
	bool loadFile(std::ifstream& file);

	/**
	@brief  This method take the content of the variable that was declared for returning it later.
	@return string The string that is contained in the object
	*/
	inline const std::string& getName() const { return name; }

	/**
	@brief Sets the handlers that will control the actions when and object is touched
	*/
	void setEventHandlers();

	/**
	@brief Plays a sound of an object
	*/
	void playSound();

	/**
	@brief This method sets some actions when you touch and object
	*/
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	/**
	@brief This method sets some actions when you end touching an object
	*/
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	/**
	@brief  This refers to each line in the file that is going to be loaded.
	*/

	inline void setDelegate(Delegate* delegate){ this->delegate = delegate;}

private:

	/**
	@brief This object will save the name of an object
	*/
	std::string name;

	Delegate* delegate;

public:

	/**
	@brief This object will save the name of an object that has been touched
	*/
	static std::string touchedObject;
	
};

#endif
