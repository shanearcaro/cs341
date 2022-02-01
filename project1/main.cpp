#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>


/**
 * @brief Project Instructions
 * https://web.njit.edu/~marvin/cs341/projects/prog1email.pdf
 */

// Prints the opening messages required in project instructions
void printOpening();

int main(int argc, char* argv[]) {
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

