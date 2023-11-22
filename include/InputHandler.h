#pragma once

#include <SFML/Graphics.hpp>
#include "MapDisplay.h"
#include "Node.h"
#include <iostream>

class InputHandler {
public:
    // Constructor
    InputHandler();

    // Public methods
    void handleInput(const sf::Event& event, sf::RenderWindow& window);
    bool isMouseClicked();
    void handleAddNode(sf::RenderWindow& window, MapDisplay& mapDisplay);
    void handleDeleteNode(sf::RenderWindow& window, MapDisplay& mapDisplay);

    sf::Vector2i getMousePosition() const;

private:
    // Private members
    bool mouseClicked;
    sf::Vector2i mousePosition;
    sf::Clock clickClock;
    const sf::Time clickThreshold = sf::milliseconds(200);
};



