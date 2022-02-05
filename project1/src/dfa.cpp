#include <iostream>

#include "../include/dfa.h"

void DFA::setNodes(std::vector<Node> qNodes) {
    nodes = qNodes;
    this->head = &nodes.at(0);

    std::cout << "Head is being created: \n\tID: " << head->getID() << std::endl;
}

std::vector<Node> DFA::getNodes() {
    return nodes;
}


bool DFA::next(std::string input) {
    char currentCharacter;
    for (int i = 0; i < input.length(); i++) {
        currentCharacter = input[i];
        std::cout << "Current Character: " << currentCharacter << std::endl;
        Node* temp = head->next(std::string(1, currentCharacter));
        std::cout << "Temp values: " << std::endl;
        std::cout << "\tID: " << temp->getID() << std::endl;
    }
    // Once this ends the string has been read and head is in the end
    return false;
}