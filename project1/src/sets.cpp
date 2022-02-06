#include <string>  

// Length of the GAMMA set
const int GAMMA_LENGTH = 26;

// Length of the DELTA set
const int DELTA_LENGTH = 1;

// Length of the PHI set
const int PHI_LENGTH = 1;

// LENGTH of the SIGMA set
const int SIGMA_LENGTH = GAMMA_LENGTH + DELTA_LENGTH + PHI_LENGTH;

// Set of all lowercase roman letters (a-z)
std::string GAMMA[GAMMA_LENGTH] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

// Set of a period (.)
std::string DELTA[DELTA_LENGTH] = {"."};

// Set of an at sign (@)
std::string PHI[PHI_LENGTH] = {"@"};

// Set of all allowed letters in previous sets, combined
std::string SIGMA[SIGMA_LENGTH];

// Concatenate GAMMA, DELTA, and PHI iinto SIGMA
void concat() {
    for (int i = 0; i < GAMMA_LENGTH; i++) SIGMA[i] = GAMMA[i];
    SIGMA[GAMMA_LENGTH] = DELTA[0];
    SIGMA[GAMMA_LENGTH + DELTA_LENGTH] = PHI[0];
}