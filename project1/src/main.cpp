#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/util.h"
#include "../include/dfa.h"


/**
 * @brief Project Instructions
 * https://web.njit.edu/~marvin/cs341/projects/prog1email.pdf
 */

// State machine that handles user input
void start(std::string input);

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

    L1.next("a");

    // Ask user if they want to enter a string and continue on with the program; otherwise terminate
    std::string user_input;
    std::cout << "Would you like to enter a string? Y or N: ";
    getline(std::cin, user_input);

    if (user_input == "Y" || user_input == "y") {
        // If user enters a string read the string but if user enters a file read all input from file
        std::cout << "Enter string or file to be read: ";
        std::string input;
        getline(std::cin, input);

        std::fstream file(input);
        if (file.is_open()) {
            // File was successfully read
            while (!file.eof()) {
                getline(file, input);
                start(input);
            }
            file.close();
        }
        else {
            // File could not be read, must be string input
            start(input);
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
    return 0;
}

void start(std::string input) {
    std::cout << "From DFA: " << input << std::endl;
    for (int i = 0; i < input.length(); i++) {
        int set = determine(input[i]);
        std::string s = set == 0 ? "GAMMA" : set == 1 ? "DELTA" : "PHI";
        std::cout << input[i] << " belongs to: " << s << std::endl;
    }
    // Could make this very similar to a tokenizer
}

void createL1() {
    Node q1, q2, q3, q4, q5, q6, q7, q8(true);
    
    q1.addTransition("S", q2);
    q2.addTransition("S", q2);
    q2.addTransition("@", q3);
    q3.addTransition("S", q4);
    q4.addTransition("S", q4);
    q4.addTransition(".", q5);
    q5.addTransition("o", q6);
    q6.addTransition("r", q7);
    q7.addTransition("g", q8);
    
    L1.setNodes(std::vector<Node> {q1, q2, q3, q4, q5, q6, q7, q8});
}

void createL2() {
    Node q1, q2, q3, q4, q5, q6, q7, q8(true);

    q1.addTransition("S", q2);
    q2.addTransition("S", q2);
    q2.addTransition(".", q1);
    q2.addTransition("@", q3);
    q3.addTransition("S", q4);
    q4.addTransition("S", q4);
    q4.addTransition(".", q5);
    q5.addTransition("o", q6);
    q6.addTransition("r", q7);
    q6.addTransition("S-r", q4);
    q7.addTransition("g", q8);
    q7.addTransition("S-g", q4);

    L2.setNodes(std::vector<Node> {q1, q2, q3, q4, q5, q6, q7, q8});
}

