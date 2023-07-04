/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#ifndef _ELECTRIC_POKEMON_H
#define _ELECTRIC_POKEMON_H

#include "pokemon.h"

class electricPokemon : public Pokemon
{
public:
    electricPokemon(std::string, int, int, double, int);
    void checkForTerrain(const std::string);
    bool getIsConfused();
    int attack();
    void setIsConfused(const int remaining) { this->m_isConfused = remaining; }; // setter function for remaining round for confusion                                                 // calculates the given damage.

private:
    const std::string m_type = "electric";
    int m_isConfused = 0; // it is the remain round of confusion ,if it is not confused than it is 0 initally
};
#endif