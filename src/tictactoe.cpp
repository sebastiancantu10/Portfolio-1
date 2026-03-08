#include <iostream>
#include <vector>
#include "tictactoe.hpp"

// constructor: initialize board and get current player
TicTacToe::TicTacToe() {
    board = std::vector<char>(9, ' ');
    currentPlayer = 'X';
}

// print the current state of the board game
void TicTacToe::printBoard() {

    for (int i = 0; i < 9; i++) {

        if (board[i] == ' ') {
            std::cout << " " << i + 1 << " ";
        } else {
            std::cout << " " << board[i] << " ";
        }

        if (i % 3 != 2) {
            std::cout << "|";
        }

        if (i % 3 == 2 && i != 8) {
            std::cout << "\n-----------\n";
        }
    }

    std::cout << std::endl;
}

// make a move, returns true if valid move
bool TicTacToe::makeMove(int position) {
    if (position < 1 || position > 9) {
        return false; // out of bounds for the index. ie outside the 3x3 game board
    }
    if (board[position - 1] != ' ') {
        return false; // provided space entered is occupied
    }
    board[position - 1] = currentPlayer;
    return true;
}

// check winning conditions
bool TicTacToe::checkWin() {
    const int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // columns
        {0,4,8}, {2,4,6}           // diagonals};
    };

    for (auto &combo : wins) {
        if (board[combo[0]] == currentPlayer && board[combo[1]] == currentPlayer && board[combo[2]] == currentPlayer) {
            return true;
        }
    }
    return false;
}

// check if board is full
bool TicTacToe::checkDraw() {
    for (char cell : board) {
        if (cell == ' ') {
            return false; // board still has empty spaces
        }
    }
    return true; // no empty spaces
}

// useful resource
/* Using the ?: operator, you can combine these operators:

int number;
// user inputs a value and it is put into number
int answer = (number >= 0 ? number : 0);

The code inside the parens evaluates to either number or 0 as the ? acts like an if, and then that value is assigned to answer.
*/
// https://courses.washington.edu/css342/zander/css332/datatypes.html

// switch between X and O
void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
char TicTacToe::getCurrentPlayer() {
    return currentPlayer;
}

// reset board for new game
void TicTacToe::resetBoard() {
    board = std::vector<char>(9, ' ');
    currentPlayer = 'X';
}

// gets a value at a board position for tests
char TicTacToe::getCell(int position) {
    if (position < 1 || position > 9) {
        return ' ';
    }
    return board[position - 1];
}