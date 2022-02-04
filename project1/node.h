#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

#include "sets.h"
#include "transition.h"

int generation = 0;

class Node {
    // List of possible transitions from node
    std::vector<Transition> transitions;

    // True if accept state, otherwise false
    bool state;

    // Unique id number
    int id;

    public: 
        Node() {
            this->state = false;
            this->id = ++generation;
        }

        Node(bool state) {
            this->state = state;
            this->id = ++generation;
        }

        void addTransition(std::vector<std::string> accept, int id) {
            Transition t(accept, id);
            this->transitions.push_back(t);
        }

        void next(char input) {
            for (int i = 0; i < transitions.size(); i++) {
                std::cout << "Sending [" << input << "]: " << transitions.at(i).getTransitionNode() << std::endl;
                transitions.at(i).transition(input);
            }
        }

        bool getState() {
            return state;
        }

        int getID() {
            return id;
        }
};

#endif
