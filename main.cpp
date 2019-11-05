//------------------------------------
//  vexed.cpp
//     Move pieces to be adjacent.  Once adjacent pieces match, they are cleared off the board.  Once the entire
//     board is clear, play advances to the next level.
//     
//  Prog 4: Vexed
//  Author: Tanmay Sarin and Sajal Gupta
//  Using Codio, for UIC CS 141, Fall 2019
//
//  Running the program looks like:
/*
		Welcome to Vexed!
		The objective is to place identical pieces next to each other, so that they vanish,
		clearing the board completely within the indicated number of moves. On each move
		enter the row, column, and direction (L or R) to move, in either upper or lower
		case. You may also enter 'x' to exit the program, or 'r' to reset the current level.


			Board 0 par 4
			  0 1 2 3 4 5 6 7 8 9
			-----------------------
		  A | . . . . . . . . . . | A
		  B | . . . . . . . . . . | B
		  C | . . . @ &     . . . | C
		  D | . . . . .     . . . | D
		  E | . . .         . . . | E
		  F | . . . &     @ . . . | F
		  G | . . . . & @ . . . . | G
		  H | . . . . . . . . . . | H
			-----------------------
			  0 1 2 3 4 5 6 7 8 9
		1. Your move: c4r

			Board 0 par 4
			  0 1 2 3 4 5 6 7 8 9
			-----------------------
		  A | . . . . . . . . . . | A
		  B | . . . . . . . . . . | B
		  C | . . . @   &   . . . | C
		  D | . . . . .     . . . | D
		  E | . . .         . . . | E
		  F | . . . &     @ . . . | F
		  G | . . . . & @ . . . . | G
		  H | . . . . . . . . . . | H
			-----------------------
			  0 1 2 3 4 5 6 7 8 9

			Board 0 par 4
			  0 1 2 3 4 5 6 7 8 9
			-----------------------
		  A | . . . . . . . . . . | A
		  B | . . . . . . . . . . | B
		  C | . . . @       . . . | C
		  D | . . . . . &   . . . | D
		  E | . . .         . . . | E
		  F | . . . &     @ . . . | F
		  G | . . . . & @ . . . . | G
		  H | . . . . . . . . . . | H
			-----------------------
			  0 1 2 3 4 5 6 7 8 9

			Board 0 par 4
			  0 1 2 3 4 5 6 7 8 9
			-----------------------
		  A | . . . . . . . . . . | A
		  B | . . . . . . . . . . | B
		  C | . . . @       . . . | C
		  D | . . . . .     . . . | D
		  E | . . .     &   . . . | E
		  F | . . . &     @ . . . | F
		  G | . . . . & @ . . . . | G
		  H | . . . . . . . . . . | H
			-----------------------
			  0 1 2 3 4 5 6 7 8 9

			Board 0 par 4
			  0 1 2 3 4 5 6 7 8 9
			-----------------------
		  A | . . . . . . . . . . | A
		  B | . . . . . . . . . . | B
		  C | . . . @       . . . | C
		  D | . . . . .     . . . | D
		  E | . . .         . . . | E
		  F | . . . &   & @ . . . | F
		  G | . . . . & @ . . . . | G
		  H | . . . . . . . . . . | H
			-----------------------
			  0 1 2 3 4 5 6 7 8 9
		2. Your move:

 */
#include <iostream>   // For cin, cout
#include <fstream>    // For file input
#include <chrono>     // Used in pausing for some milliseconds using sleep_for(...)
#include <thread>     // Used in pausing for some milliseconds using sleep_for(...)

#include <vector> 

using namespace std;

// Global constants
const int MaxNumberOfBoards = 118;
const int BoardRows = 8;
const int BoardColumns = 10;
const int NumberOfPresetBoardParValues = 60;    // After the first 60 par values, the default par value is 15
const char FileName[] = "boards.txt";
const int SleepAmount = 150;                    // Length of time to pause, in milliseconds


//------------------------------------------------------------------------------------------------------------------
// Class used to store a game board
class Board
{
    public:
        // Constructor declarations  
        Board();
        Board(int boradNumber, int boardValuesArray[BoardRows*BoardColumns], int parValue);
        // Get and Set member functions, corresponding to the private data members
        void SetLevel( int boradNumber);
        void SetPar  (int parValue    );
        void SetBoardArray(int boardValuesArray[BoardRows*BoardColumns]);
    
        int GetPar();
    
        // Utility member function declarations.  
        void displayBoard();
        bool move(int fromPosition, int directionPosition);
        void drop(int finalPosition);
        bool destroy();
        void dfs(int n,bool vis[],int dx[],int x);
        int getNonEmptyTiles();
    
        

    private:
        int level; //To store the level of the board;
        int par;   //variable that displays the number of moves.
        int boardArray[BoardRows*BoardColumns];
        int notEmptyTiles;
        char characters[10] = {' ','&','@','+','%','^','#','=','*','.'};
        
};  // end class Board

Board::Board(){                                                  //
    level = -1;                                                  //
    par = -1;                                                    //Default cunstructor for Board class
    for (int i = 0; i < BoardRows * BoardColumns; i++){          //
        boardArray[i] = -1;}                                     //
}                                                                //

Board::Board(int boradNumber, int boardValuesArray[BoardRows*BoardColumns], int parValue){ //
    level = boradNumber;                                                                   //
    par = parValue;                                                                        //
    for (int i = 0; i < BoardRows * BoardColumns; i++){                                    //Fully Qualified constructor for Board class
        boardArray[i] = boardValuesArray[i];                                               //
    }                                                                                      //
}                                                                                          //

int Board::GetPar(){   //
    return par;        //Get function to get the value of "par"
}                      //

int Board::getNonEmptyTiles(){                             //     
    int notEmptyTiles = 0;                                 //
    for(int i=0; i < BoardRows*BoardColumns; i++){         //
        if(boardArray[i] > 0 && boardArray[i] < 9){        //  
            notEmptyTiles = notEmptyTiles + 1;             // Returns the number of tiles/positions which are not empty
        }                                                  //
    }                                                      //
    return notEmptyTiles;                                  // 
}                                                          //

void Board::displayBoard(){                      //Function to display the borad
    char k ='A';                                 //Initializer variable for the alphabets on the sides of the boards
    
    cout<<"\n    Board "<<level<<" par "<<par<<endl;
    
    cout<<"      ";                              //
    for(int i=0; i  < BoardColumns; i++){        //
        cout<<i<<" ";                            //Displays the numbers on the top above the dashes on the board   
    }                                            //
    cout<<endl;                                  //
    
    cout<<"    ";                                // 
    for (int j=0; j<=((2*BoardColumns)+2);j++ ){ //For loop to display the dashes above the board
    cout<<"-";}                                  // 
    
    for (int i = 0; i < BoardRows * BoardColumns; i++){ //For loop to display the board
        
        if(i % BoardColumns == 0 ){              //  
            cout<<"\n  "<<k<<" | ";              //Prints the "|" and the alphabets on the left side
            k++;                                 //
        }                                        //
    
        cout<<characters[boardArray[i]]<<" ";    //Casting character array to int array to change the numbers to characters.
        
        if(i % BoardColumns == 9 ){              //
            cout<<"| "<<char(k-1);               //Prints the "|" and the alphabets on the right side
        }                                        //           
    }
    cout<<endl;
    cout<<"    ";                                //
    for (int j=0; j<=((2*BoardColumns)+2);j++ ){ //For loop to display the dashes below the board
    cout<<"-";}                                  //
    
    cout<<endl;                                  //
    cout<<"      ";                              //
    for(int i=0; i  < BoardColumns; i++){        //Displays the numbers on the bottom below the dashes on the board
        cout<<i<<" ";                            //
    }                                            // 
    cout<<endl;                                  //
}

bool Board::move(int fromPosition, int directionPosition){ //For horizontal movement of the characters
    
    int finalPosition;
    
    finalPosition = fromPosition + directionPosition;
        
    if (boardArray[fromPosition]==9){                                                        //
        cout <<endl<<"Attempting to move an invalid character.  Please retry." << endl;      //
        return false;                                                                        //   
    }                                                                                        //                            
    else if (boardArray[finalPosition]==boardArray[fromPosition]){                           //
        return false;                                                                        // Checking for edge cases  
    }                                                                                        //
    else if (boardArray[finalPosition]!=0){                                                  //
        cout<<endl<<"Attempting to move into a non-empty space.  Please retry."<<endl;       //  
        return false;                                                                        //
    }                                                                                        //
    if(boardArray[finalPosition] == 0){                          // 
        boardArray[finalPosition] = boardArray[fromPosition];    //Swapping the position so that the characters appear to move
        boardArray[fromPosition] = 0;                            //
    }                                                            //
       
    displayBoard(); 
    drop(finalPosition);
}

void Board::drop(int finalPosition){  //For the "dropping" of the characters
    
    int dropPosition = finalPosition + BoardColumns;
    
    for(int i = BoardRows*BoardColumns; i>=0; i--){
        
        while(boardArray[dropPosition] == 0){                                   //
            boardArray[dropPosition] = boardArray[finalPosition];               //
            boardArray[finalPosition] = 0;                                      //Swaps the element which is supposed to drop with the empty space below it
                                                                                //
            finalPosition = dropPosition;                                       //
            dropPosition = finalPosition + BoardColumns;                        //
            
            displayBoard();
        }
        
        if(boardArray[i] == 0 && boardArray[i-10] != 0 && boardArray[i-10] < 9){ //
            boardArray[i] = boardArray[i-10];                                    //Swaps other eligible elements with the empty space below it
            boardArray[i-10] = 0;                                                //
                                                                                       
           displayBoard();
        }
    }
   
    destroy();
    destroy();
}

void Board::dfs(int n,bool vis[],int dx[],int x){  //
    vis[x]=true;                                   //
    boardArray[x]=0;                               //
    for(int i=0;i<4;i++){                          //
        int X=x+dx[i];                             //DFS algorithm to find similar characters and mark them 
        if(!vis[X] && boardArray[X]==n){           //
            dfs(n,vis,dx,X);                       //
        }                                          //
    }                                              //
}                                                  // 

bool Board::destroy(){
    bool flag = false;
    for (int i=0; i < BoardRows*BoardColumns; i++){
        if(boardArray[i] != 0 && boardArray[i] != 9){        //Specifying the search radius for the character search    
            if((boardArray[i] == boardArray[i+1]) || (boardArray[i] == boardArray[i-1]) || (boardArray[i] == boardArray[i+10]) || (boardArray[i] == boardArray[i -10])){
               int dx[]={1,-1,10,-10};                       //
               bool vis[BoardRows*BoardColumns];             //
               dfs(boardArray[i],vis,dx,i);                  //Initializing the requirements for the DFS algorithm
               for(int j=0;j<BoardRows*BoardColumns;j++){    //
                    vis[j]=false;                            //  
               }                                             //
               flag = true;
            }
        }
        if(flag){
            break;
        }
    }
    if(flag){                      //
        displayBoard();            //Displaying the board after removing the marked characters
    }                              // 
}

//------------------------------------------------------------------------------------------------------------------
// Class used to read in and store all game boards
class AllBoards
{
    public:
        //------------------------------------------------------------------------------------------------------------------
        // Constructor that reads in data from the data file.
        AllBoards();    // Declaration.  See the definition outside the class, below.
    
        // Get and Set member functions.
    
        //------------------------------------------------------------------------------------------------------------------
        // Find and return a particular board.
        Board getBoard( int boardIndex)
        {
            // Validate board index number
            if( boardIndex < 0 || boardIndex > MaxNumberOfBoards) {
                cout << "In getBoard() inside AllBoards class, boardIndex "
                     << boardIndex << " is out of range. Exiting..." << endl;
                exit( -1);
            }
            
            // Construct a Board from one of all the boards
            Board newBoard( boardIndex, allBoards[ boardIndex], levelParValues[ boardIndex]);
            return newBoard;
        }
    
        //------------------------------------------------------------------------------------------------------------------
        // Retrieve the par value
        int getParValue( int boardIndex) {
            int theParValue = 15;   // default
            if( boardIndex < NumberOfPresetBoardParValues) {
                theParValue = levelParValues[ boardIndex];
            }
            return theParValue;
        } // end getParValue()
    
    private:
        int par = 0;             // The number of moves it should take to solve this level
        int currentLevel = -1;   // Which board we're on
        int allBoards[ 118][ BoardRows * BoardColumns];   // Array to store all 118 8x10 boards
    
        // Par values for levels 0 through 59.  Default is 15 after that.
        const int levelParValues[ NumberOfPresetBoardParValues] =
            // 0   1   2   3   4   5   6   7   8   9
            { 4,  3, 14,  5,  6,  4,  4, 14,  5, 25,  //  0 -  9
             12, 17, 17,  8,  4, 12,  9,  8, 12,  8,  // 10 - 19
             10, 10, 16, 13, 20, 14, 10,  9, 12, 14,  // 20 - 29
             15, 13, 20,  8, 15, 10, 10, 11,  7, 23,  // 30 - 39
              8, 11, 16, 14, 12, 13, 13,  3, 35, 18,  // 40 - 49
             26, 10, 13, 18, 26, 12, 15,  5, 22, 15}; // 50 - 59
}; //end class allBoards


//------------------------------------------------------------------------------------------------------------------
// AllBoards constructor
AllBoards::AllBoards()
 {
    // Read in all the boards from the data file
    ifstream inputFileStream;  // declare the input file stream

    // Open input file and verify file open worked.
    inputFileStream.open( FileName);
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file. " << FileName << ".  Exiting..." << endl;
        exit( -1);
    }

    // Read the five lines of comments at the top of the datafile.  Datafile structure is:
    //    // Originally from Vexed v2.0 - globals.c "Global variable declarations"
    //    // Copyright (C) 1999 James McCombe (cybertube@earthling.net)
    //    // September 1,2001 - Version 2.0 changes by Mark Ingebretson (ingebret@yahoo.com) and others.
    //    // Oct 13, 2019  Format changed by Dale Reed (reed @ uic.edu)
    //    // Covered by the GNU General Public License https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html
    //    // Level 000
    //    9 9 9 9 9 9 9 9 9 9
    //    9 9 9 9 9 9 9 9 9 9
    //    9 9 9 2 1 0 0 9 9 9
    //    9 9 9 9 9 0 0 9 9 9
    //    9 9 9 0 0 0 0 9 9 9
    //    9 9 9 1 0 0 2 9 9 9
    //    9 9 9 9 1 2 9 9 9 9
    //    9 9 9 9 9 9 9 9 9 9
    //    // Level 001
    //    9 9 9 9 9 9 9 9 9 9
    //    9 9 9 9 9 9 9 9 9 9
    // ...
    
    // Read and discard the five lines of comments at the beginning of the file.
    string inputLine;
    for( int i=0; i<5; i++) {
        getline(inputFileStream, inputLine);
    }
    
    // Now read each of the 118 (MaxNumberOfBoards) boards.  Each one starts with a comment that has the board number.
    for( int boardIndex = 0; boardIndex < MaxNumberOfBoards; boardIndex++) {
        // Read the comment with the board number
        getline(inputFileStream, inputLine);
        
        // For each board now read the BoardRows * BoardColumns number of board values, as integers
        for( int row=0; row<BoardRows; row++) {
            for( int col=0; col<BoardColumns; col++) {
                inputFileStream >> allBoards[ boardIndex][ row * BoardColumns + col];
            }
            // Get rid of end-of-line character at the end of each board, so we can get a clean start on reading the
            //   first line of the next board, on the line with the comment and board number.
            getline(inputFileStream, inputLine);
        }
    }//end for( int boardIndex=0...

    // Close the input file.
    inputFileStream.close();
}//end AllBoards() constructor


//------------------------------------------------------------------------------------------------------------------
void displayDirections()
{
    cout << "Welcome to Vexed!  \n"
         << "The objective is to place identical pieces next to each other, so that they vanish,   \n"
         << "clearing the board completely within the indicated number of moves. On each move      \n"
         << "enter the row, column, and direction (L or R) to move, in either upper or lower       \n"
         << "case. You may also enter 'x' to exit the program, or 'r' to reset the current level. \n"
         << endl;
}


//------------------------------------------------------------------------------------------------------------------
// Driver for the program, using the classes and functions declared above
int main()
{
    AllBoards allTheBoards;     // Reads in and stores all the boards from a data file
    int currentBoardIndex = 0;  // Starting board index
    Board theBoard;             // The board instance, that is set to hold the values for each level
    int score = 0;              // Score accumulates par points for each level finished
    
    int step= 1;                //Variable to count the number of moves 
    char inputChar;             //Variable for the row alphabet input
    int inputNum1;              //Variable for the column number input
    char direction;             //Variable to specify the direction  
    int fromPosition;           //Variable to specify the initial position of the element
    int directionPosition = 0;  //Integer variable for the direction
    
    displayDirections();        //Displays the directions of the game
    
    for( currentBoardIndex=0; currentBoardIndex < MaxNumberOfBoards; currentBoardIndex++) {
    theBoard = allTheBoards.getBoard(currentBoardIndex);
    theBoard.displayBoard();

    //Loop Starts here:
        while(true){

            cout<<step<<". Your move:";                 //Takes the input for the row alphabet
            cin >> inputChar;                           //

            if (inputChar == 'x' || inputChar == 'X'){  //Command to exit the program          //  
                exit(-1);                               //                                     //
            }else if (inputChar == 'r' || inputChar == 'R') { //                               //
                currentBoardIndex--;                          //Command to reset               // 
                cout << endl;                                 //  the board                    //
                step = 1;                                     //                               // 
                break;                                        //                               //Declaring the special commands
            }else if (inputChar == 's' || inputChar == 'S') {   //                             // 
                cin >> inputNum1;                               //Command to set the           // 
                currentBoardIndex = inputNum1 - 1;              //board level                  //
                cout << endl;                                   //                             //
                break;                                          //                             //
            }                                                                                  //
           else if (inputChar > 72 && inputChar < 97||inputChar > 104){              //
                cin>>inputNum1;                                                      //
                if (inputNum1>9){                                                    //Initializing the edge cases
                    cout<<endl<<"Move value is out of bounds.  Please retry."<<endl; //
                }                                                                    //
            }
            else if ( inputChar >= 65 && inputChar <= 72 || inputChar >= 97 &&  inputChar <= 104){  //Bounding the Alphabet limits
                cin>>inputNum1;                                                                     //
                cin>>direction;                                                                     
                                                                                                     
                if (direction == 'R' || direction == 'r'){                                          //
                    directionPosition = 1;                                                          //Specifying the directions
                } else if (direction == 'L' || direction == 'l'){                                   //
                    directionPosition =  -1;                                                        //
                } else {                                                           //                
                    cout<<endl<<"Invalid move direction.  Please retry."<<endl;    //Edge cases for the direction input
                    directionPosition =0;                                          //
                }                                                                  //
                
                if(inputChar >= 65 && inputChar <= 72){                       //
                    fromPosition = (inputChar-65) * BoardColumns + inputNum1; // Gives the position of the item we want to move in our 1D array
                    
                }else if(inputChar >= 97 &&  inputChar <= 104){               //
                    fromPosition = (inputChar-97) * BoardColumns + inputNum1; //Gives the position of the item we want to move in our 1D array
                }                                                             //
                
                if (theBoard.move(fromPosition, directionPosition)) {
                         
                    int finalPosition;
                    cout << endl;
                    theBoard.drop(finalPosition);
                    
                    if(theBoard.getNonEmptyTiles() == 0 && step <= theBoard.GetPar()){ //
                        cout<<"Congratulations!  On to the next level."<<endl;         //
                        score = score + step;//Giving the score of the player          //
                        cout<<"Score: "<<score<<endl;                                  //If we complete the game within the specified amount of steps
                        currentBoardIndex;                                             //
                        cout<<endl;                                                    //
                        step = 1;                                                      //
                        break;                                                         //
                    }else if(theBoard.getNonEmptyTiles() == 0 && step >= theBoard.GetPar()){ //If we complete the game without meeting step requirements
                        cout<<"Sorry, you took "<<step<<" moves and you must finish within "<<theBoard.GetPar()<<" moves before moving on."<<endl;
                        currentBoardIndex--;                                                 //
                        cout << endl;                                                        //
                        step = 1;                                                            //
                        break;                                                               //
                    }                                                                        //
                    step++; // Incrementing the step counter
                }
            }
        }
    }
    return 0;
}