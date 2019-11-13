/**
 * @Author Basilio Gómez Navarro
 * @date 10/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 8 - Regular Grammars and Finite Automatons.
 * Email: alu0101049151@ull.edu.es
 * Nfa.h file: Nfa class. It represents a Nondeterministic Finite Automaton.
 *             This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/184519/mod_assign/introattachment/0/CYA_1920_Practica_8.pdf?forcedownload=1
 * Revision history:
 *                10/11/2019 - Creation (first version) of the code
 */


#ifndef PRACTICE8_NFA_H
#define PRACTICE8_NFA_H

#include <iostream>
#include <vector>
#include <set>
#include <sstream>

#include "Alphabet.h"
#include "Transition.h"
#include "State.h"


const char EPSILON = '~';
const char NEWLINE = '\n';
const std::string COMMENT = "//";
const std::string ENDOFCOMMENTS = "///";
const std::string UNCHECKED = "@";

class Nfa {  
  public:
    //Nfa(std::string& inputFile);
    Nfa(std::string startState, std::set<State> states, std::set<std::string>
    finalStates, Alphabet alphabet, std::set<Transition> transitions);
    Nfa(const Nfa& nfa);
    Nfa();
    ~Nfa();
    
    /**
    * @brief Prints the description of Nfa in the given output file. 
    */
    void printNfa(std::string& outputFile);

  private:
    /**
    * @brief Returns the start state identifier.
    */
    std::string getStartState() const;

    /**
    * @brief Returns the set of states of the automaton.
    */
    std::set<State> getStates() const;

    /**
    * @brief Returns the set of the final states identifiers.
    */
    std::set<std::string> getFinalStates() const;

    /**
    * @brief Returns the set of chars that represents the alphabet of the
    * automaton.
    */
    Alphabet getAlphabet() const;

    /**
    * @brief Returns the vector containing all the comments read from the input file.
    */
    std::vector<std::string> getComments() const;

    /**
    * @brief Returns the set of transitions of the automaton.
    */
    std::set<Transition> getTransitions() const;


    /**
    * @brief Reads the input file and builds the Nfa.
    * @param inputFile is the name of the input file.
    */
    void readAndBuildNfa(std::string& nfaDefinition);
  
  protected:
  private:
    std::string startState_;             //!< Is the boot state.
    std::set<State> states_;             //!< Set with all the states of the Nfa.
    std::set<std::string> finalStates_;  //!< Set of id's of the final states.
    Alphabet alphabet_;                  //!< Alphabet of the Nfa.
    std::set<Transition> transitions_;   //!< Transitions of the Nfa.
    std::vector<std::string> comments_;  //!< Stores all the comments at the
                                         //!< beginning of the file.
};

#endif //PRACTICE8_NFA_H
