/**
 * @Author Basilio Gómez Navarro
 * @date 10/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 8 - Regular Grammars and Finite Automatons. 
 * Email: alu0101049151@ull.edu.es
 * State.h file: State class. It represents a state of a 
 *               Non Deterministic Finite Automaton.
 *               This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/184519/mod_assign/introattachment/0/CYA_1920_Practica_8.pdf?forcedownload=1
 * Revision history:
 *                27/10/2019 - Creation (first version) of the code
 */

#ifndef PRACTICE8_STATE_H
#define PRACTICE8_STATE_H

#include <set>
#include <string>

#include "Transition.h"

class State {
	
	public:
		State(std::string stateId);
		State(const State& state);
    State();
		~State();

		std::string getStateId() const;
		int transitionsNumber() const;

		int operator< (const State& state) const;

	private:
		std::string stateId_;               //!< State Identifier.
};


#endif //PRACTICE8_STATE_H

