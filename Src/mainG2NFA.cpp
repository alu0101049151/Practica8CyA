/**
 * @Author Basilio Gómez Navarro
 * @date 10/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 8 - Regular Grammars and Finite Automatons.
 * Email: alu0101049151@ull.edu.es
 * mainG2NFA file: This file contains the main function of the program.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/184519/mod_assign/introattachment/0/CYA_1920_Practica_8.pdf?forcedownload=1
 * Revision history:
 *                10/11/2019 - Creation (first version) of the code
 */


#include "Grammar.h"

int main (int argc, char const* argv[]) {

  if (argc != 3 && argc != 4) {
    std::cout << "Usage: ./G2NFA input.gra output.nfa\n";
    std::cout << "Try 'G2NFA --help' for more information\n";
  } 
	if (argc == 2) {
    std::string inputFile = argv[1];

    if (inputFile  == "--help") {
      std::cout << "NAME\n";
      std::cout << "      G2NFA\n";
      std::cout << "\n";
      std::cout << "USAGE:\n";
      std::cout << "      G2NFA [input_file.gra] [output_file.nfa]\n";
      std::cout << "\n";
      std::cout << "DESCRIPTION\n";
      std::cout << "      Reads a \".gra\" input file with the definition of a\n";
      std::cout << "      Regular Grammar and generates a \".nfa\" output file \n";
      std::cout << "      with the NFA specification resulting from applying to\n";
      std::cout << "      the Grammar the conversion algorithm\n"; 
      std::cout << "\n";
      std::cout << "AUTHOR\n";
      std::cout << "      Written by Basilio Gómez Navarro as practice of the\n";
      std::cout << "      subject Computability and Algorithm. November of 2019.\n";
      std::cout << "\n\n";
		}
	}
  else if (argc == 3) {
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    Grammar gram(inputFile);
    Nfa myNfa(gram.convertToNFA());
    myNfa.printNfa(outputFile);
  }
	else if (argc == 4) {
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
		std::string gramOutputFile = argv[3];

    Grammar gram(inputFile);
    Nfa myNfa(gram.convertToNFA());
    myNfa.printNfa(outputFile);

		gram.printGrammar(gramOutputFile);
	}
  return 0;
}

