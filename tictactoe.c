#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void init_board(char board[])
{
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

void display_board(char board[])
{
    char c[9];

    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            c[i] = '0' + i;
        } else {
            c[i] = board[i];
        }
    }

    printf("\n");
    printf(" %c | %c | %c\n", c[0], c[1], c[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[3], c[4], c[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[6], c[7], c[8]);
    printf("\n");
}


bool is_winner(char board[], char player)
{
    if (board[0] == player && board[1] == player && board[2] == player) return true;
    if (board[3] == player && board[4] == player && board[5] == player) return true;
    if (board[6] == player && board[7] == player && board[8] == player) return true;

    if (board[0] == player && board[3] == player && board[6] == player) return true;
    if (board[1] == player && board[4] == player && board[7] == player) return true;
    if (board[2] == player && board[5] == player && board[8] == player) return true;

    if (board[0] == player && board[4] == player && board[8] == player) return true;
    if (board[2] == player && board[4] == player && board[6] == player) return true;

    return false;
}

char other_player(char player)
{
    if (player == 'O') {
        return 'X';
    }
    return 'O';
}

int get_human_move(char board[])
{
    char ch;
    int move = 0;
    bool valid = false;

    while (!valid) {
        printf("Your turn (O). Enter a square number (0-8): ");
        scanf(" %c", &ch);

        while (getchar() != '\n') {
        }

        if (ch < '0' || ch > '8') {
            printf("  That is not a square number. Enter a digit from 0 to 8.\n");
        } else {
            move = ch - '0';
            if (board[move] != ' ') {
                printf("  That square is already taken. Choose an empty one.\n");
            } else {
                valid = true;
            }
        }
    }
    return move;
}

int get_computer_move(char board[])
{
    int move;

    do {
        move = rand() % 9;
    } while (board[move] != ' ');

    return move;
}

void take_turn(char board[], char player)
{
    int move;

    if (player == 'O') {
        move = get_human_move(board);
    } else {
        printf("Computer (X) is thinking...\n");
        move = get_computer_move(board);
        printf("Computer (X) chose square %d. Your move next!\n", move);
    }
    board[move] = player;
}

void play_game(void)
{
    char board[9];
    char current = 'O';
    bool game_over = false;

    init_board(board);
    display_board(board);

    for (int turn = 0; turn < 9 && !game_over; turn++) {
        take_turn(board, current);
        display_board(board);

        if (is_winner(board, current)) {
            if (current == 'O') {
                printf("You (O) win! Congratulations!\n");
            } else {
                printf("Computer (X) wins!\n");
            }
            game_over = true;
        } else {
            current = other_player(current);
        }
    }

    if (!game_over) {
        printf("It's a draw!\n");
    }
}

bool play_again(void)
{
    char answer = ' ';

    while (answer != 'y' && answer != 'q') {
        printf("\nPlay again? (y = yes, q = quit): ");
        scanf(" %c", &answer);

        /* throw away the rest of the line the user typed */
        while (getchar() != '\n') {
        }

        if (answer != 'y' && answer != 'q') {
            printf("  Please type y or q.\n");
        }
    }

    return answer == 'y';
}

int main(void)
{
    srand(time(NULL));

    printf("=====================================\n");
    printf("        TIC-TAC-TOE vs COMPUTER\n");
    printf("=====================================\n");
    printf("You are O and you go first. The computer is X.\n");
    printf("On your turn, type the number of an empty square:\n");
    printf("\n 0 | 1 | 2\n---+---+---\n 3 | 4 | 5\n---+---+---\n 6 | 7 | 8\n");

    do {
        play_game();
    } while (play_again());

    printf("Thanks for playing. Goodbye!\n");
    return 0;
}
