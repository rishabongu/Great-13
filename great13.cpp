
/**------------------------------------------
    Program 2: Great 13

    Course: CS 141, Fall 2022.
    System: Linux x86_64 and G++
    Author: George Maratos and David Hayes
    Name: Risha Bongu, Starter code provided by George Maratos and David Hayes
 ---------------------------------------------**/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <map>
#include <string>


using namespace std;
// global variable
string userCombos = "";
bool rightMove = false;
bool checkGameOver = false;
char start;
char middle; 
char destination; 
char position1;
char position2;
char position3;


// Function that displays the instructions to the user

void display_instructions()
{
    cout << "Class: CS 141" << endl
         << "Program 2: Great 13" << endl << endl
         << "Make a series of jumps until there is a single piece left" << endl
         << "anywhere on board. On each move you must jump an adjacent" << endl
         << "piece   into   an  empty  square,  jumping  horizontally," << endl
         << "vertically, or diagonally." << endl << endl
         << "Input of 'R' resets the board back to the beginning, and " << endl
         << "'X' exits the game." << endl;
}

// The internal representation of the board as an array. 
char board[13]{};

// These two functions are how you will get and set elements on the board.

char get_element(char position)
{
    if ((position < 'A') || (position > 'M')) {
        cout << "Failed to get element at position " << position << endl
             << "Make sure the given position is an uppercase letter " << endl
             << "between A-M." << endl;
        exit(1);
    }
    return board[position - 'A'];
}

void set_element(char position, char value)
{
    if ((position < 'A') || (position > 'M')) {
        cout << "Failed to set element at postion " << position << endl
             << "Make sure the given position is an uppercase letter " << endl
             << "between A-M." << endl;
        exit(1);
    }
    board[position - 'A'] = value;
}

// prints out the board with the legend on the right

void display_board()
{
    cout << endl;
    cout << setw(7) << "Board" << setw(12) << "Position" << endl;
    cout << setw(5) << board[0] << setw(11) << 'A' << endl
         << setw(3) << board[1] << ' ' << board[2] << ' ' << board[3]
         << setw(11) << "B C D" << endl
         << board[4] << ' ' << board[5] << ' ' << board[6] << ' '
         << board[7] << ' ' << board[8] << ' '
         << " E F G H I" << endl
         << setw(3) << board[9] << ' ' << board[10] << ' ' << board[11]
         << setw(11) << "J K L" << endl
         << setw(5) << board[12] << setw(11) << 'M' << endl;
    cout << endl;
}

void make_move();
void initialize_board();
bool game_over();

// Calling functions 
int main()
{
    display_instructions();
    initialize_board();
  do {
    
     display_board();
     make_move();

    
    
    } while (game_over() && !cin.eof());

  // user input variable 
  string userInput;
  
  
    return 0;
}
// valid moves 
  string move1 = "ABE";
  string move2 = "ACG";
  string move3 = "ADI";
  string move4 = "BFJ";
  string move5 = "BGL";
  string move6 = "BCD";
  string move7 = "CGK";
  string move8 = "DGJ";
  string move9 = "DHL";
  string move10 = "DCB";
  string move11 = "EBA";
  string move12 = "EFG";
  string move13 = "EJM";
  string move14 = "FGH";
  string move15 = "GCA";
  string move16 = "GFE";
  string move17 = "IDA";
  string move18 = "IHG";
  string move19 = "ILM";
  string move20 = "JFB";
  string move21 = "JGD";
  string move22 = "JKL";
  string move23 = "KGC";
  string move24 = "LKJ";
  string move25 = "LGB";
  string move26 = "LHD";
  string move27 = "MLI";
  string move28 = "MKG";
  string move29 = "MJE";
  string move30 = "GKM";
  string move31 = "GHI";
  string move32 = "HGF";
  
// This is function is checking the valid moves and if not a valid move it will print out saying it is not a valid move.
bool checkMoves(string userInput) {
  if(userInput == move1 ||userInput == move2 ||userInput == move3 ||userInput == move4 ||userInput == move5 ||userInput == move6 ||userInput == move7 ||userInput == move8 ||userInput == move9 ||userInput == move10 ||userInput == move11 ||userInput == move12 ||userInput == move13 ||userInput == move14 ||userInput == move15 ||userInput == move16 ||userInput == move17 ||userInput == move18 ||userInput == move19 ||userInput == move20 ||userInput == move21 ||userInput == move22 ||userInput == move23 ||userInput == move24 ||userInput == move25 ||userInput == move26 ||userInput == move27 ||userInput == move28 ||userInput == move29 ||userInput == move30 ||userInput == move31 ||userInput == move32){
      rightMove = true;
      
      return true;
    }
  else  {
    rightMove = false;
    return false;
    cout<< "*** Move is invalid.";
    cout<<endl;
    
  }
}
// This function goes through position and checks to see any letter that is not A-M
bool checkPosition(string userInput){
  int count = 0;
  bool valid = false; 
  for(int i = 0; i < userCombos.length(); ++i){
    if (userCombos.at(i) < 'N'){
      count++;
    }
  }
// returns valid if count is 3
if(count == 3){
  valid = true;
}
  return valid;
}





void make_move(){
    // gets input from user 
    cout<< "Enter positions from, jump, and to (e.g. EFG): ";
    cin >> userCombos;
  // goes through the input length of the user input
    for (int i = 0;i < userCombos.length(); i++){
      userCombos.at(i) = toupper(userCombos.at(i));
    }
  // if user enters 'r', game restarts displaying the original board 
    if(userCombos == "R"){
      cout << "Restarting game.";
      initialize_board();
      
    }
  // exits the game if user enters 'X'
    else if(userCombos == "X"){
      cout << "Exiting.";
      exit(0);
    }
    // if user input character length is not 3 then the following prints 
    else if (userCombos.length()!=3){
      cout << "*** Invalid sequence. Please retry.";
      cout << endl;
      
    }
    // if user input character length is 3 and is not checking the positions then the following prints 
    else if ((userCombos.length() == 3)&& (!checkPosition(userCombos))){
      cout<< "*** Given move has positions not on the board! Please retry.";
    }
    // if user input is not a valid move, the following prints
    else if(!checkMoves(userCombos)){
      cout << "*** Move is invalid." << endl;
    }
  

  else
    {
  // variables for # and .
  char hashtag = '#';
  char period = '.';
  // assigns index positions for the variables 
  start = toupper(userCombos.at(0));
  middle = toupper(userCombos.at(1));
  destination = toupper(userCombos.at(2));


  // checks if moves are valid, but have some error messages 
  if(checkMoves(userCombos)){
    
  // When the user enters a command that would jump the peg into a position, that is already occupied, then print the following message.
  if (get_element(start) == hashtag && get_element(middle) == hashtag && get_element(destination) == hashtag)  {
    cout << "*** Destination must be empty. Please retry.";
    cout << endl;
  }

    // When the command has a peg jump over an empty space, print the following message.
  if (get_element(start) == hashtag && get_element(middle) == period && get_element(destination) == hashtag)  {
    cout << "*** Must jump a piece. Please retry.";
    cout << endl;
  }

    // When the command uses an empty space as the jumping peg, print the following message. 
  if (get_element(start) == period && get_element(middle) == hashtag && get_element(destination) == hashtag)  {
    cout << "*** Source needs a piece. Please retry.";
    cout << endl;
    }

  // sets the index positions to hashtag or period when user makes the move
  if (get_element(start) == hashtag && get_element(middle) == hashtag && get_element(destination) == period)  {
      set_element(userCombos.at(0), period);
      set_element(userCombos.at(1), period);
      set_element(userCombos.at(2), hashtag);
      }

  
  }
    }
  
  }
  
  
// When there is 12 pegs left on the board, then the following message prints declaring winning of the game 
bool game_over(){

  int numOfPegs = 0;
  int j;
  char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};
// loops through the positions of A-M and checks if they are pegs
  for(j = 0; j < 13; ++j){
    if(get_element(alphabet[j]) == '.'){
      numOfPegs += 1;
    }
  }

  if(numOfPegs == 12){
    cout << "Congrats you win!" << endl;
    return false;
  }

  else if(numOfPegs != 12){
    return true;
  }
  
    
}

void initialize_board(){
// Initialize the board to have all pegs, besides the very center hole.

  set_element( 'A', '#');
  set_element( 'B', '#');
  set_element( 'C', '#');
  set_element( 'D', '#');
  set_element( 'E', '#');
  set_element( 'F', '#');
  set_element( 'G', '.');
  set_element( 'H', '#');
  set_element( 'I', '#');
  set_element( 'J', '#');
  set_element( 'K', '#');
  set_element( 'L', '#');
  set_element( 'M', '#');
    
}
