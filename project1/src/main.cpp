#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/sets.h"
#include "../include/dfa.h"

/**
 * @brief Author
 * Shane Arcaro sma237
 * CS 341 Spring Semester 2022
 * https://web.njit.edu/~marvin/cs341/projects/prog1email.pdf
 */

/** Sets required for each DFA to work */
// Γ = set of all lowercase roman letters
// Δ = set of .
// Φ = set of @
// Σ = Γ U Δ U Φ

/** Strings that make up the rules for each DFA */
// S1 = ΓΓ*
// S2 = ΔΓΓ*
// S3 = {.org}

// DFA L1: Responsible for analyzing strings against L1 = S1ΦS1S3
DFA L1;

// DFA L2: Responsible for analyzing strings against L2 = S1S2*ΦS1S2*S3
DFA L2;

// Print the required opening text
void printOpening();

// Create the nodes and set up the required transitions for the DFA L1 to work
void createL1();

// Create the nodes and set up the required transitions for the DFA L2 to work
void createL2();

// Analyze a given string on both DFAs L1 and L2
// A string only needs to pass one of the DFAs to be accepted
void start(std::string input);


int main(int argc, char* argv[]) {
    // Concatenate the sets together
    concat();

    // Print the opening, has to be the first printed statements
    printOpening();

    // Set up both DFAs
    createL1();
    createL2();

    // Ask user if they want to enter a string and continue on with the program; otherwise terminate
    std::string user_input;
    std::cout << "Would you like to enter a string? Y or N: ";
    getline(std::cin, user_input);
    std::cout << user_input << std::endl;

    // Once DFA is finished loop back until the user terminates the program
    while (user_input != "N" || user_input != "n") {
        if (user_input == "Y" || user_input == "y") {
            // If user enters a string read the string but if user enters a file read all input from file
            std::cout << "Enter string or file to be read: ";
            std::string input;
            getline(std::cin, input);

            // The inputs are being written again only to create output.txt with the make output version
            std::cout << input << std::endl;
            std::cout << std::endl;

            // Check if the given string is a file
            std::fstream file(input);
            if (file.is_open()) {
                // While mroe lines can be read, start both DFAs
                while (!file.eof()) {
                    getline(file, input);
                    start(input);

                    // Need to reset each DFA's head node in order to be run again
                    L1.reset();
                    L2.reset();
                }
                // Close the file being read from
                file.close();
            }
            else {
                // File could not be read, must be string input
                start(input);

                // Need to reset each DFA's head node in order to be run again
                L1.reset();
                L2.reset();
            }
        }
        // If user does not want to enter a string or file terminate the program
        else if (user_input == "N" || user_input == "n") {
            std::cout << "No input string being read. Terminating." << std::endl;
            return 0;
        }
        // If input is not understood terminate the program
        else {
            std::cout << "Cannot understand input string. Terminating." << std::endl;
            return 0;
        }
        // Loop back
        std::cout << "Would you like to enter a string? Y or N: ";
        getline(std::cin, user_input);
        // The inputs are being written again only to create output.txt with the make output version
        std::cout << user_input << std::endl;
        std::cout << std::endl;
    }
    // Exit
    return 0;
}

// Analyze a given string on both DFAs L1 and L2
// A string only needs to pass one of the DFAs to be accepted
void start(std::string input) {
    // Test L1
    std::cout << "Testing L1" << std::endl;
    bool test1 = L1.next(input);
    std::cout << std::endl;

    // Test L2
    std::cout << "Testing L2" << std::endl;
    bool test2 = L2.next(input);

    // Print result
    std::cout << input << ((test1 || test2) ? ": accepted" : ": rejected") << std::endl;
    std::cout << std::endl;
}

// Print the custom opening section required by project instructions
void printOpening() {
    std::cout << "Project 1 for CS 341" << std::endl;
    std::cout << "Section Number: 452" << std::endl;
    std::cout << "Semester: Spring 2022" << std::endl;
    std::cout << "Written by: Shane Arcaro, sma237" << std::endl;
    std::cout << "Instructor: Marvin Nakayama, marvin@njit.edu" << std::endl;
}

// Create the nodes and set up the required transitions for the DFA L1 to work
void createL1() {
    // Create each node
    Node q1(L1.getTicket()), q2(L1.getTicket()), q3(L1.getTicket());
    Node q4(L1.getTicket()), q5(L1.getTicket()), q6(L1.getTicket());
    Node q7(L1.getTicket()), q8(L1.getTicket(), true), trash_node(L1.getTicket());
    
    // Add transitions between the nodes
    q1.addTransition("G", q2.getID());
    q2.addTransition("G", q2.getID());
    q2.addTransition("@", q3.getID());
    q3.addTransition("G", q4.getID());
    q4.addTransition("G", q4.getID());
    q4.addTransition(".", q5.getID());
    q5.addTransition("o", q6.getID());
    q6.addTransition("r", q7.getID());
    q7.addTransition("g", q8.getID());

    // Each node needs a final transition added to be able to reach the trash node
    // Trash node transition is only used if the DFA cannot continue properly
    std::vector<Node> nodes = {q1, q2, q3, q4, q5, q6, q7, q8, trash_node};
    for (int i = 0; i < nodes.size(); i++) {
        nodes.at(i).addTransition("X", trash_node.getID());
    }
    // Put the nodes into the DFA
    L1.setNodes(nodes);
}

// Create the nodes and set up the required transitions for the DFA L2 to work
void createL2() {
    // Create each node
    Node q1(L2.getTicket()), q2(L2.getTicket()), q3(L2.getTicket());
    Node q4(L2.getTicket()), q5(L2.getTicket()), q6(L2.getTicket());
    Node q7(L2.getTicket()), q8(L2.getTicket(), true), trash_node(L2.getTicket());

    // Add transitions between the nodes
    q1.addTransition("G",   q2.getID());
    q2.addTransition("G",   q2.getID());
    q2.addTransition(".",   q1.getID());
    q2.addTransition("@",   q3.getID());
    q3.addTransition("G",   q4.getID());
    q4.addTransition("G",   q4.getID());
    q4.addTransition(".",   q5.getID());
    q5.addTransition("o",   q6.getID());
    q5.addTransition("G-o", q4.getID());
    q6.addTransition("r",   q7.getID());
    q6.addTransition("G-r", q4.getID());
    q6.addTransition(".",   q4.getID());
    q7.addTransition("g",   q8.getID());
    q7.addTransition("G-g", q4.getID());
    q7.addTransition(".",   q5.getID());
    q8.addTransition(".",   q5.getID());

    // Each node needs a final transition added to be able to reach the trash node
    // Trash node transition is only used if the DFA cannot continue properly
    std::vector<Node> nodes = {q1, q2, q3, q4, q5, q6, q7, q8, trash_node};
    for (int i = 0; i < nodes.size(); i++) {
        nodes.at(i).addTransition("X", trash_node.getID());
    }
    // Put the nodes into the DFA
    L2.setNodes(nodes);
}
