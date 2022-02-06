#ifndef DFA_H
#define DFA_H

#include "../include/node.h"

class DFA {
    private:
        // Private ticket counter for each DFA
        // Nodes will increment each ID by 1
        int ticket = 0;

        // List of nodes for a given DFA
        std::vector<Node> nodes;

        // Head node responsible for transitioning to the next state
        Node* head;

    public:
        DFA() {};
        // Create DFA with set of initial nodes
        void setNodes(std::vector<Node> qNodes);

        // Reset the DFA so the head node is back in its starting state
        void reset();

        // Get a list of every node within the DFA
        std::vector<Node> getNodes();

        // Get a node by its unique id number
        Node* getNode(int id);

        // Generate a new ticket for a node
        int getTicket();

        // Run though the DFA given input
        bool next(std::string input);
};

#endif
