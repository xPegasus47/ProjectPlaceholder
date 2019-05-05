#pragma once
#include "stdafx.h"


class Game
{
public:
	void Start();
	sf::Time getElapsed();
	void restartClock();

private:
	void update();
	void render();
	void handlePlayerInput();
	bool IsExiting();
	void GameLoop();
	sf::Sprite player;
	sf::Clock _Clock;
	sf::Time _Elapsed;

	void ShowSplashScreen();
	void ShowMenu();

	enum GameState {
		Uninitialized, ShowingSplash, ShowingMenu, Playing, Exiting, Continue
	};

	enum PlayState {
		Paused, Menu, None
	};

	static int _side;
	static GameState _gameState;
};