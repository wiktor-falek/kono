#pragma once

#include "./board.h"
#include "./player.h"
#include <vector>

enum PlayerIndex { WHITE_PLAYER, BLACK_PLAYER };

class Game {
private:
    Board m_board;
    std::vector<std::string> m_moveHistory;
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
        m_players[m_currentPlayer].take_turn();
        m_currentPlayer = m_currentPlayer == WHITE_PLAYER ? BLACK_PLAYER : WHITE_PLAYER;
    }

    void draw() 
    { 
        m_buffer.clear();

        m_board.render(m_buffer);
        m_players[0].render(m_buffer);
        m_players[1].render(m_buffer);

        std::cout << "\033[2J\033[1;1H";
        std::cout << m_buffer;
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
