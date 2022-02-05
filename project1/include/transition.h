#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
#include <string>

class Node;

class Transition {
    private:
        // List of strings that will allow for the next transition
        std::string accept;

        // ID of node that should be transitioned to
        Node* transitionNode;

    public:
        Transition(std::string accepting, Node* tNode): accept(accepting), transitionNode(tNode) {};

        void transition(std::string input);
        std::string getAccept();
        Node* getTransitionNode();
        void setTransitionNode(Node* node);
};  

#endif
