#include "../include/transition.h"

void Transition::transition(char input) {

}

std::vector<std::string> Transition::getAccept() {
    return accept;
}

int Transition::getTransitionNode() {
    return transitionNode;
}

void Transition::setTransitionNode(int nodeID) {
    transitionNode = nodeID;
}