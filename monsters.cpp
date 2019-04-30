#include "dungeon_header.h"

/// not currently part of the program.  Working out details before implementation will occur.
// ignore me, please
/*
void goblinTurn (string (&dungeon)[MAX_SIZE][MAX_SIZE][MAX_SIZE], int bounds, int current_floor)
/*
    moves goblins according to their movement algorithm.
*/
/*
{

    int     goblin_x,
            goblin_y,
            movement;

    char movement;

    for (int x = 0; x < bounds; x++)
    {
        for (int y = 0; y < bounds; y++)
        {
            if (dungeon[current_floor][x][y] == GOBLIN)
            {
                goblin_x = x;
                goblin_y = y;
            }
            do
            {
                movement = (rand() % 4);

            } while (outOfBounds(goblin_x, goblin_y, bounds)
                    || !checkMove(dungeon, current_floor, goblin_x, goblin_y, movement, EMPTY_SPACE)
                    || !checkMove(dungeon, current_floor, goblin_x, goblin_y, movement, TRAP))
            if (checkMove(dungeon, current_floor, goblin_x, goblin_y, movement, TRAP))
            {
                cout << "You hear an ear splitting shriek which comes to a terrifyingly abrupt end.\n";
                updateFloor()
            monsterMovement (movement, goblin_x, goblin_y);

        }
    }
}

*/
