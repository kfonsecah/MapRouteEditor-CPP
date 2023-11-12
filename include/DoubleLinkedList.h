
#pragma once
#include "Node.h"
#include <string>


class DoubleLinkedList {
public:
    DoubleLinkedList(std::string name);
    void addNode(int x, int y);
    void deleteNode(Node* node);
    void deleteRoute();
    const std::string& getRouteName() const;

private:
    std::string routeName;
    Node* head;
    Node* tail;
};




