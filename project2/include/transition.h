#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
#include <string>

class Transition {
    private:
        // List of strings that allow for a transition to be followed
        std::string accept;

        // What will get popped following this transition
        std::string pop;

        // What will get pushed following this transition
        std::string push;

        // ID of the node that initialized this transition
        int from;

        // ID of the ndoe that ends this transition (will become the new head of PDA)
        int to;

    public:
        Transition(std::string accepting, std::string popping, std::string pushing, int from, int to): accept(accepting), pop(popping), push(pushing), from(from), to(to) {};

        // Get the acceptable string to transition on
        std::string getAccept();

        // Get the string that should be popped off the stack
        std::string getPop();

        // Get the string that will be pushed on to the stack
        std::string getPush();

        // Get the ID of the node that initialized this transition
        int getFrom();

        // Get the ID of the node that ends this transition
        int getTo();

        // Compare accept, pop, and push to see if a transition can be followed or not
        bool compare(std::string accept, std::string push);
};  

#endif
