#pragma once

#include <SFML/Graphics.hpp>
#include "DoubleLinkedList.h"

class MapDisplay {
public:
    MapDisplay(const char* imagePath);
    void displayMap(sf::RenderWindow& window);

private:
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
};


