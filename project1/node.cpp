#include <iostream>

#include "node.h"

int Node::generation = 0;

void Node::addTransition(std::vector<std::string> accept, int id) {
    Transition t(accept, id);
    this->transitions.push_back(t);
}

void Node::next(char input) {
    for (int i = 0; i < transitions.size(); i++) {
        std::cout << "Sending [" << input << "]: " << transitions.at(i).getTransitionNode() << std::endl;
        transitions.at(i).transition(input);
    }
}

bool Node::getState() {
    return state;
}

int Node::getID() {
    return id;
}
