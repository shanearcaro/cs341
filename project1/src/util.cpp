#include "../include/util.h"

void printOpening() {
    std::cout << "Project 1 for CS 341" << std::endl;
    std::cout << "Section Number: 452" << std::endl;
    std::cout << "Semester: Spring 2022" << std::endl;
    std::cout << "Written by: Shane Arcaro, sma237" << std::endl;
    std::cout << "Instructor: Marvin Nakayama, marvin@njit.edu" << std::endl;
}

int determine(char character) {
    // Get ascii value of character
    int ascii_value = (int) character;

    // 46 = . 64 = @
    if (ascii_value == 46)
        return 1;
    else if (ascii_value == 64)
        return 2;
    return 0;
}