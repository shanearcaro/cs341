#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
#include <string>

class Transition {
    private:
        // List of strings that will allow for the next transition
        std::string accept;

        // ID of node that should be transitioned to
        int transitionNode;

    public:
        Transition(std::string accepting, int nodeID): accept(accepting), transitionNode(nodeID) {};

        void transition(std::string input);
        std::string getAccept();
        int getTransitionNode();
        void setTransitionNode(int nodeID);
};  

#endif
