#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class MapDisplay {
public:
    MapDisplay(const char* imagePath);
    void displayMap(sf::RenderWindow& window);
    void loadButtonTextures();
    void configureButtonSprites();
    void displayButtons(sf::RenderWindow& window);

    std::string getClickedButton(sf::Vector2i mousePosition);


private:
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    sf::Texture textureAdd, textureDelete, textureEdit, textureSave, textureShowHide, textureUpload;
    sf::Sprite spriteAdd, spriteDelete, spriteEdit, spriteSave, spriteShowHide, spriteUpload;
};



