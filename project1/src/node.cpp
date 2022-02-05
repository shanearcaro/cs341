#include <iostream>

#include "../include/node.h"

void Node::addTransition(std::string accept, int id) {
    Transition t(accept, this->getID(), id);
    this->transitions.push_back(t);
}

// Transition to the next node given input
int Node::next(std::string input) {
    for (int i = 0; i < transitions.size(); i++) {
        Transition* p_temp = &transitions.at(i);
        // If input is a direct match
        if (input.compare(p_temp->getAccept()) == 0) {
            return p_temp->getTo();
        }
        // G is designated for roman lowercase letters
        else if (p_temp->getAccept().compare("G") == 0) {
            // If input is a letter
            if (isalpha(input[0])) {
                return p_temp->getTo();
            }
        }
        else if (p_temp->getAccept().substr(0, 2).compare("G-") == 0) {
            std::string letter = p_temp->getAccept().substr(2);
            if (isalpha(input[0]) && input.compare(letter) != 0) {
                return p_temp->getTo();
            }
        }
    }

    Transition* p_trash = &transitions.back();
    return p_trash->getTo();
}

std::vector<Transition> Node::getTransitions() {
    return this->transitions;
}

// Return the state of the node
bool Node::getState() {
    return state;
}

// Get the ID of the node
int Node::getID() {
    return id;
}

void Node::setID(int id) {
    this->id = id;
}
