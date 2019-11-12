/**
 * @Author Basilio Gómez Navarro
 * @date 10/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 8 - Regular Grammars and Finite Automatons.
 * Email: alu0101049151@ull.edu.es
 * Production.cpp file: Production class. It represents a producction rule of a
 *                      Context Free Grammar (CFG).
 *                      This file contains the class implementation.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/184519/mod_assign/introattachment/0/CYA_1920_Practica_8.pdf?forcedownload=1
 * Revision history:
 *                10/11/2019 - Creation (first version) of the code
 */

#include "Production.h"

Production::Production () {}

/**
* Parameter constructor that receives a non-terminal (leftPart)
* and a set of grammatical symbol strings (rightPart).
*/
Production::Production (char leftPart, std::set<std::string> rightPart): 
  leftPart_(leftPart),
  rightPart_(rightPart) {}


Production::Production (const Production& production): 
  leftPart_(production.leftPart_),
  rightPart_(production.rightPart_) {}

Production:: ~Production () {}


/**
* Returns the non-terminal that is on the left side of the production.
*/
char Production::getLeftPart () const {
  return leftPart_;
}


/**
* Returns the set of productions that is on the right side of the production
* rule.
*/
std::set<std::string> Production::getRightPart () const {
  return rightPart_;
}


/**
* Allows modify the non-terminal on the right of the production rule.
*/
void Production::setLeftPart (char leftPart) {
  leftPart_ = leftPart;
}


/**
* Allows to insert a new production in the set of productions that 
* is on the right of the production rule.
*/
void Production::insertNewProduction (std::string& auxStr) {
  rightPart_.insert(auxStr);
}


int Production::operator< (const Production& production) const {
  if (this->leftPart_ == production.leftPart_) return 1;
  if (this->leftPart_ < production.leftPart_) return 1;
  return 0;
}
