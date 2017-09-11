#define _XOPEN_SOURCE 500

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>

//Constants
#define MIN_DIM 4
#define MAX_DIM 9

//Grid or board
int board[MAX_DIM][MAX_DIM];

//Dimension
int d;

//Seed for srand48
int seed;

//Name of the user
char* name;

//Coordinates of submarines
int x, y;

//prototypes
void clear(void);
void greet(void);
int battleship(void);
void intro(void);
void init(void);
int logo(void);
void draw(void);
void subm(void);
bool attack(int pos1,int pos2);
bool won(int pos1, int pos2);

int main(void)
{
    //Greets the player to the game
    greet();

    //Introduction of the game
    intro();

    //Initializes the board game
    init();

    while(true)
    {
        //Clears the screen
        clear();

        //Drawing the board before or after the move
        draw();

        printf("Location for Bombing (x, y): ");
        int locate1,locate2;
        scanf("%d,%d",&locate1,&locate2);

        if(!attack(locate1, locate2))
        {
            printf("\nOut of Bounds! Enemies are in the OCEAN!\n");
            system("pause");
        }

        if(won(locate1, locate2))
        {
            clear();
            printf("\n\n\n\n\n");
            printf("%33s \n\n%33s\n\n\n","Congratulations, Soldier!","You Saved Your Country!!");
            logo();
            printf("\n\n");
            break;
        }
        else
        {
            printf("Missed!\n");
            system("pause");
        }

    }
    printf("\n");
    system("pause");
    free(name);
    return 0;
}

void clear(void)
{
    system("cls");
}

void greet(void)
{
    clear();
    //Displays the ship (For good looking of the game!)
    battleship();

    printf("\t\t WELCOME TO THE BATTLESHIP!\n");

    printf("\n\t\tEnter Your Name: ");
    name = (char*)malloc(10240*sizeof(char));
    scanf(" %[^\n]s",name);
    int pin;
    printf("\n\t\tEnter Your Pin Number: ");
    scanf("%d",&pin);
    seed = strlen(name) + pin;
    printf("\n\n\n");
    system("pause");
}

/**
 * Image of the battleship
 */
int battleship(void)
{
    FILE* fp = fopen("Battleship.txt", "r");
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
    printf("\n");

    fclose(fp);
    return 0;
}

/**
 * Gives the introduction for the story of the game
 */

void intro(void)
{
    clear();
    battleship();

    printf("\tWhile you where on the daily Patroling of the sea,");
    printf("\nYou came to know that the enemy submarines are advancing towards your harbour......\n\tBut unfortunatly you don't know their exact position.....\n");
    printf("\n");
    system("pause");
    clear();
    battleship();
    printf("You are assigned the task to eliminate the enemy Submarines by bombing the Ocean.....\n\t\t\tGood Luck, Soldier!\n");
    printf("\n");
    system("pause");
}

/**
 * Draws the logo of the ship
 */
 int logo(void)
 {
    FILE* fp = fopen("Logo.txt", "r");
    if(fp == NULL)
    {
        printf("\t\tError opening the Logo!\n");
        return 1;
    }

    int spc = (d*6 + 6 - 5 - 15)/2;
    char output[256];
    for(int i = 1;fgets(output, sizeof(output), fp) != NULL;i++)
    {
        for(int j = 0;j < spc;j++)
            printf("%c",32);
        printf("%s", output);
    }
    printf("\n");

    fclose(fp);
    return 0;
 }
/**
 * Initializes the board
 */
void init(void)
{
    //Ensures the input is within the range
    do
    {
        printf("Length of the Ocean (Between %d x %d and %d x %d inclusive): ",MIN_DIM,MIN_DIM,MAX_DIM,MAX_DIM);
        scanf(" %d",&d);
    }
    while(!(d >= MIN_DIM && d <= MAX_DIM) );
    for(int i = d -1;i >= 0;i--)
    {
        for(int j = d - 1;j >= 0;j--)
        {
            board[i][j] = 94;
        }
    }
    subm();
}

/**
 * Sets the position of Submarine in the sea
 */
void subm(void)
{
    srand((long int)seed);
    while(true)
    {
        for(int i=0;i<d;i++)
        {
            y = (int)(rand());
            x = (int)(rand());
            y = y%10;
            x = x%10;
        }
        if(x < d && y < d && x > 0 && y > 0)
            break;
    }
    printf("(x, y) = (%d, %d)\n",x,y);
    system("pause");
}

/**
 * Draws the current state of the board
 */
void draw(void)
{
    int space = d*6 + 6 + 2 - 9 - strlen(name);
    for(int i=0;i < space;i++)
    {
        printf(" ");
    }
    printf("Soldier: %s\n\n",name);

    int spc2 = (d*6 + 6 - 5)/2;
    for(int i=0;i<=spc2/2;i++)
    {
        printf("~ ");
    }
    printf("OCEAN");
    for(int i=0;i<=spc2/2;i++)
    {
        printf("~ ");
    }
    printf("\n\n");

    printf("  ");
    for(int m=0;m<d;m++)
    {
        printf("%5d ",m);
    }
    printf("\n");
    for(int i = 0;i < d;i++)
    {
        printf("%2d ",i);
        for(int j = 0;j < d;j++)
            printf("~~ %c ~",board[i][j]);
        printf("%3d ",i);
        printf("\n");
    }
    printf("  ");
    for(int i = 0;i < d;i++)
    {
        printf("%5d ",i);
    }
    printf("\n\n");
    int spc = (d*6 + 6 - 7)/2;
    for(int i=0;i<=spc;i++)
    {
        printf("-");
    }
    printf("HARBOUR");
    for(int i=0;i<=spc;i++)
    {
        printf("-");
    }
    printf("\n\n");
}

/**
 * If bombs within the ocean, return true,
 * else return false
 */
bool attack(int locate1, int locate2)
{
    if(!(locate1 >= 0 && locate1 < d) || !(locate2 >= 0 && locate2 < d))
    {
        return false;
    }
    else
        return true;
    return true;
}

bool won(int locate1, int locate2)
{
    if(x == locate1 && y == locate2)
    {
        return true;
    }
    else if(locate1 != x || locate2 != y)
    {
        board[locate2][locate1] = 35;
        return false;
    }
    return true;
}

