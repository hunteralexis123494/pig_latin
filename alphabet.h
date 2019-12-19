/* Alexis Hunter
 * Coding Sample 1: Pig Latin Translator
 * alphabet.h
 */

#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "letter.h"

using namespace std;

class Alphabet {
  private:
    const int numLetters;
    const int asciiStart;
    const int letterCase;
    //vector<char> alphabet;
    vector<Letter> alphabet;

  public:
    // Default Constructor
    Alphabet();

    // Returns alphabet vector
    vector<Letter> getAlphabet();

    // Prints the alphabet
    void printAlphabet();

    // Searches through the alphabet and returns the position of the associated character
    int search(char c);

    // Determines if 'y' is a consonant or vowel based position in word and other letters
    void setY(string word);

    // Determines if 'u' is a consonant or vowel based position in word and other letters
    void setU(string word);
};

#endif
