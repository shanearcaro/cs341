#include <iostream>

#include "../include/node.h"

// Get the current state of a node (if it's an accepting state)
bool Node::getState() {
    return state;
}

// Get the unique id of a node
int Node::getID() {
    return id;
}

// Add a new transition between the current node and a new node
// The transition is only followed if the accept string matches the input string
void Node::addTransition(std::string accept, int id) {
    Transition t(accept, this->getID(), id);
    this->transitions.push_back(t);
}

// Get a list of all transitions a node has
std::vector<Transition> Node::getTransitions() {
    return this->transitions;
}

// Given an input character determine which transition should be followed
// Return the node id of the transitioned to node
int Node::next(std::string input) {
    // Iterate through every transition looking for an accept
    // If a transition is never found follow the trash transition (the last transition)
    for (int i = 0; i < transitions.size() - 1; i++) {
        Transition* p_temp = &transitions.at(i);
        // If input is a direct match
        if (input.compare(p_temp->getAccept()) == 0) {
            return p_temp->getTo();
        }
        // If the input belongs to the GAMMA set (lower case letters)
        else if (p_temp->getAccept().compare("G") == 0) {
            // If input is a letter
            if (isalpha(input[0])) {
                return p_temp->getTo();
            }
        }
        // If the input belongs to the GAMMA set except for x in G-x
        else if (p_temp->getAccept().substr(0, 2).compare("G-") == 0) {
            // Find out which letter should be ignored
            std::string letter = p_temp->getAccept().substr(2);
            if (isalpha(input[0]) && input.compare(letter) != 0) {
                return p_temp->getTo();
            }
        }
    }

    // No transition was found: follow trash transition
    Transition* p_trash = &transitions.back();
    return p_trash->getTo();
}
