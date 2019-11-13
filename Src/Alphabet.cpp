/**
 * @Author Basilio Gómez Navarro
 * @date 10/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 8 - Regular Grammars and Finite Automatons.
 * Email: alu0101049151@ull.edu.es
 * Alphabet.cpp file: Alphabet class. It represents the alphabet of the DFA
 *                    This file contains the class implementation.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/184519/mod_assign/introattachment/0/CYA_1920_Practica_8.pdf?forcedownload=1
 * Revision history:
 *                11/11/2019 - Creation (first version) of the code
 */

 #include "Alphabet.h"


Alphabet::Alphabet () {}

Alphabet::~Alphabet () {}

/**
* Inserts the symbol passed as a parameter in the alphabet. 
*/
void Alphabet::insertAlphabet (const char symbol) {
	alphabet_.insert(symbol);
}

/**
* @brief returns alphabet.
*/
std::set<char> Alphabet::getAlphabet() const {
  return alphabet_;
}

/**
* @brief check if a symbol belongs tot the alphabet.
* @return true if it belongs or false if not.
*/
bool Alphabet::checkIfBelongs(char toCheck) {
  bool belong = false;
  for (auto i: alphabet_) {
    if (i == toCheck)
      belong = true;
  }
  return belong;
}

Alphabet& Alphabet::operator= (const Alphabet &alphabet) {
  this->alphabet_ = alphabet.alphabet_;
  return *this;
}

