#include <iostream>

#include "../include/dfa.h"

void DFA::setNodes(std::vector<Node> qNodes) {
    nodes = qNodes;
    this->head = &nodes.at(0);
}

void DFA::reset() {
    this->head = &nodes.at(0);
}

std::vector<Node> DFA::getNodes() {
    return nodes;
}

bool DFA::next(std::string input) {
    char currentCharacter;
    for (int i = 0; i < input.size(); i++) {
        currentCharacter = input[i];
        std::cout << "State q" << head->getID() << ": " << currentCharacter << std::endl;
        int ticket = head->next(std::string(1, currentCharacter));
        head = getNode(ticket);
    }
    // Once this ends the string has been read and head is in the end
    std::cout << "State q" << head->getID() << std::endl;
    return head->getState();
}

Node* DFA::getNode(int id) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i).getID() == id)
            return &nodes.at(i);
    }
    return nullptr;
}

int DFA::getTicket() {
   return ++ticket; 
}