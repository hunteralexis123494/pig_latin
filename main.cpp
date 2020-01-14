/* Alexis Hunter
 * Coding Sample 1: Pig Latin Translator
 * main.cpp  
 */

#include "translator.h"
#include "alphabet.h"
#include "letter.h"

#include <fstream>
#include <sys/stat.h>

// Inspired by C++ Program find if file exists of not  
// http://www.codebind.com/cpp-tutorial/cpp-program-find-file-exists-not/
bool FileExists(const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

// Inspired by Stack Overflow: How do I flush the cin buffer? 
// https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer
// Clears the cin buffer so extra characters won't be read
void clearCinBuffer() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Controls the flow of the program
int main() {
  Translator pgTranslator;
  Alphabet alphabet;
  vector<Letter> alphaVector = alphabet.getAlphabet();

  string inputText;
  string outputText;
  string in;
  string out;
  string temp;

  bool repeat = true;
  
  // Keeps the program going until user presses '0' in the main menu to quit
  while (repeat) {
    // Prints the menu and gets the user input for an option
    pgTranslator.printMenu();
    int option = pgTranslator.getOption();

    // Exits while loop to end program
    if (option == 0) {
      repeat = false;
    }
    // Starts option 1: Translate from English to Pig Latin
    else if (option == 1) {     
      cout << "**************************************************************" << endl;

      bool request = true;

      while (request) { 
        pgTranslator.requestEnglMessage();

        cout << "English:   " << endl << pgTranslator.getEnglText() << endl << endl;
        pgTranslator.translateEnglToPL();
        cout << "Pig Latin: " << endl << pgTranslator.getPigLatinText() << endl << endl;

        cout << "Press 'Q' to quit or any other key to translate another message: ";

        char answer;
      
        cin >> answer;
        clearCinBuffer();

        if (answer == 'Q' || answer == 'q') {
	  request = false;
        }
	else {
          cout << endl;
        }
      }
    }
    // Starts option 2: Translate from Pig Latin to English
    else if (option == 2) {
      cout << "**************************************************************" << endl;

      bool request = true;

      while (request) { 
        pgTranslator.requestPLMessage();

        cout << "Pig Latin: " << endl << pgTranslator.getPigLatinText() << endl << endl;
        pgTranslator.translatePLToEngl();
        
        if(!pgTranslator.getEnglText().empty()) {
          cout << "English:   " << endl << pgTranslator.getEnglText() << endl << endl;
        }
        
        cout << "Press 'Q' to quit or any other key to translate another message: ";

        char answer;
      
        cin >> answer;
        clearCinBuffer();

        if (answer == 'Q' || answer == 'q') {
	  request = false;
        }
	else {
          cout << endl;
        }
      }
    }
    // Starts option 3 or 4: Translate English text from an input file and write it
    // to another file in Pig Latin or vice versa 
    else if (option == 3 || option == 4) {
      cout << "**************************************************************" << endl;

      bool askAgain = true;
      // Requests input file and checks if it exists
      while(askAgain) {
        cout << "Enter file name to be read (Ex: file.txt): ";
        cin >> in;

        if(!FileExists(in)) {
          cout << endl << in << " does not exist." << endl << endl;
        }
        else {
          askAgain = false;
        }    
      }
      ifstream inputFile (in);

      askAgain = true;
      temp = "";

      // Requests output file and checks if it exists
      while(askAgain) {
        cout << endl << "Enter file name to be written (Ex: file.txt): ";
        cin >> out;

        if(FileExists(out)) {
          bool getAnswer = true;
          while(getAnswer) {
            char answer;
            cout << endl << out << " exists. Do you want to overwrite it? Enter Y or N: ";
            cin >> answer;

            if(answer == 'Y' || answer == 'y') {
              clearCinBuffer();
              getAnswer = false;
              askAgain = false;
            }
            else if (answer == 'N' || answer == 'n') {
              clearCinBuffer();
              getAnswer = false;
              
            }
            else {
              clearCinBuffer();
              cout << endl << "Invalid input." << endl;
            }
          }
        }
        else {
          askAgain = false;
        }
      }

      ofstream outputFile (out);
      cout << endl;

      // Reads and stores text from input file to a string
      if (inputFile.is_open()) {
        while(!inputFile.eof()) {
          getline(inputFile, inputText);
          temp += inputText + pgTranslator.charToString('\n');
        }
        inputFile.close();

        
        // Removes the extra newline character from temp
        string store;
        for(unsigned int i = 0; i < temp.size()-1; i++) {
          store += temp.at(i);
        }
        temp = store;

        // If option 3 is selected, text is assumed to be English and is translated to Pig Latin
        if (option == 3) {
          pgTranslator.setEnglText(temp);
          pgTranslator.translateEnglToPL();
          outputText = pgTranslator.getPigLatinText();
        }
        // If option 4 is selected, text is assumed to be Pig Latin and is translated to English
        else {
          pgTranslator.setPigLatinText(temp);
          pgTranslator.translatePLToEngl();
          outputText = pgTranslator.getEnglText();
        }

        // Writes to output file and checks if a translation has been made
        if (outputFile.is_open()) {
          if(outputText.empty()) {
            cout << "Translation incomplete. Unable to write to " << out << endl;
          }
          else {
            outputFile << outputText;
            outputFile.close();
            cout << "Successfully wrote translation to " << out << endl;
          }
        }
        else {
          cout << "Unable to write to file" << endl << endl;
        }
      }
      else {
        cout << "Unable to open file" << endl << endl;
      }
      
    }
    // Inspired by https://stackoverflow.com/questions/21257544/c-wait-for-user-input
    // Prints Pig Latin rules
    else if (option == 5) {
      cout << "**************************************************************" << endl;

      pgTranslator.printRules();
      
      // Doesn't automatically print the main menu, so rules remain on the bottom of the scree
      do {
        cout << "Press any key and Enter to return to the main menu..." << endl;
      } 
      while (!cin.get());

      clearCinBuffer();
    }
    // Prints error message if input is not one of the options
    else {
      cout << "Invalid option. Type 1, 2, 3, 4, or 5 and press Enter." << endl;
    }
  }

  return 0;
}
