#ifndef SettingsScene_h
#define SettingsScene_h

#include "cocos2d.h"

class SettingsScene : public cocos2d::Layer
{
public:
    /// there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    /// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    /// Se invoca cuando el jugador presiona el boton 'regresar al inicio'
    void returnGameMenu(cocos2d::Ref* pSender);

	/// Se invoca cuando el jugador presiona el boton de On/Off de musica de fondo
	void turnOnOffMusic(cocos2d::Ref* pSender);

	/// Se invoca cuando el jugador presiona el boton de On/Off de efectos de sonido
	void turnOnOffSound(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(SettingsScene);

private:

	/// Crea el titulo del juego y lo anima
    void createGameTitle();

	/// Crea las opciones del menu, como el icono para regresar al menu del juego
	void createMenu();

	void setBackgroundMenu();

	void setMouseClickEffect();

	void setSoundEffectsButton();

	void setSoundEffectsLabel();

	void setMusicButton();

	void setMusicLabel();

	void setHomeButton();
};

#endif // SettingsScene