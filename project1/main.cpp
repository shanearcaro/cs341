#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Project Instructions
 * https://web.njit.edu/~marvin/cs341/projects/prog1email.pdf
 */

#define GAMMA_LENGTH 26
#define DELTA_LENGTH 1
#define PHI_LENGTH 1
#define SIGMA_LENGTH GAMMA_LENGTH + DELTA_LENGTH + PHI_LENGTH

// Set of lower-case Roman letters
std::string GAMMA[GAMMA_LENGTH] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

// Set of a period
std::string DELTA[DELTA_LENGTH] = {"."};

// Set of an at symbol
std::string PHI[PHI_LENGTH] = {"@"};

// Set of all available letters
std::string SIGMA[SIGMA_LENGTH];

// Prints the opening messages required in project instructions
void printOpening();

// State machine that handles user input
void dfa(std::string input);

// Just needed a function to concat everything into SIGMA
void concat();

int main(int argc, char* argv[]) {
    // Print opening has to be first
    printOpening();
    concat();

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

void printOpening() {
    std::cout << "Project 1 for CS 341" << std::endl;
    std::cout << "Section Number: 452" << std::endl;
    std::cout << "Semester: Spring 2022" << std::endl;
    std::cout << "Written by: Shane Arcaro, sma237" << std::endl;
    std::cout << "Instructor: Marvin Nakayama, marvin@njit.edu" << std::endl;
}

void dfa(std::string input) {
    std::cout << "From DFA: " << input << std::endl;
}

void concat() {
    for (int i = 0; i < GAMMA_LENGTH; i++) {
        SIGMA[i] = GAMMA[i];
    }
    SIGMA[GAMMA_LENGTH] = DELTA[0];
    SIGMA[GAMMA_LENGTH + DELTA_LENGTH] = PHI[0];
}
