#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include "terminal.h"
#include "color.h"
#include "game.h"



void printmap(char** map, int map_row, int map_col)
{
    int i;
    int j;

    for (i = 0; i < map_row; i++)/*Left Border*/
    {
            map[i][0] = '*';
    }

    for (i = 0; i < map_row; i++)/*Right Border*/
    {
            map[i][map_col - 1] = '*';
    }

    for(i = 0; i < map_col; i++) /*Top border*/
    {
            map[0][i] = '*';
    }

    for (i = 0; i < map_col; i++)/*Bottom Border*/
    {
            map[map_row - 1][i] = '*';
    }        
     
    for(i = 0; i < map_row; i++)
    {
        for(j = 0; j < map_col; j++)
        {
        printf("%c", map[i][j]);
        }
    }
}

void printcolor(char** map, int map_row, int map_col, int goal_row, int goal_col, int box_col, int box_row)
{
    int i;
    int j;
    for(i = 0; i < map_row; i++) /*This gives the color of the background*/
    {
         for(j = 0; j < map_col; j++)
         {
             if(i == goal_row && j == goal_col)
             {
                 if(i == box_row && j == box_col)
                 {
                    setBackground("green");
                 }else
                 {
                    setBackground("red");
                 }
                     }
        }
         printf("%c", map[map_row][map_col]);
    }
}


int wining(int* new_box_row, int* new_box_col, int* goal_row, int* goal_col)
{
    int game_won; 
    if(new_box_row == goal_row && new_box_col == goal_col)
    {
        printf("You won the game\n");
        game_won = 1;
    }
    return game_won;
}