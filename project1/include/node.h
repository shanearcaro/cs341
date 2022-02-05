#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

#include "../include/sets.h"
#include "../include/transition.h"

class Node {
    private:
        // Unique identifer for Nodes
        static int generation;
        
        // List of possible transitions from node
        std::vector<Transition> transitions;

        // True if accept state, otherwise false
        bool state;

        // Unique id number
        int id;

    public: 
        Node(): state(false), id(++generation) {};
        Node(bool acceptState): state(acceptState), id(++generation) {};
        
        void addTransition(std::vector<std::string> accept, int id);
        void next(char input);
        bool getState();
        int getID();
};

#endif
