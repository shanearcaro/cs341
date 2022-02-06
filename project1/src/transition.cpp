#include "../include/transition.h"

// Get the list of acceptable strings to transition on
std::string Transition::getAccept() {
    return accept;
}

// Get the ID of the node that initialized this transition
int Transition::getFrom() {
    return from;
}

// Get the ID of the node that ends this transition
int Transition::getTo() {
    return to;
}
