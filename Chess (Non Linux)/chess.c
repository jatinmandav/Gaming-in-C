 /**
 *
 * #CodingOf208
 *
 * The Game Of Chess!
 * Mandav's Blog
 *
 * By - Jatin Kumar Mandav
 * Non-Terminal Based System
 *
 * Input 1 : Cooordintes of the Piece you Want to Move
 * Input 2 : Coordinates of the Spot Where You Want to Move
 *
 * Output : The Desired Piece is moved According to the Rules of Chess
 *
 * Contact :
 * FaceBook : https://www.facebook.com/jatinmandav
 * Email : jatinmandav3@gmail.com
 * Twitter : @jatinmandav
 *
 */

#define _XOPEN_SOURCE 500

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<windows.h>
#include<conio.h>

//Chess Board
char board[8][8];

//Players
void player1();
void player2();
bool draw_match();

//Animation and greeting the use
void clear();
int greet();
void draw();
int instruct();
void init();

//Chess Pieces
bool pawn(int, int, int, int);
bool knight(int, int, int ,int);
bool king(int, int, int, int);
bool rook(int, int, int, int);
bool bishop(int, int, int, int);
bool queen(int, int, int, int);

//Checks for validity of Castling, and if possible, executes it
bool castling(int, int, int, int);
int cast = 0;

//Decides Which Player Wins
int flag = 0;

int main(void)
{
    clear();
    init();
    while(true)
    {
        clear();
        int s;
        printf("---------------------------------------------------------");
        printf("\n\n\n\t1. Start \t\t 2. Instructions\n\n\n");
        printf("---------------------------------------------------------");
        printf("\n\n\tChoice : ");
        scanf("%d",&s);
        if(s == 1)
        {
            greet();
            break;
        }
        else if(s == 2)
        {
            instruct();
            continue;
        }
        else
        {
            printf("Invalid Selection!\n");
            continue;
        }
    }

    while(true)
    {

        clear();
        draw();
        player1();
        if(flag == 1)
        {
            clear();
            printf("\n\n\n%40s \n%40s\n\n\n","Congratulations!!","Player 1 Wins!!!");
            printf("\n");
            system("1wins.vbs");
            system("pause");
            break;
        }
        else if(flag == 2)
        {
            clear();
            printf("\n\n\n%40s \n%40s\n\n\n","Congratulations!!","Player 2 Wins!!!");
            printf("\n");
            system("2wins.vbs");
            system("pause");
            break;
        }
        else if(flag == 3)
        {
            clear();
            printf("\n\n\n%40s\n\n\n","The Match Is Draw!!");
            printf("\n");
            system("draw.vbs");
            system("pause");
            break;
        }
        player2();
        if(flag == 1)
        {
            clear();
            printf("\n\n\n%40s \n%40s\n\n\n","Congratulations!!","Player 1 Wins!!!");
            printf("\n");
            system("1wins.vbs");
            system("pause");
            break;
        }
        else if(flag == 2)
        {
            clear();
            printf("\n\n\n%40s \n%40s\n\n\n","Congratulations!!","Player 2 Wins!!!");
            printf("\n");
            system("2wins.vbs");
            system("pause");
            break;
        }
        else if(flag == 3)
        {
            clear();
            printf("\n\n\n%40s\n\n\n","The Match Is Draw!!");
            printf("\n");
            system("draw.vbs");
            system("pause");
            break;
        }
    }
    return 0;
}


/**
 * Clearing the Screen
 */
void clear(void)
{
    system("cls");
}

/**
 * Initializong the Chess Board
 */
void init(void)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(i == 0)
            {
                board[i][0] = 'r';
                board[i][1] = 'h';
                board[i][2] = 'b';
                board[i][3] = 'q';
                board[i][4] = 'k';
                board[i][5] = 'b';
                board[i][6] = 'h';
                board[i][7] = 'r';
            }
            else if(i == 1)
            {
                board[i][j] = 'p';
            }
            else if(i == 6)
            {
                board[i][j] = 'P';
            }
            else if(i == 7)
            {
                board[i][0] = 'R';
                board[i][1] = 'H';
                board[i][2] = 'B';
                board[i][3] = 'Q';
                board[i][4] = 'K';
                board[i][5] = 'B';
                board[i][6] = 'H';
                board[i][7] = 'R';
            }
            else
            {

                board[i][j] = 32;
            }
        }
    }
}

/**
 * Draws the Board
 */
void draw(void)
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 002);
    printf("\n%33s\n","> Player 1 <");
    SetConsoleTextAttribute(h, 006);
    printf("--------");
    for(int k=0;k<8;k++)
        printf("------");
    printf("-\n");
    printf("|   ");
    for(int i=0;i<8;i++)
        printf("|  %d  ",i+1);
    printf("|   |\n");
    for(int i=0;i<8;i++)
    {
        printf("----");
        for(int k=0;k<8;k++)
            printf("------");
        printf("-----\n");
        SetConsoleTextAttribute(h, 006);
        printf("| %c ",i + 'A');
        for(int j=0;j<8;j++)
        {
            if((i+j)%2 == 0)
            {
                if(board[i][j] >= 'a' && board[i][j] <= 'z')
                {
                    SetConsoleTextAttribute(h, 006);
                    printf("|");
                    SetConsoleTextAttribute(h, 007);
                    printf("  %c  ",board[i][j]);
                }
                else if(board[i][j] >= 'A' && board[i][j] <= 'Z')
                {
                    SetConsoleTextAttribute(h, 006);
                    printf("|");
                    SetConsoleTextAttribute(h, 001);
                    printf("  %c  ",board[i][j]);
                }
                else
                {
                    printf("|  %c  ",board[i][j]);
                }
            }
            else
            {
                if(board[i][j] >= 'a' && board[i][j] <= 'z')
                {
                    SetConsoleTextAttribute(h, 006);
                    printf("|");
                    SetConsoleTextAttribute(h, 007);
                    printf("  %c  ",board[i][j]);
                }
                else if(board[i][j] >= 'A' && board[i][j] <= 'Z')
                {
                    SetConsoleTextAttribute(h, 006);
                    printf("|");
                    SetConsoleTextAttribute(h, 001);
                    printf("  %c  ",board[i][j]);
                }
                else
                {
                    printf("|  %c  ",board[i][j]);
                }
            }
            SetConsoleTextAttribute(h, 006);
            if(j == 7)
                printf("| %c |",i + 'A');
        }
        printf("\n");
    }
    printf("--------");
    for(int k=0;k<8;k++)
        printf("------");
    printf("-\n");
    printf("|   ");
    SetConsoleTextAttribute(h, 006);
    for(int i=0;i<8;i++)
        printf("|  %d  ",i+1);
    printf("|   |\n");
    printf("--------");
    for(int k=0;k<8;k++)
        printf("------");
    printf("-\n");
    SetConsoleTextAttribute(h, 002);
    printf("%33s\n","> Player 2 <");
    SetConsoleTextAttribute(h, 007);
}

/**
 * Greets the Players
 */
 int greet()
 {
    clear();
    printf("\n\n%53s","WELCOME TO THE EPIC GAME OF CHESS!!\n\n");
    FILE* fp = fopen("Logo.txt", "r");
    if(fp == NULL)
    {
        printf("\t\tError opening the Image!\n");
        return 1;
    }

    char output[256];
    for(int i = 1;fgets(output, sizeof(output), fp) != NULL;i++)
    {
        printf("      ");
        printf("%s", output);
    }
    printf("\n\n");
    system("welcome.vbs");
    system("welcome2.vbs");
    system("pause");
    fclose(fp);
    return 0;
 }

/**
 * Gives The Instructions on how to play
 */
int instruct()
{
    clear();
    FILE* fp = fopen("Instructions.txt", "r");
    if(fp == NULL)
    {
        printf("\t\tError opening the Image!\n");
        return 1;
    }

    char output[256];
    for(int i = 1;fgets(output, sizeof(output), fp) != NULL;i++)
    {
        printf("%s", output);
    }
    printf("\n\n");
    system("pause");
    fclose(fp);
    return 0;
}

/**
 * Player 1
 */
void player1()
{
    char* str = (char*)malloc(10*sizeof(char) + 1);
    int a,b,x,y;
    while(true)
    {
        printf("Player 1:");
        system("player1.vbs");
        printf("\nEnter The Coordinates Of the Piece You Want to Move: ");
        scanf("%s",str);
        if(!strcmp(str, "Surrender") || !strcmp(str, "surrender") || !strcmp(str, "SURRENDER"))
        {
            system("surrender1.vbs");
            flag = 2;
            break;
        }
        if(!strcmp(str, "Draw") || !strcmp(str, "draw") || !strcmp(str, "DRAW"))
        {
            if(draw_match())
                break;
            else
            {
                printf("Player 2 Did Not Agree to DRAW, So the WAR continues......\n");
                printf("\n");
                system("nodraw1.vbs");
                system("pause");
                clear();
                draw();
                continue;
            }
        }
        for(int i=0,n=strlen(str);i<n;i++)
        {
            if((str[i] >= 'a' && str[i] <= 'h'))
            {
                a = (int)(str[i] - 'a');
            }
            else if(str[i] >= 'A' && str[i] <= 'H')
            {
                a = (int)(str[i] - 'A');
            }
            if(str[i] >= '1' && str[i] <= '8')
            {
                b = (int)(str[i] - '1');
            }
        }
        if(!strcmp(str, "castling") || !strcmp(str, "Castling") || !strcmp(str, "CASTLING"))
        {
            printf("Enter the Coordinates of Rook : ");
            scanf(" %[^\n]s",str);
            for(int i=0,n=strlen(str);i<n;i++)
            {
                if((str[i] >= 'a' && str[i] <= 'h'))
                {
                    x = (int)(str[i] - 'a');
                }
                else if(str[i] >= 'A' && str[i] <= 'H')
                {
                    x = (int)(str[i] - 'A');
                }
                if(str[i] >= '1' && str[i] <= '8')
                {
                    y = (int)(str[i] - '1');
                }
            }
            if(x < 0 || y > 7 || x < 0 || y > 7 || board[x][y] == 32 || (board[x][y] >= 'A' && board[x][y] <= 'Z'))
            {
                printf("Illegal Piece!\n");
                usleep(2000000);
                clear();
                draw();
                continue;
            }
            a = 0;
            b = 4;
            if(!castling(a, b, x, y))
            {
                printf("Invalid Input!\n");
                usleep(2000000);
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        if(a < 0 || a > 7 || b < 0 || b > 7 || board[a][b] == 32 || (board[a][b] >= 'A' && board[a][b] <= 'Z'))
        {
            printf("Illegal Piece!\n");
            printf("\n");
            system("pause");
            clear();
            draw();
            continue;
        }
        printf("Enter the Coordinates Where You Want to move the Piece: ");
        scanf("%s",str);
        for(int i=0,n=strlen(str);i<n;i++)
        {
            if((str[i] >= 'a' && str[i] <= 'h'))
            {
                x = (int)(str[i] - 'a');
            }
            else if(str[i] >= 'A' && str[i] <= 'H')
            {
                x = (int)(str[i] - 'A');
            }
            if(str[i] >= '1' && str[i] <= '8')
            {
                y = (int)(str[i] - '1');
            }
        }
        if(!strcmp(str, "Surrender") || !strcmp(str, "surrender") || !strcmp(str, "SURRENDER"))
        {
            system("surrender1.vbs");
            flag = 2;
            break;
        }
        if(board[x][y] >= 'a' && board[x][y] <= 'z')
        {
            printf("You cannot kill your own Army!!\n");
            printf("\n");
            system("pause");
            clear();
            draw();
            continue;
        }
        if(board[a][b] == 'p')
        {
            if(!pawn(a, b, x, y))
            {
                printf("Illegal Move!\n");
                printf("\n");
                system("pause");
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        else if(board[a][b] == 'h')
        {
            if(!knight(a, b, x, y))
            {
                printf("Illegal Move!\n");
                printf("\n");
                system("pause");
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        else if(board[a][b] == 'k')
        {
            if(!king(a, b, x, y))
            {
                printf("Illegal Move!\n");
                printf("\n");
                system("pause");
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        else if(board[a][b] == 'r')
        {
            if(!rook(a, b, x, y))
            {
                printf("Illegal Move!\n");
                printf("\n");
                system("pause");
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        else if(board[a][b] == 'b')
        {
            if(!bishop(a, b, x, y))
            {
                printf("Illegal Move!\n");
                printf("\n");
                system("pause");
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        else if(board[a][b] == 'q')
        {
            if(!queen(a, b, x, y))
            {
                printf("Illegal Move!\n");
                printf("\n");
                system("pause");
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        else
        {
            printf("Invalid Selection!\n");
            printf("\n");
            system("pause");
            clear();
            draw();
            continue;
        }
    }
}

/**
 * Player 2
 */
void player2()
{
    char* str = (char*)malloc(10*sizeof(char));
    int a,b,x=0,y=0;
    while(true)
    {
        printf("Player 2:");
        system("player2.vbs");
        printf("\nEnter The Coordinates Of the Piece You Want to Move: ");
        scanf("%s",str);
        for(int i=0,n=strlen(str);i<n;i++)
        {
            if((str[i] >= 'a' && str[i] <= 'h'))
            {
                a = (int)str[i] - 'a';
            }
            else if(str[i] >= 'A' && str[i] <= 'H')
            {
                a = (int)str[i] - 'A';
            }
            if(str[i] >= '1' && str[i] <= '8')
            {
                b = (int)str[i] - '1';
            }
        }
        if(!strcmp(str, "Surrender") || !strcmp(str, "surrender") || !strcmp(str, "SURRENDER"))
        {
            system("surrender2.vbs");
            flag = 1;
            break;
        }

        if(!strcmp(str, "Draw") || !strcmp(str, "draw") || !strcmp(str, "DRAW"))
        {
            if(draw_match())
                break;
            else
            {
                printf("Player 1 Did Not Agree to DRAW, So the WAR continues......\n");
                printf("\n");
                system("nodraw2.vbs");
                system("pause");
                clear();
                draw();
                continue;
            }
        }

        if(!strcmp(str, "castling") || !strcmp(str, "Castling") || !strcmp(str, "CASTLING"))
        {
            printf("Enter the Coordinates of Rook : ");
            scanf(" %[^\n]s",str);
            for(int i=0,n=strlen(str);i<n;i++)
            {
                if((str[i] >= 'a' && str[i] <= 'h'))
                {
                    x = (int)(str[i] - 'a');
                }
                else if(str[i] >= 'A' && str[i] <= 'H')
                {
                    x = (int)(str[i] - 'A');
                }
                if(str[i] >= '1' && str[i] <= '8')
                {
                    y = (int)(str[i] - '1');
                }
            }
            if(x < 0 || x > 7 || y < 0 || y > 7 || board[x][y] == 32 || (board[x][y] >= 'a' && board[x][y] <= 'z'))
            {
                printf("Illegal Piece!\n");
                usleep(2000000);
                clear();
                draw();
                continue;
            }
            a = 7;
            b = 4;
            if(!castling(a, b, x, y))
            {
                printf("Invalid Input!\n");
                usleep(2000000);
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }

        if(a < 0 || a > 7 || b < 0 || b > 7 || board[a][b] == 32 || (board[a][b] >= 'a' && board[a][b] <= 'z'))
        {
            printf("Illegal Piece!\n");
            printf("\n");
            system("pause");
            clear();
            draw();
            continue;
        }
        printf("Enter the Coordinates Where You Want to move the Piece: ");
        scanf("%s",str);
        for(int i=0,n=strlen(str);i<n;i++)
        {
            if((str[i] >= 'a' && str[i] <= 'h'))
            {
                x = (int)(str[i] - 'a');
            }
            else if(str[i] >= 'A' && str[i] <= 'H')
            {
                x = (int)(str[i] - 'A');
            }
            if(str[i] >= '1' && str[i] <= '8')
            {
                y = (int)(str[i] - '1');
            }
        }
        if(!strcmp(str, "Surrender") || !strcmp(str, "surrender") || !strcmp(str, "SURRENDER"))
        {
            system("surrender2.vbs");
            flag = 1;
            break;
        }
        if(board[x][y] >= 'A' && board[x][y] <= 'Z')
        {
            printf("You cannot kill your own Army!!\n");
            printf("\n");
            system("pause");
            clear();
            draw();
            continue;
        }
        if(board[a][b] == 'P')
        {
            if(!pawn( a, b, x, y))
            {
                printf("Illegal Move!\n");
                printf("\n");
                system("pause");
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        else if(board[a][b] == 'H')
        {
            if(!knight(a, b, x, y))
            {
                printf("Illegal Move!\n");
                printf("\n");
                system("pause");
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        else if(board[a][b] == 'K')
        {
            if(!king(a, b, x, y))
            {
                printf("Illegal Move!\n");
                printf("\n");
                system("pause");
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        else if(board[a][b] == 'R')
        {
            if(!rook(a, b, x, y))
            {
                printf("Illegal Move!\n");
                printf("\n");
                system("pause");
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        else if(board[a][b] == 'B')
        {
            if(!bishop(a, b, x, y))
            {
                printf("Illegal Move!\n");
                printf("\n");
                system("pause");
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        else if(board[a][b] == 'Q')
        {
            if(!queen(a, b, x, y))
            {
                printf("Illegal Move!\n");
                printf("\n");
                system("pause");
                clear();
                draw();
                continue;
            }
            else
            {
                clear();
                draw();
                break;
            }
        }
        else
        {
            printf("Invalid Selection!\n");
            printf("\n");
            system("pause");
            clear();
            draw();
            continue;
        }
    }
}

/**
 * Checks for Castling and does the same if possible
 */
bool castling(int a, int b, int x, int y)
{
    if(cast == 0)
    {
        if(board[a][b] == 'k')
        {
            if(board[x][y] == 'r' && y == 0)
            {
                for(int i = y+1;i<b;i++)
                {
                    if(board[x][i] != 32)
                    {
                        return false;
                    }
                }
                board[0][1] = 'k';
                board[0][2] = 'r';
                board[a][b] = 32;
                board[x][y] = 32;
                return true;
            }
            else if(board[x][y] == 'r')
            {
                for(int i = b+1;i<y;i++)
                {
                    if(board[x][i] != 32)
                    {
                        return false;
                    }
                }
                board[0][6] = 'k';
                board[0][5] = 'r';
                board[a][b] = 32;
                board[x][y] = 32;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(board[a][b] == 'K')
        {
            if(board[x][y] == 'R' && y == 0)
            {
                for(int i = y+1;i<b;i++)
                {
                    if(board[x][i] != 32)
                    {
                        return false;
                    }
                }
                board[7][1] = 'K';
                board[7][2] = 'R';
                board[a][b] = 32;
                board[x][y] = 32;
                return true;
            }
            else if(board[x][y] == 'R')
            {
                for(int i = b+1;i<y;i++)
                {
                    if(board[x][i] != 32)
                    {
                        return false;
                    }
                }
                board[7][6] = 'K';
                board[7][5] = 'R';
                board[a][b] = 32;
                board[x][y] = 32;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
            return false;
    }
    else
    {
        return false;
    }
    return true;
}


/**
 * Moves the Pawn on the Chess Board
 */
bool pawn(int a,int b,int x,int y)
{
    char* str = (char*)malloc(15*sizeof(char));
    if(board[a][b] == 'P')
    {
        if(x == a - 1 && y == b - 1 && board[x][y] == 32)
        {
            if(board[a][b-1] == 'p' && board[a+1][b-1] == 'P')
            {
                board[a][b-1] = 32;
                board[x][y] = 'P';
                board[a][b] = 32;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(x == a - 1 && y == b + 1 && board[x][y] == 32)
        {
            if(board[a][b+1] == 'p' && board[a+1][b+1] == 'P')
            {
                board[a][b-1] = 32;
                board[x][y] = 'P';
                board[a][b] = 32;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((x == a-1 && y == b - 1 && board[x][y] != 32) || (x == a-1 && y == b + 1 && board[x][y] != 32))
        {
            if(board[x][y] == 'k')
            {
                flag = 2;
                //player2wins();
            }
            if(x == 0)
            {
                printf("Hard Work of Your Pawn Has Payed Off!!!\nPromote This Pawn!\nPromote To : ");
                system("promote.vbs");
                scanf("%s",str);
                if(str[0] == 'q' || str[0] == 'Q')
                    {
                    board[x][y] = 'Q';
                    board[a][b] = 32;
                }
                else if(str[0] == 'r' || str[0] == 'R')
                {
                    board[x][y] = 'R';
                    board[a][b] = 32;
                }
                else if(str[0] == 'k' || str[0] == 'K')
                {
                    board[x][y] = 'H';
                    board[a][b] = 32;
                }
                else if(str[0] == 'b' || str[0] == 'B')
                {
                    board[x][y] = 'B';
                    board[a][b] = 32;
                }
                return true;
            }
            else
            {
                board[x][y] = 'P';
                board[a][b] = 32;
                return true;
            }
            return true;
        }
        else if(x == a-1 && y == b && board[x][y] == 32)
        {
            if(board[x][y] == 'k')
            {
                flag = 2;
                //player2wins();
            }
            if(x == 0)
            {
                printf("Hard Work of Your Pawn Has Payed Off!!!\nPromote This Pawn!\nPromote To : ");
                scanf("%s",str);
                if(str[0] == 'q' || str[0] == 'Q')
                    {
                    board[x][y] = 'Q';
                    board[a][b] = 32;
                }
                else if(str[0] == 'r' || str[0] == 'R')
                {
                    board[x][y] = 'R';
                    board[a][b] = 32;
                }
                else if(str[0] == 'k' || str[0] == 'K')
                {
                    board[x][y] = 'H';
                    board[a][b] = 32;
                }
                else if(str[0] == 'b' || str[0] == 'B')
                {
                    board[x][y] = 'B';
                    board[a][b] = 32;
                }
                return true;
            }
            else
            {
                board[x][y] = 'P';
                board[a][b] = 32;
                return true;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(board[a][b] == 'p')
    {
        if(x == a + 1 && y == b - 1 && board[x][y] == 32)
        {
            if(board[a][b-1] == 'P' && board[a-1][b+1] == 'p')
            {
                board[a][b-1] = 32;
                board[x][y] = 'p';
                board[a][b] = 32;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(x == a + 1 && y == b + 1 && board[x][y] == 32)
        {
            if(board[a][b+1] == 'P' && board[a+1][b+1] == 'p')
            {
                board[a][b+1] = 32;
                board[x][y] = 'p';
                board[a][b] = 32;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((x == a+1 && y == b - 1 && board[x][y] != 32) || (x == a+1 && y == b + 1 && board[x][y] != 32))
        {
            if(board[x][y] == 'K')
            {
                flag = 1;
                //player1wins();
            }

            if(x == 7)
            {
                printf("Hard Work of Your Pawn Has Payed Off!!!\nPromote This Pawn!\nPromote To : ");
                scanf("%s",str);
                if(str[0] == 'q' || str[0] == 'Q')
                    {
                    board[x][y] = 'q';
                    board[a][b] = 32;
                }
                else if(str[0] == 'r' || str[0] == 'R')
                {
                    board[x][y] = 'r';
                    board[a][b] = 32;
                }
                else if(str[0] == 'k' || str[0] == 'K')
                {
                    board[x][y] = 'h';
                    board[a][b] = 32;
                }
                else if(str[0] == 'b' || str[0] == 'B')
                {
                    board[x][y] = 'b';
                    board[a][b] = 32;
                }
                return true;
            }
            else
            {
                board[x][y] = 'p';
                board[a][b] = 32;
                return true;
            }
            return true;
        }
        else if(x == a+1 && y == b && board[x][y] == 32)
        {
            if(board[x][y] == 'K')
            {
                flag = 1;
                //player1wins();
            }

            if(x == 7)
            {
                printf("Hard Work of Your Pawn Has Payed Off!!!\nPromote This Pawn!\nPromote To : ");
                scanf("%s",str);
                if(str[0] == 'q' || str[0] == 'Q')
                    {
                    board[x][y] = 'q';
                    board[a][b] = 32;
                }
                else if(str[0] == 'r' || str[0] == 'R')
                {
                    board[x][y] = 'r';
                    board[a][b] = 32;
                }
                else if(str[0] == 'k' || str[0] == 'K')
                {
                    board[x][y] = 'h';
                    board[a][b] = 32;
                }
                else if(str[0] == 'b' || str[0] == 'B')
                {
                    board[x][y] = 'b';
                    board[a][b] = 32;
                }
                return true;
            }
            else
            {
                board[x][y] = 'p';
                board[a][b] = 32;
                return true;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
        return false;

    return true;
}

/**
 * Moves the Knight on the Chess Board
 */
bool knight(int a, int b, int x, int y)
{
    if(board[a][b] == 'h' || board[a][b] == 'H')
    {
        if((x == a + 2 && y == b - 1) || (x == a + 2 && y == b + 1) || (x == a - 2 && y == b - 1) || (x == a - 2 && y == b + 1))
        {
            if(board[a][b] == 'h')
            {
                if(board[x][y] == 'K')
                {
                    flag = 1;
                    //player1wins();
                }
                board[a][b] = 32;
                board[x][y] = 'h';
                return true;
            }
            else
            {
                if(board[x][y] == 'k')
                {
                    flag = 2;
                    //player2wins();
                }
                board[a][b] = 32;
                board[x][y] = 'H';
                return true;
            }
        }
        else if((x == a + 1 && y == b - 2) || (x == a + 1 && y == b + 2) || (x == a - 1 && y == b - 2) || (x == a - 1 && y == b + 2))
        {
            if(board[a][b] == 'h')
            {
                if(board[x][y] == 'K')
                {
                    flag = 1;
                    //player1wins();
                }
                board[a][b] = 32;
                board[x][y] = 'h';
                return true;
            }
            else
            {
                if(board[x][y] == 'k')
                {
                    flag = 2;
                    //player2wins();
                }
                board[a][b] = 32;
                board[x][y] = 'H';
                return true;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
        return false;
}

/**
 * Moves the King on the Chess Board
 */
bool king(int a, int b, int x, int y)
{
    if(board[a][b] == 'k' || board[a][b] == 'K')
    {
        cast = 1;
        if((x == a + 1 && y == b) || (x == a && y == b + 1) || (x == a && y == b - 1) || (x == a - 1 && y == b))
        {
            if(board[a][b] == 'k')
            {
                if(board[x][y] == 'K')
                {
                    flag = 1;
                    //player1wins();
                }
                board[a][b] = 32;
                board[x][y] = 'k';
                return true;
            }
            else
            {
                if(board[x][y] == 'k')
                {
                    flag = 2;
                    //player2wins();
                }
                board[a][b] = 32;
                board[x][y] = 'K';
                return true;
            }
        }
        else if((x == a + 1 && y == b - 1) || (x == a + 1 && y == b + 1) || (x == a - 1 && y == b - 1) || (x == a - 1 && y == b + 1))
        {
            if(board[a][b] == 'k')
            {
                if(board[x][y] == 'K')
                {
                    flag = 1;
                    //player1wins();
                }
                board[a][b] = 32;
                board[x][y] = 'k';
                return true;
            }
            else
            {
                if(board[x][y] == 'k')
                {
                    flag = 2;
                    //player2wins();
                }
                board[a][b] = 32;
                board[x][y] = 'K';
                return true;
            }
        }
        else
            return false;
    }
    else
        return false;
    return true;
}

/**
 * Moves the Rook on the Chess Board
 */
bool rook(int a, int b, int x, int y)
{
    if(board[a][b] == 'r' || board[a][b] == 'R')
    {
        cast = 1;
        if(x == a)
        {
            if(y > b)
            {
                for(int i=b+1;i<y;i++)
                {
                    if(board[x][i] != 32)
                    {
                        return false;
                    }
                }
            }
            else if(y < b)
            {
                for(int i=b-1;i>y;i--)
                {
                    if(board[x][i] != 32)
                    {
                        return false;
                    }
                }
            }
        }
        else if(y == b)
        {
            if(x > a)
            {
                for(int i=a + 1;i<x;i++)
                {
                    if(board[i][y] != 32)
                    {
                        return false;
                    }
                }
            }
            else if(x < a)
            {
                for(int i=a - 1;i>x;i--)
                {
                    if(board[i][y] != 32)
                    {
                        return false;
                    }
                }
            }
            if(board[a][b] == 'r')
            {
                if(board[x][y] == 'K')
                {
                    flag = 1;
                    //player1wins();
                }
                board[a][b] = 32;
                board[x][y] = 'r';
                return true;
            }
            else
            {
                if(board[x][y] == 'k')
                {
                    flag = 2;
                    //player2wins();
                }
                board[a][b] = 32;
                board[x][y] = 'R';
                return true;
            }
        }
        else
            return false;
    }
    else
        return false;
    return true;
}

/**
 * Moves the Bishop on the Chess Board
 */
bool bishop(int a, int b, int x, int y)
{
    if(board[a][b] == 'b' || board[a][b] == 'B')
    {
        if(x > a)
        {
            if(y > b)
            {
                for(int i = a+1,j = b + 1;i<x;i++,j++)
                {
                    if(board[i][j] != 32)
                    {
                        return false;
                    }
                }
            }
            else if(y < b)
            {
                for(int i = a+1,j = b - 1;i<x;i++,j--)
                {
                    if(board[i][j] != 32)
                    {
                        return false;
                    }
                }
            }
        }
        else if(y > b && x < a)
        {
            for(int i = a-1,j = b + 1;i>x;i--,j++)
            {
                if(board[i][j] != 32)
                {
                    return false;
                }
            }
        }
        else if(y < b && x < a)
        {
            for(int i = a-1,j = b - 1;i>x;i--,j--)
            {
                if(board[i][j] != 32)
                {
                    return false;
                }
            }
        }
        if(board[a][b] == 'b')
        {
            if(board[x][y] == 'K')
            {
                flag = 1;
                //player1wins();
            }
            board[a][b] = 32;
            board[x][y] = 'b';
            return true;
        }
        else
        {
            if(board[x][y] == 'k')
            {
                flag = 2;
                //player2wins();
            }
            board[a][b] = 32;
            board[x][y] = 'B';
            return true;
        }
    }
    else
        return false;
    return true;
}

/**
 * Moves the Queen on the Chess Board
 */
 bool queen(int a, int b, int x, int y)
 {
    if(board[a][b] == 'q' || board[a][b] == 'Q')
    {
        if(x > a && y > b)
        {
            for(int i = a+1,j = b + 1;i<x;i++,j++)
            {
                if(board[i][j] != 32)
                {
                    return false;
                }
            }
        }
        else if( x > a && y < b)
        {
            for(int i = a+1,j = b - 1;i<x;i++,j--)
            {
                if(board[i][j] != 32)
                {
                    return false;
                }
            }
        }
        else if(y > b && x < a)
        {
            for(int i = a-1,j = b + 1;i>x;i--,j++)
            {
                if(board[i][j] != 32)
                {
                    return false;
                }
            }
        }
        else if(y < b && x < a)
        {
            for(int i = a-1,j = b - 1;i>x;i--,j--)
            {
                if(board[i][j] != 32)
                {
                    return false;
                }
            }
        }
        else if(x == a)
        {
            if(y > b)
            {
                for(int i=b+1;i<y;i++)
                {
                    if(board[x][i] != 32)
                    {
                        return false;
                    }
                }
            }
            else if(y < b)
            {
                for(int i=b-1;i>y;i--)
                {
                    if(board[x][i] != 32)
                    {
                        return false;
                    }
                }
            }
        }
        else if(y == b)
        {
            if(x > a)
            {
                for(int i=a + 1;i<x;i++)
                {
                    if(board[i][y] != 32)
                    {
                        return false;
                    }
                }
            }
            else if(x < a)
            {
                for(int i=a - 1;i>x;i--)
                {
                    if(board[i][y] != 32)
                    {
                        return false;
                    }
                }
            }
        }
        else
            return false;
    }
    if(board[a][b] == 'q')
    {
        if(board[x][y] == 'K')
        {
            flag = 1;
            //player1wins();
        }
        board[a][b] = 32;
        board[x][y] = 'q';
        return true;
    }
    else
    {
        if(board[x][y] == 'k')
        {
            flag = 2;
            //player2wins();
        }
        board[a][b] = 32;
        board[x][y] = 'Q';
        return true;
    }
    return true;
}

bool draw_match()
{
    char* str = (char*)malloc(10*sizeof(char));
    while(true)
    {
    printf("Would You too like to make peace with your opponent??['yes' or 'no'] -> ");
    system("drawInput.vbs");
    scanf(" %[^\n]s",str);
    if(!strcmp(str, "YES") || !strcmp(str, "yes") || !strcmp(str, "Yes"))
    {
        flag = 3;
        return true;
    }
    else if(!strcmp(str, "No") || !strcmp(str, "no") || !strcmp(str, "NO"))
    {
        return false;
    }
    else
    {
        printf("Invalid Input!\n");
        printf("\n");
        system("pause");
        clear();
        draw();
        continue;
    }
    }
    free(str);
    return true;
}
