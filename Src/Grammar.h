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

#ifndef PRACTICE8_NFA_H
#define PRACTICE8_NFA_H

#include "Nfa.h"
#include "Production.h"

class Grammar {
  public:
  protected:
  private:
    std::set<char>  terminals_;         //!< Represents the set of terminals of the grammar.
    std::set<char> noTerminals_;        //!< Represents the set of non terminals of
                                        //!< the grammar.
    std::string    startSymbol_;        //!< Is the boot symbol.
    std::set<Production> productions_;  //!< Is the set of productions of the
                                        //!< Grammar.
};

#endif  //PRACTICE8_NFA_H
