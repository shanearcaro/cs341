#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

#include "sets.h"
#include "transition.h"

class Node {
    private:
        // List of possible transitions from node
        std::vector<Transition> transitions;

        // True if accept state, otherwise false
        bool state;

        // Unique id number
        int id;

    public: 
        // Unique identifer for Nodes
        static int generation = 0;

        Node(): state(false), id(++generation) {};
        Node(bool acceptState): state(acceptState), id(++generation) {};

        
        inline void addTransition(std::vector<std::string> accept, int id);
        inline void next(char input);
        inline bool getState();
        inline int getID();
};

#endif
