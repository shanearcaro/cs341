#ifndef DFA_H
#define DFA_H

#include "../include/node.h"

class DFA {
    private:

        int ticket = 0;

        std::vector<Node> nodes;

        // This should be a pointer to a memory location
        Node* head;

    public:
        DFA() {};
        void setNodes(std::vector<Node> qNodes);
        void reset();
        std::vector<Node> getNodes();
        bool next(std::string input);
        Node* getNode(int id);
        int getTicket();
};

#endif
