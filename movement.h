#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED

#include <iostream>
#include "dungeon_header.h"

int getMove (int current_floor, int current_x, int current_y, int bounds, bool boulder_carry = false);
/*
    accepts the current location of the player in three dimensions
    requests user decide whether they wish to go left, right, up, or down
    returns a character indicating the user's chosen movement
*/

void moveTarget (int &object_x, int &object_y, int movement);
/*
    changes the position for an object
*/

void takeStairs (int &current_floor, int current_x, int current_y, char stairs);
/*
    goes up or down stairs
*/

void updateStairs (std::string dungeon[][MAX_SIZE][MAX_SIZE], int &current_floor, int current_x, int current_y, char stairs, std::string new_square, std::string prev_square);
/*
    goes up or down stairs
*/

void updateFloor (std::string dungeon[][MAX_SIZE][MAX_SIZE], int current_floor, int &object_x, int &object_y, int movement, std::string new_square, std::string prev_square);
/*
    changes floors and preserves stair location
*/

void updateDungeon (std::string dungeon[][MAX_SIZE][MAX_SIZE], int movement, char stairs, int &current_floor, int &current_x, int &current_y, std::string prev_square, std::string new_square);
/*
a) Input – the dungeon and move code
b) Function – update the dungeon moving the player marker
c) Return – the updated dungeon
*/

#endif // MOVEMENT_H_INCLUDED
