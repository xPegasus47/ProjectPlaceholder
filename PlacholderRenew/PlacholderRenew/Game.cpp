#include "Game.h"

void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1200, 1040, 32), "Requiem");

	_gameState = Game::ShowingSplash;

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}



bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	switch (_gameState)
	{
	case Game::ShowingMenu:
	{
		ShowMenu();
		break;
	}
	case Game::ShowingSplash:
	{
		ShowSplashScreen();
		break;
	}
	case Game::Playing:
	{
		handlePlayerInput();
		update();
		render();
		break;
	}
	}
}

void Game::handlePlayerInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		ShowMenu();
	}
}


void Game::update()
{
	_mainWindow.update();
}

void Game::render()
{
	_mainWindow.beginDraw();
	//_mainWindow.draw();
	_mainWindow.endDraw();
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

sf::Time Game::getElapsed() { return _Elapsed; }
void Game::restartClock() { _Elapsed = _Clock.restart(); }

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
	{
		_gameState = Game::Exiting;
		break;
	}
	case MainMenu::PlayLight:
	{
		_gameState = Game::Playing;
		_side = 1;
		break;
	}
	case MainMenu::PlayDark:
	{
		_gameState = Game::Playing;
		_side = 0;
		break;
	}
	}
}

// A quirk of C++, static member variables need to be instantiated outside of the class
Game::GameState Game::_gameState = Uninitialized;
Window _mainWindow;
