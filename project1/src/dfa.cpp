#include <iostream>

#include "../include/dfa.h"

void DFA::setNodes(std::vector<Node> qNodes) {
    nodes = qNodes;

    if (qNodes.size() > 0)
        setActiveNode(qNodes.at(0));
}

std::vector<Node> DFA::getNodes() {
    return nodes;
}


bool DFA::next(std::string input) {
    // std::cout << "Node Input[" << activeNode.getID() << "]: " << input << std::endl;
    // while (activeNode.next(input, activeNode)) {
    // }
    return false;
}