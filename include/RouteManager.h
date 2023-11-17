#pragma once

#include <vector>

#include "Route.h"

class RouteManager {

    std::vector < Route > routes;
    int selected_route;

public:

    RouteManager();
    void add_route();

};