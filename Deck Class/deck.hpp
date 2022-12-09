// Manraj Mondair - Go Fish Card Game (Object-Oriented Programming)
// 12/09/2022
// This is the deck header file

#include "card.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#ifndef DECK_HPP
#define DECK_HPP

class Deck 
{
  private:
    Card* cards;
    int numCards;  //This variable is used to iterate the cards that are left in the deck

  public:
    Deck();
    ~Deck();

    Card* getCards();
    void shuffleDeck(); //This function is used to shuffle the cards in the deck
    Card deal(); //This function is used to deal out a card to the player while removing one card from the deck
    void printDeck();
};

#endif