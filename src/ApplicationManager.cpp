#include "../include/ApplicationManager.h"

ApplicationManager::ApplicationManager(const char* imagePath) : mapDisplay(imagePath), window(sf::VideoMode(1100, 820), "Map Display") {
    if (!menuSoundBuffer.loadFromFile("./resources/gta-menu.wav")) {
        std::cerr << "Failed to load menu sound." << std::endl;
    }
    if (!selectSoundBuffer.loadFromFile("./resources/gta-menu (1).wav")) {
        std::cerr << "Failed to load select sound." << std::endl;
    }
    if (!clickSoundBuffer.loadFromFile("./resources/gta-menu (2).wav")) {
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
                if (inputHandler.getMousePosition().x < 826) {
                    if (mapDisplay.editMode) {
                        std::cout << "nodo poof" << std::endl;
                        inputHandler.handleDeleteNode(window, mapDisplay);
                    }
                    else {
                        inputHandler.handleAddNode(window, mapDisplay);
                    }
                }
            }
        }

        window.clear();
        mapDisplay.displayMap(window);
        mapDisplay.displayButtons(window);
        window.display();
    }
}

Color ApplicationManager::getColorFromButton(const std::string& buttonName) {
    if (buttonName == "Rojo") {
        return Color::Red;
    }
    else if (buttonName == "Azul") {
        return Color::Blue;
    }
    else if (buttonName == "Verde") {
        return Color::Green;
    }

    return Color::White;
}

void ApplicationManager::handleButtonClick(const std::string& buttonName) {
    if (buttonName == "AddRoute") {
        std::cout << "Ruta Agregada" << std::endl;
        mapDisplay.addRoute();
    }
    else if (buttonName == "DeleteRoute") {
        std::cout << "Ruta Eliminada." << std::endl;
        mapDisplay.deleteRoute();
    }
    else if (buttonName == "Rojo" || buttonName == "Azul" || buttonName == "Verde") {
        mapDisplay.routes[mapDisplay.getSelectedRoute()].changeRouteColor(getColorFromButton(buttonName));
        std::cout << "Ruta " << buttonName << "." << std::endl;
    }
    else if (buttonName == "ShowHide") {
        std::cout << "Ruta Mostrada/Oculta." << std::endl;
    }
    else if (buttonName == "Edit") {
        std::cout << "Modo editar activado." << std::endl;
        mapDisplay.editMode = !mapDisplay.editMode; // swap mode on/off
    }
    else if (buttonName == "Save") {
        mapDisplay.save_routes();
        std::cout << "Ruta Guardadao." << std::endl;
    }
    else if (buttonName == "Upload") {
        mapDisplay.load_routes();
        std::cout << "Ruta Cargada." << std::endl;
    }
    else if (buttonName == "Edit") {
        std::cout << "Ruta Editada." << std::endl;
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
