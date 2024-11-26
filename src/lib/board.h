#pragma once

#include <cstdint>
#include <cstdio>

enum Square : uint8_t { BLACK, WHITE, EMPTY };

class Board {
private:
    Square m_squares[4][4] = {
        {Square::BLACK, Square::BLACK, Square::BLACK, Square::BLACK},
        {Square::EMPTY, Square::EMPTY, Square::EMPTY, Square::EMPTY},
        {Square::EMPTY, Square::EMPTY, Square::EMPTY, Square::EMPTY},
        {Square::WHITE, Square::WHITE, Square::WHITE, Square::WHITE},
    };
public:
    Board() {}

    char get_square_c(uint8_t x, uint8_t y)
    {
        Square s = m_squares[y][x];
        switch (s)
        {
            case BLACK:
                return 'c';
            case WHITE:
                return 'b';
            default:
                return ' ';
        }
    }

    void render(std::string& buffer) 
    {
        std::ostringstream oss;
        
        oss << "   ╔═══╦═══╦═══╦═══╗\n";
        oss << " 4 ║ " << get_square_c(0, 0) << " ║ " << get_square_c(1, 0) << " ║ "<< get_square_c(2, 0) << " ║ "<< get_square_c(3, 0) << " ║\n";
        oss << "   ╠═══╬═══╬═══╬═══╣\n";
        oss << " 3 ║ " << get_square_c(0, 1) << " ║ " << get_square_c(1, 1) << " ║ "<< get_square_c(2, 1) << " ║ "<< get_square_c(3, 1) << " ║\n";
        oss << "   ╠═══╬═══╬═══╬═══╣\n";
        oss << " 2 ║ " << get_square_c(0, 2) << " ║ " << get_square_c(1, 2) << " ║ "<< get_square_c(2, 2) << " ║ "<< get_square_c(3, 2) << " ║\n";
        oss << "   ╠═══╬═══╬═══╬═══╣\n";
        oss << " 1 ║ " << get_square_c(0, 3) << " ║ " << get_square_c(1, 3) << " ║ "<< get_square_c(2, 3) << " ║ "<< get_square_c(3, 3) << " ║\n";
        oss << "   ╚═══╩═══╩═══╩═══╝\n";
        oss << "     A   B   C   D  \n";
        
        buffer += oss.str();
    }
};
