#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
	public:
		// there's no 'id' in cpp, so we recommend returning the class instance pointer
		static cocos2d::Scene* createScene();

		// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
		virtual bool init();  

		/// a selector callback
		void menuCloseCallback(cocos2d::Ref* pSender);
    
		/// It is called when the player touches the "User_Name" button and gets the player to the New Game Scene.
		void startGame(cocos2d::Ref* pSender);

		/// It is called when the player touches the "Instructions" button and gets the player to the Instructions Scene.
		void showInstructions(cocos2d::Ref* pSender);
	
		/// It is called when the player touches the "Settings" button and gets the player to the Settings Scene.
		void showSettings(cocos2d::Ref* pSender);

		/// It is called when the player touches the "Exit" button. This will be only available on a PC.
		void exit(cocos2d::Ref* pSender);
    
		// implement the "static create()" method manually
		CREATE_FUNC(HelloWorld);

	private:
		/// Creates, places and animates the game title.
		void createGameTitle();

		/// Creates and places the menu options (New Game, Username, Settings, Exit) for this scene.
		void createGameMenu();

		/// Sets the background music for the main menu scene.
		void setMenuMusic();

		/// Places the background for the main menu scene.
		void setBackground();

		/// Places the personal label of our team, which is located on the left bottom corner.
		void setPersonalLabel();

		/// Creates and places the button in charge of exiting the app on PC or laptops.
		void setExitButton();

		/// Creates and places the button that directs to the Instructions Scene.
		void setInstructionsButton();
		
		/// Creates and places the button that directs to the Settings Scene.
		void setSettingsButton();

		/// Creates and places the button that directs to the New Game Scene.
		void setPlayButton();
};

#endif // __HELLOWORLD_SCENE_H__
