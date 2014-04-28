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

	// a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    /// Se invoca cuando el jugador presiona el boton 'New Game'
    void startGame(cocos2d::Ref* pSender);

	/// Se invoca cuando el jugador presiona el boton 'Instructions'
    void showInstructions(cocos2d::Ref* pSender);
	
    /// Se invoca cuando el jugador presiona el boton 'Settings'
    void showSettings(cocos2d::Ref* pSender);

	/// Se invoca cuando el jugador presiona el boton 'Exit'
	void exit(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
    /// Crea el titulo del juego y lo anima
    void createGameTitle();

    /// Crea las opciones del menu del juego: los botones Iniciar, Premios, Opciones...
    void createGameMenu();
};

#endif // __HELLOWORLD_SCENE_H__
