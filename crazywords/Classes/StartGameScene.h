
#ifndef StartGameScene_h
#define StartGameScene_h


#include "cocos2d.h"

class StartGameScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	/// It is called when the player touches the "Return" button
	//void returnGameMenu(cocos2d::Ref* pSender);

	/// Creates the whole Settings Scene and the transition to this scene.
	void showSettings(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(StartGameScene);

private: 

	/// Creates and places the background for the Instructions Scene.
	void setBackground();

	/// Creates and places the button that gets you to the Settings Scene
	void setSettingsButton();

};

#endif // StartGameScene

