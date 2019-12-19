/* Alexis Hunter
 * Coding Sample 1: Pig Latin Translator
 * consonants.cpp  
 */

#include "consonants.h"


// Default Constructor
Consonants::Consonants(): check(false) { }

// Checks if the string has at least two letters in order to perform the consonant checks
bool Consonants::checkWordSize(string word) {
  if(word.size() < 2) {
    return false;
  }
  else {
    return true;
  }
}

// Checks if there is one of the following consonants in front of c, m, p, t to form a consonant blend:
// s
bool Consonants::checkCMPT(string word, int charPos) {
  check = false;
  
  unsigned int min = 3;
  if(word.size() > min) {
    if(word.at(charPos-1) == 's' || word.at(charPos-1) == 'S') {
      if( word.size() == 4 && (word.at(0) == 'i' || word.at(0) == 'I') ) {
        check = false;
      }
      else {
        check = true;
      }
    }
  } 

  return check;
}

// Checks if there is one of the following consonants in front of h to form a consonant blend:
// c, g, p, r, s, t, w
bool Consonants::checkH(string word, int charPos) {
  check = false;
  
  if(checkWordSize(word)) {
    if(word.at(charPos-1) == 'c'|| word.at(charPos-1) == 'p' ||
         word.at(charPos-1) == 's' || word.at(charPos-1) == 't' || word.at(charPos-1) == 'w') {
      check = true;
    }
    else if(word.at(charPos-1) == 'C'|| word.at(charPos-1) == 'P' ||
              word.at(charPos-1) == 'S' || word.at(charPos-1) == 'T' || word.at(charPos-1) == 'W') {
      check = true;
    }
    // Only forms the consonant blend if the 'g' word is "ghost" or "ghosts"
    else if(word.at(charPos-1) == 'g' || word.at(charPos-1) == 'G') {
      if(word.size() == 5 || word.size() == 6) {
        // If the first three letters are 'ost', the word is most likely ghost, so g is a part of a
        // consonant blend
        if( (word.at(0) == 'o' || word.at(0) == 'O') && (word.at(1) == 's' || word.at(1) == 'S') &&
            (word.at(2) == 't' || word.at(2) == 'T') ) {

          // If the word has 5 letters, the word is most likely ghost, so g is a part of a
          // consonant blend
          if(word.size() == 5) {
            check = true;
          }
          // If the word has 6 letters, it checks if the 4th letter is an 's'
          // If the letter is an 's', the word is most likely ghosts, so g is a part of a
          // consonant blend
          else {
            if( (word.at(3) == 's' || word.at(3) == 'S') ) {
              check = true;
            }
          }
        }
      }
    }
  } 

  return check;
}

// Checks if there is one of the following consonants in front of k to form a consonant blend:
// s
bool Consonants::checkK(string word, int charPos) {
  check = false;
  
  if(checkWordSize(word)) {
    if(word.at(charPos-1) == 's' || word.at(charPos-1) == 'S') {
      // If the English word is "sky", it will form the consonant blend
      if(word.at(0) == 'y' || word.at(0) == 'Y') {
          check = true;
      }
    }
  } 

  return check;
}

// Checks if there is one of the following consonants in front of l to form a consonant blend:
// b, c, f, g, l, p, s
// The only consonant blend for double l is for the word "llama," so only that word is considered
bool Consonants::checkL(string word, int charPos) {
  check = false;
  
  if(checkWordSize(word)) {
    if(word.at(charPos-1) == 'b'|| word.at(charPos-1) == 'c'|| word.at(charPos-1) == 'f' || 
         word.at(charPos-1) == 'g' || word.at(charPos-1) == 'p' || word.at(charPos-1) == 's') {
      check = true;
    }
    else if(word.at(charPos-1) == 'B'|| word.at(charPos-1) == 'C' || word.at(charPos-1) == 'F' || 
              word.at(charPos-1) == 'G' || word.at(charPos-1) == 'P'|| word.at(charPos-1) == 'S') {
      check = true;
    }
    // If the previous letter is 'l', check if the word is most likely llama
    else if(word.at(charPos-1) == 'l' || word.at(charPos-1) == 'L') {
      if(word.size() == 5) {
        // If the first three letters are 'ama', the word is most likely llama, so l is a part of a
        // consonant blend
        if( (word.at(0) == 'a' || word.at(0) == 'A') && (word.at(1) == 'm' || word.at(1) == 'M') &&
            (word.at(2) == 'a' || word.at(2) == 'A') ) {
          check = true;
        }
      } 
    } 
  } 

  return check;
}

// Checks if there is one of the following consonants in front of n to form a consonant blend:
// g, k, p, s
bool Consonants::checkN(string word, int charPos) {
  check = false;
  
  if(checkWordSize(word)) {
    if(word.at(charPos-1) == 'g' || word.at(charPos-1) == 'k' || word.at(charPos-1) == 'p' || 
         word.at(charPos-1) == 's') {
      check = true;
    }
    else if(word.at(charPos-1) == 'G' || word.at(charPos-1) == 'K' || word.at(charPos-1) == 'P'|| 
              word.at(charPos-1) == 'S') {
      check = true;
    }
  } 

  return check;
}

// Checks if there is one of the following consonants in front of q to form a consonant blend:
// s
bool Consonants::checkQ(string word, int charPos) {
  check = false;

  if(checkWordSize(word)) {
    if(word.at(charPos-1) == 's' || word.at(charPos-1) == 'S') {
      check = true;
    }
  }

  return check;
}

// Checks if there is one of the following consonants in front of r to form a consonant blend:
// b, c, d, f, g, h, p, t, w
// Will not count for words with double r's
bool Consonants::checkR(string word, int charPos) {
  check = false;
  
  if(checkWordSize(word)) {
    if(word.at(charPos-1) == 'b'|| word.at(charPos-1) == 'c' ||
         word.at(charPos-1) == 'f' || word.at(charPos-1) == 'h' || word.at(charPos-1) == 'p' || 
           word.at(charPos-1) == 'w') {
      check = true;
    }
    else if(word.at(charPos-1) == 'B'|| word.at(charPos-1) == 'C' ||  
              word.at(charPos-1) == 'F' || word.at(charPos-1) == 'H' || word.at(charPos-1) == 'P' || 
                word.at(charPos-1) == 'W') {
      check = true;
    }
    // If the English 'g' word has 5 or less letters, it will form the consonant blend
    else if(word.at(charPos-1) == 'g' || word.at(charPos-1) == 'G') {
      if(word.size() < 6) {
        check = true;
      }
      // If the letter after "gr" is 'o', it will form the consonant blend
      else {
        if(word.at(0) == 'o' || word.at(0) == 'O') {
          check = true;
        }
      }  
    }
    else if(word.at(charPos-1) == 't' || word.at(charPos-1) == 'T') {
      if(word.size() == 5) {
        // If the first three letters are 'ight', the word is most likely right, so t is not a part of a
        // consonant blend. Otherwise, it is
        if( (word.at(0) == 'i' || word.at(0) == 'I') && (word.at(1) == 'g' || word.at(1) == 'G') &&
            (word.at(2) == 'h' || word.at(2) == 'H') && (word.at(3) == 't' || word.at(3) == 'T') ) {
          check = false;
        }
        else {
         check = true;
        }
      }
      else {
        check = true;
      } 
    }
    else if(word.at(charPos-1) == 'd' || word.at(charPos-1) == 'D') {
      // Forms consonant blend except for if the word is "red"
      if(word.size() > 3) {
        check = true;
      }
    }
  } 

  return check;
}

// Checks if there is one of the following consonants in front of u to form a consonant blend:
// q
bool Consonants::checkU(string word, int charPos) {
  check = false;
  
  if(checkWordSize(word)) {
    if(word.at(charPos-1) == 'q' || word.at(charPos-1) == 'Q') {
      check = true;
    }
  } 

  return check;
}

// Checks if there is one of the following consonants in front of w to form a consonant blend:
// d, s, t
bool Consonants::checkW(string word, int charPos) {
  check = false;
  
  unsigned int min = 5;
  if(word.size() > min) {
    if(word.at(charPos-1) == 's'|| word.at(charPos-1) == 't') {
      check = true;
    }
    else if(word.at(charPos-1) == 'S' || word.at(charPos-1) == 'T') {
      check = true;
    }
    else if(word.at(charPos-1) == 'd'|| word.at(charPos-1) == 'D') {
      if(word.at(0) == 'i' || word.at(0) == 'I') {
        check = true;
      }
    }
  } 

  return check;
}

// Checks for small "w" words
bool Consonants::checkSmallW(string word) {
  bool valid = false;

  // Checks for 3-letter "w" words
  if(word.size() == 3) {
    // If the "w" word is "way", add the 'w' to the front
    if( (word.at(0) == 'a' || word.at(0) == 'A') && 
        (word.at(1) == 'y' || word.at(1) == 'Y') ) {
      valid = true;
    }
  }
  // Checks for 4-letter "w" words
  else if(word.size() == 4) {
    // If the "w" word is "with" or "wish", add the 'w' to the front
    if( (word.at(0) == 'i' || word.at(0) == 'I') && 
        (word.at(1) == 't' || word.at(1) == 'T' || word.at(1) == 's' || word.at(1) == 'S') && 
        (word.at(2) == 'h' || word.at(2) == 'H') ) {
      valid = true;
    }
    // If the "w" word is "wind", add the 'w' to the front
    else if( (word.at(0) == 'i' || word.at(0) == 'I') && 
             (word.at(1) == 'n' || word.at(1) == 'N') && 
             (word.at(2) == 'd' || word.at(2) == 'D') ) {
      valid = true;
    }
    // If the "w" word is "will", add the 'w' to the front
    else if( (word.at(0) == 'i' || word.at(0) == 'I') && 
             (word.at(1) == 'l' || word.at(1) == 'L') && 
             (word.at(2) == 'l' || word.at(2) == 'L') ){
      valid = true;
    }
    // If the "w" word is "well", add the 'w' to the front
    else if( (word.at(0) == 'e' || word.at(0) == 'E') && 
             (word.at(1) == 'l' || word.at(1) == 'L') && 
             (word.at(2) == 'l' || word.at(2) == 'L') ){
      valid = true;
    }
  }
  // Checks for 5-letter "w" words
  else if(word.size() == 5) {
    // If the "w" word is "would" or "wound", add the 'w' to the front
    if( (word.at(0) == 'o' || word.at(0) == 'O') && 
        (word.at(1) == 'u' || word.at(1) == 'U') && 
        (word.at(2) == 'l' || word.at(2) == 'L' || word.at(2) == 'n' || word.at(2) == 'N') &&
        (word.at(3) == 'd' || word.at(3) == 'D') ) {
      valid = true;
    }
  }

  return valid;
}
