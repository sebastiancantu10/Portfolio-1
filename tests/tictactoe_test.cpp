#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/tictactoe.hpp"

TEST_CASE("Initial Board is Empty") {
    TicTacToe game;
    for (int i = 1; i <= 9; i++) {
        REQUIRE(game.getCell(i) == ' ');
    }
    REQUIRE(game.getCurrentPlayer() == 'X');
}

TEST_CASE("Valid Moves") {
    TicTacToe game;
    REQUIRE(game.makeMove(1) == true);
    REQUIRE(game.getCell(1) == 'X');
    game.switchPlayer();
    REQUIRE(game.makeMove(2) == true);
    REQUIRE(game.getCell(2) == 'O');
}

TEST_CASE("Invalid Moves") {
    TicTacToe game;
    REQUIRE(game.makeMove(0) == false);
    REQUIRE(game.makeMove(10) == false);
    REQUIRE(game.makeMove(5) == true);
    REQUIRE(game.makeMove(5) == false); // already taken
}

TEST_CASE("WIN") {
    TicTacToe game;
    game.makeMove(1); game.makeMove(4); // X at 1, O at 4
    game.makeMove(2); game.makeMove(5);
    game.makeMove(3); // X wins
    REQUIRE(game.checkWin() == true);
}

TEST_CASE("DRAW") {
    TicTacToe game;
    std::vector<int> moves = {1,2,3,5,4,6,8,7,9};
    for (size_t i = 0; i < moves.size(); i++) {
        game.makeMove(moves[i]);
        game.switchPlayer();
    }
    REQUIRE(game.checkDraw() == true);
}
