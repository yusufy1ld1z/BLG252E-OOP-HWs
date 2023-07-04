/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#ifndef _ARENA_H
#define _ARENA_H

#include <random>
#include "electricPokemon.h"
#include "psychicPokemon.h"

class Arena
{
public:
    ~Arena();
    void simulateBattle();
    void addPokemon(const char, const std::string, const int, const int);
    void spawnTerrain();
    void restartTerrain();
    // Print methods for user informing
    void printRoundStates(const int, const int);
    void printMatchResults();

private:
    electricPokemon *m_electricPokemon;
    pyschicPokemon *m_pyschicPokemon;
    std::string m_terrain;
    int m_toNewTerrain = 0; // a counter variable for terrain for changing
};
#endif