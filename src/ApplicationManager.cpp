#include "../include/ApplicationManager.h"

ApplicationManager::ApplicationManager(const char* imagePath) :
    mapDisplay(imagePath),
    window(sf::VideoMode(1100, 820), "Map Display") {

}

void ApplicationManager::run() {

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            inputHandler.handleInput(event, window);
        }

        if (inputHandler.isMouseClicked()) {
            std::cout << "Mouse clicked at: " << inputHandler.getMousePosition().x << ", " << inputHandler.getMousePosition().y << std::endl;
        }

        window.clear();
        mapDisplay.displayMap(window);
        window.display();
    }
}





