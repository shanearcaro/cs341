#include <iostream>

#include "../include/pda.h"

// Create PDA with set of initial nodes
void PDA::setNodes(std::vector<Node> qNodes) {
    nodes = qNodes;
    
    // Head will be set to the first node within the nodes list
    this->head = &nodes.at(0);
}

// Reset the PDA so the head node is back in its starting state
void PDA::reset() {
    this->head = &nodes.at(0);
}

// Push a new symbol on top of the stack
void PDA::push(std::string symbol) {
    this->stack.push_back(symbol);
}

// Remove the top symbol from the stack
void PDA::pop() {
    this->stack.pop_back();
}

// Look at the symbol on top of the stack without removing it
std::string PDA::peak() {
    if (this->stack.size() == 0)
        return "";
    return this->stack.back();
}

// Get a list of every node within the PDA
std::vector<Node> PDA::getNodes() {
    return nodes;
}

// Get a node by its unique id number
Node* PDA::getNode(int id) {
    // Iterate through the list and check the id against the given id
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i).getID() == id)
            return &nodes.at(i);
    }

    // If the node isn't found (this should never happen) return the null ptr
    return nullptr;
}

// Generate a new ticket for a node
int PDA::getTicket() {
   return ++ticket; 
}

// Run through the PDA given input
bool PDA::next(std::string input) {
    char currentCharacter;
    std::string pushStack = "";
    std::string popStack  = "";

    // Loop through the entire input string and iterate the PDA transition state
    for (int i = 0; i < input.size(); i++) {
        // Get a single character to test
        currentCharacter = input[i];

        // Get the unique id of the node that should be transitioned to
        int ticket = head->next(std::string(1, currentCharacter), this->peak(), pushStack, popStack);

        // The string analysis crashed
        if (ticket == -1) {
            // Accept or reject the input string based on the PDA characteristics
            std::cout << "Machine Crashed" << std::endl;
            return false;
        }

        // Make sure stack is only manipulated when a push or pop operation is called
        if (pushStack.compare("") != 0 && popStack.compare("") != 0) {
            if (pushStack.compare(popStack) == 0) {
                this->pop();
            }
            else if (pushStack.compare("") != 0 && popStack.compare("!") == 0) {
                this->push(pushStack);
            }
        }

        if (pushStack.compare("") == 0 || pushStack.compare("!") == 0)
            pushStack = "ε";
        if (popStack.compare("") == 0 || popStack.compare("!") == 0)
            popStack = "ε";
        if (popStack.compare(pushStack) == 0)
            pushStack = "ε";
        std::cout << "State q" << head->getID() << ": " << currentCharacter << ", " << popStack << " ➜ " << pushStack << std::endl;

        // Head now becomes the transitioned node
        head = getNode(ticket);
        pushStack = "";
        popStack = "";
    }

    // Accept or reject the input string based on the PDA characteristics
    std::cout << "State q" << head->getID() << std::endl;
    std::cout << "Final q" << head->getID() << ": " << (head->getState() ? "accept" : "reject") << std::endl;

    return head->getState();
}