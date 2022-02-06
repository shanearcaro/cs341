#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
#include <string>

class Transition {
    private:
        // List of strings that allow for a transition to be followed
        std::string accept;

        // ID of the node that initialized this transition
        int from;

        // ID of the ndoe that ends this transition (will become the new head of DFA)
        int to;

    public:
        Transition(std::string accepting, int from, int to): accept(accepting), from(from), to(to) {};

        // Get the list of acceptable strings to transition on
        std::string getAccept();

        // Get the ID of the node that initialized this transition
        int getFrom();

        // Get the ID of the node that ends this transition
        int getTo();
};  

#endif
