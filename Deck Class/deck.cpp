// Manraj Mondair - Go Fish Card Game (Object-Oriented Programming)
// 12/09/2022
// This is the deck implementation file

#include "deck.hpp"

Deck::Deck() //This is a default constructor that dynamically initializes the array of cards to set their suit and rank to create the entire deck
{
  cards = new Card[52];
  numCards = 52;
  int count = 0;

  for(int r = 0; r < 13; r++)
  {
    for(int s = 0; s < 4; s++)
    {
      cards[count].setRank(r);
      cards[count].setSuit(s);
      count++;
    }
  }
}

Deck::~Deck() //This is a simple destructor that deletes the dynamic array of cards that were previously created
{
  delete[] cards;
}

Card* Deck::getCards() //This function gets the deck's cards to make them accessible
{
  return cards;
}

void Deck::shuffleDeck() //This deck is used to shuffle the deck of cards by switching two cards that are randomly selected for a certain amount of iterations
{
  srand(time(NULL));
  
  for(int i = 0; i < 1000; i++)
  {
    int card1 = rand() % 52;
    int card2 = rand() % 52;

    Card temp = cards[card1];
    cards[card1] = cards[card2];
    cards[card2] = temp;
  }
}

Card Deck::deal() //This function deals out a card to the player from the deck by removing one card from the deck
{
  Card draw = cards[numCards-1]; //Removes the card
  numCards--;
  return draw; //Returns the card that was drawn
}

void Deck::printDeck() //This final function outputs the suit and rank of the cards in the deck
{
  for(int i = 0; i < numCards; i++)
  {
    cout << "Rank: " << cards[i].getRank() << " ";
    cout << "Suit: " << cards[i].getSuit() << endl;
  }
}