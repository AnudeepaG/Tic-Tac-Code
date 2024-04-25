#include<stdio.h>
#include<stdlib.h>

char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void gameName() {
    printf("\n\t\t\t\t\t Tic Tac Toe Game\n");
}

void show() {
    printf("\n\n");
    printf("\t\t\t  %c | %c | %c\n", a[0], a[1], a[2]);
    printf("\t\t\t ---|---|---\n");
    printf("\t\t\t  %c | %c | %c\n", a[3], a[4], a[5]);
    printf("\t\t\t ---|---|---\n");
    printf("\t\t\t  %c | %c | %c\n", a[6], a[7], a[8]);
    printf("\n\n");
}

void inputSymbol() {
    printf("\nPlayer 1 symbol: X");
    printf("\nPlayer 2 symbol: O");
}

void play(char sym) {
    char pos;
    printf("\nEnter position for symbol '%c': ", sym);
    fflush(stdin);
    scanf("%c", &pos);

    for (int i = 0; i < 9; i++) {
        if (a[i] == pos) {
            a[i] = sym;
            return;
        }
    }

    printf("Invalid move! Please try again.\n");
    play(sym);
}

int end() {
    if ((a[0] == 'X' && a[1] == 'X' && a[2] == 'X') || (a[0] == 'X' && a[4] == 'X' && a[8] == 'X') || (a[0] == 'X' && a[3] == 'X' && a[6] == 'X'))
        return 1;
    else if ((a[0] == 'O' && a[1] == 'O' && a[2] == 'O') || (a[0] == 'O' && a[4] == 'O' && a[8] == 'O') || (a[0] == 'O' && a[3] == 'O' && a[6] == 'O'))
        return 2;
    else if (a[1] == 'X' && a[4] == 'X' && a[7] == 'X')
        return 1;
    else if (a[1] == 'O' && a[4] == 'O' && a[7] == 'O')
        return 2;
    else if (a[2] == 'X' && a[5] == 'X' && a[8] == 'X')
        return 1;
    else if (a[2] == 'O' && a[5] == 'O' && a[8] == 'O')
        return 2;
    else if (a[3] == 'X' && a[4] == 'X' && a[5] == 'X')
        return 1;
    else if (a[3] == 'O' && a[4] == 'O' && a[5] == 'O')
        return 2;
    else if (a[2] == 'X' && a[4] == 'X' && a[6] == 'X')
        return 1;
    else if (a[2] == 'O' && a[4] == 'O' && a[6] == 'O')
        return 2;
    else if (a[6] == 'X' && a[7] == 'X' && a[8] == 'X')
        return 1;
    else if (a[6] == 'O' && a[7] == 'O' && a[8] == 'O')
        return 2;
    else
        return 0;
}

int main() {
    int k, count = 0;
    char ch;

    gameName();
    show();
    inputSymbol();

    do {
        count++;
        if (count % 2 == 0)
            play('O');
        else
            play('X');

        show();
        k = end();

        if (k == 1 || k == 2 || count == 9) {
            if (k == 1)
                printf("\nPlayer 1 won!");
            else if (k == 2)
                printf("\nPlayer 2 won!");
            else
                printf("\nGame draw!");

            printf("\nDo you want to play again? (Y/N): ");
            fflush(stdin);
            scanf(" %c", &ch);

            if (ch == 'Y' || ch == 'y') {
                for (int i = 0; i < 9; i++)
                    a[i] = '1' + i;
                count = 0;
                printf("\n\n");
                show();
            } else {
                printf("\nThank you for playing!\n");
                break;
            }
        }
    } while (1);

    return 0;
}
