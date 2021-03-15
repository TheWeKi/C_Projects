#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char placedMarks[10] = "---------"; 
int draw=1, player=1, playerTurn=1, validMark;

void showRules();
void referGrid();
void mainGrid(char []);
void showGrid();

int checkWin(char []);
void changeMark(int, int, char []);

void getMark();
int askPlayerForMark(int);
void validityCheck(int);

void game();

int main(void)
{
    system("cls");
    
    showRules();
    game();
    
    printf("\n\n");
    system("pause");

    return 0;
}

void showRules() //show Rules and ask for permission to start the game
{
    printf("\n\n1.The game is played on 3 by 3 squares grid");
    printf("\n2.Player 1 is x and Player 2 is o");
    printf("\n3.The first player to get 3 of his/her Marks in a row or column or diagonal will win");
    printf("\n4.When all 9 squares are full and if no one has 3 marks in row/column/diagonal, the game ends in tie");
    printf("\n\n\t\t\t\tPress Enter to Start");
    getch();
}

void showGrid()
{
    referGrid();
    mainGrid(placedMarks);
}

void referGrid() //show Reference Grid and Marks at side
{
    system("cls");
    printf("\n\n  %d  |  %d  |  %d  ", 1, 2, 3);
    printf("\t\t\tPRESS DESIRED PLACE NUMBER TO PUT YOUR MARK");
    printf("\n_____|_____|_____");
    printf("\n  %d  |  %d  |  %d  ", 4, 5, 6);
    printf("\t\t\tPlayer 1 ---->   x");
    printf("\n_____|_____|_____");
    printf("\n  %d  |  %d  |  %d  ", 7, 8, 9);
    printf("\t\t\tPlayer 2 ---->   o");
    printf("\n     |     |     ");
}

void mainGrid(char a[]) // show Main Grid
{
    printf("\n\n\n");
    printf("\n\t\t\t\t\t       |       |       ");
    printf("\n\t\t\t\t\t   %c   |   %c   |   %c   ", a[0], a[1], a[2]);
    printf("\n\t\t\t\t\t_______|_______|_______");
    printf("\n\t\t\t\t\t       |       |       ");
    printf("\n\t\t\t\t\t   %c   |   %c   |   %c   ", a[3], a[4], a[5]);
    printf("\n\t\t\t\t\t_______|_______|_______");
    printf("\n\t\t\t\t\t       |       |       ");
    printf("\n\t\t\t\t\t   %c   |   %c   |   %c   ", a[6], a[7], a[8]);
    printf("\n\t\t\t\t\t       |       |       ");
}

int checkWin(char a[]) // check for win if win returns 1 otherwise returns 0
{
    int win=0;
    //Row Check
    if( (a[0]==a[1] && a[1]==a[2]) && (a[0]=='x'||a[0]=='o') )
        win=1;
    else if( (a[3]==a[4] && a[4]==a[5]) && (a[3]=='x'||a[3]=='o') )
        win=1;
    else if( (a[6]==a[7] && a[7]==a[8]) && (a[6]=='x'||a[6]=='o') )
        win=1;
    //Column Check
    else if( (a[0]==a[3] && a[3]==a[6]) && (a[0]=='x'||a[0]=='o') )
        win=1;
    else if( (a[1]==a[4] && a[4]==a[7]) && (a[1]=='x'||a[1]=='o') )
        win=1;
    else if( (a[2]==a[5] && a[5]==a[8]) && (a[2]=='x'||a[2]=='o') )
        win=1;
    //Diagonal Check
    else if( (a[0]==a[4] && a[4]==a[8]) && (a[0]=='x'||a[0]=='o') )
        win=1;
    else if( (a[2]==a[4] && a[4]==a[6]) && (a[2]=='x'||a[2]=='o') )
        win=1;
    //if no check passed 
    else
        win=0;
    //return value of win
    return win;
}

void getMark()
{
    system("cls");
    showGrid();
    validityCheck ( askPlayerForMark(playerTurn) );
}

int askPlayerForMark(int pT)
{
    int mark;
    if( pT % 2 == 0)
        player = 2;
    else
        player = 1;
    printf("\nPlayer %d Turn ----->   ", player);
    mark = getchar();
    return mark;
}

void validityCheck(int mark)
{
    if ( mark>=49 && mark<=57 ) // ASCII of 1 is 49 and ASCII of 9 is 57
        validMark = mark - 48;
    else
        getMark();
}

void changeMark(int p, int vM, char a[])
{
    if(p==1)
    {
        a[vM-1] = 'x';
        playerTurn = playerTurn + 1;
    }
    else if(p==2)
    {
        a[vM-1] = 'o';
        playerTurn = playerTurn + 1;
    }
}

void game()
{
    while( playerTurn <= 9 )
    {
        getMark();
        changeMark(player, validMark, placedMarks);
        if ( checkWin(placedMarks) )
        {
            draw=0;
            break;
        }
        else
            draw=1;
    }

    system("cls");
    mainGrid(placedMarks);
    if( draw )
        printf("\nGame Draw!");
    else
        printf("\nPlayer %d Won", player);
}

//The End.