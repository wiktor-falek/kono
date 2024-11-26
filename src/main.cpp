#include <iostream>
#include <sstream>

#include "./lib/game.h"

int main() 
{
    std::string player_name;
    std::cout << "Enter your name: ";
    std::cin >> player_name;

    Game game;
    game.run(player_name);

    return 0;
}
