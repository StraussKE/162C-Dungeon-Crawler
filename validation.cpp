#include "validation.h"
#include "movement.h"

bool outOfBounds (int x_axis, int y_axis, int bounds, int movement)
/*
    accepts the (x,y) coordinates for the intended move or object placement
    checks to see if coordinates are within the limits of the array
    returns true if coordinates exceed the set bounds, returns false if the coordinates fall within the acceptable range
*/
{
    moveTarget(x_axis, y_axis, movement);

    if (x_axis >= bounds || x_axis < 0 || y_axis >= bounds || y_axis < 0)
    {
        return true;
    }
    return false;
}

bool tooClose (std::string dungeon[][MAX_SIZE][MAX_SIZE], int current_floor, int bounds, int x_axis, int y_axis, std::string target_object)
/*
    accepts layout of the current floor of the dungeon, and the proposed x and y coordinates as well as the object being looked for
    tests to see if proposed placement is within one square of designated test object
    returns true if object is within one space, returns false if object is not within one space
*/
{
    if (!outOfBounds(x_axis, y_axis, bounds, NORTH) && checkMove(dungeon, current_floor, x_axis, y_axis, NORTH, target_object))
    {
        return true;
    }
    if (!outOfBounds(x_axis, y_axis, bounds, WEST) && checkMove(dungeon, current_floor, x_axis, y_axis, WEST, target_object))
    {
        return true;
    }
    if (!outOfBounds(x_axis, y_axis, bounds, SOUTH) && checkMove(dungeon, current_floor, x_axis, y_axis, SOUTH, target_object))
    {
        return true;
    }
    if (!outOfBounds(x_axis, y_axis, bounds, EAST) && checkMove(dungeon, current_floor, x_axis, y_axis, EAST, target_object))
    {
        return true;
    }
    return false;
}

int validInt (const int MIN_INPUT, const int MAX_INPUT)
/*
    Validation of integer input within a designated range.
    Accepts maximum and minimum input to constrain the range of valid choices.
    protects the cin stream from bad input and continues to ask the user for input until user chooses input within the acceptable range limitations
    Returns valid integer value.
*/
{
    int user_input = MIN_INPUT - 1;

    while (user_input < MIN_INPUT || user_input > MAX_INPUT)
    {
        std::cin >> user_input;
        if (std::cin.fail() || user_input < MIN_INPUT || user_input > MAX_INPUT)
        {

         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         user_input = MIN_INPUT - 1;

         std::cout <<   "Your input is not within acceptable parameters for this program.\n"
                        "Please enter a number within the given range of " << MIN_INPUT << " to " << MAX_INPUT << "\n";
        }

    }
    return user_input;
}

bool yesNo ()
/*
    Obtains valid input for yes/no questions.
    Accepts no arguments.
    Returns true if yes, false if no.
*/
{
    char choice;
    bool valid = false;

    std::cout << "Please select Y for yes or N for no.\n";

    while ( ! valid )
    {
        std::cin >> choice;

        switch (choice)
        {
        case 'y':
        case 'Y':
            return true;

        case 'n':
        case 'N':
            return false;
        default:
            std::cout << "That is not an acceptable input, please select Y or N.\n";
        }
    }
    abort();
}
