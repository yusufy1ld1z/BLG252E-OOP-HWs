/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#ifndef _PSYCICH_POKEMON_H
#define _PSYCICH_POKEMON_H

#include "pokemon.h"
#include "electricPokemon.h"

class pyschicPokemon : public Pokemon
{
public:
    pyschicPokemon(std::string, int, int, double, int);
    void checkForTerrain(const std::string);
    int attack(electricPokemon *&);

private:
    const std::string m_type = "pyschic";
};
#endif