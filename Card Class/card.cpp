// Manraj Mondair - Go Fish Card Game (Object-Oriented Programming)
// 12/09/2022
// This is the card implementation file

#include "card.hpp"

Card::Card() //This is a default constructor that sets both the rank and the suit private variables initially to 0 to initialize
{
  rank = 0;
  suit = 0;
}

int Card::getRank() const //This function retrieves the card's rank after it has been initialized so that it can be accessible
{
  return rank;
}

int Card::getSuit() const //This function retrieves the card's suit after it has been initialized so that it can be accessible
{
  return suit;
}

void Card::setRank(int r) //This function sets the sets the card's rank and it is re-assigned to the value of r
{
  rank = r;
}

void Card::setSuit(int s) //This function sets the sets the card's suit and it is re-assigned to the value of s
{
  suit = s;
}

void Card::printCard() //This final function prints out the card's rank and suit
{
  cout << "Rank: " << rank << endl;
  cout << "Suit: " << suit << endl;
}