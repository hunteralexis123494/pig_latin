/* Alexis Hunter
 * Coding Sample 1: Pig Latin Translator
 * letter.h  
 */

#ifndef LETTER_H
#define LETTER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

//#include "alphabet.h"

using namespace std;

class Letter {
  private:
    // Letter character
    char character;
    // If the letter is a consonant
    bool isConsonant;
    // If the letter is a vowel
    bool isVowel;
    // If the letter is capital
    bool isCapital;
    // difference between capital and lower case letter in ASCII
    const int letterCase;
    // position in alphabet
    int position; 

  public:
    // Default Constructor
    Letter();
    // Regular Constructor
    Letter(char c);

    // Returns the letter character
    char getChar();
    // Sets the letter character
    void setChar(char c);

    // Returns true or false if the letter is a consonant
    bool getIsConsonant();
    // Sets isConsonant to true or false
    void setIsConsonant(bool c);

    // Returns true or false if the letter is a vowel
    bool getIsVowel();
    // Sets isVowel to true or false
    void setIsVowel(bool v);

    // Returns true if letter is capital, false if letter is lowercased
    bool getIsCapital();
    // Sets isCapital to true or false
    void setIsCapital(bool c);

    // Returns the letter's position in the alphabet
    int getPosition();
    // Sets the letter's position in the alphabet
    void setPosition(int i);

    // Prints the letter properties
    void printProps();
};

#endif
