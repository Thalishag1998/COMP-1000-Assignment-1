#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include "game.h"
#include "terminal.h"
#include "color.h"
#include "random.h"


int main(int argc, char* argv[])
{
    
    int i;
    int j;
    int game_won = 0;
    int map_row = atoi(argv[1]);
    int map_col = atoi(argv[2]);
    int player_row = atoi(argv[3]);
    int player_col = atoi(argv[4]);
    int goal_row = atoi(argv[5]);
    int goal_col = atoi(argv[6]);
    int box_row;
    int box_col;
    int new_player_row;
    int new_player_col;
    int new_box_row;
    int new_box_col;
    char input;
    char** map;

    if(argc != 7)
    {
        printf("Error: Incorrect number of arguments.\n");
        return 1;
    }
    if(map_row < 5 || map_col < 5 || player_row < 0 || player_col < 0 || goal_row < 0 || goal_col < 0)
    {
        printf("Error: Incorrect Number of Arguments\n");
        return 1;
    }else if(player_row > map_row || player_col > map_col)
    {
        printf("Error: Out of Bounds\n");
        return 1;
    }else if(goal_row > map_row || goal_col > map_col)
    {
        printf("Error: Out of Bounds\n");
        return 1;       
    }

    map = (char**)malloc(sizeof(char*) * map_row);
    for(i = 0; i < map_row; i++)
    {
        map[i] = (char*)malloc(sizeof(char) * map_col);
    }

    initRandom();

    for(i = 0; i < map_row; i++)
    {
        for(j = 0; j < map_col; j++)
        {
            if(i == player_row && j == player_col)
            {
                map[i][j] = 'P';
            }
            if(i == goal_row && j == goal_col)
            {
                map[i][j] = 'G';
            }

            randomUCP(box_row, box_col);

            if(i == box_row && j == box_col)
            {
                map[i][j] = 'B';
            }
    }

    while(game_won != 1)/*Main game loop*/
    {
    system("clear");
    printmap(map, map_row, map_col);
    printcolor(map, map_row, map_col, goal_row, goal_col, box_row, box_col);

    new_player_row = player_row;
    new_player_col = player_col;

    disableBuffer();
    scanf(" %c", &input);
    enableBuffer();

    if(input == 'w')
    {
        new_player_row--;
    }else if(input == 's')
    {    
        new_player_row++;
    }else if(input == 'a')
    {    
        new_player_col--;
    }else if(input == 'd')
    { 
        new_player_col++;
    }else
    {
        printf("Invalid Key\n");
    }

    if(new_player_row >= 0 && new_player_row < map_row && new_player_col >= 0 && new_player_col < map_col && map[new_player_row][new_player_col] != '*')
        {   
            new_box_row = box_row + (new_player_row - player_row);
            new_box_col = box_col + (new_player_col - player_col);
        }
    
    if(new_player_row != box_row || new_player_col != box_col || (new_box_row >= 0 && new_box_row < map_row && new_box_col >= 0 && new_box_col < map_col && map[new_box_row][new_box_col] != '*'))
        {
            map[player_row][player_col] = ' ';
            player_row = new_player_row;
            player_col = new_box_col;
            map[player_row][player_col] = 'P';

            if(player_row == box_row && player_col == box_col)
            {
                map[box_row][box_col] = ' ';
                box_row = new_box_row;
                box_col = new_box_col;
                map[box_row][box_col] = 'B';
            }
        }
        wining(&new_box_row, &new_box_col, &goal_row, &goal_col);
    }
    }

    for(i = 0; i < map_row; i++)
    {
        free(map[i]);
    }

    free(map);

return 0;
}




 

