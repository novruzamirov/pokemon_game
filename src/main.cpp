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
#include <fstream>

#include "pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;           //Use this to keep track of the enemy names
int POK_COUNTER = 0;            //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---//
//
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string *readEnemyNames(const char *);
string *readPokemonNames(const char *);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player *, string *, string *);
void catchPokemon(player *, string *);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---//
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char *argv[])
{
    system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string *enemyNames = readEnemyNames(argv[1]);
    string *pokemonNames = readPokemonNames(argv[2]);

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n"
         << endl;
    cout << "Please enter your name: ";
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);

    int menuChoice;

    while (true)
    {
        mainMenu();
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout << newPlayer.showPokemonNumber() << endl;
            break;
        case 4:
            cout << newPlayer.showPokeballNumber() << endl;
            break;
        case 5:
            cout << newPlayer.showBadgeNumber() << endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" << endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;

        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string *readEnemyNames(const char *argv)
{ // to read enemyNames.txt file and create dynamic string array for enemy names
    //---Code Here---//
    fstream enemyFile;
    enemyFile.open(argv, ios::in);
    if (enemyFile.is_open())
    {
        int number;
        string word;
        enemyFile >> number;
        string *enemyArray = new string[number];

        for (int i = 0; i < number; i++)
        {
            enemyFile >> word;
            enemyArray[i] = word;
        }

        enemyFile.close();
        return enemyArray;
    }
    else
    {
        cout << "File can not be opened" << endl;
        return 0;
    }

    //---------------//
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string *readPokemonNames(const char *argv)
{
    //---Code Here---//

    fstream pokemonFile;
    pokemonFile.open(argv, ios::in);
    if (pokemonFile.is_open())
    {
        int number;
        string word;
        pokemonFile >> number;
        string *pokemonArray = new string[number];

        for (int i = 0; i < number; i++)
        {
            pokemonFile >> word;
            pokemonArray[i] = word;
        }

        pokemonFile.close();
        return pokemonArray;
    }
    else
    {
        cout << "File can not be opened" << endl;
        return 0;
    }

    //---------------//
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice)
{
    //---Code Here---//

    if (pokemonChoice == 1)
    {
        pokemon newPokemon = pokemon("Bulbasaur", 20);
        player newPlayer = player(playerName, &newPokemon);
        return newPlayer;
    }
    else if (pokemonChoice == 2)
    {
        pokemon newPokemon = pokemon("Charmender", 20);
        player newPlayer = player(playerName, &newPokemon);
        return newPlayer;
    }
    else
    {
        pokemon newPokemon = pokemon("Squirtle", 20);
        player newPlayer = player(playerName, &newPokemon);
        return newPlayer;
    }

    //---------------//
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu()
{
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player *newPlayer, string *enemyNames, string *pokemonNames)
{
    //---Code Here---//
    pokemon enemyPokemon = pokemon(pokemonNames[POK_COUNTER], ENEMY_POKEMON_ATTACK); // to create a Pokemon and an enemy
    enemy enemyUser = enemy(enemyNames[NAME_COUNTER], &enemyPokemon);
    newPlayer->playerPokedex.updatePokedex(&enemyPokemon); //  update the pokedex
    cout << "You encounter with " << enemyUser.getName() << " and his/hers pokemon " << enemyUser.getPokemon()->getName() << endl;
    cout << enemyPokemon.getName() << " Health: " << enemyPokemon.getHp() << " Attack: " << enemyUser.getPokemon()->getAtk() << endl;
    POK_COUNTER++; // increasing pok counter for next fight and catch es.
    NAME_COUNTER++;
    int choice;

    while (newPlayer->getPokemon()->getHp() > 0 && enemyUser.getPokemon()->getHp() > 0)
    {
        cout << "1- Fight" << endl;
        cout << "2- Runaway" << endl;
        cout << "Choice: ";
        cin >> choice;
        if (choice == 1)
        {

            enemyUser.getPokemon()->setHp(PLAYER_POKEMON_ATTACK);
            newPlayer->getPokemon()->setHp(ENEMY_POKEMON_ATTACK);

            cout << "Your Pokemons Health: " << newPlayer->getPokemon()->getHp() << endl;
            cout << enemyUser.getName() << " Pokemons Health: " << enemyUser.getPokemon()->getHp() << endl;

            if (enemyUser.getPokemon()->getHp() <= 0)
            {
                cout << "You Won!" << endl;
                newPlayer->getPokemon()->setHp(newPlayer->getPokemon()->getHp() - 100);
                enemyUser.getPokemon()->setHp(enemyUser.getPokemon()->getHp() - 100);
                newPlayer->battleWon();
                return;
            }
            else if (newPlayer->getPokemon()->getHp() <= 0)
            {
                cout << "You Lost!" << endl;
                newPlayer->getPokemon()->setHp(newPlayer->getPokemon()->getHp() - 100);
                enemyUser.getPokemon()->setHp(enemyUser.getPokemon()->getHp() - 100);
                return;
            }
        }

        else if (choice == 2)
        {
            cout << "You Lost!" << endl;
            return;
        }
    }

    //---------------//
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player *newPlayer, string *pokemonNames)
{
    //---Code Here---//
    pokemon newPokemon = pokemon(pokemonNames[POK_COUNTER], 10);
    POK_COUNTER++;

    cout << "You encounter with " << newPokemon.getName() << " Health: " << newPokemon.getHp() << " Attack: " << newPokemon.getAtk() << endl;

    newPlayer->playerPokedex.updatePokedex(&newPokemon);

    int choice;
    cout << "1- Catch" << endl;
    cout << "2- Runaway" << endl;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "You catch " << newPokemon.getName() << endl;
        newPlayer->catchPokemon();
    }
    else if (choice == 2)
    {
        cout << "You run away" << endl;
    }

    //---------------//
};
//--------------------------------------------//
