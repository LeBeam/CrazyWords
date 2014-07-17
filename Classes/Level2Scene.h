#ifndef Level2Scene_h
#define Level2Scene_h

#include "cocos2d.h"
#include <ctime>
#include <cstdlib>
#include <CCSprite.h>
#include "GameObjectManager.h"

class Level2Scene : public cocos2d::Layer
{
public:

	/**
	@brief Creates the scene that will be used to place all the objects
	*/
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
	CREATE_FUNC(Level2Scene);

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
	@brief Sets and shows the host of the game
	*/
	void showHost();

	/**
	@brief Set the instruction for the level
	*/
	void setInstructionLabel();

	/**
	@brief Set the fruit that is going to be on the screen
	*/
	void showFruits();

	/**
	@brief Sets the color of the fruit, which is going to be used to paint the fruit
	*/
	void setFruitColor();

	/**
	@brief Set the red color button on the screen with the sound
	*/
	void setRedColorButton();

	/**
	@brief Set the blue color button on the screen with the sound
	*/
	void setBlueColorButton();

	/**
	@brief Set the orange color button on the screen with the sound
	*/
	void setOrangeColorButton();

	/**
	@brief Set the purple color button on the screen with the sound
	*/
	void setPurpleColorButton();

	/**
	@brief Set the yellow color button on the screen with the sound
	*/
	void setYellowColorButton();

	/**
	@brief Set the fruit that is painted after touching the right color
	*/
	void setPaintedFruit();

	/**
	@brief Set all the color buttons, that were created separetely
	*/
	void setColorButtons();

	/**
	@brief Sets a different background music
	*/
	void setPlayingMusic();

protected:

	/**
	@brief This object helps to create an object that will be used for different purposes
	*/
	GameObjectManager gameObjectManager;

	/**
	@brief Contains the color according the fruit
	*/
	std::string fruitColor;

	/**
	@brief Contains the name of the fruit that will be painted
	*/
	std::string paintedFruit;
};

#endif // Level2Scene