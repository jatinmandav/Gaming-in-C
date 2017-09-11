/**
 * 
 * #CodingOf208
 * 
 * The Quiz Master!
 * Mandav's Blog
 * 
 * By - Jatin Kumar Mandav
 * Linux Based System
 * 
 * Add Questions, Add Categories
 * Play in Single as well as V/S Mode with your friend
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
#include<stdbool.h>
#include<unistd.h>
#include<math.h>
#include<ctype.h>

void clear();
int greet();
int instruct();
int play();
int add_ques();

void disp_score();
char* category;
char* cat_ans;
int score = 0;
float accuracy = 0;
int attempts = 0;
int correct = 0;

int p1;
int p2;

int main(void)
{
    clear();
    greet();
    int n=1;
    while(true)
    {
        clear();
        int s;
        printf("----------------------------------------------------------------------------------------------");
        printf("\n\n\n\t1. Start The Quiz\t\t 2. Add Questions\t\t 3. Exit \n\n\n");
        printf("----------------------------------------------------------------------------------------------");
        printf("\n\n\t\t\tChoice : ");
        scanf(" %d",&s);
        clear();
        if(s == 1)
        {
            printf("----------------------------------------------------------------------------------------------");
            printf("\n\n\n\t1. Single Player\t\t 2. V/S Mode\t\t 3. Exit \n\n\n");
            printf("----------------------------------------------------------------------------------------------");
            printf("\n\n\t\t\tChoice : ");
            scanf(" %d",&n);
            if(n == 1)
                play();
            else if(n == 2)
            {
                printf("\n\n\t\t--------------------Player 1------------------\n\n\n");
                usleep(2000000);
                play();
                p1 = score;
                score = 0;
                printf("\n\n\t\t--------------------Player 2------------------\n\n\n");
                usleep(2000000);
                play();
                p2 = score;
                if(p1 > p2)
                    printf("\n\n\t\tCongratulations\n\t\tPlayer 1 Wins!\n\n");
                else if(p1 < p2)
                    printf("\n\n\t\tCongratulations\n\t\tPlayer 2 Wins!\n\n");
                else
                    printf("\n\n\t\tThe Match Is Draw!\n\n");
            }
            else
            {
                printf("Invalid Input!\n");
                break;
            }
            usleep(2000000);
            break;
        }
        else if(s == 3)
        {
            break;
        }
        else if(s == 2)
        {
            add_ques();
        }
        else
        {
            printf("Invalid Input!\n");
            usleep(2000000);
            continue;
        }
    }
    if(n == 1)
        disp_score();
    return 0;
}

void clear()
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

int greet()
{
    printf("\t\t\t\t\t\tWELCOME TO THE QUIZ!\n\n");
    FILE* fp = fopen("logo.txt", "r");
    if(fp == NULL)
    {
        printf("ERROR OPENING THE IMAGE!\n\n");
        usleep(2000000);
        return 1;
    }
    char output[256];
    for(int i=1;fgets(output, sizeof(output), fp) != NULL;i++)
    {
        printf("\t\t\t\t%s",output);
    }
    printf("\n\n\t\t\t\tLoading the Quiz . .");
    for(int i=0;i<5;i++)
    {
        printf(" . .");
        usleep(1000000);
    }
    fclose(fp);
    return 0;
}

int add_ques()
{
    FILE* fp3 = fopen("categories.txt", "r");
    category = (char*)malloc(10240*sizeof(char));
    cat_ans = (char*)malloc(10240*sizeof(char));
    while(true)
    {
        clear();
        if(fp3 == NULL)
        {
            printf("ERROR OPENING THE FILE!\n");
            usleep(2000000);
            return 1;
        }
        printf("\n\t\t1 . Add to Existing one\t\t 2. Create a New Category\n");
        int choice;
        printf("\n\t\tYour Choice : ");
        scanf(" %d",&choice);
        if(choice == 2)
        {
            fclose(fp3);
            fp3 = fopen("categories.txt","a");
            printf("Enter the Name of New Category (Case-Sensitive) : ");
            scanf(" %[^\n]s",category);
            fputs(category, fp3);
            fputs("\n", fp3);
            fclose(fp3);
            printf("Creating New Category . .");
            for(int i=0;i<3;i++)
            {
                printf(" . .");
                usleep(1000000);
            }
            printf("\n\tCategory Successfully Created!\n");
            usleep(2000000);
            continue;
        }
        else if(choice != 1)
        {
            printf("Invalid Input!");
            usleep(2000000);
            continue;;
        }
        else if(choice == 1)
            break;
    }
    clear();
    fp3 = fopen("categories.txt", "r");
    char output[256];
    for(int i=1;fgets(output, sizeof(output), fp3) != NULL;i++)
    {
        printf("\t%s\n",output);
    }
    printf("Pick Your Category (Case-Sensitive): ");
    scanf(" %[^\n]s",category);
    strcpy(cat_ans, category);
    strcat(cat_ans, "a.txt");
    strcat(category, ".txt");
    FILE* fp = fopen(category, "a");
    FILE* fp2 = fopen(cat_ans, "a");
    if(fp == NULL || fp2 == NULL)
    {
        printf("ERROR OPENING THE FILE!\n");
        usleep(2000000);
        return 1;
    }
    while(true)
    {
        clear();
        printf("Enter The Question (or \"quit\") : ");
        char* ques = (char*)malloc(10240*sizeof(char));
        scanf(" %[^\n]s",ques);
        if(strlen(ques) == 4)
        {
            int i=0;
            while(ques[i] != '\0')
            {
                ques[i] = tolower(ques[i]);
                i++;
            }
        }
        if(!strcmp(ques, "quit"))
        {
            free(ques);
            break;
        }
        fprintf(fp, "Q> %s\n",ques);
        for(int i=0;i<4;i++)
        {
            printf("Enter Option %d : ",i+1);
            fprintf(fp, "%d. ",i+1);
            char* ans = (char*)malloc(10240*sizeof(char));
            scanf(" %[^\n]s",ans);
            fputs(ans, fp);
            fputs("\n",fp);
            free(ans);
        }
        char* cor_opt = (char*)malloc(10*sizeof(char));
        printf("Enter The Correct Option of The Question : ");
        scanf(" %[^\n]s",cor_opt);
        fprintf(fp2, "%s\n",cor_opt);
        free(cor_opt);
        free(ques);
    }
            fclose(fp);
            fclose(fp2);
            fclose(fp3);
    return 0;
}

int play()
{
    clear();
    category = (char*)malloc(10240*sizeof(char));
    cat_ans = (char*)malloc(10240*sizeof(char));
    FILE* fp3 = fopen("categories.txt", "r");
    if(fp3 == NULL)
    {
        printf("ERROR OPENING THE FILE!\n");
        usleep(2000000);
        return 1;
    }
    char o[256];
    for(int i=1;fgets(o, sizeof(o),fp3) != NULL;i++)
    {
        printf("\t%s\n",o);
    }
    printf("Pick Your Category (Case - Sensitive) : ");
    scanf(" %[^\n]s",category);
    strcpy(cat_ans, category);
    strcat(cat_ans, "a.txt");
    strcat(category, ".txt");
    printf("%50s : %d | %10s : %.2f\n", "Score", score,"Accuracy", accuracy);
    FILE* fp = fopen(category, "r");
    FILE* fp2 = fopen(cat_ans, "r");
    if(fp == NULL || fp2 == NULL)
    {
        clear();
        printf("\n\n\t\t\tERROR OPENING THE FILE!\n");
        usleep(2000000);
        return 1;
    }
    char* s[5];
    int user_ans,cor_ans,flag = 0,exit1 = 0;
    while(true)
    {
        clear();
        if(attempts == 0)
            accuracy = 0;
        else
        {
            accuracy = ((float)correct/attempts*100);
        }
        printf("%50s : %d | %s : %.2f\n", "Score", score,"Accuracy", accuracy);
        if(flag == 0)
        {
            char output[256];
            for(int i=0;i<5;i++)
            {
                s[i] = (char*)malloc(10240*sizeof(char));
                fgets(output, sizeof(output), fp);
                if(feof(fp))
                {
                    exit1 = 1;
                    break;
                }
                strcpy(s[i], output);
            }
            if(exit1 == 1)
            {
                break;
            }
            char output2[10];
            fgets(output2, sizeof(output2), fp2);
            cor_ans = atoi(output2);
            flag = 1;
        }
        for(int i=0;i<5;i++)
        {
            printf("%s",s[i]);
        }
        printf("\nYour Answer : ");
        scanf(" %d",&user_ans);
        if(user_ans != cor_ans)
        {
            clear();
            printf("%50s : %d | %s : %.2f\n", "Score", score,"Accuracy", accuracy);
            for(int i=0;i<5;i++)
            {
                if(i == user_ans)
                {
                    score--;
                    attempts++;
                    printf("\x1B[31m%s\x1B[0m",s[i]);
                    continue;
                }
                printf("%s",s[i]);
            }
            usleep(2000000);
        }
        else
        {
            clear();
            printf("%50s : %d | %s : %.2f\n", "Score", score,"Accuracy", accuracy);
            for(int i=0;i<5;i++)
            {
                if(i == user_ans)
                {
                    score = score + 4;
                    attempts++;
                    correct++;
                    printf("\x1B[32m%s\x1B[0m",s[i]);
                    continue;
                }
                printf("%s",s[i]);
            }
            flag = 0;
            usleep(2000000);
        }
    }
    return 0;
}

void disp_score()
{
    clear();
    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf(" ");
    }
    for(int i=0;i<61;i++)
    {
        printf("-");
    }
    printf("\n");
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf(" ");
        }
        printf("|");
        if(i == 3)
        {
            printf("%30s : %3d","Your Score", score);
            for(int j=0;j<23;j++)
                printf(" ");
            printf("|");
            printf("\n");
            continue;
        }
        if(i == 4)
        {
            printf("%30s : %6.2f","Your Accuracy",accuracy);
            for(int j=0;j<20;j++)
                printf(" ");
            printf("|");
            printf("\n");
            continue;
        }
        else
        {
            for(int j=0;j<30;j++)
            {
                printf(" ");
            }
        }
        printf("%30c\n",'|');
    }
    for(int i=0;i<5;i++)
    {
        printf(" ");
    }
    for(int i=0;i<61;i++)
    {
        printf("-");
    }
    printf("\n");
    printf("\n");
}