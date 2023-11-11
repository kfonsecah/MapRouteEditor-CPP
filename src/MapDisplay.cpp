#include "../include/MapDisplay.h"

MapDisplay::MapDisplay(const char* imagePath) : mapTexture(), mapSprite() {
    if (!mapTexture.loadFromFile(imagePath)) {
    }
    mapSprite.setTexture(mapTexture);

    float scale = std::min(1100.0f / mapSprite.getLocalBounds().width, 820.0f / mapSprite.getLocalBounds().height);
    mapSprite.setScale(scale, scale);
}

void MapDisplay::displayMap(sf::RenderWindow& window) {
    window.draw(mapSprite);
}

