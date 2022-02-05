#ifndef DFA_H
#define DFA_H

#include "../include/node.h"

class DFA {
    private:
        std::vector<Node> nodes;
        Node activeNode;

    public:
        DFA() {};
        void setNodes(std::vector<Node> qNodes);
        std::vector<Node> getNodes();
        void setActiveNode(Node qNode);
        bool next(std::string input);

};

#endif
