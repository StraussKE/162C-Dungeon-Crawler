#ifndef TEXT_TABLES_H_INCLUDED
#define TEXT_TABLES_H_INCLUDED

#include <iostream>

#include "dungeon_header.h"

void starBar ();
/*
    Used for visually dividing output for greater user readability
    It's a line of asterisks. There's a newline character at the end.
    That's it, really.  Nothing special in any way here.
*/

void hitWall (std::string moving_object);
/*
    For the inevitable moment the user decides to venture through a perimeter wall.
    Random number triggers a switch which leads to a remark about their attempt to pass the wall being returned via cout
    Not really anything here but randomized sass.
*/

void boulderPlay (std::string target_object);
/*
    When carrying around small rocks life can be a bit challenging.
    These are the responses given when trying to take your new pet rock into different scenarios.

    accepts the object in the square you are attempting to move your boulder into
    outputs some words
    fin (that's end)
*/

void hitTrap (std::string moving_object);
/*
    Dungeons are full of traps.  Eventually someone or something is going to run into one.
    When that happens they'd probably like to know how they died.
    If a monster dies in a trap, does the player hear anything?
    If they defuse a trap using a stone, what did they narrowly avoid?

    Accepts the type of moving object so as to enter the correct switch statement for output text.
    Randomly selects a text blurb to report back to the user.
    Returns that text blurb.
*/

void bigBoulder();
/*
    big rocks have stories too!
*/

#endif // TEXT_TABLES_H_INCLUDED
