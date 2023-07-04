/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#include "../include/electricPokemon.h"

electricPokemon::electricPokemon(std::string in_name, int in_hp, int in_damage, double in_powerUpChance, int in_recharge) : Pokemon{in_name, in_hp, in_damage, in_powerUpChance, in_recharge}
{ // Constructor of the electricPokemon derived from Pokemon class
    std::cout << "Electric Pokemon " << in_name << " has entered the arena." << std::endl;
    std::cout << "Class: Electric" << std::endl;
    std::cout << "        Name: " << in_name << std::endl;
    std::cout << "        HP: " << in_hp << std::endl;
    std::cout << "        Damage: " << in_damage << std::endl
              << std::endl
              << std::endl;
}

void electricPokemon::checkForTerrain(const std::string terrain)
{ // sets the whether tje pokemon is in the it's own terrain or not
    if (terrain == this->m_type)
    {
        this->setIsOwnTerrain(true);
    }
    else
    {
        this->setIsOwnTerrain(false);
    }
}

int electricPokemon::attack()
{ // to calculate the given damage, we need to check 3 circumstances
    if (this->getIsInOwnTerrain())
    { // firstly, state of the is in own terrain, if it is then the pokemon will not be confused so we make the counter 0 and calculate the damage.
        this->m_isConfused = 0;
        if (this->getIsPowerUp())
        { // secondly, if the pokemon's power is up than we triple the damage.
            return this->getDamage() * 3;
        }
        else
        { // otherwise, just give the regular damage
            return this->getDamage();
        }
    }
    else
    {
        if (this->getIsConfused())
        { // if it is not in it's own terrain and the pokemon is confused, then the given damage is 0
            if (this->getIsPowerUp())
            { // it is not important that whether the pokemon's power is up or not but for counter of remaining round
                return 0;
            }
            else
            { // the given damage is 0 in both circumstances
                return 0;
            }
        }
        else
        { // if the pokemon is not confused, then check for power up and if the pokemon's power is up, triple the given damage
            if (this->getIsPowerUp())
            {
                return this->getDamage() * 3;
            }
            else
            { // last possibility, just give the regular damage
                return this->getDamage();
            }
        }
    }
}

bool electricPokemon::getIsConfused()
{ // this method checks and returns the confusion state of the pokemon
    if (this->m_isConfused == 0)
    {
        return false;
    }
    else
    {
        this->m_isConfused--;
        return true;
    }
}
