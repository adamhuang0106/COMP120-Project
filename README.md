# Tic-Tac-Toe vs. the Computer

This is my Project 1 for COMP 120. It's a tic-tac-toe game in C where you play against the computer.

You are O and you go first. The computer is X and just picks a random empty square each turn, so it's not very smart.

## How to run it

```
gcc -o tictactoe tictactoe.c
./tictactoe
```

## How to play

The squares are numbered 0 to 8:

```
 0 | 1 | 2
---+---+---
 3 | 4 | 5
---+---+---
 6 | 7 | 8
```

Type the number of an empty square and press Enter. Get three in a row to win. If the board fills up and nobody has three in a row, it's a draw. When a game ends, type y to play again or q to quit.

If you type something that isn't a digit from 0 to 8, or pick a square that's already taken, the program tells you and asks again.

## How the code is organized

I split the program into small functions so each one does one thing:

- `init_board` - sets every square to empty
- `display_board` - prints the board, showing numbers for empty squares
- `is_winner` - checks if a player has three in a row
- `other_player` - switches between O and X
- `get_human_move` - asks for a move until it gets a valid one
- `get_computer_move` - picks a random empty square
- `take_turn` - one move for whoever's turn it is
- `play_game` - runs one whole game
- `play_again` - asks if you want another game

`play_game` is a loop that takes a turn, shows the board, checks for a win, and switches players if nobody won yet.

## Loops I used

- `while` for asking again until the input is valid
- `do...while` for the computer's random pick and for playing at least one game
- `for` for setting up the board and counting the 9 turns
