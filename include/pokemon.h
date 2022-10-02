//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Novruz Amirov
//---Student Number: 150200903
//--------------------------//

#ifndef _H
#define _H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//-------------Do Not Add Any New Class(es)-------------//

class pokemon
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
private:
    string name;
    int hpValue;
    int atkValue;

public:
    pokemon();                // default constructor which will initialize all values.
    pokemon(string, int);     // string for name, integer for attack value, and to set default Pokemon hp to 100.
    pokemon(const pokemon &); // copy constructor, taking Pokemon class object and copy its contents.
    //getters:
    string getName() const;
    int getHp() const;
    int getAtk() const;

    void setHp(int number)
    { // inline setter function
        hpValue -= number;
    }
    // if another methods for this class, implement them as an inline function.
};

class pokedex
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
private:
    pokemon pokedexArray[100];
    int value; //keeps track of the position
public:
    pokedex();                     // constructor to initialize value attribute as 0
    void updatePokedex(pokemon *); // to add new pokemons to the pokedexArray, only new ones will be added, check for duplicated ones.
    void printPokedex() const;     // to print Pokemon names from pokedexArray
};

class player
{
private:
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    string name;
    int pokemonNumber;
    int pokeballNumber;
    int badgeNumber;
    pokemon playerPokemon;

public:
    pokedex playerPokedex;
    //methods:
    player();                      // default constructor to initialize all values.
    player(string, pokemon *);     // to construct a new player with a given name and Pokemon
    int showPokemonNumber() const; // method to return pokemonNumber like getters
    int showPokeballNumber() const;
    int showBadgeNumber() const;
    pokemon *getPokemon();
    void battleWon();    // everytime you win, badgeNumber += 1, pokeballNumber += 3
    void catchPokemon(); // to update pokemonNumber += 1 and pokeballNumber -= 1,
};

class enemy
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
private:
    string name;
    pokemon enemyPokemon;

public:
    enemy();                  // default constructor to initialize all values
    enemy(string, pokemon *); // constructor with arguments, will construct a new enemy with a given name and pokemon
    pokemon *getPokemon();    // to return enemyPokemon object
    string getName() const;   // to return the name of enemy
};

#endif
