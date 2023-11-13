#include "../include/ApplicationManager.h"



ApplicationManager::ApplicationManager(const char* imagePath)
    : mapDisplay(imagePath), window(sf::VideoMode(1100, 820), "Map Display") {


    if (!menuSoundBuffer.loadFromFile("./resources/gta-menu.wav")) {
        std::cerr << "Failed to load menu sound." << std::endl;
    }
    if(!selectSoundBuffer.loadFromFile("./resources/gta-menu (1).wav")) {
		std::cerr << "Failed to load select sound." << std::endl;
	}
    if(!clickSoundBuffer.loadFromFile("./resources/gta-menu (2).wav")){
        std::cerr << "Failed to load select sound." << std::endl;
     }


    menuSound.setBuffer(menuSoundBuffer);
    selectSound.setBuffer(selectSoundBuffer);
    clickSound.setBuffer(clickSoundBuffer);
}

void ApplicationManager::run() {
    playMenuSound();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            inputHandler.handleInput(event, window);
        }

        if (inputHandler.isMouseClicked()) {
            std::string clickedButton = mapDisplay.getClickedButton(inputHandler.getMousePosition());
            if (!clickedButton.empty()) {
                handleButtonClick(clickedButton);
                selectMenuSound();
            }
            else if (clickedButton.empty()) {
                std::cout << "Mouse clicked at: " << inputHandler.getMousePosition().x << ", " << inputHandler.getMousePosition().y << std::endl;
                clickMenuSound();

            }
        }

        window.clear();
        mapDisplay.displayMap(window);
        mapDisplay.displayButtons(window);
        window.display();
    }
}


void ApplicationManager::handleButtonClick(const std::string& buttonName) {

    if (buttonName == "AddRoute") {
        std::cout << "Add Route button clicked." << std::endl;


    }
    else if (buttonName == "DeleteRoute") {
        std::cout << "Delete Route button clicked." << std::endl;
        

    }

}

void ApplicationManager::playMenuSound() {

    menuSound.play();
}

void ApplicationManager::selectMenuSound() {

    selectSound.play();
}

void ApplicationManager::clickMenuSound() {

	clickSound.play();
}
