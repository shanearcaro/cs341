#include "../include/dfa.h"

void DFA::setNodes(std::vector<Node> qNodes) {
    nodes = qNodes;

    if (qNodes.size() > 0)
        setActiveNode(qNodes.at(0));
}

std::vector<Node> DFA::getNodes() {
    return nodes;
}

void DFA::setActiveNode(Node qNode) {
    activeNode = qNode;
}

bool DFA::next(std::string input) {
    activeNode.next(input);
}