#ifndef SETS_H
#define SETS_H

#include <string>

// Length of the DIGITS set
extern const int DIGITS_LENGTH;

// Lentgh of the SYMBOLS set
extern const int SYMBOLS_LENGTH;

// Length of the PERIOD set
extern const int PERIOD_LENGTH;

// Length of the AMPERSAND set
extern const int AMPERSAND_LENGTH;

// Length of the SIGMA set
extern const int SIGMA_LENGTH;

// Set of all digits
extern std::string DIGITS[];

// Set of all SYMBOLS
extern std::string SYMBOLS[];

// Set of a period
extern std::string PERIOD[];

// Set of an ampersand
extern std::string AMPERSAND[];

// Set of all allowed letters in previous sets, combined
extern std::string SIGMA[];

// Concatenate DIGITS, SYMBOLS, PERIOD, and AMPERSAND into SIGMA
extern void concat();

#endif