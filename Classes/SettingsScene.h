#ifndef SettingsScene_h
#define SettingsScene_h

#include "cocos2d.h"

class SettingsScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	/**
	@brief  It is called when the player touches the "Return" button.
	*/
	void returnGameMenu(cocos2d::Ref* pSender);

	/**
	@brief It is called when the player touches the "Music On/Off" button, this method turns on and turns off the background music.
	*/
	void turnOnOffMusic(cocos2d::Ref* pSender);

	/**
	@brief It is called when the player touches the "Effects On/Off" button, this method turns on and turns off the effect sounds.
	*/
	void turnOnOffSound(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(SettingsScene);

private:

	/**
	@brief Creates, places and animates the scene title.
	*/
	void createGameTitle();

	/**
	@brief Creates and places the menu options, as well as the "Home" button.
	*/
	void createMenu();

	/**
	@brief Creates and places the background for the Settings Scene.
	*/
	void setBackground();

	/**
	@brief  Set the touch sound effect which will be played when the player touches any button.
	*/
	void setTouchSoundEffect();

	/**
	@brief Creates and places the sound effect button that will turn on or off the sound effects.
	*/
	void setSoundEffectsButton();

	/**
	@brief  Creates and places the sound effect label next to the sound effect button.
	*/
	void setSoundEffectsLabel();

	/**
	@brief  Creates and places the music button that will turn on or off the background music.
	*/
	void setMusicButton();

	/**
	@brief  Creates and places the music label next to the music button.
	*/
	void setMusicLabel();

	/**
	@brief Creates the home button and places it on the screen.
	*/
	void setHomeButton();
};

#endif // SettingsScene