#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
#include <string>

class Transition {
    private:
        // List of strings that will allow for the next transition
        std::string accept;

        int from;
        int to;

    public:
        Transition(std::string accepting, int from, int to): accept(accepting), from(from), to(to) {};

        std::string getAccept();

        int getFrom();
        int getTo();
};  

#endif
