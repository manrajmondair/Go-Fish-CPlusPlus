// Manraj Mondair - Go Fish Card Game (Object-Oriented Programming)
// 12/09/2022
// This is the game header file

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#ifndef GAME_HPP
#define GAME_HPP

class Game 
{
  private:
    Deck cards;
    Player players[2];
    bool isGameOver;

  public:
    Game();
    string intToRank(int rank);

    void gameOver();
    void displayGame();

    int checkInput(string question, string valid);
    int checkAndChoose();
    int checkAndRand();

    void compHasMatch(int rankChosen);
    void humHasMatch(int rankChosen);
    void humFish(int rankChosen, bool &myTurn);
    void compFish(int rankChosen, bool &compTurn);
    void humanTurn();
    void compTurn();
    void beginTurns();
};
#endif