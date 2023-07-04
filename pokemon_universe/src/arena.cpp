/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#include "../include/arena.h"
#include <iostream>

Arena::~Arena()
{ // if there are some pokemons added to the arena and not simulated in a battle, then they must be deleted
    if (this->m_electricPokemon == nullptr)
    {
        delete this->m_electricPokemon;
    }

    if (this->m_pyschicPokemon == nullptr)
    {
        delete this->m_pyschicPokemon;
    }
    this->m_electricPokemon = nullptr; // set deleted pointers as null to prevent memory dangling
    this->m_pyschicPokemon = nullptr;
}

void Arena::simulateBattle()
{
    this->restartTerrain();
    int round = 0; // choose the terrain and start the counter
    while (true)   // battle loop which finishes only if one pokemon is fainted
    {
        round++;                   // round counter increased
        int firstHit = rand() % 2; // 0 for electricPokemon and 1 for pyschicPokemon

        this->m_electricPokemon->checkForTerrain(this->m_terrain); // check terrains for both pokemons
        this->m_pyschicPokemon->checkForTerrain(this->m_terrain);

        int damage;

        if (firstHit == 0)
        {                                               // if first hit comes from electric pokemon
            damage = this->m_electricPokemon->attack(); // calculate the damage given by rival
            this->m_pyschicPokemon->defense(damage);    // calculate the new hit point
            if (!this->m_pyschicPokemon->getIsFainted())
            {                                                                     // check whether the pokemon is fainted or not
                damage = this->m_pyschicPokemon->attack(this->m_electricPokemon); // if it is not fainted it is time to counter attack
                this->m_electricPokemon->defense(damage);
            }
            else
            { // if the pokemon is fainted, then print the round status and break the loop for printing match result
                this->printRoundStates(round, firstHit);
                break;
            }
        }
        else
        { // if first hit comes from pyschic pokemon
            damage = this->m_pyschicPokemon->attack(this->m_electricPokemon);
            this->m_electricPokemon->defense(damage);
            if (!this->m_electricPokemon->getIsFainted())
            {
                damage = this->m_electricPokemon->attack(); // it is time to counter attack
                this->m_pyschicPokemon->defense(damage);
            }
            else
            { // if the pokemon is fainted, then print the round status and break the loop for printing match result
                this->printRoundStates(round, firstHit);
                break;
            }
        }
        if (this->m_electricPokemon->getIsFainted() || this->m_pyschicPokemon->getIsFainted())
        { // check for both pokemon whether one of them is fainted, if one of them is fainted, then this battle is finished and we print the round status, then break the loop
            this->printRoundStates(round, firstHit);
            break;
        }
        this->printRoundStates(round, firstHit); // if neither of the pokemon is fainted, then print just the round status and continue to the battle
        this->spawnTerrain();                    // spawnTerrain method to calculate the new terrain in the arena
    }
    this->printMatchResults(); // if the battle is over, proceed to the match result

    // delete both pokemon and assign pointers as null to prevent memory dangling
    delete this->m_electricPokemon;
    delete this->m_pyschicPokemon;
    this->m_electricPokemon = nullptr;
    this->m_pyschicPokemon = nullptr;
}

void Arena::addPokemon(const char type, const std::string name, const int hp, const int damage)
{                    // create new pokemon by it's type
    if (type == 'e') // electric pokemon, electricity!!!
    {
        this->m_electricPokemon = new electricPokemon(name, hp, damage, 20, 3);
    }
    else if (type == 'p') // pyschic pokemon
    {
        this->m_pyschicPokemon = new pyschicPokemon(name, hp, damage, 30, 5);
    }
    else
    { // cover all the situations including some incorrect input
        std::cout << "Unknown error, control the input values." << std::endl;
    }
}

void Arena::spawnTerrain()
{ // firstly, determine the current terrain.
    if (m_toNewTerrain == 0 || this->m_terrain == "none")
    {                             // if it is time for the change or the current terrain is 'none', then choose a new random terrain
        int random = rand() % 10; // get a random value to calculate new terrain with given possibilities
        if (random < 2)
        { // 20% change for pyschic and it will stand for 5 rounds
            this->m_terrain = "pyschic";
            this->m_toNewTerrain = 4;
        }
        else if (random < 4)
        { // 20% change for electric and it will stand for 5 rounds
            this->m_terrain = "electric";
            this->m_toNewTerrain = 4;
        }
        else
        {
            this->m_terrain = "none"; // 60% change for none and it will stand for just one round
            this->m_toNewTerrain = 0;
        }
    }
    else
    { // else, just decrease the remaning round and continue to battle
        this->m_toNewTerrain--;
    }
}

void Arena::restartTerrain()
{
    // new random terrain is chhosen at the beginning of every battle
    int random = rand() % 10;
    if (random < 2)
    { // 20% change for electric and it will stand for 5 rounds
        this->m_terrain = "electric";
        this->m_toNewTerrain = 4;
    }
    else if (random < 4)
    { // 20% change for pyschic and it will stand for 5 rounds
        this->m_terrain = "pyschic";
        this->m_toNewTerrain = 4;
    }
    else
    {
        this->m_terrain = "none"; // 60% change for none and it will stand for just one round
        this->m_toNewTerrain = 0;
    }
}

void Arena::printRoundStates(const int round, const int head)
{ // print the required informations first
    std::cout << "Round: " << round << std::endl;
    std::cout << "Current Terrain: " << this->m_terrain << std::endl;
    std::string firstHit = (head == 0) ? this->m_electricPokemon->getName() : this->m_pyschicPokemon->getName(); // determine which pokemon hits first
    std::cout << firstHit << " goes first." << std::endl;

    // print which pokemon hits first according to if it is powered up or not, then print the second one
    if (head == 0)
    {
        if (this->m_electricPokemon->getPowerUpState())
        {
            std::cout << this->m_electricPokemon->getName() << " has initiated a power up." << std::endl;
        }
        if (this->m_pyschicPokemon->getPowerUpState())
        {
            std::cout << this->m_pyschicPokemon->getName() << " has initiated a power up." << std::endl;
        }
    }
    else
    {
        if (this->m_pyschicPokemon->getPowerUpState())
        {
            std::cout << this->m_pyschicPokemon->getName() << " has initiated a power up." << std::endl;
        }
        if (this->m_electricPokemon->getPowerUpState())
        {
            std::cout << this->m_electricPokemon->getName() << " has initiated a power up." << std::endl;
        }
    }

    std::cout << this->m_electricPokemon->getName() << " HP:" << this->m_electricPokemon->getHP() << std::endl;
    std::cout << this->m_pyschicPokemon->getName() << " HP:" << this->m_pyschicPokemon->getHP() << std::endl;
    std::string leadPokemon = (this->m_electricPokemon->getHP() > this->m_pyschicPokemon->getHP()) ? this->m_electricPokemon->getName() : this->m_pyschicPokemon->getName(); // determine which pokemon is in the lead
    std::cout << leadPokemon << " is in the lead!" << std::endl
              << std::endl
              << std::endl;
}

void Arena::printMatchResults()
{ // this method prints the match's result
    std::cout << "Match Results:" << std::endl;
    std::string winner = this->m_pyschicPokemon->getHP() <= 0 ? this->m_electricPokemon->getName() : this->m_pyschicPokemon->getName();
    std::cout << winner << " has won the match!" << std::endl
              << std::endl
              << std::endl;
}