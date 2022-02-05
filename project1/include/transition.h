#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
#include <string>

class Node;

class Transition {
    private:
        // List of strings that will allow for the next transition
        std::string accept;

        Node* from;
        Node* to;

    public:
        Transition(std::string accepting, Node* fromNode, Node* toNode): accept(accepting), from(fromNode), to(toNode) {};

        std::string getAccept();

        Node* getFrom();
        Node* getTo();
};  

#endif
