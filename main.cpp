// Manraj Mondair - Go Fish Card Game (Object-Oriented Programming)
// 12/09/2022
// This is the main file

#include "game.hpp"

int main() //This function/file is used to initiate the game of Go Fish between the user and a automated computer
{
  int again = 1;

  while(again == 1)
  {
    Game game;
    game.beginTurns();
    again = game.checkInput("Good game, hope you had fun! Please enter 1 to play again or 2 to quit: ", "12");
  }
}