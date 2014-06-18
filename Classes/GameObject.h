#ifndef Object_h
#define Object_h

#include <fstream>
#include <string>
#include <cocos2d.h>

class GameObject : public cocos2d::Sprite
{

public:

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

	void setEventHandlers();

	void playSound();

	/**
	@brief  This refers to each line in the file that is going to be loaded.
	*/
private:

	std::string name;
public:

	std::string touchObject;
};

#endif
