#pragma once

#include <string>
#include <regex>

class Player
{
private:
public:
    std::string m_name;
    std::string m_color;

    Player() = default;

    Player(std::string name, std::string color) 
    {
        m_name = name;
        m_color = color;
    }

    void render(std::string& buffer) {
        buffer += m_color + ": " + m_name + "\n";
    }

    void take_turn(Board &board)
    {
        std::string move_input;

        std::smatch match;
        std::regex pattern("^[a-d][1-4]-[a-d][1-4]$");
        while (!std::regex_search(move_input, match, pattern))
        {
            // TODO: invalid move notification with correct move format
            std::cout << m_color << " to move: ";
            std::cin >> move_input;
        }

        std::string from_input = move_input.substr(0, 2);
        std::string to_input = move_input.substr(3);

        Point2D from(static_cast<uint8_t>(from_input[0] - 'a'), static_cast<uint8_t>(from_input[1] - '1'));
        Point2D to(static_cast<uint8_t>(to_input[0] - 'a'), static_cast<uint8_t>(to_input[1] - '1'));

        // TODO: notify and prompt again on invalid move
        bool valid_move = board.move(from, to);
    }
};
