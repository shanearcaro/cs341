#include <iostream>

#include "../include/node.h"

// Generation number for keeping nodes unique 
int Node::generation = 0;

// Add a new transition state to a node
void Node::addTransition(std::vector<std::string> accept, int id) {
    Transition t(accept, id);
    this->transitions.push_back(t);
}

// Transition to the next node given input
void Node::next(char input) {
    for (int i = 0; i < transitions.size(); i++) {
        std::cout << "Sending [" << input << "]: " << transitions.at(i).getTransitionNode() << std::endl;
        transitions.at(i).transition(input);
    }
}

// Return the state of the node
bool Node::getState() {
    return state;
}

// Get the ID of the node
int Node::getID() {
    return id;
}
