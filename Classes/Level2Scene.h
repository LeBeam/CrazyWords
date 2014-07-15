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

	static cocos2d::Scene* createScene();

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
};

#endif // Level2Scene