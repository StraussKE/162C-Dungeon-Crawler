#include <ctime>

#include "dungeon_header.h"
#include "movement.h"
#include "validation.h"
#include "help_menu.h"
#include "text_tables.h"

using namespace std;

int main()
{
    short int       SEED                    = time(0);

    int             current_floor           = START_POINT,
                    player_x                = START_POINT,
                    player_y                = START_POINT,
                // starting coordinates established

                    turn[MAX_SIZE],
                // tracks player's turn count on each floor

                    treasure = 0,
                    gold = 0,
                    dynamite = 0,
                    keys = 0,
                // inventory items

                    difficulty,
                // selects the difficulty level the user wishes to play

                    bounds,
                // the boundaries as determined by user difficulty selection

                    movement;
                // move code for user

    string          dungeon[MAX_SIZE][MAX_SIZE][MAX_SIZE];
                //  floor number, width, height

    char            stairs = EMPTY;

    bool            playing,
                    searching_floor,
                    boulder_carry = false,
                    descend_stairs = false,
                    ascend_stairs = false;
                //  fight_monster, // requires monsters, player stats, loot table, etc. not implemented at this time
                //  move_boulder; // requires player stats and loot table, not implemented at this time


    srand(SEED);
    welcome ();
    difficulty = selectDifficulty();
    bounds = setBounds(difficulty);
    for (int i = 0; i< bounds; i++)
    {
        turn[i] = START_POINT;
    }

// external do while loop, used when generating new dungeon floors
    do
    {
        playing = true;
        searching_floor = true;

    // if the player is playing the tutorial the program will create a mostly predetermined tutorial version of the dungeon
        if (difficulty == TUTORIAL)
        {
            createTutorial(dungeon, current_floor, player_x, player_y, bounds);
        }
    // if the player has selected any other difficulty level the program will shunt over to the regular level generation function
        else
        {
            createDungeon(dungeon, current_floor, player_x, player_y, difficulty, bounds);
        }

    // internal do while loop, used when maneuvering on the current dungeon floor
        do
        {
            displayDungeon(dungeon, current_floor, bounds);

            currentInventory (gold, keys, dynamite, boulder_carry);

            turn[current_floor] += 1;

            movement = getMove(current_floor, player_x, player_y, bounds, boulder_carry);

        // if the user selects quit
            if (movement == QUIT)
            {
                quitTime(playing, searching_floor);
            }

        // if the user wishes to view the help menu
            else if (movement == HELP)
            {
                turn[current_floor] -= 1;
                getHelp();
            }

        // if the user wishes to put down their boulder
            else if (boulder_carry && movement == RID_BOULDER)
            {
                while (boulder_carry)
                {
                    cout << "Please select the direction in which you would like to abandon your boulder.\n";
                    movement = getMove(current_floor, player_x, player_y, bounds);
                    if (outOfBounds(player_x, player_y, bounds, movement))
                    {
                        hitWall(SMALL_BOULDER);
                    }
                    else if (!checkMove(dungeon, current_floor, player_x, player_y, movement, EMPTY_SPACE))
                    {
                        cout << "That direction is obstructed. Please be rid of your boulder in a different\n"
                                "direction.\n";
                    }
                    else if (checkMove(dungeon, current_floor, player_x, player_y, movement, KEY))
                    {
                        boulderPlay(KEY);
                        boulder_carry = false;
                        cout << "You somberly retreat from the room containing your traitorous boulder.";
                        updateDungeon(dungeon, movement, stairs, current_floor, player_x, player_y, PLAYER, SMALL_BOULDER);
                    }
                    else
                    {
                        cout << "You thrust your boulder from you into the next room. A beautiful thing has\n"
                                "come to an end. You notice that your former boulder seems somehow greyer,\n"
                                "as though it has somehow discovered what it is to feel sadness.\n";
                        boulder_carry = false;
                        updateDungeon(dungeon, movement, stairs, current_floor, player_x, player_y, PLAYER, SMALL_BOULDER);
                    }
                }
            }

        // if the user decides to walk into a boundary wall
            else if (outOfBounds(player_x, player_y, bounds, movement))
            {
                if (boulder_carry) // if the user is currently carrying a boulder
                {
                    hitWall(SMALL_BOULDER);
                }
                else
                {
                    hitWall(PLAYER);
                }
            }

        // if the user moves onto a downward stairway
            else if (checkMove(dungeon, current_floor, player_x, player_y, movement, STAIRS_DOWN))
            {
                stairs = DOWN;
                starBar();
                cout << "You descend the stairs and venture forth to the next floor.\n";
                updateDungeon(dungeon, movement, stairs, current_floor, player_x, player_y, STAIRS_DOWN, PLAYER);
                stairs = EMPTY;
                descend_stairs = true;
                if (turn[current_floor]== 0)
                {
                    searching_floor = false;
                }
            }

        // if the user descended stairs the previous turn - the user can be assumed to be moving onto an empty space due to object placement algorithm
            else if (descend_stairs)
            {
                updateDungeon(dungeon, movement, stairs, current_floor, player_x, player_y, STAIRS_UP, PLAYER);
                descend_stairs = false;
            }

        // if the user moves onto an upward stairway
            else if (checkMove(dungeon, current_floor, player_x, player_y, movement, STAIRS_UP))
            {
                if (boulder_carry) // if the user is currently carrying a boulder
                {
                    boulderPlay(STAIRS_UP);
                }
                else
                {
                    stairs = UP;
                    updateDungeon(dungeon, movement, stairs, current_floor, player_x, player_y, STAIRS_UP, PLAYER);
                    stairs = EMPTY;
                    ascend_stairs = true;
                }
            }

        // if the user ascended stairs the previous turn - the user can be assumed to be moving onto an empty space due to object placement algorithm
            else if (ascend_stairs)
            {
                updateDungeon(dungeon, movement, stairs, current_floor, player_x, player_y, STAIRS_DOWN, PLAYER);
                ascend_stairs = false;
            }

        // if the user moves into a key space
            else if (checkMove(dungeon, current_floor, player_x, player_y, movement, KEY))
            {
                if (boulder_carry) // if the user is currently carrying a boulder
                {
                    boulderPlay(KEY);
                }
                else
                {
                    starBar();
                    cout << "Congratulations, you have recovered a key!\n";
                    keys += 1;
                }
                updateDungeon(dungeon, movement, stairs, current_floor, player_x, player_y, EMPTY_SPACE, PLAYER);
            }

        // if the user moves into a treasure space
            else if (checkMove(dungeon, current_floor, player_x, player_y, movement, TREASURE))
            {


                if (boulder_carry)
                {
                    boulderPlay(TREASURE);
                }
                else
                {
                // if the user has at least one key
                    if (keys > 0)
                    {
                        starBar();
                        keys -= 1;
                        treasure = 1 + (rand() % ((current_floor+difficulty)* 100));
                        cout << "You have discovered " << treasure << " gold coins.\n";
                        gold += treasure;
                        treasure = (rand() % (difficulty + 1));
                        if (treasure == 1)
                        {
                            cout << "You have discovered " << treasure << " stick of EZ ignite dynamite\n";
                        }
                        else if (dynamite > 1)
                        {
                            cout << "You have discovered " << treasure << " sticks of EZ ignite dynamite\n";
                        }
                        dynamite += treasure;
                        starBar();
                        updateDungeon(dungeon, movement, stairs, current_floor, player_x, player_y, EMPTY_SPACE, PLAYER);
                    }
                // if the user has no keys
                    else
                    {
                        starBar();
                        cout << "You cannot get the treasure without a key. Try exploring some more.\n";
                    }
                }
            }

        // if the user attempts to move around a small boulder
            else if (checkMove(dungeon, current_floor, player_x, player_y, movement, SMALL_BOULDER))
            {
                if (boulder_carry)
                {
                    boulderPlay(SMALL_BOULDER);
                }
                else
                {
                    boulderPlay(PLAYER);
                    boulder_carry = yesNo();

                    if (boulder_carry)
                    {
                        updateDungeon(dungeon, movement, stairs, current_floor, player_x, player_y, EMPTY_SPACE, PLAYER);
                    }
                    else
                    {
                        starBar();
                        cout << "/nYou decide to retreat and leave the boulder behind./n";
                    }
                }
            }

        // if the user moves onto a trap
            else if (checkMove(dungeon, current_floor, player_x, player_y, movement, TRAP))
            {
                if (boulder_carry)
                {
                    boulderPlay(TRAP);
                    boulder_carry = false;
                    updateDungeon(dungeon, movement, stairs, current_floor, player_x, player_y, PLAYER, EMPTY_SPACE);
                }
                else
                {
                    hitTrap(PLAYER);
                    quitTime(playing, searching_floor);
                }
            }

        // if the user attempts to share space with an unmovable boulder
            else if (checkMove(dungeon, current_floor, player_x, player_y, movement, LARGE_BOULDER))
            {
                if (boulder_carry)
                {
                    boulderPlay(LARGE_BOULDER);
                }
                else
                {
                    if (dynamite > 0)
                    {
                        starBar();
                        cout << "You lob a stick of dynamite at the boulder, clearing your path.\n";
                        dynamite -= 1;
                        updateDungeon(dungeon, movement, stairs, current_floor, player_x, player_y, PLAYER, EMPTY_SPACE);
                    }
                    else
                    {
                        bigBoulder();
                    }
                }
            }

        // if the user attempts to enter a portal
            else if (checkMove(dungeon, current_floor, player_x, player_y, movement, PORTAL))
            {
                starBar();
                cout << "Congratulations, you have successfully completed this dungeon.\n"
                        "Final inventory is:\n";
                        currentInventory(gold, keys, dynamite, boulder_carry);
                cout << "Would you like to select a new difficulty and continue your adventure?\n\n";
                        if (yesNo())
                        {
                            searching_floor = false;
                            difficulty = selectDifficulty();
                            bounds = setBounds(difficulty);
                            for (int i = 0; i< bounds; i++)
                            {
                                turn[i] = START_POINT;
                            }
                            current_floor = START_POINT;
                            player_x = START_POINT;
                            player_y = START_POINT;
                        }
                        else
                        {
                            quitTime(playing, searching_floor);
                        }
            }
            else
            {
                updateDungeon(dungeon, movement, stairs, current_floor, player_x, player_y, EMPTY_SPACE, PLAYER);
            }

        } while (searching_floor);

    } while (playing);

    return 0;
}
