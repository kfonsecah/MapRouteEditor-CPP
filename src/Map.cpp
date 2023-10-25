#include "../include/Map.h"

Map::Map(const std::string& imagePath) : image(imagePath.c_str()) {}

void Map::addRoute(const Route& route) {
    routes.push_back(route);
}

void Map::removeRoute(const std::string& routeName) {
    routes.remove_if([&](const Route& r) { return r.getName() == routeName; });
}

Route& Map::getRoute(const std::string& routeName) {
    for (Route& route : routes) {
        if (route.getName() == routeName) {
            return route;
        }
    }
    throw std::runtime_error("Route not found");
}

void Map::draw() {
    for (const Route& route : routes) {
        route.draw(image);
    }
    image.display("Map with Routes");
}

void Map::saveToFile(const std::string& filename) {

}

void Map::loadFromFile(const std::string& filename) {

}

