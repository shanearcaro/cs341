#include <iostream>

#include "../include/node.h"

// Generation number for keeping nodes unique 
int Node::generation = 0;

// // Add a new transition state to a node
// void Node::addTransition(std::string accept, int id) {
//     Transition t(accept, id);
//     this->transitions.push_back(t);
// }

// Add a new transition state to a node
void Node::addTransition(std::string accept, Node* node) {
    Transition t(accept, this, node);

    std::cout << this << " and " << node << std::endl;
    std::cout << this->getID() << " and " << node->getID() << std::endl;

    this->transitions.push_back(t);
}

// Transition to the next node given input

Node* Node::next(std::string input) {
    return this;
}

// Return the state of the node
bool Node::getState() {
    return state;
}

// Get the ID of the node
int Node::getID() {
    return id;
}
