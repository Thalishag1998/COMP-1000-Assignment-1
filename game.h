#ifndef GAME_H
#define GAME_H

void printmap(char** map, int map_row, int map_col);
void printcolor(char** map, int map_row, int map_col, int goal_row, int goal_col, int box_col, int box_row);
int wining(int* new_box_row, int* new_box_col, int* goal_row, int* goal_col);

#endif