#ifndef SETS_H
#define SETS_H

#include <string>

// Length of the GAMMA set
extern const int GAMMA_LENGTH;

// Lentgh of the DELTA set
extern const int DELTA_LENGTH;

// Length of the PHI set
extern const int PHI_LENGTH;

// Length of the SIGMA set
extern const int SIGMA_LENGTH;

// Set of all lowercase roman letters (a-z)
extern std::string GAMMA[];

// Set of a period (.)
extern std::string DELTA[];

// Set of an at sign (@)
extern std::string PHI[];

// Set of all allowed letters in previous sets, combined
extern std::string SIGMA[];

// Concatenate GAMMA, DELTA, and PHI into SIGMA
extern void concat();
    
#endif
