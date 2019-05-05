#pragma once
#include "stdafx.h"

#pragma once
#include <list>
class MainMenu
{

public:
   enum MenuResult { Nothing, Exit, PlayLight, PlayDark, Options };

   struct MenuItem
     {
     public:
       sf::IntRect rect;
       MenuResult action;
     };

   MenuResult Show(sf::RenderWindow& window);

private:
   MenuResult GetMenuResponse(sf::RenderWindow& window);
   std::vector<MenuItem> _menuItems;
 };

