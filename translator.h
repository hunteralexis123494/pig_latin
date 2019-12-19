/* Alexis Hunter
 * Coding Sample 1: Pig Latin Translator
 * translator.h  
 */

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstddef>

#include "letter.h"
#include "alphabet.h"

using namespace std;

class Translator {
  private:
    // English text to be translated to Pig Latin
    string englText;     
    // Pig Latin suffix
    string suffix;  
    // Pig Latin translation     
    string pigLatinText; 

  public:
   // Default Constructor
   Translator();
   // Regular Constructor - Input english text
   Translator(string w);

   // Returns the English word
   string getEnglText();
   // Sets the English word
   void setEnglText(string w);

   // Returns the Pig Latin suffix
   string getSuffix();
   // Sets the Pig Latin suffix
   void setSuffix(string s);

   // Returns the Pig Latin word
   string getPigLatinText();
   // Sets the Pig Latin word
   void setPigLatinText(string w);

   // Translates the English word to Pig Latin
   // Compound words must be hyphenated (good-bye)
   void translateEnglToPL();

   // Translates the Pig Latin word to English
   void translatePLToEngl();

   // Returns true if the word is in all caps
   bool checkAllCaps(string word);

   // Returns true if the last letter in the word is in all caps
   bool checkLastLetterCaps(string oldWord, string consonants, string newWord);

   // Holds the remaining characters after the character in text at position i
   void getRemainingChars(string text, int i);

   // Ensures that the first letter of the word is capitalized after translation
   string switchWordCaps(string consonants, string newWord);

   // Ensures that the first letter of the word is capitalized after translation
   string switchConsCaps(string consonants, string newWord);

   // Converts the char to a string
   string charToString(char c);

   // Prints the main menu
   void printMenu();

   // Requests, checks, and returns input for a menu option
   int getOption();

   // Requests the English message to be translated
   void requestEnglMessage();

   // Requests the Pig Latin message to be translated
   void requestPLMessage();

   // Prints the pig logo design
   void printLogo();

   // Prints pig latin rules
   void printRules();
};

#endif
