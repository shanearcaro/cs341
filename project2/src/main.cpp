/**
 * @brief Author
 * Shane Arcaro sma237
 * CS 341 Spring Semester 2022
 * https://web.njit.edu/~marvin/cs341/projects/prog2pda-ae.pdf
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/sets.h"
#include "../include/pda.h"

PDA pda;

// Print the required opening text
void printOpening();

// Create the nodes and set up the required transitions for the PDA to work
void createPDA();

int main(int argc, char* argv[]) {
    // Concatenate the sets together
    concat();

    // Print the opening, has to be the first printed statements
    printOpening();

    // Set up the PDA
    createPDA();

    // Ask user if they want to enter a string and continue on with the program; otherwise terminate
    std::string user_input;
    std::cout << "Would you like to enter a string? Y or N: ";
    getline(std::cin, user_input);
    std::cout << user_input << std::endl;

    // Once PDA is finished loop back until the user terminates they program
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
                // While more lines can be read, start both DFAs
                while (!file.eof()) {
                    getline(file, input);
                    start(input);

                    // Need to reset the PDA's head node in order to be run again
                    pda.reset();
                }
                // Close the file being read from
                file.close();
            }
            else {
                // File could not be read, must be string input
                start(input);

                // Need to reset the PDA's head node in order to run again
                pda.reset();
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

// Analyze a given string on the DFA
void start(std::string input) {
    bool test = pda.next(input);

    std::cout << "Final Result: " << input << ((test) ? " is accepted" : " is rejected") << std::endl;
    std::cout << std::endl;
}

// Print the custom opening section required by project instructions
void printOpening() {
    std::cout << "Project 2 for CS 341" << std::endl;
    std::cout << "Section Number: 452" << std::endl;
    std::cout << "Semester: Spring 2022" << std::endl;
    std::cout << "Written by: Shane Arcaro, sma237" << std::endl;
    std::cout << "Instructor: Marvin Nakayama, marvin@njit.edu" << std::endl;
}

// Create the nodes and set up the required transitions for the DFA to work
void createDFA() {
    // Create each node
    // TODO: Create nodes here

    // Add transitions between the nodes
    // TODO: Add nodes here

    // Each node needs a final transition added to be able to reach the trap node (q9)
    // Trap node transition is only used if the DFA cannot continue properly
    // std::vector<Node> nodes = {q1, q2, q3, q4, q5, q6, q7, q8, q9};
    // for (int i = 0; i < nodes.size(); i++) {
        // TODO: Add trash node
    // }
    // Put the nodes into the DFA
    // pda.setNodes(nodes);
}