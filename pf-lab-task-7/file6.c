#include <stdio.h>

int main()
{
    char board[3][3];
    char winner = '-';

    printf("Enter the 3x3 Tic-Tac-Toe board line by line (use X, O, or -):\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter value for row%d column%d", i, j);
            scanf(" %c", &board[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            winner = board[i][0];
        }
    }

    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
        {
            winner = board[0][j];
        }
    }

    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        winner = board[0][0];
    }

    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        winner = board[0][2];
    }

    printf("Complete Map\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }

    printf("\nResults\n");
    if (winner == 'X' || winner == 'O')
    {
        printf("The winner is: %c\n", winner);
    }
    else
    {
        printf("The game is a Draw!\n");
    }
}
