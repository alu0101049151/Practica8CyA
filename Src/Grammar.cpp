/**
 * @Author Basilio Gómez Navarro
 * @date 10/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 8 - Regular Grammars and Finite Automatons.
 * Email: alu0101049151@ull.edu.es
 * Grammar.h file: Grammar class. It represents a Regular Linear Grammar on the
 *                 right.
 *                 This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/184519/mod_assign/introattachment/0/CYA_1920_Practica_8.pdf?forcedownload=1
 * Revision history:
 *                10/11/2019 - Creation (first version) of the code
 */


#include "Grammar.h"

Grammar::Grammar (std::string& grammarDefinition) {
  readAndBuildGrammar(grammarDefinition);
}

Grammar::~Grammar () {}

/**
* Reads the grammar description of the input file and builds the grammar.
*/
void Grammar::readAndBuildGrammar(std::string& grammarDefinition) {
  std::ifstream inputFile;
  inputFile.open(grammarDefinition);

  if (!inputFile.is_open()) {
    std::cerr << "There was a problem opening the input file, please, try ";
    std::cerr << "again." << NEWLINE;
  }
  else {
    std::string read;  // stores what is read every time a line is read, in the fil
    bool isComment = true;

  //================================================
  // Reading header comments
  //================================================
    int pos;

    while (isComment) {
      std::getline(inputFile, read);
      pos = read.find(COMMENT);

      if (pos == 0)
        isComment = true;
      else 
        isComment = false;
    }

    int temp; // Used for store the amounts (alphabet size, number of states
              // etc.) temporarily

  //================================
  // Reading the alphabet symbols
  //================================
    // 'read' contains now Read the number of alphabet symbols
    temp = stoi(read);
    read.clear();
    char auxChar;

    for (int i = 0; i < temp; i++) {
      std::getline(inputFile, read);
      auxChar = read[0];
      std::cout << "Auxchar:  " << auxChar << NEWLINE;
      terminals_.insertAlphabet(auxChar);
      read.clear();
    }

    //==============================
    // Reading of non-terminals
    //==============================
     std::getline(inputFile, read);  // Read the number of non-terminals.
     temp = stoi(read);
     read.clear();

     for (int i = 0; i < temp; ++i) {
       std::getline(inputFile, read);
       auxChar = read[0];
       nonTerminals_.insert(auxChar);
       read.clear();
     }

     //==============================
     // Reading of start symbol
     //==============================
     std::getline(inputFile, read); // Read the star symbol.
     startSymbol_ = read;
     read.clear();

     //================================
     // Reading grammar productions
     //================================
     std::getline(inputFile, read); // Read the number of productions.
     temp = stoi(read);
     read.clear();

     char auxNonTerminal;
     std::string auxString;
     std::string auxGrammaticalSymb; // Temporarily stores the strings of grammar
                                    // symbols read.
     for (int i = 0; i < temp; ++i) {
       std::getline(inputFile, read);
       std::stringstream iss(read);

       iss >> auxString;
       auxNonTerminal = auxString[0]; // Read nonTerminal at the left part of the production rule.
       
       iss >> auxGrammaticalSymb;  // Read the arrow.
       auxGrammaticalSymb.clear();

       iss >> auxGrammaticalSymb;

       Production auxProduction(auxNonTerminal, auxGrammaticalSymb);
       productions_.insert(auxProduction);
     }
  }
}


/**
* Generates an NFA from the grammar read.
*/
Nfa Grammar::convertToNFA() {

  // Generate the states set
  std::set<State> auxStates;
  for (auto i: nonTerminals) {
    std::string auxStr(1, i);
    State auxState(auxStr);
    auxStates.insert(auxState);
  }
  State finalState(FINAL);
  auxStates.insert(finalState);

  // Generate the final statets set only with de state 'f'.
  std::set<std::string> auxfinalStates;
  auxfinalStates.insert(FINAL);

  // Start State will have the same id as Start Symbol.
  // The alphabet will be the same as Terminals + the epsilon.

  // Generate the set of transitions of the NFA.
  std::set<Transition> auxTransitions;

  char auxIput;
  std::string auxCurrent;
  std::string auxDestination;
  
  for (auto i: productions_) {

  }
  
}

