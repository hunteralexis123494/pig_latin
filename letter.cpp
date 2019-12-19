/* Alexis Hunter
 * Coding Sample 1: Pig Latin Translator
 * letter.cpp  
 */

#include "letter.h"


// Default Constructor
Letter::Letter(): character('\0'), isConsonant(false), isVowel(false), isCapital(false), letterCase(32), position(0) { }

/* Regular Constructor
   The letter 'y' by default will be considered to be a vowel and will get checked later to determine
   if it is a consonant or a vowel
*/
Letter::Letter(char c): character(c), letterCase(32), position(0) {
  char a = 'a';
  char e = 'e';
  char i = 'i';
  char o = 'o';
  char u = 'u';
  char y = 'y';
  char z = 'z';

  // You get the uppercase of the letter by subtracting letterCase (32)
  char A = a - letterCase;
  char E = e - letterCase;
  char I = i - letterCase;
  char O = o - letterCase;
  char U = u - letterCase;
  char Y = y - letterCase;
  char Z = z - letterCase;

  //ASCII val = 97
  int lowerBegin = a;
  //ASCII val = 122;
  int lowerEnd = z;

  //ASCII val = 65;
  int capitalBegin = A;
  //ASCII val = 90;
  int capitalEnd = Z;

  // If the letter is lowercased
  if (c >= lowerBegin && c <= lowerEnd) {
    // Letter is lowercased
    isCapital = false;
    // If the letter is a, e, i, o, u, or y, it is a vowel
    if (c == a || c == e || c == i || c == o || c == u || c == y) {
      isConsonant = false;
      isVowel = true;
    }
    // Otherwise, it is a consonant
    else {
      isConsonant = true;
      isVowel = false;
    }
  }
  // If the letter is uppercased
  else if (c >= capitalBegin && c <= capitalEnd) {
    isCapital = true;
    // If the letter is A, E, I, O, U, or Y, it is a vowel
    if (c == A || c == E || c == I || c == O || c == U || c == Y) {
      isConsonant = false;
      isVowel = true;
    }
    else {
      // Otherwise, it is a consonant
      isConsonant = true;
      isVowel = false;
    }
  }
  // If the input character is not a letter, it is neither a consonant or vowel
  else {
    isConsonant = false;
    isVowel = false;
    isCapital = false;
  } 
}

// Returns the letter character
char Letter::getChar() {return character;}

// Sets the letter character
void Letter::setChar(char c) {character = c;}

// Returns true or false if the letter is a consonant
bool Letter::getIsConsonant() {return isConsonant;}

// Sets isConsonant to true or false
void Letter::setIsConsonant(bool c) {isConsonant = c;}

// Returns true or false if the letter is a vowel
bool Letter::getIsVowel() {return isVowel;}

// Sets isVowel to true or false
void Letter::setIsVowel(bool v) {isVowel = v;}

// Returns true if letter is capital, false if letter is lowercased
bool Letter::getIsCapital() {return isCapital;}

// Sets isCapital to true or false
void Letter::setIsCapital(bool c) {isCapital = c;}

// Returns the letter's position in the alphabet
int Letter::getPosition() {return position;}
    
// Sets the letter's position in the alphabet
void Letter::setPosition(int i) {position = i;}

// Prints letter properties: character and if it is a consonant or vowel
void Letter::printProps() {
  cout << "Character: " << character << endl;

  cout << "Position: " << position << endl;

  cout << "Consonant or Vowel?: ";

  if (isConsonant) {
    cout << "consonant" << endl;
  }
  if (isVowel) {
    cout << "vowel" << endl;
  }

  
  if (isCapital) {
    cout << "capital letter" << endl;
  }
  else {
    cout << "lowercased letter" << endl;
  }

  cout << endl;
}
