#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

#include "Route.h"

#include <vector>

class MapDisplay {
public: MapDisplay(const char* imagePath);
	  void displayMap(sf::RenderWindow& window);
	  void loadButtonTextures();
	  void configureButtonSprites();
	  void displayButtons(sf::RenderWindow& window);
	  void addRoute();
	  void deleteRoute();
	  

	  int selected_route;

	  std::string getClickedButton(sf::Vector2i mousePosition);

	  Route& getCurrentRoute();

	  void change_selected_route(int route_id);

	  int getSelectedRoute() const;

	  void drawAllRoutes(sf::RenderWindow& window);

private: sf::Texture mapTexture;
	   sf::Sprite mapSprite;
	   sf::Texture textureAdd,
		   textureDelete,
		   textureEdit,
		   textureSave,
		   textureShowHide,
		   textureUpload;
	   sf::Sprite spriteAdd,
		   spriteDelete,
		   spriteEdit,
		   spriteSave,
		   spriteShowHide,
		   spriteUpload;


	   CircleShape redCircle;
	   CircleShape blueCircle;
	   CircleShape greenCircle;

	   std::vector<Route> routes;
	   Route currentRoute;
};


