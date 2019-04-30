#include "dungeon_header.h"
#include "help_menu.h"
#include "validation.h"
#include "text_tables.h"

void getHelp ()
/*
    accepts no arguments
    brings up interactive help menu for user to request clarification on various objects within the game
    returns nothing
*/
{
    const int   EXIT = 0,
                EX_DUNG = 1,
                EX_MOVE = 2,
                EX_TREAS = 3,
                EX_STAIR = 4,
                EX_TRAP = 5,
                EX_ROCK = 6,
                EX_MONST = 8,
                EX_PORT = 7;

    int         help_desired = -1;

    while (help_desired != 0)
    {
        std::cout <<    " Please select a topic from our help menu for clarification:\n"
                        "\t1 - |   |\tThe Dungeon\t|   |\n"
                        "\t2 - |   |\tMovement \t|   |\n"
                        "\t3 - |" << TREASURE << "|\tTreasure \t|" << KEY << "|\n"
                        "\t4 - |" << STAIRS_DOWN << "|\tStairs \t\t|" << STAIRS_UP << "|\n"
                        "\t5 - |" << TRAP << "|\tTraps \t\t|" << TRAP << "|\n"
                        "\t6 - |" << SMALL_BOULDER << "|\tRocks \t\t|" << LARGE_BOULDER << "|\n"
                        "\t7 - |" << PORTAL << "|\tPortals \t|" << PORTAL << "|\n"


                        "\n\t0 - Return to game\n\n";
/*
not yet implemented

            "\t7 - |" << GOBLIN << "|\tMonsters \t|" << ORC << "|\n"
*/

        help_desired = validInt(EXIT, EX_PORT);
        switch (help_desired)
        {
            case EXIT:
            {
                std::cout << "\nFeel free to use the help menu again anytime you require. Happy adventuring!\n\n";
                break;
            }
            case EX_DUNG:
            {
                std::cin.ignore();
                welcome();
                break;
            }
            case EX_MOVE:
            {
                std::cin.ignore();
                aboutMovement();
                break;
            }
            case EX_TREAS:
            {
                std::cin.ignore();
                aboutTreasure();
                break;
            }
            case EX_STAIR:
            {
                std::cin.ignore();
                aboutStairs();
                break;
            }
            case EX_TRAP:
            {
                std::cin.ignore();
                aboutTraps();
                break;
            }
            case EX_ROCK:
            {
                std::cin.ignore();
                aboutBoulders();
                break;
            }
            case EX_MONST:
            {
                std::cin.ignore();
                aboutMonsters();
                break;
            }
            case EX_PORT:
            {
                std::cin.ignore();
                aboutPortals ();
                break;
            }
            default:
            {
                std::cout << "Unexpected input.\n";
                break;
            }
        }
    }

}
void aboutMovement ()
/*
    explains movement mechanics
*/
{
    std::string pause;

    std::cout <<    "\nEach turn you may move a single square in one of the cardinal directions.\n"
                    "Diagonal motion is not permitted.\n\n"
                    "You have two options for controlling your character.\n\n"
                    "Left handed control:\tW = up  A = left  S = down  D = right\n"
                    "Right handed control:\t8 = up  4 = left  2 = down  6 = right\n\n"
                    "(Press enter to continue)\n";

    getline(std::cin, pause);
    starBar();
}

void aboutStairs ()
/*
    explains stair mechanics
*/
{
    std::string pause;

    std::cout <<    "\nStairs allow you to travel between floors of the dungeon.\n\n"
                    "|" << STAIRS_DOWN << "| indicates a downward stairway that will allow you to descend deeper\n"
                    "into the dungeon.\n\n"
                    "|" << STAIRS_UP << "| indicates an upward stairway that will allow you to return to floors\n"
                    "previously explored.\n\n"
                    "(Press enter to continue)";

    getline(std::cin, pause);
    starBar();

}

void aboutTreasure ()
/*
    explains about treasure and key mechanics
*/
{
    std::string pause;

    std::cout <<    "\n|" << KEY << "| Keys are required to open treasure chests.\n\n"
                    "|" << TREASURE << "| Treasure chests are filled with gold for you to collect.\n\n"
                    "Once you have collected a treasure, you will always be given the option to quit or continue\n"
                    "exploring the dungeon.\n\n"
                    "(Press enter to continue)";

    getline(std::cin, pause);
    starBar();
}

void aboutTraps ()
/*
    explains trap mechanics
*/
{
    std::string pause;

    std::cout <<    "\n|" << TRAP << "| Traps are dangerous and you will die if you step in one.\n"
                    "Avoid or disarm traps whenever possible.\n\n"
                    "(Press enter to continue)";

    getline(std::cin, pause);
    starBar();
}

void aboutBoulders ()
/*
    small rock and boulder mechanics
*/
{
    std::string pause;

    std::cout <<    "\n|" << LARGE_BOULDER << "| Boulders are immobile obstacles that you must travel around.\n\n"
                    "\n|" << SMALL_BOULDER << "| Small rocks can be pushed around and used to disarm traps.\n\n"
                    "(Press enter to continue)";

    getline(std::cin, pause);
    starBar();
}

void aboutMonsters ()
/*
    explains monster mechanics
*/
{
    // monsters
    std::string pause;
}

void aboutPortals ()
/*
    explains portal mechanics
*/
{
    std::string pause;

    std::cout <<    "\n|" << PORTAL << "| Portals exist on the final floor of a dungeon. Stepping on the portal\n"
                    "allows you to keep the treasure you've collected and continue on to another dungeon of\n"
                    "whatever difficulty level you'd like.\n\n"
                    "(Press enter to continue)";

    getline(std::cin, pause);
    starBar();
}
