#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>


/**
 * @brief Project Instructions
 * https://web.njit.edu/~marvin/cs341/projects/prog1email.pdf
 */

// Prints the opening messages required in project instructions
void printOpening();

int main(int argc, char* argv[]) {
    std::string user_input;
    std::cout << "Would you like to enter a string? Y or N: ";
    getline(std::cin, user_input);

    if (user_input == "Y" || user_input == "y") {
        // Begin DFA here
    }
    else if (user_input == "N" || user_input == "n") {
        std::cout << "No input string being read. Terminating.\n";
        return 0;
    }
    else {
        std::cout << "Cannot understand input string. Terminating.\n";
        return 0;
        }

    printOpening();
    return 0;
}

void printOpening() {
    std::cout << "Project 1 for CS 341" << std::endl;
    std::cout << "Section Number: 452" << std::endl;
    std::cout << "Semester: Spring 2022" << std::endl;
    std::cout << "Written by: Shane Arcaro, 31488936" << std::endl;
    std::cout << "Instructor: Marvin Nakayama, marvin@njit.edu" << std::endl;
}

