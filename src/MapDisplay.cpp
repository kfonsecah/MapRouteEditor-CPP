#include "../include/MapDisplay.h"

MapDisplay::MapDisplay(const char* imagePath) : mapTexture(), mapSprite(), selected_route(-1) {
    if (!mapTexture.loadFromFile(imagePath)) {
    }
    mapSprite.setTexture(mapTexture);

    float scale = std::min(1100.0f / mapSprite.getLocalBounds().width, 824.0f / mapSprite.getLocalBounds().height);
    mapSprite.setScale(scale+0.001, scale);

	loadButtonTextures();
	configureButtonSprites();

	redCircle.setRadius(20);
	redCircle.setFillColor(Color::Red);
	redCircle.setPosition(875, 745);

	blueCircle.setRadius(20);
	blueCircle.setFillColor(Color::Blue);
	blueCircle.setPosition(935, 745);

	greenCircle.setRadius(20);
	greenCircle.setFillColor(Color::Green);
	greenCircle.setPosition(995, 745);
}


void MapDisplay::loadButtonTextures() {
	try {
		if (!textureAdd.loadFromFile("./resources/ButtonAdd.jpg")) {
			throw std::runtime_error("Failed to load ButtonAdd texture");
		}
}   catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		if (!textureDelete.loadFromFile("./resources/ButtonDelete.jpg")) {
			throw std::runtime_error("Failed to load ButtonDelete texture");
		}
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		if (!textureEdit.loadFromFile("./resources/ButtonEdit.jpg")) {
			throw std::runtime_error("Failed to load ButtonEdit texture");
		}
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		if (!textureSave.loadFromFile("./resources/ButtonSave.jpg")) {
			throw std::runtime_error("Failed to load ButtonSave texture");
		}
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		if (!textureShowHide.loadFromFile("./resources/ButtonShow_Hide.jpg")) {
			throw std::runtime_error("Failed to load ButtonShowHide texture");
		}
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		if (!textureUpload.loadFromFile("./resources/ButtonUpload.jpg")) {
			throw std::runtime_error("Failed to load ButtonUpload texture");
		}
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	/*try {
		if (!textureAdd.loadFromFile("./resources/cross.g")) {
			throw std::runtime_error("Failed to load cross texture");
		}
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	*/
}

void MapDisplay::configureButtonSprites() {
	float buttonScale = 0.2f; 

	spriteAdd.setTexture(textureAdd);
	spriteDelete.setTexture(textureDelete);
	spriteEdit.setTexture(textureEdit);
	spriteSave.setTexture(textureSave);
	spriteShowHide.setTexture(textureShowHide);
	spriteUpload.setTexture(textureUpload);


	spriteAdd.setScale(buttonScale+0.001, buttonScale+0.001);
	spriteDelete.setScale(buttonScale, buttonScale);
	spriteEdit.setScale(buttonScale-0.01, buttonScale-0.001);
	spriteSave.setScale(buttonScale, buttonScale);
	spriteShowHide.setScale(buttonScale, buttonScale);
	spriteUpload.setScale(buttonScale, buttonScale);


	spriteAdd.setPosition(855, 170);
	spriteDelete.setPosition(834, 270);
	spriteEdit.setPosition(834, 220);
	spriteSave.setPosition(834, 520);
	spriteShowHide.setPosition(840, 370);
	spriteUpload.setPosition(831, 560);


}

void MapDisplay::displayButtons(sf::RenderWindow& window) {

	window.draw(spriteAdd);
	window.draw(spriteDelete);
	window.draw(spriteEdit);
	window.draw(spriteSave);
	window.draw(spriteShowHide);
	window.draw(spriteUpload);

	window.draw(redCircle);
	window.draw(blueCircle);
	window.draw(greenCircle);

	// debug routes printing

}


void MapDisplay::displayMap(sf::RenderWindow& window) {
	// display each <route> by calling .draw on route
	window.draw(mapSprite);
	currentRoute.draw(window);

	
}

std::string MapDisplay::getClickedButton(sf::Vector2i mousePosition) {
	if (spriteAdd.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		return "AddRoute";
	}
	else if (spriteDelete.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		return "DeleteRoute";
	}
	else if (spriteEdit.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		return "EditRoute";
	}
	else if (spriteSave.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		return "Save";
	}
	else if (spriteShowHide.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		return "ShowHide";
	}
	else if (spriteUpload.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		return "Upload";
	}
	else if (redCircle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		return "Rojo";
	}
	else if (blueCircle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		return "Azul";
	}
	else if (greenCircle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
		return "Verde";
	}
	return "";
}

void MapDisplay::addRoute() {

	if (selected_route != -1) {
		Route newRoute;
		routes.push_back(newRoute);

		currentRoute = routes[selected_route];
		selected_route = routes.size() - 1;
	}
	else if (selected_route == -1) {
		Route newRoute;
		routes.push_back(newRoute);

		
		selected_route = routes.size() - 1;
	}
	else {
		std::cout << "No route selected" << std::endl;
	}

	std::cout << "Selected Route: " << selected_route << std::endl;

}

void MapDisplay::deleteRoute() {
	routes.erase(routes.begin() - selected_route);
	selected_route = -1;
}

Route& MapDisplay::getCurrentRoute() {
	return currentRoute;
}

int MapDisplay::getSelectedRoute() const {
	return selected_route;
}

void MapDisplay::drawAllRoutes(sf::RenderWindow& window) {
	for (int i = 0; i < routes.size(); i++) {
		routes[i].draw(window);
	}
}
