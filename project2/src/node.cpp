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
void Node::addTransition(std::string accept, std::string pop, std::string push, int id) {
    Transition t(accept, pop, push, this->getID(), id);
    this->transitions.push_back(t);
}

// Get a list of all transitions a node has
std::vector<Transition> Node::getTransitions() {
    return this->transitions;
}

// Given an input character determine which transition should be followed
// Return the node id of the transitioned to node
int Node::next(std::string input, std::string stack, std::string &push, std::string &pop) {
    // Iterate through every transition looking for an accept
    // If a transition is never found follow the trash transition (the last transition)
    for (int i = 0; i < transitions.size() - 1; i++) {
        Transition* p_temp = &transitions.at(i);

        // Transition is supposed to accept a digit
        if (p_temp->getAccept().compare("D") == 0) {
            // Input is a digit
            // Never have to check the stack for when a digit is being added
            if (isdigit(input.at(0))) {
                push = "";
                pop = "";
                return p_temp->getTo();
            }
        }
        // Transition is supposed to accept a period
        else if (p_temp->getAccept().compare("P") == 0) {
            if (input.compare(".") == 0) {
                push = "";
                pop = "";
                return p_temp->getTo();
            }
        }
        // Transition is supposed to accept a left parenthesis
        else if (p_temp->getAccept().compare("L") == 0) {
            if (input.compare("(") == 0) {
                // Change the push element for the PDA to recognize on return
                push = "L";
                pop = "!";
                return p_temp->getTo();
            }
        }
        // Transition is supposed to accept a right parenthesis
        else if (p_temp->getAccept().compare("R") == 0) {
            if (input.compare(")") == 0) {
                // Only allow transition if top of stack matches what should be popped
                if (stack.compare("L") == 0) {
                    push = "L";
                    pop = p_temp->getPop();
                    return p_temp->getTo();
                }
            }
        }
        // Transition is supposed to accept a symbol
        else if (p_temp->getAccept().compare("S") == 0) {
            if (input.compare("+") == 0 || input.compare("-") == 0 ||
                input.compare("*") == 0 || input.compare("/") == 0)
                    return p_temp->getTo();
        }
        else if (p_temp->getAccept().compare("A") == 0) {
            if (input.compare("&") == 0) {
                // Check if ! transition is pushing or popping a &
                if (p_temp->getPush().compare("A") == 0) {
                    push = "A";
                    pop = "!";
                    return p_temp->getTo();
                }
                else {
                    // Only allow transition if top of stack matches what should be popped
                    if (stack.compare("A") == 0) {
                        push = "A";
                        pop = p_temp->getPop();
                        return p_temp->getTo();
                    }
                }
            }
        }
    }

    // No transition was found: follow trash transition
    Transition* p_trash = &transitions.back();
    return p_trash->getTo();
}
