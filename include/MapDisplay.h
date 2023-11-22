#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

#include <fstream>

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

	  int getSelectedRoute() const;

	  void drawAllRoutes(sf::RenderWindow& window);

	  std::vector<Route> routes;

	  bool editMode;

	  void showHideRoute();

	  void save_routes();

	  void load_routes();

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

	   
	   Route currentRoute;
};


