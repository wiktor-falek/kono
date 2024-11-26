#pragma once

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

    void take_turn() 
    {
        std::string move;
        std::cout << m_color << " to move: ";
        std::cin >> move;

        // TODO: validate the move
        // TODO: mutate the board state and move history
    }
};
