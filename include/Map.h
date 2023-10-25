#pragma once

#include "Route.h" 
#include "../include/CImg.h"  // Biblioteca CImg
#include <string> 

class Map {
private:
    cimg_library::CImg<unsigned char> image;
    std::list<Route> routes;

public:
    Map(const std::string& imagePath);

    void addRoute(const Route& route);
    void removeRoute(const std::string& routeName);
    Route& getRoute(const std::string& routeName);

    void draw();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};




