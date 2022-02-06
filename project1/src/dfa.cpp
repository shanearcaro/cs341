#include <iostream>

#include "../include/dfa.h"

// Create DFA with set of initial nodes
void DFA::setNodes(std::vector<Node> qNodes) {
    nodes = qNodes;
    
    // Head will be set to the first node within the nodes list
    this->head = &nodes.at(0);
}

// Reset the DFA so the head node is back in its starting state
void DFA::reset() {
    this->head = &nodes.at(0);
}

// Get a list of every node within the DFA
std::vector<Node> DFA::getNodes() {
    return nodes;
}

// Get a node by its unique id number
Node* DFA::getNode(int id) {
    // Iterate through the list and check the id against the given id
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i).getID() == id)
            return &nodes.at(i);
    }

    // If the node isn't found (this should never happen) return the null ptr
    return nullptr;
}

// Generate a new ticket for a node
int DFA::getTicket() {
   return ++ticket; 
}

// Run through the DFA given input
bool DFA::next(std::string input) {
    char currentCharacter;
    std::cout << "Start q1" << std::endl;

    // Loop through the entire input string and iterate the DFA transition state
    for (int i = 0; i < input.size(); i++) {
        // Get a single character to test
        currentCharacter = input[i];
        std::cout << "State q" << head->getID() << ": " << currentCharacter << std::endl;

        // Get the unique id of the node that should be transitioned to
        int ticket = head->next(std::string(1, currentCharacter));

        // Head now becomes the transitioned node
        head = getNode(ticket);
    }

    // Accept or reject the input string based on the DFA characteristics
    std::cout << "State q" << head->getID() << std::endl;
    std::cout << "Final q" << head->getID() << ": " << (head->getState() ? "accept" : "reject") << std::endl;

    return head->getState();
}
