// Manraj Mondair - Go Fish Card Game (Object-Oriented Programming)
// 12/09/2022
// This is the game implementation file

#include "game.hpp"

Game::Game() //This is a default constructor that sets the private variable "isGameOver" to false to begin the game
{
  isGameOver = false;
}

string Game::intToRank(int rank) //This function converts the integer of the rank to a string and returns it to the player for the functionality of the game
{
  string ranks [13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
  return ranks[rank];
}

void Game::gameOver() //This function updates the variable that was initialized previously based on the status of the game and whether the game is complete or not by referencing the cards
{
  if(players[0].getNumBooks() + players[1].getNumBooks() > 12)
  {
    isGameOver = true;
  } 
  else 
  {
    isGameOver = false;
  }
}

void Game::displayGame() //This function provides a display for the user to get an update of the status of the game and if they are winning or not based on the comparison of cards
{
  cout << endl << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "\tComputer" << endl;
  cout << "Books: ";

  for(int i = 0; i < players[0].getNumBooks(); i++)
  {
    cout << "[" << intToRank(players[0].getBooks()[i]) << "]";
  }
  
  cout << endl << "Hand: "; //Provides the user with the status of the computer's hand
  int numCardsP1 = players[0].getHand().getNumCards();

  for(int i = 0; i < numCardsP1; i++)
  {
    cout << "[] ";
  }

  cout << endl << endl << "\t[Deck]";
  cout << endl << endl << "\tYou" << endl;
  cout << "Books: ";

  for(int i = 0; i < players[1].getNumBooks(); i++)
  {
    cout << "[" << intToRank(players[1].getBooks()[i]) << "]";
  }

  cout << endl << "Hand: "; //Provides the user with the status of their hand
  int numCardsP2 = players[1].getHand().getNumCards();

  for(int i = 0; i < numCardsP2; i++)
  {
    cout << "[" << intToRank(players[1].getHand().getCards()[i].getRank()) << "] ";
  }

  cout << endl << "     ";

  for(int i = 0; i < numCardsP2; i++)
  {
    if(intToRank(players[1].getHand().getCards()[i].getRank()) == "10")
    {
      cout << "   " << i << " ";
    } 
    
    else 
    {
      if(i > 9)
      {
        cout << " " << i << " ";
      }

      else 
      {
          cout << "  " << i << " ";
      }
    }
  }
}

int Game::checkInput(string question, string valid) //This function implements a do-while statement to test valid characters
{
   string var_str;
   size_t found;

   do
   {
      cout << question << endl;
      cin >> var_str;
      found = var_str.find_first_not_of(valid);
   }

   while(found != string::npos && var_str.length() < 3);

   return stoi(var_str);
}

int Game::checkAndChoose() //This function is used to guide the player when it is their turn to request a card
{
  if(players[1].getHand().getNumCards() < 1 && !isGameOver)
  {
    cout << "You go draw a card!";
    players[1].getHand().addCard(cards.deal());
    displayGame();
  }

  int index = -1;
  index = checkInput("Please enter the value of the card that you want to choose: ", "0123456789");
  int rankChosen = players[1].getHand().getCards()[index].getRank();
  cout << "You are asking for a: " << intToRank(rankChosen) << endl;

  if(players[0].getHand().getNumCards() < 1)
  {
    cout << "You go draw a card!";
    players[1].getHand().addCard(cards.deal());
    displayGame();
  }
  return rankChosen;
}

int Game::checkAndRand() //This function provides the computer with a random card that it requests
{
  if(players[0].getHand().getNumCards() < 1 && !isGameOver)
  {
    cout << "I am drawing a card.";
    players[0].getHand().addCard(cards.deal());
    displayGame();
  }

  srand(time(NULL));
  int randInd = rand() % players[0].getHand().getNumCards();
  int rankChosen = players[0].getHand().getCards()[randInd].getRank();
  cout << "Do you have a: " << intToRank(rankChosen) << endl;

  if(players[1].getHand().getNumCards() < 1)
  {
    cout << "I am going to draw a card.";
    players[0].getHand().addCard(cards.deal());
    displayGame();
  }

  return rankChosen;
}

void Game::compHasMatch(int rankChosen) //This function checks the computer's current hand for a card based on rank to give to the player
{
  int count = 0;

  while(players[0].getHand().hasRank(rankChosen))
  {
    Card removed = players[0].getHand().removeCard(rankChosen);
    players[1].getHand().addCard(removed);
    count++;
  }

  if(count > 0)
  {
    cout << "I am giving you " << count << ": " << intToRank(rankChosen) << endl;
  }

  displayGame();

  if(players[1].getHand().checkBook(rankChosen))
  {
    cout << "You got a book!" << endl;
    players[1].removeBook(rankChosen);
    displayGame();
  }
}

void Game::humHasMatch(int rankChosen) //This function checks the user's current hand for a card based on rank to give to the computer
{
  int count = 0;

  while(players[1].getHand().hasRank(rankChosen))
  {
    Card removed = players[1].getHand().removeCard(rankChosen);
    players[0].getHand().addCard(removed);
    count++;
  }

  if(count > 0)
  {
    cout << "You are giving the Computer " << count << ": " << intToRank(rankChosen) << endl;
  }

  displayGame();

  if(players[0].getHand().checkBook(rankChosen))
  {
    cout << "I got a book!" << endl;
    players[0].removeBook(rankChosen);
  }
}

void Game::humFish(int rankChosen, bool &myTurn) //This function guides the user to fish for a card from the computer when it is their turn
{
  cout << "Go Fish for a card!" << endl;
  Card cardDealt = cards.deal();
  int rankDealt = cardDealt.getRank();
  cout << "You draw a: " << intToRank(rankDealt) << endl;
  players[1].getHand().addCard(cardDealt);

  if(rankDealt == rankChosen)
  {
    cout << "You fished for what you wanted!" << endl;

    if(players[1].getHand().checkBook(rankChosen))
    {
      cout << "You got a book!" << endl;
      players[1].removeBook(rankChosen);
    }

    displayGame();
  } 
  
  else 
  {
    cout << endl;

    if(players[1].getHand().checkBook(rankDealt))
    {
      cout << "You got a book!" << endl;
      players[1].removeBook(rankDealt);
      displayGame();
    }

    cout << "\tCOMPUTER'S TURN!\t" << endl;
    myTurn = !myTurn;
  }
}

void Game::compFish(int rankChosen, bool &compTurn) //This function is used to guide the user as to what the computer is doing every step of the way
{
  cout << "I am going to Go Fish!" << endl;
  Card cardDealt = cards.deal();
  int rankDealt = cardDealt.getRank();
  players[0].getHand().addCard(cardDealt);

  if(rankDealt == rankChosen)
  {
    cout << "I got what I wanted!" << endl;

    if(players[0].getHand().checkBook(rankChosen))
    {
      cout << "I got a book!" << endl;
      players[0].removeBook(rankChosen);
    }
  } 
  
  else 
  {
    cout << endl;

    if(players[0].getHand().checkBook(rankDealt))
    {
      cout << "Computer got a book!" << endl;
      players[0].removeBook(rankDealt);
    }

    cout << "\tYOUR TURN!\t" << endl;
    compTurn = !compTurn;
  }
}

void Game::humanTurn() //This function is used for the functionality of the user in the game to play the game
{
  displayGame();
  bool myTurn = true;

  while(!isGameOver && myTurn)
  {
    int rankChosen = checkAndChoose();

    if(players[0].getHand().hasRank(rankChosen))
    {
      compHasMatch(rankChosen);
    } 

    else 
    {
      humFish(rankChosen, myTurn);
    }

    gameOver();
  }
}

void Game::compTurn() //This function is used for the functionality of the computer in the game to play the game
{
  displayGame();
  bool compTurn = true;

  while(!isGameOver && compTurn)
  {
    int rankChosen = checkAndRand();

    if(players[1].getHand().hasRank(rankChosen))
    {
      humHasMatch(rankChosen);
    } 

    else 
    {
      compFish(rankChosen, compTurn);
    }

    gameOver();
  }
}

void Game::beginTurns() //This function is crucial for the entire functionality, It consistently shuffles the deck, gives out the starting cards, and continues in a loop until someone wins
{
  cards.shuffleDeck();

  for(int i = 0; i < 7; i++)
  {
    players[0].getHand().addCard(cards.deal());
  }

  for(int i = 0; i < 7; i++)
  {
    players[1].getHand().addCard(cards.deal());
  }

  while(!isGameOver) //The start of the back and forth requesting of cards
  {
    humanTurn();
    compTurn();
  }

  cout << "GAME OVER" << endl;
  displayGame();

  if(players[0].getNumBooks() > players[1].getNumBooks())
  {
    cout << "I win ha ha! Better luck nextime!" << endl;
  } 

  else 
  {
    cout << "Congratulations! You have successfully beaten the master at Go Fish :(!" << endl;
  }
}