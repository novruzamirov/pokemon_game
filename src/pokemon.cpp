//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Novruz Amirov
//---Student Number: 150200903
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//

// for pokemon class we have 6 methods:
pokemon::pokemon()
{ // default constructor
	name = "";
	hpValue = 0;
	atkValue = 0;
}

pokemon::pokemon(string name, int atkValue)
{
	this->name = name;
	this->atkValue = atkValue;
	this->hpValue = 100;
}

pokemon::pokemon(const pokemon &pokemonIn)
{
	name = pokemonIn.name;
	hpValue = pokemonIn.hpValue;
	atkValue = pokemonIn.atkValue;
}

string pokemon::getName() const
{
	return name;
}

int pokemon::getHp() const
{
	return hpValue;
}

int pokemon::getAtk() const
{
	return atkValue;
}

// for pokedex class we have 4 methods:
pokedex::pokedex()
{
	value = 0;
}

void pokedex::printPokedex() const
{
	for (int i = 0; i < value; i++)
	{
		cout << pokedexArray[i].getName() << " " << endl;
	}
	cout << endl;
}

void pokedex::updatePokedex(pokemon *newPokemon)
{
	int duplicate = 0;
	for (int i = 0; i < value; i++)
	{
		if (pokedexArray[i].getName() == newPokemon->getName())
		{
			duplicate = 1;
			break;
		}
	}

	if (!duplicate)
	{
		pokedexArray[value] = *newPokemon;
		value++;
	}
}

// for player class we have 8 methods:
player::player()
{
	name = "";
	pokemonNumber = 0;
	pokeballNumber = 10;
	badgeNumber = 0;
	playerPokemon = pokemon();
	playerPokedex = pokedex();
}

player::player(string name, pokemon *poke)
{
	this->name = name;
	this->playerPokemon = *poke;
	this->pokeballNumber = 10;
}

int player::showPokemonNumber() const
{
	return pokemonNumber;
}

int player::showPokeballNumber() const
{
	return pokeballNumber;
}

int player::showBadgeNumber() const
{
	return badgeNumber;
}

pokemon *player::getPokemon()
{
	pokemon *b = &playerPokemon;
	return b;
}

void player::battleWon()
{
	this->badgeNumber += 1;
	this->pokeballNumber += 3;
}

void player::catchPokemon()
{
	this->pokemonNumber += 1;
	this->pokeballNumber -= 1;
}

// for enemy class we have 4 methods
enemy::enemy()
{
	name = "";
	enemyPokemon = pokemon();
}

enemy::enemy(string name, pokemon *poke)
{
	this->name = name;
	this->enemyPokemon = *poke;
}

pokemon *enemy::getPokemon()
{
	pokemon *b = &enemyPokemon;
	return b;
}

string enemy::getName() const
{
	return name;
}
