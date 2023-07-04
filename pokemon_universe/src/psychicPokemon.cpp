/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#include "../include/psychicPokemon.h"

pyschicPokemon::pyschicPokemon(std::string in_name, int in_hp, int in_damage, double in_powerUpChance, int in_recharge) : Pokemon{in_name, in_hp, in_damage, in_powerUpChance, in_recharge}
{ // Constructor of the pyschicPokemon derived from Pokemon class
    std::cout << "Psychic Pokemon " << in_name << " has entered the arena." << std::endl;
    std::cout << "Class: Psychic" << std::endl;
    std::cout << "        Name: " << in_name << std::endl;
    std::cout << "        HP: " << in_hp << std::endl;
    std::cout << "        Damage: " << in_damage << std::endl
              << std::endl
              << std::endl;
}

int pyschicPokemon::attack(electricPokemon *&in_electricPokemon)
{ // to calculate the given damage we need to check 2 circumstances
    if (this->getIsInOwnTerrain())
    { // if the pokemon is in its own terrain then, we double the given damage
        if (this->getIsPowerUp())
        { // if there is power up ,then we make electric pokemon confused for three rounds in a row
            in_electricPokemon->setIsConfused(3);
            return this->getDamage() * 2;
        }
        else
        { // if there is no confusion just give the  calculated damage to the electric pokemon
            return this->getDamage() * 2;
        }
    }
    else
    {
        if (this->getIsPowerUp())
        { // if there is power up ,then we make electric pokemon confused for three rounds in a row
            in_electricPokemon->setIsConfused(3);
            return this->getDamage();
        }
        else
        { // last possibility, just give the calculated damage to the electric pokemon
            return this->getDamage();
        }
    }
}

void pyschicPokemon::checkForTerrain(const std::string terrain)
{ // if the pokemon is in its own terrain then, we set own terrain variable true otherwise false
    if (terrain == this->m_type)
    {
        this->setIsOwnTerrain(true);
    }
    else
    {
        this->setIsOwnTerrain(false);
    }
}