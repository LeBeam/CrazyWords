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
<<<<<<< HEAD

	// a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    /// Se invoca cuando el jugador presiona el boton 'iniciar juego'
    void startGame(cocos2d::Ref* pSender);
	
    /// Se invoca cuando el jugador presiona el boton 'Trofeos'
    void showAwards(cocos2d::Ref* pSender);
    
    /// Se invoca cuando el jugador presiona el boton 'Opciones'
    void showOptions(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
    /// Crea el titulo del juego y lo anima
    void createGameTitle();

    /// Crea las opciones del menu del juego: los botones Iniciar, Premios, Opciones...
    void createGameMenu();
=======
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
>>>>>>> dbb879cdaa0498ea5226cf7d144475efe5dbfe30
};

#endif // __HELLOWORLD_SCENE_H__
