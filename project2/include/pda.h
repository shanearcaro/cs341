#ifndef DFA_H
#define DFA_H

#include "../include/node.h"

class PDA {
    private:
        // Private ticket counter for each PDA
        // Nodes will increment each ID by 1
        int ticket = 0;

        // List of nodes for a given PDA
        std::vector<Node> nodes;

        // Head node responsible for transitioning to the next state
        Node* head;

        // Stack of elements
        std::vector<std::string> stack;

    public:
        PDA() {};
        // Create PDA with set of initial nodes
        void setNodes(std::vector<Node> qNodes);

        // Reset the PDA so the head node is back in its starting state
        void reset();

        void push(std::string symbol);

        void pop();

        // Get a list of every node within the PDA
        std::vector<Node> getNodes();

        // Get a node by its unique id number
        Node* getNode(int id);

        // Generate a new ticket for a node
        int getTicket();

        // Run though the PDA given input
        bool next(std::string input);
};

#endif
