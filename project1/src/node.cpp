#include <iostream>

#include "../include/node.h"

// Generation number for keeping nodes unique 
int Node::generation = 0;

// // Add a new transition state to a node
// void Node::addTransition(std::string accept, int id) {
//     Transition t(accept, id);
//     this->transitions.push_back(t);
// }

// Add a new transition state to a node
void Node::addTransition(std::string accept, Node node) {
    Transition t(accept, &node);
    this->transitions.push_back(t);
}

// Transition to the next node given input

bool Node::next(std::string input, Node& activeNode) {
    std::cout << "Doing nothing\n" << std::endl;
    return false;
}

// bool Node::next(std::string input, Node& activeNode) {
//     for (int i = 0; i < transitions.size(); i++) {
//         std::cout << "Transition[" << i << "]: " << transitions.at(i).getAccept() << std::endl;
//         std::cout << std::endl;
//         // std::cout << "Sending [" << input << "]: " << transitions.at(i).getTransitionNode() << std::endl;
//         Transition temp = transitions.at(i);
//         // Direct match just transition
//         if (input.compare(temp.getAccept()) == 0) {
//             activeNode = temp.getTransitionNode();
//             return true;
//         }
//         else if (temp.getAccept().compare("S") == 0) {
//             if (isalpha(input[0]) == 0) {
//                 activeNode = temp.getTransitionNode();
//                 return true;
//             }
//         }
//         else if(temp.getAccept().compare("S-") == 0) {
//             std::string ignore = temp.getAccept().substr(2);
//             if (isalpha(input[0]) == 0 && input.compare(ignore) != 0) {
//                 activeNode = temp.getTransitionNode();
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// Return the state of the node
bool Node::getState() {
    return state;
}

// Get the ID of the node
int Node::getID() {
    return id;
}
