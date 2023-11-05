#ifndef NODE_H
#define NODE_H

class Node {
public:
    int x, y; 
    Node* prev; 
    Node* next; 

    Node(int x, int y); 
};

#endif 
