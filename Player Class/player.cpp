// Manraj Mondair - Go Fish Card Game (Object-Oriented Programming)
// 12/09/2022
// This is the player implementation file

#include "player.hpp"

Player::Player() //This is a default constructor that creates an array to set the "numBooks" variable to 0
{
  books = new int[13];
  numBooks = 0;
}

Player::~Player() //This is a simple destructor that deletes the array that was created previously
{
  delete[] books;
}

Hand& Player::getHand() //This function retrieves the player's current hand
{
  return hand;
}

int* Player::getBooks() //This function retrieves the player's current books
{
  return books;
}

int Player::getNumBooks() //This function retrieves the player's "numBooks" variable
{
  return numBooks;
}

Card Player::randCard() //This funcntion is the core of the functionality of the game as it is used for the computer to request a card in the user's hand by randomly selecting out of the player's hand (because it is the computer)
{
  srand(time(NULL));
  int randInd = rand() % hand.getNumCards();
  Card randCard = hand.getCards()[randInd];
  return randCard;
}

void Player::removeBook(int rankChosen) //This function removes the rank of every card to add it to the array of books
{
  books[numBooks] = rankChosen;
  numBooks = numBooks + 1;

  while(hand.hasRank(rankChosen))
  {
    hand.removeCard(rankChosen);
  }
}