#ifndef DUNGEON_HEADER_H_INCLUDED
#define DUNGEON_HEADER_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>


const int           MAX_SIZE                = 19,
                // maximum dimension for dungeon

                    START_POINT             = 0,
                // beginning coordinate

                    TUTORIAL                = 1,
                    EASY                    = 2,
                    NORMAL                  = 3,
                    HARD                    = 4,
                // difficulty levels

                    NORTH                   = 0,
                    WEST                    = 1,
                    SOUTH                   = 2,
                    EAST                    = 3,
                // movement codes
                    QUIT                    = 4,
                    HELP                    = 5,
                    RID_BOULDER             = 6,
                // also technically movement codes, despite being used to access non movement related features

                    TUTORIAL_DIMENSION      = 4,
                    EASY_DIMENSION          = MAX_SIZE / 2.5,
                    NORMAL_DIMENSION        = MAX_SIZE / 1.5,
                    HARD_DIMENSION          = MAX_SIZE;

const std::string   GRID_SQUARE_LINE        = "- -|",
                    PERIMETER_LINE          = "---|",
                    EMPTY_SPACE             = "   ",
                    TRAP                    = "<X>",
                    TREASURE                = "[T]",
                    KEY                     = "[K]",
                    STAIRS_DOWN             = "Dwn",
                    STAIRS_UP               = "Prv",
                    GOBLIN                  = "-_-",    // not currently implemented, requires behavioral algorithm (random movements)
                //  ORC                     = "o_o",    // not currently implemented, requires behavioral algorithm (always moves toward player)
                //  MERCHANT                = "$M$",    // not currently implemented, requires inventory, loot tables, character stats, etc.
                    LARGE_BOULDER           = "{B}",
                    SMALL_BOULDER           = "{b}",
                    PORTAL                  = "(@)",
                    PLAYER                  = "You";
                // building the dungeon

const char
                // navigating a single floor of the dungeon

                    UP                      = 'U',
                    DOWN                    = 'D',
                // ascending or descending stairs

                    EMPTY                    = '\0';
                // EMPTY character

void welcome();
/*
    accepts no arguments
    welcomes user to the game and explains the purpose of the game
    returns nothing
*/

int selectDifficulty ();
/*
    accepts no arguments
    prompts user to select a difficulty level
    returns selected difficulty level
*/

int setBounds (int difficulty);
/*
    accepts the selected difficulty level
    determines through a simple switch the appropriate bounds for the game
    returns bounds
*/

void createTutorial (std::string dungeon[][MAX_SIZE][MAX_SIZE], int current_floor, int current_x, int current_y, int bounds);
/*
    accepts the dungeon (in reference form to permit modification), the current floor the player is exploring, the current position of the player, and the bounds for the dungeon
    creates a minimally randomized dungeon to introduce the basic game concepts to the player
    returns a populated dungeon through that reference we sent in
*/

void createDungeon (std::string dungeon[][MAX_SIZE][MAX_SIZE], int current_floor, int current_x, int current_y, int difficulty, int bounds);
/*
    accepts the dungeon (in reference form to permit modification), the current floor the player is exploring, and the current position of the player.
    maintains current player position and mostly randomly places traps, treasures, etc.
    returns a populated dungeon through that reference we sent in
*/

void placeObject (std::string dungeon[][MAX_SIZE][MAX_SIZE], int current_floor, int bounds, int quantity_object, std::string target_object);
/*
    accepts the dungeon, the current floor, the bounds as determined by the difficulty level, the number of objects to be placed and the kind of object being placed
    places the designated quantity of the designated object within the designated bounds on the designated floor
    updates the dungeon via reference
*/

void displayDungeon (std::string dungeon[][MAX_SIZE][MAX_SIZE], int current_floor, int bounds);
/*
    accepts the dungeon and the current floor as parameters
    displays the current floor of the dungeon
    returns nothing
*/

std::string drawRow(int iterations, int bounds, std::string line_type);
/*
    accepts the outer limits of the grid being generated and a string dictating what type of line is currently desired
    generates string which displays a single row of the dungeon frame
    returns a string comprised of the appropriate number of repetitions of the string sent into the function to draw the line (my that is wordy and convoluted phrasing)
*/

void currentInventory (int gold, int keys, int dynamite, bool boulder);
/*
    accepts the current quantity of various items the player has collected
    displays inventory
    returns nothing
*/

bool checkMove (std::string dungeon[][MAX_SIZE][MAX_SIZE], int current_floor, int current_x, int current_y, int movement, std::string target_object);
/*
a) Input – the dungeon, object code you are checking for, move code
b) Function – check the move to see if onto a space containing the object code
c) Return – true if moved onto such a space
d) This function checks both for traps and finding treasure.
*/

void quitTime (bool &playing, bool &searching_floor);
/*
    accepts boolean control variables via reference
    sets control variables to false
    returns false values via reference
*/

#endif // DUNGEON_HEADER_H_INCLUDED
