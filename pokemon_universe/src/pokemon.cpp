/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#include "../include/pokemon.h"
#include <random>

void Pokemon::defense(const int takenDamage)
{ // it calculates new hitpoint and make necessary arrangements
    this->m_hitpoint -= takenDamage;
    if (this->m_hitpoint <= 0)
    {
        this->m_hitpoint = 0;
        this->m_isFainted = true;
    }
}

const bool Pokemon::getIsPowerUp()
{ // first it controls if there is not a remaing round ,if there is ,then we decrease the remaining round,
  // otherwise it generates a random value and then make it true or false
    if (this->m_remaingRoundForPowerUp == 0)
    {
        int random = rand() % 100;
        if (this->getPowerUpChance() > random)
        {
            this->m_remaingRoundForPowerUp = this->m_recharge;
            this->m_powerUpState = true;
            return true;
        }
        else
        {
            this->m_powerUpState = false;
            return false;
        }
    }
    else
    {
        this->m_remaingRoundForPowerUp--;
        this->m_powerUpState = false;
        return false;
    }
}
