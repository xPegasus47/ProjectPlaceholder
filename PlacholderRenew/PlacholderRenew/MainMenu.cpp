#pragma once
#include "MainMenu.h"


MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	unsigned int select = 0;

	while (true)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					// move left...
					if (select - 1 <= 0)
					{
						select = 0;
					}
					else
					{
						select -= 1;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					if (select + 1 <= _menuItems.size())
					{
						select = (_menuItems.size() - 1);
					}
					else
					{
						select += 1;
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					// move left...
					if (select - 1 <= 0)
					{
						select = 0;
					}
					else
					{
						select -= 1;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					if (select + 1 <= _menuItems.size())
					{
						select = (_menuItems.size() - 1);
					}
					else
					{
						select += 1;
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
				{
					return _menuItems[select].action;
				}
			}
		}
	}
}

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	sf::Texture menuImage;
	menuImage.loadFromFile("./Images/MainMenu.png");

	sf::Sprite sprite;
	sprite.setTexture(menuImage);

	MenuItem playLight;
	playLight.rect.top = 0;
	playLight.rect.left = 0;
	playLight.rect.width= 100;
	playLight.rect.height = 100;
	playLight.action = PlayLight;

	MenuItem playDark;
	playDark.rect.top = 145;
	playDark.rect.left = 145;
	playDark.rect.width = 100;
	playDark.rect.height = 100;
	playDark.action = PlayDark;

	MenuItem exitBtn;
	exitBtn.rect.top = 300;
	exitBtn.rect.left = 300;
	exitBtn.rect.width = 80;
	exitBtn.rect.height = 80;
	exitBtn.action = Exit;

	_menuItems.push_back(playLight);
	_menuItems.push_back(playDark);
	_menuItems.push_back(exitBtn);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

