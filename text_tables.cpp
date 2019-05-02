#include "dungeon_header.h"
#include "text_tables.h"

void starBar ()
/*
    Used for visually dividing output for greater user readability
    It's a line of asterisks. There's a newline character at the end.
    That's it, really.  Nothing special in any way here.
*/
{
    std::cout << "*******************************************************************************\n";
}

void hitWall (std::string moving_object)
/*
    For the inevitable moment the user decides to venture through a perimeter wall.
    Random number triggers a switch which leads to a remark about their attempt to pass the wall being returned via cout
    Not really anything here but randomized sass.
*/
{
    int                 comment;

    if (moving_object == PLAYER)
    {
        comment = rand() % (4);

        switch (comment)
        {
            case 0:
                starBar();
                std::cout << "With feline stealth the exterior wall suddenly appears in front of you.\nPlease try something else.\n";
                break;
            case 1:
                starBar();
                std::cout << "Your jaunty step is thrown off by an abrupt encounter with a sturdy wall.\nPlease try something else.\n";
                break;
            case 2:
                starBar();
                std::cout << "Despite your efforts to prove otherwise, the wall is not an illusion.\nPlease try something else.\n";
                break;
            case 3:
                starBar();
                std::cout << "Your quixotic effort to slay the wall has only gained you shame.\nPlease try something else.\n";
                break;
            default:
                starBar();
                std::cout << "Error, you should not be here.  Error, error, error.....\n";
                break;
        }
    }

    if (moving_object == SMALL_BOULDER)
    {
        comment = rand() % (2);

        switch (comment)
        {
            case 0:
                starBar();
                std::cout << "Your efforts to shove the small boulder through the wall are met with resistance\n Please try something else.\n";
                break;
            case 1:
                starBar();
                std::cout << "You are unable to achieve enough force to embed the bounder into the wall.\n Please try something else.\n";
                break;
            default:
                starBar();
                std::cout << "You have chosen to attempt something improbable with the boulder.  It failed.\n";
                break;
        }
    }
}

void boulderPlay (std::string target_object)
/*
    When carrying around small rocks life can be a bit challenging.
    These are the responses given when trying to take your new pet rock into different scenarios.

    accepts the object in the square you are attempting to move your boulder into
    outputs some words
    fin (that's end)
*/
{
    if (target_object == PLAYER)
    {
        starBar();
        std::cout <<    "You begin to enter a room but are unable to bypass a small boulder. It appears\n"
                        "that you can carry it, barely. Would you like to carry the boulder?\n";
    }
    else if (target_object == TRAP)
    {
        starBar();
        std::cout << "After straining to move your boulder around for what seems an eternity, your\n"
                "diligence is rewarded as you shove it into the next room. A resounding click\n"
                "is the only warning before ";
        hitTrap(SMALL_BOULDER);
    }
    else if (target_object == STAIRS_UP)
    {
        starBar();
        std::cout <<    "You attempt to carry the boulder up the stairs but discover yourself extremely\n"
                        "lacking in the strength category. Humiliated you vow to exercise rigorously...\n"
                        "Eventually.\n";
    }
    else if (target_object == KEY)
    {
        starBar();
        std::cout <<    "You hear the dismaying sound of breaking metal as you set your boulder down to\n"
                        "rest a moment. Lifting it back up with trepidation you discover the mangled\n"
                        "remains of a key.\n";
    }
    else if (target_object == TREASURE)
    {
        starBar();
        std::cout <<    "Peering around your boulder as best you can you spy the gleam of a treasure\n"
                        "chest in your intended direction. Taking a moment to reflect upon the chances\n"
                        "of the chest surviving contact with your boulder you reconsider your plans.\n";
    }
    else if (target_object == LARGE_BOULDER)
    {
        starBar();
        std::cout <<    "You see a boulder of such proportions as to dwarf the one you are currently\n"
                        "struggling to carry. You retreat before your boulder can become envious of its\n"
                        " bigger brother.\n";
    }
    else if (target_object == SMALL_BOULDER)
    {
        std::cout <<    "You attempt to progress forward but find your progress impeded. When you set\n"
                        "your boulder down to discover the cause you discover it pressed close against\n"
                        "it's twin. You realize with some sorrow that if you wish to go this way you will\n"
                        "first have to be rid of your beloved boulder.\n";
    }
    else if (target_object == PORTAL)
    {
        std::cout <<    "As you enter the portal your faithful boulder friend disintegrates. You feel\n"
                        "unexpectedly lonely without the companionship.\n";
    }
}

void hitTrap (std::string moving_object)
/*
    Dungeons are full of traps.  Eventually someone or something is going to run into one.
    When that happens they'd probably like to know how they died.
    If a monster dies in a trap, does the player hear anything?
    If they defuse a trap using a stone, what did they narrowly avoid?

    Accepts the type of moving object so as to enter the correct switch statement for output text.
    Randomly selects a text blurb to report back to the user.
    Returns that text blurb.
*/

{
    int trap_type;

    if (moving_object == SMALL_BOULDER)
    {
        trap_type = rand() % (3);

        switch (trap_type)
        {
            case 0:
                std::cout << "a sudden eruption of fire incinerates your boulder.\n";
                break;
            case 1:
                std::cout << "your boulder drops into a newly exposed acid vat.\n";
                break;
            case 2:
                std::cout << "monstrous scythes drop from above and split your boulder.\n";
                break;
            default:
                std::cout << "something underwhelming happens.\n";
                break;
        }
    }
    else if (moving_object == PLAYER)
    {
        starBar();
        std::cout << "Horrible things happen.  You die.  Game over.  I'm sad, really. \n";
    }
}

void bigBoulder ()
/*
    big rocks have stories too!
*/
{
    starBar();
    std::cout << "\nThe solemn boulder stands eternal sentinel here. You can not pass.\n";
}
