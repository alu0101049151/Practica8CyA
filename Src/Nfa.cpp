/**
 * @Author Basilio Gómez Navarro
 * @date 10/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 8 - Regular Grammars and Finite Automatons.
 * Email: alu0101049151@ull.edu.es
 * Grammar.cpp file: Grammar class. It represents a Regular Linear Grammar on the
 *                 right.
 *                 This file contains the class Implementation.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/184519/mod_assign/introattachment/0/CYA_1920_Practica_8.pdf?forcedownload=1
 * Revision history:
 *                10/11/2019 - Creation (first version) of the code
 */

#include "Nfa.h"

/*Nfa::Nfa(std::string& inputFile) {
  readAndBuildNfa(inputFile);
}*/


Nfa::Nfa(const Nfa& nfa):
  startState_(nfa.startState_),
  states_(nfa.states_),
  finalStates_(nfa.finalStates_),
  alphabet_(nfa.alphabet_),
  transitions_(nfa.transitions_),
  comments_(nfa.comments_) {}


Nfa::Nfa(std::string startState, std::set<State> states, std::set<std::string>
     finalStates, Alphabet alphabet, std::set<Transition> transitions):
     startState_(startState),
     states_(states),
     finalStates_(finalStates),
     alphabet_(alphabet),
     transitions_(transitions) {}


Nfa::Nfa() {}


Nfa::~Nfa() {}


/**
* Returns the start state identifier.
*/
std::string Nfa::getStartState() const {
  return startState_;
}


/**
* Returns the set of states of the automaton.
*/
std::set<State> Nfa::getStates() const {
  return states_;
}


/**
* Returns the set of the final states identifiers.
*/
std::set<std::string> Nfa::getFinalStates() const {
  return finalStates_;
}


/**
* Returns the set of chars that represents the alphabet of the
* automaton.
*/
Alphabet Nfa::getAlphabet() const {
  return alphabet_;
}


/**
* Returns the vector containing all the comments read from the input file.
*/
std::vector<std::string> Nfa::getComments() const {
  return comments_;
}


/**
* Returns the set of transitions of the automaton.
*/
std::set<Transition> Nfa::getTransitions() const {
  return transitions_;
}


/**
* Reads the input file and builds the Nfa.
*/
void Nfa::readAndBuildNfa(std::string& nfaDefinition) {
  std::ifstream inputFile;
  inputFile.open(nfaDefinition);

  if (!inputFile.is_open()) {
    std::cerr << "There was a problem opening the inputfile, ";
    std::cerr << "please, try again." << NEWLINE;
  }
  else {
   std::string readed;      //!< Stores what is read every time we read a line from the file

   std::getline(inputFile, readed);
   std::string auxStr = readed.substr (0,3);

   bool isComment = auxStr == COMMENT;
   bool noEndComment = auxStr != ENDOFCOMMENTS; // ENDOFCOMMENTS = "///" means the end of comments

  //================================================
  // Reading header comments
  //================================================
   while (auxStr == COMMENT) {
     comments_.push_back(readed);
     readed.clear();
     std::getline(inputFile, readed);
     auxStr = readed.substr (0,3);
   }

     int temp;  //!< Used for store the amounts (alpabet symbols, states, etc.)
                //!< temporarily

     //================================
     // Reading the alphabet symbols
     //================================
     std::getline(inputFile, readed);  // Read the number of alphabet symbols
     temp = stoi(readed);
     readed.clear();
     char auxChar;

     std::getline(inputFile, readed);  //Read the ~ (epsilon) symbol.
     auxChar = readed[0];
     alphabet_.insertAlphabet(auxChar);
     readed.clear();

     for (int i = 0; i < temp; i++) {
       std::getline(inputFile, readed);
       auxChar = readed[0];
       alphabet_.insertAlphabet(auxChar);
       readed.clear();
     }

     //==============================
     // Reading of DFA states
     //==============================
     std::getline(inputFile, readed);  // Read the number of automaton states.
     temp = stoi(readed);
     readed.clear();

     for (int i = 0; i < temp; ++i) {
       std::getline(inputFile, readed);
       State auxState(readed);
       states_.insert(auxState);
       readed.clear();
     }

     //==============================
     // Reading of start state
     //==============================
     std::getline(inputFile, readed); // Read the star state.
     startState_ = readed;
     readed.clear();

     //==============================
     // Reading final states
     //==============================
     std::getline(inputFile, readed); // Read the number of final states.
     temp = stoi(readed);
     readed.clear();

     for (int i = 0; i < temp; ++i) {
       std::getline(inputFile, readed);
       finalStates_.insert(readed);
       readed.clear();
     }

     //================================
     // Reading automaton transitions
     //================================
     std::getline(inputFile, readed); // Read the number of transitions.
     temp = stoi(readed);
     readed.clear();

     std::string auxCurrentState;
     std::string auxInput;
     std::string auxDestination;
     char auxCharInput;

     for (int i = 0; i < temp; ++i) {
       std::getline(inputFile, readed);
       std::stringstream iss(readed);
       iss >> auxCurrentState;
       iss >> auxInput;
       iss >> auxDestination;

       Transition auxTransition(auxInput[0], auxCurrentState, auxDestination);
       transitions_.insert(auxTransition);
     }
  }
}

void Nfa::printNfa(std::string& outputFile) {
  std::ofstream outputNfa;
  outputNfa.open(outputFile);

  outputNfa << alphabet_.getAlphabet().size() << NEWLINE;
  for (auto i: alphabet_.getAlphabet()) {
    outputNfa << i << NEWLINE;
  }

  outputNfa << states_.size() << NEWLINE;
  for (auto i: states_) {
    outputNfa << i.getStateId() << NEWLINE;
  }

  outputNfa << startState_ << NEWLINE;
  
  outputNfa << finalStates_.size() << NEWLINE;
  for (auto i: finalStates_) {
    outputNfa << i << NEWLINE;
  }

  outputNfa << transitions_.size() << NEWLINE;
  for (auto i: transitions_) {
    outputNfa << i.getCurrent() << " " << i.getInput() << " " << i.getDestination() << NEWLINE;
  }
  
  outputNfa.close();
}
