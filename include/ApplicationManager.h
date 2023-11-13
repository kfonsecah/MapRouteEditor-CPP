#pragma once

#include "MapDisplay.h"
#include "InputHandler.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ApplicationManager {
public:
    ApplicationManager(const char* imagePath);
    void handleButtonClick(const std::string& buttonName);
    void run();
    void playMenuSound();
    void selectMenuSound();
    void clickMenuSound();

private:
    MapDisplay mapDisplay;
    InputHandler inputHandler;
    sf::RenderWindow window;

    sf::SoundBuffer menuSoundBuffer;  
    sf::Sound menuSound;

    sf::SoundBuffer selectSoundBuffer;
    sf::Sound selectSound;

    sf::SoundBuffer clickSoundBuffer;
    sf::Sound clickSound;
};