#pragma once

#include "./board.h"
#include "./player.h"

enum PlayerIndex { WHITE_PLAYER, BLACK_PLAYER };

class Game {
private:
    Board m_board;
    Player m_players[2];
    PlayerIndex m_currentPlayer;
    std::string m_buffer;

    void initialize(std::string player_name) 
    {
        m_players[WHITE_PLAYER] = Player(player_name, "white");
        m_players[BLACK_PLAYER] = Player("COMPUTER", "black");
        m_currentPlayer = WHITE_PLAYER;
    }

    void update() {
        m_players[m_currentPlayer].take_turn(m_board);
        m_currentPlayer = m_currentPlayer == WHITE_PLAYER ? BLACK_PLAYER : WHITE_PLAYER;
    }

    void draw() 
    { 
        m_buffer.clear();

        m_board.render(m_buffer);
        m_players[WHITE_PLAYER].render(m_buffer);
        m_players[BLACK_PLAYER].render(m_buffer);

        std::cout << "\033[2J\033[1;1H" << m_buffer;
    }

   public:
    Game() {}

    void run(std::string player_name) 
    {
        initialize(player_name);
        while (1) 
        {
            draw();
            update();
        }
    }
};
