#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>

#include "sets.h"

namespace util {
    // Prints the opening messages required in project instructions
    void printOpening() {
        std::cout << "Project 1 for CS 341" << std::endl;
        std::cout << "Section Number: 452" << std::endl;
        std::cout << "Semester: Spring 2022" << std::endl;
        std::cout << "Written by: Shane Arcaro, sma237" << std::endl;
        std::cout << "Instructor: Marvin Nakayama, marvin@njit.edu" << std::endl;
    }

    // Just needed a function to concat everything into SIGMA
    void concat() {
        for (int i = 0; i < set::GAMMA_LENGTH; i++) {
            set::SIGMA[i] = set::GAMMA[i];
        }
        set::SIGMA[set::GAMMA_LENGTH] = set::DELTA[0];
        set::SIGMA[set::GAMMA_LENGTH + set::DELTA_LENGTH] = set::PHI[0];
    }

    // Determine which set characters belongs to, 0 for GAMMA, 1 for DELTA, 2 for PHI
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
}

#endif
