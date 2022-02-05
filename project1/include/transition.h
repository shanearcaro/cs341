#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
#include <string>

class Transition {
    private:
        // List of strings that will allow for the next transition
        std::vector<std::string> accept;

        // ID of node that should be transitioned to
        int transitionNode;

    public:
        Transition(std::vector<std::string> accepting, int nodeID): accept(accepting), transitionNode(nodeID) {};

        void transition(char input);
        std::vector<std::string> getAccept();
        int getTransitionNode();
        void setTransitionNode(int nodeID);
};  

#endif
