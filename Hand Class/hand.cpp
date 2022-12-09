// Manraj Mondair - Go Fish Card Game (Object-Oriented Programming)
// 12/09/2022
// This is the hand implementation file

#include "hand.hpp"

bool operator< (Card const &c1, Card const &c2) //This function is used for sorting by comparing two cards by their rank
{
  return (c1.getRank() < c2.getRank());
}

Hand::Hand() //This default constructor is used to initialize the "numCards" variable to 0 and initialize the dynamic array of cards
{
  numCards = 0;
  cards = new Card[52];
}

Hand::~Hand() //This destructor deletes the array of cards that was created previously
{
  delete[] cards;
}

Card* Hand::getCards() //This function retrieves the hand's current cards
{
  return cards;
}

int Hand::getNumCards() //This function retrieves the hand's variable of "numCards" that is for the number of cards that are present
{
  return numCards;
}

void Hand::addCard(Card card) //This function moves the card from the deck (the array of cards) and then sorts the deck again
{
  cards[numCards] = card;
  this->numCards++;
  sort(cards, cards + numCards);
}

bool Hand::hasRank(int rank) //This function checks if the card is present in the array of cards
{
  for(int i = 0; i < numCards; i++)
  {
    if(cards[i].getRank() == rank)
    {
      return true;
    }
  }

  return false;
}

Card Hand::removeCard(int rank) //This function removes a card that is pulled (based on rank) from the cards
{
  Card removed;
  int cardPos = -1;

  for(int i = 0; i < numCards; i++)
  {
    if(cards[i].getRank() == rank)
    {
      cardPos = i;
    }
  }

  removed = cards[cardPos];
  cards[cardPos].setRank(69);
  cards[cardPos].setSuit(69);
  sort(cards, cards + numCards);
  this->numCards = this->numCards - 1;
  return removed;
}

bool Hand::checkBook(int rank) //This function checks if there is a full book of a rank in a hand
{
  int count = 0;

  for(int i = 0; i < numCards; i++)
  {
    if(cards[i].getRank() == rank)
    {
      count++;
    }
  }

  if(count > 3)
  {
    return true;
  }

  return false;
}

void Hand::printHand() //This final function outputs the suit and the rank of the cards that are in the hand
{
  for(int i = 0; i < numCards; i++)
  {
    cout << "Rank: " << cards[i].getRank() << " " << "Suit: " << cards[i].getSuit() << endl;
  }
}