#ifndef StartGameScene_h
#define StartGameScene_h

#include "cocos2d.h"
#include <ctime>
#include <cstdlib>

class StartGameScene : public cocos2d::Layer
{
public:
	cocos2d::Sprite *animalSprite;

	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	/**
	@brief Creates the whole Settings Scene and the transition to this scene.
	@param pSender  the reference to the Settings Scene
	*/
	void showSettings(cocos2d::Ref* pSender);
	
	/**
	@brief It is called when the player touches the "Return" button.
	@param pSender  the reference to the "Return" button
	*/
	void returnGameMenu(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(StartGameScene);

private: 

	/**
	@brief  Creates and places the background for the Instructions Scene.
	*/
	void setBackground();

	/**
	@brief  Creates and places the button that gets you to the Settings Scene.
	*/
	void setSettingsButton();

	/**
	@brief  Creates and places the button that gets back to the Home Scene.
	*/
	void setHomeButton();

	/**
	@brief Set the touch sound effect which will be played when the player touches any button.
	*/
	void setTouchSoundEffect();

	/**
	@brief  This method gives the position to the sprite
	@param chosenAnimal  The name of the object we are dealing with.
	@param i  The position related to the x axis
	@param j  The position related to the y axis
	*/
	void setChosenAnimal(int i, int j);

	/**
	@brief  This methods is in charge of setting every animal sprite on the screen with the touch effect sound.
	*/
	void showAnimals();

	/**
	@brief  This method is in charge of setting the name of the animal that is going to be used in other methods.
	*/
	std::string setSelectedAnimal();

protected:
	/**
	@brief  This method is in charge of setting the action that will be played once you touch any sprite
	*/
	void setEventHandlers();

	/**
	@brief  Sets the related sound of the sprite
	*/
	void placeAnimalPronunciation();
};

#endif // StartGameScene

