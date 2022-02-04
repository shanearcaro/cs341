#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
#include <string>

#include "node.h"

class Transition {
    // List of strings that will allow for the next transition
    std::vector<std::string> accept;

    // ID of node that should be transitioned to
    int transitionNode;

    public:
        Transition(std::vector<std::string> accept) {
            this->accept = accept;
            this->transitionNode = -1;
        }

        Transition(std::vector<std::string> accept, int nodeID) {
            this->accept = accept;
            this->transitionNode = nodeID;
        }

        void transition(char input) {
        }

        std::vector<std::string> getAccept() {
            return accept;
        }

        int getTransitionNode() {
            return transitionNode;
        }

        bool isActive() {
            return transitionNode != -1;
        }

        void setTransitionNode(int nodeID) {
            transitionNode = nodeID;
        }
};  

#endif
