/* Alexis Hunter
 * Coding Sample 1: Pig Latin Translator
 * alphabet.cpp  
 */

#include "alphabet.h"

// Default Constructor
// Sets the standard alphabet with lowercase a-z
// Inspired by http://www.cplusplus.com/reference/vector/vector/insert/
Alphabet::Alphabet():numLetters(26), asciiStart(97), letterCase(32) {
  int ascii = asciiStart;

  // Puts each letter a-z in the vector in alphabetical order
  for (int i = 0; i < numLetters; i++) {
    //Letter a = static_cast<char>(ascii);
    Letter a(static_cast<char>(ascii));
    alphabet.push_back(a);
    ascii++;
    alphabet.at(i).setPosition(i);
  }
}

// Returns alphabet vector
vector<Letter> Alphabet::getAlphabet() {return alphabet;}

// Prints the alphabet in a 4 x 6 grid layout
void Alphabet::printAlphabet() {
  for (unsigned int i = 0; i < alphabet.size(); i++) {
    if (i >= 6 && i % 6 == 0) {
      cout << endl;
    }  
    cout << alphabet[i].getChar() << " ";
  }
}

// Searches through the alphabet and returns Letter with character c
int Alphabet::search(char c) {

  //cout << "Searching alphabet for letter " << c << endl;
  char tempChar = c;

  if (c >= 65 && c <= 90) {
    //cout << c << " is capital" << endl;
    tempChar = c + letterCase;
  }


  for (unsigned int i = 0; i < alphabet.size(); i++) {
    if (alphabet[i].getChar() == tempChar) {
      return alphabet[i].getPosition();
    }
  }
  return -1;
}

// Determines if 'y' is a consonant or vowel based position in word and other letters
void Alphabet::setY(string word) {
  // If word is empty, leave it alone
  if (word.empty()) {
    return;
  }
  
  // If word only has one letter, it is automatically a consonant
  if (word.size() == 1) {
    if (word[0] == 'Y' || word[0] == 'y') {
      alphabet.at(search(word[0])).setIsConsonant(true);
      alphabet.at(search(word[0])).setIsVowel(false);
      return;
    }
  }
 
  // If the first letter is a 'y'
  if (word[0] == 'Y' || word[0] == 'y') {
    // If the letter after it is a vowel, 'y' is a consonant
    if (alphabet.at(search(word[1])).getIsVowel()) {
      alphabet.at(search(word[0])).setIsConsonant(true);
      alphabet.at(search(word[0])).setIsVowel(false);
      return;
    }
    // Otherwise, the letter after it is a consonant, so 'y' is a vowel
    else {
      alphabet.at(search(word[0])).setIsConsonant(false);
      alphabet.at(search(word[0])).setIsVowel(true);
      return;
    }
  }
  // If the first letter is not a 'y', leave it alone 
  else {
    alphabet.at(search('y')).setIsConsonant(false);
    alphabet.at(search('y')).setIsVowel(true);
    return;
  }
}

// Determines if 'u' is a consonant or vowel based position in word and other letters
void Alphabet::setU(string word) {
  // If word is empty, leave it alone
  if (word.empty()) {
    return;
  }
  
  // If word only has one letter, it is automatically a vowel
  if (word.size() == 1) {
    if (word[0] == 'U' || word[0] == 'U') {
      alphabet.at(search(word[0])).setIsConsonant(false);
      alphabet.at(search(word[0])).setIsVowel(true);
      return;
    }
  }
 
  // If the first letter is a 'q'
  if (word[0] == 'Q' || word[0] == 'q') {
    // If the letter after it is a u, 'u' is a consonant
    if (word[1] == 'U' || word[1] == 'u') {
      alphabet.at(search(word[1])).setIsConsonant(true);
      alphabet.at(search(word[1])).setIsVowel(false);
      return;
    }
    // Otherwise, u is a vowel
    else {
      alphabet.at(search('u')).setIsConsonant(false);
      alphabet.at(search('u')).setIsVowel(true);
      return;
    }
  }
  // If the first letter is not a 'q', 'u' is a vowel 
  else {
    alphabet.at(search('u')).setIsConsonant(false);
    alphabet.at(search('u')).setIsVowel(true);
    return;
  }
}
