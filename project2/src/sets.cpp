#include <string>

// Length of the DIGITS set
const int DIGITS_LENGTH = 10;

// Lentgh of the SYMBOLS set
const int SYMBOLS_LENGTH = 6;

// Length of the PERIOD set
const int PERIOD_LENGTH = 1;

// Length of the AMPERSAND set
const int AMPERSAND_LENGTH = 1;

// Length of the SIGMA set
const int SIGMA_LENGTH = DIGITS_LENGTH + SYMBOLS_LENGTH + PERIOD_LENGTH + AMPERSAND_LENGTH;

// Set of all digits
std::string DIGITS[DIGITS_LENGTH];

// Set of all SYMBOLS
std::string SYMBOLS[SYMBOLS_LENGTH];

// Set of a period
std::string PERIOD[PERIOD_LENGTH];

// Set of an ampersand
std::string AMPERSAND[AMPERSAND_LENGTH];

// Set of all allowed letters in previous sets, combined
std::string SIGMA[SIGMA_LENGTH];

// Concatenate DIGITS, SYMBOLS, PERIOD, and AMPERSAND into SIGMA
void concat() {
    for (int i = 0; i < DIGITS_LENGTH; i++) SIGMA[i] = DIGITS[i];
    for (int i = DIGITS_LENGTH; i < DIGITS_LENGTH + SYMBOLS_LENGTH; i++) SIGMA[i] = SYMBOLS[i - DIGITS_LENGTH];
    SIGMA[DIGITS_LENGTH + SYMBOLS_LENGTH] = PERIOD[0];
    SIGMA[DIGITS_LENGTH + SYMBOLS_LENGTH + 1] = AMPERSAND[0];
}