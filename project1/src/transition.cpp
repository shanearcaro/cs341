#include "../include/transition.h"

// Transition to the next state given input
void Transition::transition(std::string input) {

}

// Return if the node is an accepting state
std::string Transition::getAccept() {
    return accept;
}

// Return the id of the node to be transitioned to
Node* Transition::getTransitionNode() {
    return transitionNode;
}

// Set the transition node id to nodeID
void Transition::setTransitionNode(Node* node) {
    transitionNode = node;
}