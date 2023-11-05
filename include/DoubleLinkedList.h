#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <string>

class DoublyLinkedList {
private:
    Node* head; 
    Node* tail; 
    std::string routeName; 


public:
    DoublyLinkedList(std::string name);
    void addNode(int x, int y); 
    void deleteNode(Node* node); 
    void deleteRoute(); 

};

#endif 
