#include "dungeon_header.h"
#include "movement.h"
#include <iostream>

int getMove (int current_floor, int current_x, int current_y, int bounds, bool boulder_carry)
/*
a) Input – current location
b) Function – input a move code and validate it (valid code, move inside dungeon)
c) Return – the move code
*/
{
    const char  UPPERWEST               = 'A',
                LOWERWEST               = 'a',
                NUMERICWEST             = '4',
            // westward motion
                UPPERNORTH              = 'W',
                LOWERNORTH              = 'w',
                NUMERICNORTH            = '8',
            // northward motion
                UPPEREAST               = 'D',
                LOWEREAST               = 'd',
                NUMERICEAST             = '6',
            // eastward motion
                UPPERSOUTH              = 'S',
                LOWERSOUTH              = 's',
                NUMERICSOUTH            = '2',
            // southern motion
                UPPERCASEQUIT           = 'Q',
                LOWERCASEQUIT           = 'q',
            // quit game
                UPPERCASEHELP           = 'H',
                LOWERCASEHELP           = 'h',
            // access help menu
                UPPERCASERIDOFROCK      = 'R',
                LOWERCASERIDOFROCK      = 'r';
            // set down your small boulder (in a different room)

    bool move_accepted = false;

    char target_movement;

    do
    {
        std::cout   <<  "In which direction would you like to move?\n"
                        "(To review controls press H.  To quit press Q.";
        if (boulder_carry)
        {
            std::cout <<    "\nTo get rid of your boulder, press R.";
        }

        std::cout   <<  ")\n\n";

        std::cin >> target_movement;

        switch (target_movement)
        {
            case UPPERNORTH:
            case LOWERNORTH:
            case NUMERICNORTH:
                return NORTH;
            // all north options lead to north

            case UPPERWEST:
            case LOWERWEST:
            case NUMERICWEST:
                return WEST;
            // all west options lead to west

            case UPPERSOUTH:
            case LOWERSOUTH:
            case NUMERICSOUTH:
                return SOUTH;
            // all south options lead to south

            case UPPEREAST:
            case LOWEREAST:
            case NUMERICEAST:
                return EAST;
            // all east options lead to east

            case UPPERCASEQUIT:
            case LOWERCASEQUIT:
                return QUIT;
            // all quit options lead to quit

            case UPPERCASEHELP:
            case LOWERCASEHELP:
                return HELP;
            // all help options lead to help

            case UPPERCASERIDOFROCK:
            case LOWERCASERIDOFROCK:
                return RID_BOULDER;

            default:
                std::cout << "You have entered an invalid choice.\n";
        }
    } while (!move_accepted);
}

void moveTarget (int &object_x, int &object_y, int movement)
/*
    changes the position for an object
*/
{
    switch (movement)
    {
        case NORTH:
            object_x -= 1;
            break;
        case WEST:
            object_y -= 1;
            break;
        case SOUTH:
            object_x += 1;
            break;
        case EAST:
            object_y += 1;
            break;
        default:
            std::cout   <<  "I haven't the foggiest notion how you managed to get here, but you shouldn't have.\n"
                            "Program will now terminate.\n";
            exit(EXIT_FAILURE);
            break;
    }
}

void takeStairs (int &current_floor, int current_x, int current_y, char stairs)
/*
    goes up or down stairs

*/
{
    switch (stairs)
    {
        case UP:
        {
            current_floor -= 1;
            break;
        }
        case DOWN:
        {
            current_floor += 1;
            break;
        }
        default:
            break;
    }
}

void updateFloor (std::string dungeon[][MAX_SIZE][MAX_SIZE],int current_floor, int &object_x, int &object_y, int movement, std::string prev_square, std::string new_square)
/*
    updates the state of the current floor of the dungeon
*/
{
    int temp_x = object_x,
        temp_y = object_y;

    dungeon[current_floor][object_x][object_y] = prev_square;
    moveTarget(object_x, object_y, movement);
    dungeon[current_floor][object_x][object_y] = new_square;

    if (prev_square == PLAYER)
    {
        object_x = temp_x;
        object_y = temp_y;
    }
}

void updateStairs (std::string dungeon[][MAX_SIZE][MAX_SIZE],int &current_floor, int object_x, int object_y, char stairs, std::string prev_square, std::string new_square)
/*
    changes floors and preserves stair location
*/
{
    dungeon[current_floor][object_x][object_y] = prev_square;
    takeStairs(current_floor, object_x, object_y, stairs);
    dungeon[current_floor][object_x][object_y] = new_square;
}

void updateDungeon (std::string dungeon[][MAX_SIZE][MAX_SIZE], int movement, char stairs, int &current_floor, int &object_x, int &object_y, std::string prev_square, std::string new_square)
/*
a) Input – the dungeon and move code
b) Function – update the dungeon moving the player marker
c) Return – the updated dungeon
*/
{
    if (stairs != EMPTY && new_square == PLAYER)
    {
        updateFloor(dungeon, current_floor, object_x, object_y, movement, EMPTY_SPACE, PLAYER);
        updateStairs(dungeon, current_floor, object_x, object_y, stairs, prev_square, new_square);
    }
    else
    {
        updateFloor(dungeon, current_floor, object_x, object_y, movement, prev_square, new_square);
    }
}
