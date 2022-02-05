#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

#include "../include/transition.h"

class Node {
    private:
        // List of possible transitions from node
        std::vector<Transition> transitions;

        // Unique id number
        int id;

        // True if accept state, otherwise false
        bool state;

    public: 
        Node(int id): id(id), state(false) {};
        Node(int id, bool acceptState): id(id), state(acceptState) {};
        
        // void addTransition(std::string accept, int id);
        void addTransition(std::string accept, int id);
        int next(std::string input);
        std::vector<Transition> getTransitions();
        bool getState();
        int getID();
        void setID(int id);
};

#endif
