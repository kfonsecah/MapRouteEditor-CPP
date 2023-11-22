#pragma once

#include "MapDisplay.h"
#include "InputHandler.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ApplicationManager {
public:
    // Constructor
    ApplicationManager(const char* imagePath);

    // Public methods
    void handleButtonClick(const std::string& buttonName);
    void run();
    void playMenuSound();
    void selectMenuSound();
    void clickMenuSound();
    sf::Color getColorFromButton(const std::string& buttonName);

    MapDisplay mapDisplay; // Instance of MapDisplay

    bool isAddingRoute;

private:
    // Private members
    InputHandler inputHandler;
    sf::RenderWindow window;

    sf::SoundBuffer menuSoundBuffer;
    sf::Sound menuSound;

    sf::SoundBuffer selectSoundBuffer;
    sf::Sound selectSound;

    sf::SoundBuffer clickSoundBuffer;
    sf::Sound clickSound;
};
