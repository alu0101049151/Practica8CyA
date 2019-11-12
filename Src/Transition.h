/**
 * @Author Basilio Gómez Navarro
 * @date 10/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 8 - Regular Grammars and Finite Automatons. 
 * Email: alu0101049151@ull.edu.es
 * Transition.h file: Transition class. It represents a transition between the
 *                    current state and another state of the automaton. The 
 *                    destination depends on the entry that reaches the current 
 *                    state. This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/184519/mod_assign/introattachment/0/CYA_1920_Practica_8.pdf?forcedownload=1
 * Revision history:
 *                10/11/2019 - Creation (first version) of the code
 */

#ifndef PRACTICE8_TRANSITION_H
#define PRACTICE8_TRANSITION_H

#include <string>

class Transition {

	public:
		Transition(char input, std::string current, std::string destination);
		Transition(const Transition& transition);
		~Transition();

		char getInput() const;
		std::string getDestination() const;
    std::string getCurrent() const;

		int operator< (const Transition& transition) const;

	private:
		char input_;                //!< Input symbol that determines the state to which transit the current state
		std::string  current_;      //!< If of the current state.
    std::string  destination_;  //!< Id of the destination state to which it transits with "input_"
};

#endif //PRACTICE8_TRANSITION_H
