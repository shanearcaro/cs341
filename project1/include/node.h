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
        // Create a regular node with default accept state
        Node(int id): id(id), state(false) {};

        // Create an accept state node
        Node(int id, bool acceptState): id(id), state(acceptState) {};

        // Get the current state of a node (if it's an accepting node)
        bool getState();

        // Get the unique id of a node
        int getID();
        
        // Add a new transition between the current node and a new node
        // The transition is only followed if the accept string matches the input string
        void addTransition(std::string accept, int id);

        //Get a list of all transitions a node has
        std::vector<Transition> getTransitions();

        // Given an input character determine which transition should be followed
        // Return the node id of the transitioned to node
        int next(std::string input);

};

#endif
