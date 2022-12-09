// Manraj Mondair - Go Fish Card Game (Object-Oriented Programming)
// 12/09/2022
// This is the player header file

#include "card.hpp"
#include "hand.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player 
{
  private:
    Hand hand;
    int* books;
    int numBooks;

  public:
    Player();
    ~Player();

    Hand& getHand();
    int* getBooks();
    int getNumBooks();

    void setNumBooks(int add);
    Card randCard();
    void removeBook(int rankChosen);
};

#endif