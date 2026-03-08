#include <iostream>
#include <string>
#include <vector>
#include "src/tictactoe.hpp"

int main() {
  TicTacToe game;
  std::string playAgain;

  std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

  do {
    game.resetBoard();
    bool gameOver = false;

    while (!gameOver) {

      game.printBoard();
      std::cout << std::endl;

      int move;

      while (true) {
        std::cout << "Player " << game.getCurrentPlayer() << " , enter your move (1-9): " << std::endl;

        // check input is valid number within the range 1 - 9 inclusive
        if (std::cin >> move && move >= 1 && move <= 9) {
          // check if the move is valid
          if (game.makeMove(move)) {
            break; // valid move, exits loop
          } else {
            std::cout << "That cell is occupied! Please enter another location." << std::endl;
          }
        } else {
          std::cout << "That is not a valid move! Please enter a location between 1-9.";
        }
        // clear invalid input
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      }

      // check if the current player won
      if (game.checkWin()) {
        game.printBoard();
        std::cout << "Player " << game.getCurrentPlayer() << " wins!" << std::endl;
        gameOver = true;
      }

      // check for draw
      else if (game.checkDraw()) {
        game.printBoard();
        std::cout << "The game ends in a DRAW!" << std::endl;
        gameOver = true;
      }

      // otherwise switch player
      else {
        game.switchPlayer();
      }
    }

    // clear leftover newline from input buffer
    std::cin.ignore(10000, '\n');

    // ask users if they want to play again
    while (true) {
      std::cout << "Would you like to play again? (yes/no)? ";
      std::getline(std::cin, playAgain);

      if (playAgain == "yes" || playAgain == "no") {
        break;
      } else {
        std::cout << "That is not a valid input!" << std::endl;
      }
    }

  } while (playAgain == "yes");

  std::cout << "Goodbye!" << std::endl;

  return 0;
}