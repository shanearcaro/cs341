#include "../include/transition.h"

// Return if the node is an accepting state
std::string Transition::getAccept() {
    return accept;
}

int Transition::getFrom() {
    return from;
}

int Transition::getTo() {
    return to;
}

