
#ifndef InstructionsScene_h
#define InstructionsScene_h

#include "cocos2d.h"

class InstructionsScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	/**
	@brief  It is called when the player touches the "Return" button.
	@param pSender  The reference to the return button
	*/
	void returnGameMenu(cocos2d::Ref* pSender);

	/**
	@brief  Creates the whole Settings Scene and the transition to this scene.
	@param pSender  The reference to the Settings Scene
	*/
	void showSettings(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(InstructionsScene);

private:

	/**
	@brief  Creates, places and animates the scene title.
	*/
	void createGameTitle();

	/**
	@brief Creates the home button and places it on the screen.
	*/
	void setHomeButton();

	/**
	@brief Creates and places the background for the Instructions Scene.
	*/
	void setBackground();

	/**
	@brief  Set the touch sound effect which will be played when the player touches any button.
	*/
	void setTouchSoundEffect();

	/**
	@brief  Creates and places the button that gets you to the Settings Scene.
	*/
	void setSettingsButton();

	/**
	@brief  Set the background music for the Instructions Scene.
	*/
	void setBackgroundMusic();
};

#endif // InstructionsScene