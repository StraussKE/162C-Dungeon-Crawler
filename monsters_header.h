#ifndef MONSTERS_HEADER_H_INCLUDED
#define MONSTERS_HEADER_H_INCLUDED

#include "dungeon_header.h"

void goblinTurn (string (&dungeon)[MAX_SIZE][MAX_SIZE][MAX_SIZE], int bounds, int current_floor, int &monster_x, int &monster_y);
/*
    moves goblins according to their movement algorithm.
*/

#endif // MONSTERS_HEADER_H_INCLUDED
