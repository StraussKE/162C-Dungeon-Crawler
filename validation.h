#ifndef VALIDATION_H_INCLUDED
#define VALIDATION_H_INCLUDED

#include <iostream>
#include <limits>

#include "dungeon_header.h"

bool outOfBounds (int x_axis, int y_axis, int bounds, int movement);
/*
    accepts the (x,y) coordinates for the intended move or object placement
    checks to see if coordinates are within the limits of the array
    returns true if coordinates exceed the set bounds, returns false if the coordinates fall within the acceptable range
*/

bool tooClose (std::string dungeon[][MAX_SIZE][MAX_SIZE], int current_floor, int bounds, int x_axis, int y_axis, std::string target_object);
/*
    accepts layout of the current floor of the dungeon, and the proposed x and y coordinates as well as the object being looked for
    tests to see if proposed placement is within one square of designated test object
    returns true if object is within one space, returns false if object is not within one space
*/

int validInt (const int MIN_INPUT, const int MAX_INPUT);
/*
    Validation of integer input within a designated range.
    Accepts maximum and minimum input to constrain the range of valid choices.
    protects the cin stream from bad input and continues to ask the user for input until user chooses input within the acceptable range limitations
    Returns valid integer value.
*/

bool yesNo ();
/*
    Obtains valid input for yes/no questions.
    Accepts no arguments.
    Returns true if yes, false if no.
*/

#endif // VALIDATION_H_INCLUDED
