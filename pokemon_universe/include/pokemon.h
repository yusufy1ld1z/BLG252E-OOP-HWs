/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#ifndef _POKEMON_H
#define _POKEMON_H

#include <string>
#include <iostream>

class Pokemon
{
public:
    Pokemon(std::string name, int hp, int damage, double powerup, int recharge) : m_name{name}, m_hitpoint{hp}, m_damage{damage}, m_powerUpChance{powerup}, m_recharge{recharge} {}; // member initializer list

    void defense(const int); // it recieves the given damage as a paramater and
                             // calculates the new hitpoint of the pokemon
                             // if new hitpoint is below or equal to zero .then pokemon will be fainted and new hitpoint will be set to zero
    //  Getter functions for Pokemon class for encapsulation
    const bool getIsPowerUp(); // it calculates the power up state and rearrange the state of power up, then return the state
    // Below functions implemented in header for better coding style
    const std::string getName() const { return this->m_name; };
    const int getHP() const { return this->m_hitpoint; };
    const int getDamage() const { return this->m_damage; };
    const double getPowerUpChance() const { return this->m_powerUpChance; };
    const int getRecharge() const { return this->m_recharge; };
    const bool getIsFainted() const { return this->m_isFainted; };
    const bool getPowerUpState() const { return this->m_powerUpState; };
    const int getRemaingRoundForPowerUp() const { return this->m_remaingRoundForPowerUp; };
    const bool getIsInOwnTerrain() const { return this->m_isInOwnTerrain; };
    // Setter functions for Pokemon class
    void setIsOwnTerrain(const bool is_in_own) { this->m_isInOwnTerrain = is_in_own; };
    void setRemainingRoundForPowerUp(const int remaining_round) { this->m_remaingRoundForPowerUp = remaining_round; };

private:
    const std::string m_name;
    int m_hitpoint;
    const int m_damage;
    const double m_powerUpChance;
    const int m_recharge;
    bool m_powerUpState = false;
    int m_remaingRoundForPowerUp = 0; // it is a counter for remaning round of power ups.
    bool m_isInOwnTerrain = false;
    bool m_isFainted = false;
};
#endif