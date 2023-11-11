#pragma once

#include "MapDisplay.h"
#include "InputHandler.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class ApplicationManager {
public:
    ApplicationManager(const char* imagePath);
    void run();

private:
    MapDisplay mapDisplay;
    InputHandler inputHandler;
    sf::RenderWindow window;
};



