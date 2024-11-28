#pragma once

#include <cstdint>
#include <cstdio>
#include <vector>

struct Point2D {
    uint8_t x;
    uint8_t y;
    Point2D(uint8_t x_val = 0, uint8_t y_val = 0) : x(x_val), y(y_val) {}
};

struct Move {
    Point2D from;
    Point2D to;
};

enum Square : uint8_t { BLACK, WHITE, EMPTY };

class Board {
private:
    Square m_squares[4][4] = {
        {Square::WHITE, Square::WHITE, Square::WHITE, Square::WHITE},
        {Square::EMPTY, Square::EMPTY, Square::EMPTY, Square::EMPTY},
        {Square::EMPTY, Square::EMPTY, Square::EMPTY, Square::EMPTY},
        {Square::BLACK, Square::BLACK, Square::BLACK, Square::BLACK},
    };
    std::vector<Move> m_moveHistory;
public:
    Board() {}

    char get_square_c(uint8_t x, uint8_t y)
    {
        Square s = m_squares[y][x];
        switch (s)
        {
            case BLACK:
                return 'b';
            case WHITE:
                return 'w';
            default:
                return ' ';
        }
    }

    bool move(Point2D from, Point2D to)
    {
        // prevent moving other player's piece
        // limit moves to valid directions and boundaries
        // prevent moving over a piece
        // capturing moves
        m_squares[to.y][to.x] = m_squares[from.y][from.x];
        m_squares[from.y][from.x] = EMPTY;
        m_moveHistory.push_back({from, to});
        return false;
    }

    void render(std::string& buffer) 
    {
        std::ostringstream oss;
        
        oss << "   ╔═══╦═══╦═══╦═══╗\n";
        oss << " 4 ║ " << get_square_c(0, 3) << " ║ " << get_square_c(1, 3) << " ║ "<< get_square_c(2, 3) << " ║ "<< get_square_c(3, 3) << " ║\n";
        oss << "   ╠═══╬═══╬═══╬═══╣\n";
        oss << " 3 ║ " << get_square_c(0, 2) << " ║ " << get_square_c(1, 2) << " ║ "<< get_square_c(2, 2) << " ║ "<< get_square_c(3, 2) << " ║\n";
        oss << "   ╠═══╬═══╬═══╬═══╣\n";
        oss << " 2 ║ " << get_square_c(0, 1) << " ║ " << get_square_c(1, 1) << " ║ "<< get_square_c(2, 1) << " ║ "<< get_square_c(3, 1) << " ║\n";
        oss << "   ╠═══╬═══╬═══╬═══╣\n";
        oss << " 1 ║ " << get_square_c(0, 0) << " ║ " << get_square_c(1, 0) << " ║ "<< get_square_c(2, 0) << " ║ "<< get_square_c(3, 0) << " ║\n";
        oss << "   ╚═══╩═══╩═══╩═══╝\n";
        oss << "     A   B   C   D  \n";
        
        buffer += oss.str();
    }
};
