#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/util.h"
#include "../include/dfa.h"

/**
 * @brief Author
 * Shane Arcaro sma237
 * CS 341 Spring Semester 2022
 * https://web.njit.edu/~marvin/cs341/projects/prog1email.pdf
 */


// State machine that handles user input
std::string start(std::string input, bool write);

void createL1();
void createL2();

DFA L1;
DFA L2;

int main(int argc, char* argv[]) {
    // Print opening has to be first
    printOpening();
    concat();

    // Set up both DFAs
    createL1();
    createL2();

    // Ask user if they want to enter a string and continue on with the program; otherwise terminate
    std::string user_input;
    std::cout << "Would you like to enter a string? Y or N: ";
    getline(std::cin, user_input);

    // Instructions say to loop back to start again
    while (user_input != "N" || user_input != "n") {
        if (user_input == "Y" || user_input == "y") {
            // If user enters a string read the string but if user enters a file read all input from file
            std::cout << "Enter string or file to be read: ";
            std::string input;
            getline(std::cin, input);
            std::cout << std::endl;

            std::fstream file(input);
            if (file.is_open()) {
                // File was successfully read

                std::ofstream output_file;
                output_file.open(input.substr(0, input.size() - 4) + "_answers.txt");
                while (!file.eof()) {
                    getline(file, input);
                    // Send input to get tested by the DFAs
                    output_file << start(input, true) + "\n";

                    // Reset the DFAs to start state
                    L1.reset();
                    L2.reset();
                }
                output_file.close();
                file.close();
            }
            else {
                // File could not be read, must be string input
                start(input, false);
                L1.reset();
                L2.reset();
            }
        }
        else if (user_input == "N" || user_input == "n") {
            std::cout << "No input string being read. Terminating." << std::endl;
            return 0;
        }
        else {
            std::cout << "Cannot understand input string. Terminating." << std::endl;
            return 0;
        }
        std::cout << "Would you like to enter a string? Y or N: ";
        getline(std::cin, user_input);
    }
    return 0;
}

// Start both L1 and L2 DFA tests
// A string only needs to pass one of the tests to be accepted
std::string start(std::string input, bool write) {
    std::cout << "Testing L1" << std::endl;
    bool test1 = L1.next(input);
    std::cout << std::endl;

    std::cout << "Testing L2" << std::endl;
    bool test2 = L2.next(input);

    std::cout << input << ((test1 || test2) ? ": accepted" : ": rejected") << std::endl;
    std::cout << std::endl;

    if (write)
        return input + ((test1 || test2) ? ": accepted" : ": rejected");
    return "";
}

// I just don't like this code at all
void createL1() {
    Node q1(L1.getTicket()), q2(L1.getTicket()), q3(L1.getTicket());
    Node q4(L1.getTicket()), q5(L1.getTicket()), q6(L1.getTicket());
    Node q7(L1.getTicket()), q8(L1.getTicket(), true), trash_node(L1.getTicket());
    
    q1.addTransition("G", q2.getID());
    q2.addTransition("G", q2.getID());
    q2.addTransition("@", q3.getID());
    q3.addTransition("G", q4.getID());
    q4.addTransition("G", q4.getID());
    q4.addTransition(".", q5.getID());
    q5.addTransition("o", q6.getID());
    q6.addTransition("r", q7.getID());
    q7.addTransition("g", q8.getID());

    std::vector<Node> nodes = {q1, q2, q3, q4, q5, q6, q7, q8, trash_node};
    for (int i = 0; i < nodes.size(); i++) {
        nodes.at(i).addTransition("X", trash_node.getID());
    }
    L1.setNodes(nodes);
}

// Not amazing
void createL2() {
    Node q1(L2.getTicket()), q2(L2.getTicket()), q3(L2.getTicket());
    Node q4(L2.getTicket()), q5(L2.getTicket()), q6(L2.getTicket());
    Node q7(L2.getTicket()), q8(L2.getTicket(), true), trash_node(L2.getTicket());

    q1.addTransition("G", q2.getID());
    q2.addTransition("G", q2.getID());
    q2.addTransition(".", q1.getID());
    q2.addTransition("@", q3.getID());
    q3.addTransition("G", q4.getID());
    q4.addTransition("G", q4.getID());
    q4.addTransition(".", q5.getID());
    q5.addTransition("o", q6.getID());
    q5.addTransition("G-o", q4.getID());
    q6.addTransition("r", q7.getID());
    q6.addTransition("G-r", q4.getID());
    q6.addTransition(".", q4.getID());
    q7.addTransition("g", q8.getID());
    q7.addTransition("G-g", q4.getID());
    q7.addTransition(".", q5.getID());
    q8.addTransition(".", q5.getID());

    std::vector<Node> nodes = {q1, q2, q3, q4, q5, q6, q7, q8, trash_node};
    for (int i = 0; i < nodes.size(); i++) {
        nodes.at(i).addTransition("X", trash_node.getID());
    }

    L2.setNodes(nodes);
}

