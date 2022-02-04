#include <iostream>
#include <fstream>
#include <string>

#include "sets.h"
#include "util.h"
#include "node.h"
#include "transition.h"

/**
 * @brief Project Instructions
 * https://web.njit.edu/~marvin/cs341/projects/prog1email.pdf
 */

// State machine that handles user input
void dfa(std::string input);

int main(int argc, char* argv[]) {
    // Print opening has to be first
    util::printOpening();
    util::concat();

    // TEST
    Node q1(false);
    q1.addTransition(std::vector<std::string> {"SIGMA"}, 0);

    // END TEST

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
                dfa(input);
            }
            file.close();
        }
        else {
            // File could not be read, must be string input
            dfa(input);
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

void dfa(std::string input) {
    std::cout << "From DFA: " << input << std::endl;
    for (int i = 0; i < input.length(); i++) {
        int set = util::determine(input[i]);
        std::string s = set == 0 ? "GAMMA" : set == 1 ? "DELTA" : "PHI";
        std::cout << input[i] << " belongs to: " << s << std::endl;
    }
    // Could make this very similar to a tokenizer
}


