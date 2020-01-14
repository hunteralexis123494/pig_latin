/* Alexis Hunter
 * Coding Sample 1: Pig Latin Translator
 * translator.cpp  
 */

#include "translator.h"
#include "consonants.h"

// Default Constructor
Translator::Translator(): englText(""), suffix("ay"), pigLatinText("") { }

// Regular Constructor
Translator::Translator(string w): englText(), suffix("ay") { 
  translateEnglToPL();
}

// Returns the English word
string Translator::getEnglText() {return englText;}

// Sets the English word
void Translator::setEnglText(string w) {englText = w;}

// Returns the Pig Latin suffix
string Translator::getSuffix() {return suffix;}

// Sets the Pig Latin suffix
void Translator::setSuffix(string s) {suffix = s;}

// Returns the Pig Latin word
string Translator::getPigLatinText() {return pigLatinText;}

// Sets the Pig Latin word
void Translator::setPigLatinText(string w) {pigLatinText = w;}

// Inspired by http://www.snowcrest.net/donnelly/piglatin.html
// Translates the English word to Pig Latin
// Compound words must be hyphenated (good-bye)
void Translator::translateEnglToPL() {
  pigLatinText = "";
  string tempText = englText;
  string tempWord = "";
  string translation = "";
  string firstLetter = "";

  string origTempWord = "";

  string space = "";

  Letter checkLetter;

  string consonants = "";
  Alphabet alphabet;
  char tempChar;
  
  // If the string is empty, return (can't translate an empty string)
  if (englText.empty()) {
    return;
  }
  // If the string is too large, it cannot translate
  else if (englText.size() > englText.max_size()) {
    cout << "Text is too large. Cannot translate." << endl << endl;
    return;
  }
  // Otherwise...
  else {
    // While temp string is not empty...
    // If characters are not letters, automatically add them to PGText
    // Get word from temp string
    // Translate first word
    // Add translation to PGText
    // Repeat

    unsigned int pos = 0;
    unsigned int cons = 0;

    // Iterate through the entire string
    while (pos < englText.size()) {
      tempWord = "";
      consonants = "";
      translation = "";
      origTempWord = "";
      cons = 0;

      // When the iteration through the text is complete, the method is finished, so return
      if(pos >= englText.size()) {
        return;
      }

      // Create a Letter of char in englText at position pos
      Letter currLetter(englText.at(pos));

      // If the character is not a letter, automatically add it to the final translation text
      if (!currLetter.getIsConsonant() && !currLetter.getIsVowel()) {
        pigLatinText += currLetter.getChar();
        pos++;
      }
      // Otherwise, add it to the word string to be checked
      else {
        bool canAddToWord = true;

        while(canAddToWord) {
          // If the last character has been added to the word, stop checking to add
          if(pos >= englText.size()) {
            break;
          }

          // If the character is a letter or an apostrophe ('), add it to the word
          // and move on to the next character
          if( (englText.at(pos) >= 65 && englText.at(pos) <= 90) || 
                (englText.at(pos) >= 97 && englText.at(pos) <= 122) || englText.at(pos) == 39) {
            tempWord += englText.at(pos);
            origTempWord += englText.at(pos);
            pos++;
          }
          // Otherwise, stop checking to add
          else {
            canAddToWord = false;
            break;
          }
        }

        // Determine if 'y' is a consonant or vowel based on its position in the word
        alphabet.setY(tempWord);
        // Determines if 'u' is a consonant or vowel based position in word and other letters
        alphabet.setU(tempWord);

        bool addToConsonants = true;

        // While there are consonants at the front
        while (addToConsonants) {
          string keepTempWord = tempWord;
          
          // Iterates through word
          for (unsigned int i = 0; i < keepTempWord.size(); i++) {
            // References character at position i in word
            tempChar = keepTempWord[i];

            // If the character is a consonant
            if(alphabet.getAlphabet().at(alphabet.search(tempChar)).getIsConsonant()) {
              // Add it to the consonants to remove and add at the end
              consonants += tempChar;
              cons++;

              // If all of the letters are consonants, stop iterating
              if(cons == origTempWord.size()) {
                addToConsonants = false;
                break;
              }
 
              // Clear the string to hold the remaining characters
              tempWord = "";

              // Holds the remaining characters after the consonant
              for (unsigned int j = i+1; j < keepTempWord.size(); j++) {
                tempWord += keepTempWord.at(j);
              }
            }
            // If the character is a vowel, move on to the next step
            else {
              addToConsonants = false;
              break;
            }
          }
          // You have iterated through the entire word (no more letters to check)
          addToConsonants = false;
          break;
        }
     
        // Doesn't consider one-letter words to be all caps
        if(!checkAllCaps(origTempWord) && (cons != origTempWord.size()) ) {
          // Switches capitalization if the word has more than one letter
          if (origTempWord.size() > 1) {
            tempWord = switchWordCaps(consonants, tempWord);
            consonants = switchConsCaps(consonants, tempWord);
          }
        }
       
        // If the word has only one letter...
        if(origTempWord.size() == 1) {
          // If the letter is a vowel, the suffix is "way"
          if(consonants.empty()) {
            suffix = "way";
          }
          // If the letter is a consonant, the suffix is "ay"
          else {
            suffix = "ay";
          }
        }
        // If the word is in all caps, the ending suffix will be in all caps
        else if (checkLastLetterCaps(origTempWord, consonants, tempWord)) {
          // If the first letter was a vowel, the Pig Latin suffix is "WAY"
          if(consonants.empty()) {
            suffix = "WAY";
          }
          // If the first letter was a consonant, the Pig Latin suffix is "AY"
          else {
            suffix = "AY";
          }
        }
        // Otherwise, the ending suffix will be lowercased
        else {
          // If the first letter was a vowel, the Pig Latin suffix is "way"
          if(consonants.empty()) {
            suffix = "way";
          }
          // If the first letter was a consonant, the Pig Latin suffix is "ay"
          else {
            suffix = "ay";
          }
        }

        // If all of the letters are consonants, just add the "ay" suffix
        if(cons == origTempWord.size()) {
          translation += consonants + suffix;
        }
        // Pig Latin translation = (word - consonants) + consonants + suffix 
        else {  
          translation += tempWord + consonants + suffix;
        }
        // Set the pigLatinText variable to translation
        pigLatinText += translation;
      }
    }
  }
}

// Translates the Pig Latin word to English
void Translator::translatePLToEngl() {
  englText = "";
  string translation = "";
  string origTempWord = "";
  string consonants = "";
  string rest = "";
  
  // If the string is empty, return (can't translate an empty string)
  if (pigLatinText.empty()) {
    return;
  }
  // If the string is too large, it cannot translate
  else if (pigLatinText.size() > pigLatinText.max_size()) {
    cout << "Text is too large. Cannot translate." << endl << endl;
    return;
  }
  // Otherwise...
  else {
    // While temp string is not empty...
    // If characters are not letters, automatically add them to englishText and delete from temp string
    // Get word from temp string
    // Delete "-ay" suffix. Some may have "w" at the end and translator will determine if it is
    // a part of the suffix.
    // Translate first word. If "w" is determined to be a part of the suffix, it will be deleted
    // Add translation to englishText
    // Repeat

    unsigned int pos = 0;

    // Iterate through the entire string
    while (pos < pigLatinText.size()) {
      consonants = "";
      translation = "";
      origTempWord = "";
      rest = "";

      // When the iteration through the text is complete, the method is finished, so return
      if(pos >= pigLatinText.size()) {
        return;
      }

      // Create a Letter of char in englText at position pos
      Letter currLetter(pigLatinText.at(pos));

      // If the character is not a letter, automatically add it to the final translation text
      if (!currLetter.getIsConsonant() && !currLetter.getIsVowel()) {
        englText += currLetter.getChar();
        pos++;
      }
      // Otherwise, add it to the word string to be checked
      else {
        bool canAddToWord = true;

        while(canAddToWord) {
          // If the last character has been added to the word, stop checking to add
          if(pos >= pigLatinText.size()) {
            break;
          }

          // If the character is a letter or an apostrophe ('), add it to the word
          // and move on to the next character
          if( (pigLatinText.at(pos) >= 65 && pigLatinText.at(pos) <= 90) || 
                (pigLatinText.at(pos) >= 97 && pigLatinText.at(pos) <= 122) || pigLatinText.at(pos) == 39) {
            origTempWord += pigLatinText.at(pos);
            pos++;
          }
          // Otherwise, stop checking to add
          else {
            canAddToWord = false;
            break;
          }
        }

        // If the word has less than 3 letters, it is not a valid pig latin word and will not get translated
        if(origTempWord.size() < 3) {
           cout << origTempWord << " is not a valid pig latin word. Cannot translate." << endl << endl;
           englText = "";
           return;
        }
        // Otherwise, the suffix will get check to see if the word is a valid pig latin word
        else {
          // Referencing the third-to-last letter
          int firstPos = origTempWord.size()-3;
          char first = origTempWord.at(firstPos);

          // Checking if that letter is a consonant
          Letter tempLetter(first);
          // If the letter is a 'y' or 'u', it is counted as a consonant
          if (first == 'y' || first == 'Y' || first == 'u' || first == 'U') {
            tempLetter.setIsConsonant(true);
          } 

          // Referencing the second-to-last letter
          int secPos = origTempWord.size()-2;
          // Referencing the last letter
          int thirdPos = origTempWord.size()-1;
         
          // Does not attempt to translate for the following cases:
          // If the third-to-last letter is a vowel
          // If the second-to-last letter is not an 'a'
          // If the last letter is not a 'y'
          if(!tempLetter.getIsConsonant() || 
             (origTempWord.at(secPos) != 'a' && origTempWord.at(secPos) != 'A') ||
             (origTempWord.at(thirdPos) != 'y' && origTempWord.at(thirdPos) != 'Y') ) {
            cout << origTempWord << " is not a valid pig latin word. Cannot translate." << endl << endl;
            englText = "";
            return;
          }
          // Otherwise, the word is a valid pig latin word and will get translated
          else {
            // Will hold first part (word - "ay")
            string append;
            
            int vowels = 0;

            // Remove the suffix from the word ('ay')
            // Will check later if there is a 'w' at the end that may be a part of the suffix
            // Also makes sure the remaining letters are not all consonants
            for (unsigned int i = 0; i < origTempWord.size()-2; i++) {
              Letter letter(origTempWord.at(i));
              if(letter.getIsVowel()) {
                vowels++;
              }
              append += origTempWord.at(i);
            }

            // If there aren't any vowels in the appended word, just remove the "ay" suffix
            // Set the englWord variable to translation and move on to the next word
            if(vowels == 0) {
              translation = append;
              englText += translation;
            }
            else {
              Consonants consonantsClass;

              // Referencing the last letter in the appended string
              unsigned int pos = append.size()-1;
              char c = append.at(pos);

              // Controls the consonants blend loop
              bool addToConsonants = true;
              bool stopCons;

              // Automatically adding consonant to consonant string
              consonants += charToString(c);

              // Checks for consonant blends
              // Checks may not account for plural words
              while(addToConsonants) {
                // If the last letter in the appended string has a w at the end, check if the 'w' is a part of the suffix
                if(c == 'W' || c == 'w') {
                  // If the 'w' has a consonant before it that is a part of a consonant blend, 'w' is not a part of the suffix
                  if(consonantsClass.checkW(append, pos)) {
                    stopCons = false;
                  }
                  // Otherwise, 'w' is a part of the suffix and will be removed based on the original word size
                  // The translation for the word is complete
                  else {
                    stopCons = true;
                  }
                }
                // If the last letter is a 'c', 'k', 'm', 'p', or 't', check if it is a part of a consonant blend
                else if(c == 'c' || c == 'C' || c == 'm' || c == 'M' || 
                          c == 'p' || c == 'P' || c == 't' || c == 'T') {
                  // If the 'c' has a consonant before it that is a part of a consonant blend, keep checking
                  if(consonantsClass.checkCMPT(append, pos)) {
                    stopCons = false;
                  }
                  // Otherwise, 'w' is a part of the suffix and will be removed
                  // The translation for the word is complete
                  else {
                    stopCons = true;
                  }
                }
                // If the last letter is 'h', check if it is a part of a consonant blend
                else if(c == 'h' || c == 'H') {
                  // If the 'c' has a consonant before it that is a part of a consonant blend, keep checking
                  if(consonantsClass.checkH(append, pos)) {
                    stopCons = false;
                  }
                  // Otherwise, 'w' is a part of the suffix and will be removed
                  // The translation for the word is complete
                  else {
                    stopCons = true;
                  }
                }
                else if(c == 'k' || c == 'K') {
                  // If the 'c' has a consonant before it that is a part of a consonant blend, keep checking
                  if(consonantsClass.checkK(append, pos)) {
                    stopCons = false;
                  }
                  // Otherwise, 'w' is a part of the suffix and will be removed
                  // The translation for the word is complete
                  else {
                    stopCons = true;
                  }
                }
                // If the last letter
                else if(c == 'l' || c == 'L') {
                  // If the 'c' has a consonant before it that is a part of a consonant blend, keep checking
                  if(consonantsClass.checkL(append, pos)) {
                    stopCons = false;
                  }
                  // Otherwise, 'w' is a part of the suffix and will be removed
                  // The translation for the word is complete
                  else {
                    stopCons = true;
                  }
                }
                else if(c == 'n' || c == 'N') {
                  // If the 'c' has a consonant before it that is a part of a consonant blend, keep checking
                  if(consonantsClass.checkN(append, pos)) {
                    stopCons = false;
                  }
                  // Otherwise, 'w' is a part of the suffix and will be removed
                  // The translation for the word is complete
                  else {
                    stopCons = true;
                  }
                }
                
                else if(c == 'q' || c == 'Q') {
                  // If the 'q' has a consonant before it that is a part of a consonant blend, keep checking
                  if(consonantsClass.checkQ(append, pos)) {
                    stopCons = false;
                  }
                  // Otherwise, 'w' is a part of the suffix and will be removed
                  // The translation for the word is complete
                  else {
                    stopCons = true;
                  }
                }
                
                else if(c == 'r' || c == 'R') {
                  // If the 'r' has a consonant before it that is a part of a consonant blend, keep checking
                  if(consonantsClass.checkR(append, pos)) {
                    stopCons = false;
                  }
                  // Otherwise, 'w' is a part of the suffix and will be removed
                  // The translation for the word is complete
                  else {
                    stopCons = true;
                  }
                }
                else if(c == 'u' || c == 'U') {
                  // If the 'c' has a consonant before it that is a part of a consonant blend, keep checking
                  if(consonantsClass.checkU(append, pos)) {
                    stopCons = false;
                  }
                  // Otherwise, 'w' is a part of the suffix and will be removed
                  // The translation for the word is complete
                  else {
                    stopCons = true;
                  }
                }
                else {
                  stopCons = true;
                }

                // If the consonant is a part of a consonant blend, add it to the blend and keep checking for more
                if(!stopCons) {
                  pos--;
                  c = append.at(pos);
                  consonants += charToString(c);
                }
                // Otherwise, end the check and finalize the translation
                else {
                  // If there is only one letter in the consonants string
                  if(consonants.size() == 1) {
                    char single = consonants.at(0);

                    // If the letter is a 'w', the 'w' could be a part of the suffix
                    if(single == 'w' || single == 'W') {
                      // Checking if the final word could be a small 'w' word
                      bool check = consonantsClass.checkSmallW(append);

                      // If false, the English word is assumed to begin with a vowel
                      // And the 'w' is a part of the suffix so it will get removed from
                      // the consonants string
                      if(!check) {
                        consonants = "";
                      }
                    }
                  }

                  // Remove the consonant from the word
                  for (unsigned int i = 0; i < pos; i++) {
                    rest += append.at(i);
                  } 

                  addToConsonants = false;
                }
              }

              // Will store the reversed order of consonants
              string tempCons;

              // Storing the reversed order of consonants to get the correct consonant blend
              for(unsigned int i = consonants.size(); i > 0; i--) {
                tempCons += consonants.at(i-1);
              }
              // Places correct consonant blend in consonants
              consonants = tempCons;

              // Don't need to switch caps if the word is in all caps
              if(!checkAllCaps(origTempWord)) {
                // Making sure that there are consonants before attempting to switch caps
                if(!consonants.empty()) {
                  // Switch capitalization if necessary
                  Letter firstLetter(rest.at(0));
                  Letter otherLetter(consonants.at(0));

                  // If the first letter in the pig latin word is capitalized...
                  if(firstLetter.getIsCapital()) {
                    // Make that letter lowercased
                    char lower = firstLetter.getChar() + 32;
                    rest.at(0) = lower;

                    // If the first letter of consonants is lowercased, capitalize it
                    if(!otherLetter.getIsCapital()) {
                      char upper = consonants.at(0) - 32;
                      consonants.at(0) = upper;
                    }
                  }
                }
              }
            
              // english translation = consonants + (word - suffix - consonants)
              translation += consonants + rest;

              // Set the englWord variable to translation
              englText += translation;
            }
          }         
        }
      }
    }
  }
}

// Returns true if the word is in all caps
bool Translator::checkAllCaps(string word) {
  if(word.size() < 2) {
    return false;
  }
  else {
    // Stores word
    string tempWord = word;

    // Iterates through word to see if any of the letters are lowercased
    for (unsigned int i = 0; i < tempWord.length(); i++) {
      // Creates a Letter from char at position i
      Letter tempLetter(tempWord.at(i));
      // If the letter is lowercased, the word is not in all caps
      if (!tempLetter.getIsCapital()) {
        return false;
      }
    }

    // If the loop finishes iterating, it did not detect any lowercased letters, so
    // the word is in all caps
    return true;
  }
}

// Returns true if the last letter in the word is in all caps
bool Translator::checkLastLetterCaps(string oldWord, string consonants, string newWord) {
  // If the word has only one letter...
  if(oldWord.size() == 1) {
    Letter temp(oldWord.at(0));

    // If the letter is a vowel, don't count it as capitalized
    if(temp.getIsVowel()) {
      return false;
    }
    // If the letter is a consonant, count it as capitalized
    else {
      return true;
    }
  }
  // If the word is a vowel, check the last letter of the newWord
  if(consonants.empty()) {
    unsigned int pos = newWord.size() - 1;

    Letter temp(newWord.at(pos));

    // If the last letter is capitalized, return true
    if(temp.getIsCapital()) {
      return true;
    }
    // Otherwise, return false
    else {
      return false;
    }
  }
  // If the word is a consonant, check the last letter of consonants
  else {
    unsigned int pos = consonants.size() - 1;

    Letter temp(consonants.at(pos));

    // If the last letter is capitalized, return true
    if(temp.getIsCapital()) {
      return true;
    }
    // Otherwise, return false
    else {
      return false;
    }
  } 
}

// Holds the remaining characters after the character in text at position i
void Translator::getRemainingChars(string text, int i) {
  if(text.size() < 2) {
    text = "";
    return;
  }
  else {
    string tempWord;
    for (unsigned int j = i+1; j < text.size(); j++) {
      tempWord += text.at(j);
    }
  }
}

// Ensures that the first letter of the word is capitalized after translation
string Translator::switchWordCaps(string consonants, string newWord) {
  string switched = newWord;

  // If the word began with a vowel, don't switch the capitalization
  if(consonants.empty()) {
    return switched;
  }

  Letter tempLetter(consonants.at(0));

  // If the first letter was lowercased, don't switch the capitalization
  if(!tempLetter.getIsCapital()) {
    return switched;
  }
  // Otherwise...
  else {
    Letter temp = newWord.at(0);
    char firstLetter = newWord.at(0);

    // Capitalizes the first letter if it isn't already capitalized
    if(!temp.getIsCapital()) {
      firstLetter -= 32;
    }

    switched = firstLetter;

    // Adds the rest of the letters to the new string
    for(unsigned int i = 1; i < newWord.size(); i++) {
      char tempChar = newWord.at(i);
      switched += charToString(tempChar);
    }

    return switched;
  }
}

// Ensures that the first letter of the word is capitalized after translation
string Translator::switchConsCaps(string consonants, string newWord) {
  string switched = consonants;

  // If the letter began with a vowel, don't switch capitalization
  if (consonants.empty()) {
    return switched;
  }

  bool allCaps = checkAllCaps(newWord);

  // If the letter is in all caps
  if(allCaps) {
    return switched;
  }

  // Creates a Letter from first character in origWord
  Letter tempLetter(consonants.at(0));
  // If the first letter is lowercased, don't switch capitalization
  if (!tempLetter.getIsCapital()) {
    return switched;
  }
  // Otherwise...
  else {
    // Lowercase the first moved consonant letter
    char firstLetter = consonants.at(0);
    firstLetter += 32;
    switched = charToString(firstLetter);
    
    // Iterates through the rest of the word to find the capitalized letter and make it lowercased
    for(unsigned int i = 1; i < consonants.size(); i++) {
      char tempChar = consonants.at(i);
      switched += charToString(tempChar);
    }

    return switched;
  }
}

// Translate a char to a string
// Inspired by https://www.geeksforgeeks.org/how-to-convert-a-single-character-to-string-in-cpp/
string Translator::charToString(char c) {
    /* string class has a constructor that allows us to specify size of string as first 
       parameter and character to be filled in given size as second parameter.
    */ 
    string s(1, c); 
  
    return s;    
}

// Prints the main menu
void Translator::printMenu() {
  cout << "**************************************************************" << endl;
  cout << "            Welcome to the Pig Latinator-inator!              " << endl;
  cout << "       Elcomeway otay ethay Igpay Atinatorlay-inatorway!      ";
  printLogo();
  cout << endl;
  cout << "        Please choose one of the options below.               " << endl << endl;
  cout << "        1. Translate a message from English to Pig Latin      " << endl << endl;
  cout << "        2. Translate a message from Pig Latin to English      " << endl << endl;
  cout << "        3. Print an encrypted message to file (Engl --> PL)   " << endl << endl;
  cout << "        4. Print a decrypted message to file (PL --> Engl)    " << endl << endl;
  cout << "        5. Read Pig Latin rules                               " << endl << endl;
  cout << "            Type 1, 2, 3, 4, or 5 and press Enter             " << endl << endl;
  cout << "                       Type 0 to quit                         " << endl;
  cout << "**************************************************************" << endl; 
}

// Requests, checks, and returns input for a menu option
int Translator::getOption() {
  int option;

  // Inspired by https://stackoverflow.com/questions/12721911/c-how-to-verify-is-the-data-input-is-of-the-correct-datatype
  // Ensures that user inputs an int
  while(!(cin >> option)){
    cout << "Invalid option. Type 1, 2, 3, 4, or 5 and press Enter." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    printMenu();
  }

  cin.get();
  return option;
} 

// Inspired by http://www.cplusplus.com/reference/string/string/getline/
// Inspired by https://stackoverflow.com/questions/10053860/getline-wont-let-me-type-c
// Requests the English message to be translated
void Translator::requestEnglMessage() {
  string message;

  cout << "Please enter the English message, and press Enter: " << endl;
  getline(cin, message);
  cout << endl;
  
  englText = message;
}

// Requests the Pig Latin message to be translated
void Translator::requestPLMessage() {
  string message;

  cout << "Please enter the Pig Latin message, and press Enter: " << endl;
  getline(cin, message);
  cout << endl;
  
  pigLatinText = message;
}

// Prints the pig logo design
void Translator::printLogo() {
  cout << "                                                       " << endl;
  cout << "                                                       " << endl;
  cout << "                *      *                               " << endl;
  cout << "               * * * *  *                              " << endl;
  cout << "               *        *                              " << endl;
  cout << "            ***          *   *  *  *                   " << endl;
  cout << "           *  *          *             *     *  *      " << endl;
  cout << "            ****        *                * *  *        " << endl;
  cout << "                 * * *                    *            " << endl;
  cout << "                   **                     *            " << endl;
  cout << "                    *    *    ***    *    *            " << endl;
  cout << "                     *  * *  *   *  * *  *             " << endl;
  cout << "                      **   **     **   **              " << endl;
}

// Prints pig latin rules
void Translator::printRules() {
  cout << "Translate from English to Pig Latin: " << endl << endl;

  cout << "Move the consonant or consonant blend from the beginning" << endl; 
  cout << "to the end of the word." << endl;
  cout << "If a word begins with a vowel, add \"-way\" to the end instead." << endl;
  cout << "All other characters except apostrophes (\') remain the same." << endl;

  cout << "Special Cases - Y and U:" << endl << endl;

  cout << "If 'y' is the first letter in the word, it is considered" << endl; 
  cout << "to be a consonant. Otherwise, it is considered to be a vowel." << endl << endl;

  cout << "If 'q' comes before 'u', 'u' is a part of the \"qu\" consonant" << endl;
  cout << "blend. Therefore, it is considered to be a consonant." << endl;
  cout << "Otherwise, it is considered to be a vowel." << endl << endl;

  cout << "Examples: " << endl << endl;

  cout << "Single Consonant: pig --> igpay" << endl;
  cout << "Consonant blend:  translator --> anslatortray" << endl;
  cout << "Vowel:            apple --> appleway" << endl;
  cout << "Consonant \'Y\':  yellow --> ellowyay" << endl;
  cout << "Consonant \'U\':  quiet --> ietquay" << endl;

  cout << "**************************************************************" << endl << endl;

  cout << "See the following websites for more information:" << endl;
  cout << "https://www.wikihow.com/Speak-Pig-Latin" << endl;
  cout << "http://www.snowcrest.net/donnelly/piglatin.html" << endl << endl;
}
