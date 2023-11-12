// Route.h
#pragma once
#include "DoubleLinkedList.h"

class Route {
public:
    Route(const std::string& name);
    const std::string& getName() const;
    DoubleLinkedList& getNodesList();

private:
    std::string name;
    DoubleLinkedList nodesList;
};


s