#ifndef __MenuScene_SCENE_H__
#define __MenuScene_SCENE_H__

#include <cocos2d.h>

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by Director.
*/
class MenuScene : public cocos2d::Layer
{
public:
	/**
	@brief  there's no 'id' in cpp, so we recommend returning the class instance pointer
	*/
	static cocos2d::Scene* createScene();

	/**
	@brief  Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	*/
	virtual bool init();  

	/**
	@brief  It is called when the player touches the "New Game" button and gets the player to the New Game Scene.
	@param pSender  The reference to the New Game Scene
	*/
	void startGame(cocos2d::Ref* pSender);

	/**
	@brief  It is called when the player touches the "Instructions" button and gets the player to the Instructions Scene.
	@param pSender  The reference to the Instructions Scene
	*/ 
	void showInstructions(cocos2d::Ref* pSender);

	/**
	@brief  It is called when the player touches the "Settings" button and gets the player to the Settings Scene.
	@param pSender  The reference to the Settings Scene
	*/
	void showSettings(cocos2d::Ref* pSender);

	/**
	@brief  It is called when the player touches the "Exit" button. This will be only available on a PC.
	@param pSender  The reference to the exit button
	*/
	void exit(cocos2d::Ref* pSender);

	/**
	@brief  implement the "static create()" method manually
	*/
	CREATE_FUNC(MenuScene);

private:
	/**
	@brief  Creates, places and animates the game title.
	*/
	void createGameTitle();

	/**
	@brief  Creates and places the menu options (New Game, Username, Settings, Exit) for this scene.
	*/
	void createGameMenu();

	/**
	@brief  Sets the background music for the main menu scene.
	*/
	void setMenuMusic();

	/**
	@brief  Places the background for the main menu scene.
	*/
	void setBackground();

	/**
	@brief  Places the personal label of our team, which is located on the left bottom corner.
	*/
	void setPersonalLabel();

	/**
	@brief  Creates and places the button in charge of exiting the app on PC or laptops.
	*/
	void setExitButton();

	/**
	@brief  Creates and places the button that directs to the Instructions Scene.
	*/
	void setInstructionsButton();

	/**
	@brief  Creates and places the button that directs to the Settings Scene.
	*/
	void setSettingsButton();

	/**
	@brief  Creates and places the button that directs to the New Game Scene.
	*/
	void setPlayButton();
};

#endif // __MenuScene_SCENE_H__
