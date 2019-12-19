/* Alexis Hunter
 * Coding Sample 1: Pig Latin Translator
 * consonants.h  
 */

#ifndef CONSONANTS_H
#define CONSONANTS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Consonants {
  private:
    // Returns true or false based on whether a consonant blend can be formed
    bool check;

  public:
    // Default Constructor
    Consonants();

    // Checks if the string has at least two letters in order to perform the consonant checks
    bool checkWordSize(string word);

    // Checks if there is one of the following consonants in front of c, k, m, p, or t to form a consonant blend:
    // s
    bool checkCMPT(string word, int charPos);
    // Checks if there is one of the following consonants in front of h to form a consonant blend:
    // c, g, p, s, t, w
    bool checkH(string word, int charPos);
    // Checks if there is one of the following consonants in front of k to form a consonant blend:
    // s
    bool checkK(string word, int charPos);
    // Checks if there is one of the following consonants in front of l to form a consonant blend:
    // b, c, f, g, l, p, s
    bool checkL(string word, int charPos);
    // Checks if there is one of the following consonants in front of n to form a consonant blend:
    // g, p, s
    bool checkN(string word, int charPos);
    // Checks if there is one of the following consonants in front of q to form a consonant blend:
    // s
    bool checkQ(string word, int charPos);
    // Checks if there is one of the following consonants in front of r to form a consonant blend:
    // b, c, f, g, p, t, w
    bool checkR(string word, int charPos);
    // Checks if there is one of the following consonants in front of u to form a consonant blend:
    // q
    bool checkU(string word, int charPos);
    // Checks if there is one of the following consonants in front of w to form a consonant blend:
    // s, t
    bool checkW(string word, int charPos);

    // Checks for small "w" words
    bool checkSmallW(string word);
};

#endif
