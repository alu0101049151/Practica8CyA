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

#ifndef PRACTICE8_GRAMMAR_H
#define PRACTICE8_GRAMMAR_H

#include "Nfa.h"
#include "Production.h"

const std::string STICK = "|";
const std::string ARROW = "->";
const std::string FINAL = "f";

class Grammar {
  public:
    Grammar (std::string& grammarDefinition);
    ~Grammar ();

    /**
    * @brief Generates an NFA from the grammar read.
    * @return the nfa resulting from the conversion.
    */
    Nfa convertToNFA();

		void printGrammar(std::string& outputFile);
  
	private:
    //std::set<char> getTerminals() const;
    //std::set<char> getNonTerminals() const;
    //std::string getstartSymbol() const;
    //std::set<Production> getProductions() const;
   
    /**
    * @brief Reads the grammar description of the input file and builds the grammar.
    * @param inputFile is the file that constains the Grammar description.
    */
    void readAndBuildGrammar(std::string& grammarDefinition);
    
    
		Alphabet        terminals_;         //!< Represents the set of terminals of the grammar.
    Alphabet     nonTerminals_;         //!< Represents the set of non terminals of
                                        //!< the grammar.
    std::string    startSymbol_;        //!< Is the boot symbol.
    std::set<Production> productions_;  //!< Is the set of productions of the
                                        //!< Grammar.
  //  std::vector<std::string> comments_; //!< Contains the comments of the input file.
};

#endif  //PRACTICE8_GRAMMAR_H
