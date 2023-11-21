#pragma once

#include <SFML/Graphics.hpp>

#include "MapDisplay.h"

#include "Node.h"

#include <iostream>


class InputHandler {
public: InputHandler();
	  void handleInput(const sf::Event& event, sf::RenderWindow& window);
	  bool isMouseClicked();
	  sf::Vector2i getMousePosition() const;

	  void handleAddRoute(sf::RenderWindow& window, MapDisplay& mapDisplay);


private: bool mouseClicked;
	   sf::Vector2i mousePosition;
	   sf::Clock clickClock;
	   const sf::Time clickThreshold = sf::milliseconds(200);

};



