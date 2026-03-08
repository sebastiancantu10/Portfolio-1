#include <string>
#include <vector>
#include <iostream>

class TicTacToe {
private:
    std::vector<char> board; // 1-9 spaces, X , O , or empty
    char currentPlayer; // X or O

public:
    // constructor
    TicTacToe();

    // methods for TicTacToe START
    // display the game board
    void printBoard();

    // make a move, returns true if valid move
    bool makeMove(int position);

    // check if the current player won
    bool checkWin();

    // check if board is full
    bool checkDraw();

    // swap between X turn and O turn
    void switchPlayer();

    // get the player whose turn it is
    char getCurrentPlayer();

    // clear the board for a new game
    void resetBoard();

    // methods for TicTacToe ENDS

    // unit testing checker
    // get value at this space
    char getCell(int position);
};
