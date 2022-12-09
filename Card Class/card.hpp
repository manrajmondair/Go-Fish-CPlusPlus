// Manraj Mondair - Go Fish Card Game (Object-Oriented Programming)
// 12/09/2022
// This is the card header file

#include <iostream>
using namespace std;
#ifndef CARD_HPP
#define CARD_HPP

class Card 
{
  private:
    int rank;
    int suit;

  public:
    Card();

    int getRank() const;
    int getSuit() const;

    void setRank(int r);
    void setSuit(int s);
    void printCard();
};

#endif