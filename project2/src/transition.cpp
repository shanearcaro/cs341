#include "../include/transition.h"

// Get the list of acceptable strings to transition on
std::string Transition::getAccept() {
    return accept;
}

// Get pop
std::string Transition::getPop() {
    return pop;
}

// Get push
std::string Transition::getPush() {
    return push;
}

// Get the ID of the node that initialized this transition
int Transition::getFrom() {
    return from;
}

// Get the ID of the node that ends this transition
int Transition::getTo() {
    return to;
}
