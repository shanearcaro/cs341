#include "../include/transition.h"

// Return if the node is an accepting state
std::string Transition::getAccept() {
    return accept;
}

Node* Transition::getFrom() {
    return from;
}

Node* Transition::getTo() {
    return to;
}

