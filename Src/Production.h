/**
 * @Author Basilio Gómez Navarro
 * @date 10/11/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 8 - Regular Grammars and Finite Automatons.
 * Email: alu0101049151@ull.edu.es
 * Production.h file: Production class. It represents a producction rule of a
 *                    Context Free Grammar (CFG).
 *                    This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/184519/mod_assign/introattachment/0/CYA_1920_Practica_8.pdf?forcedownload=1
 * Revision history:
 *                10/11/2019 - Creation (first version) of the code
 */

#ifndef PRACTICE8_PRODUCTION_H
#define PRACTICE8_PRODUCTION_H

#include <set>
#include <string>

class Production {
  public:

    /**
    * @brief Default constructor.
    */
    Production ();

    /**
    * @brief Parameter Constructor.
    * @param leftPart is the non-terminal on the left of the production.
    * @param rightPart is the set of grammatical symbol string.
    */
    Production (char leftPart, std::set<std::string> rightPart);
    
    /**
    * @brief Copy constructor.
    */
    Production (const Production& production);
    
    /**
    * @brief Destructor.
    */
    ~Production ();

  private:
    /**
    * @return the non-terminal on the left of the production.
    */
    char getLeftPart () const;

    /**
    * @return the set of grammatical symbols strings.
    */
    std::set<std::string> getRightPart () const;

    
    /**
    * @brief Allows modify the non-terminal on the right of the 
    * production rule.
    */
    void setLeftPart (char leftPart);

    /**
    * @brief Allows to insert a new production in the right set of productions.
    */
    void insertNewProduction (std::string& auxStr);

    int operator< (const Production& production) const;

  protected:
  private:
    char                    leftPart_;  //!< Represents the non-terminal of production.
    std::set<std::string>  rightPart_;  //!< Represents the set of productions
                                        //!< of the production rule. 
};

#endif //PRACTICE8_PRODUCTION_H
