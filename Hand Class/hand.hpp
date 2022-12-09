// Manraj Mondair - Go Fish Card Game (Object-Oriented Programming)
// 12/09/2022
// This is the hand header file

#include "card.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#ifndef HAND_HPP
#define HAND_HPP

class Hand 
{
  private:
    Card* cards;
    int numCards;

  public:
    Hand();
    ~Hand();

    Card* getCards();
    int getNumCards();

    void addCard(Card card);
    bool hasRank(int rank);

    Card removeCard(int rank);

    bool checkBook(int rank);
    void printHand();

  friend bool operator< (Card const &c1, Card const &c2);
};
#endif