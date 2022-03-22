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

        // Get the list of acceptable strings to transition on
        std::string getAccept();

        // Get pop
        std::string getPop();

        // Get push
        std::string getPush();

        // Get the ID of the node that initialized this transition
        int getFrom();

        // Get the ID of the node that ends this transition
        int getTo();
};  

#endif
