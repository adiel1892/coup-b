#pragma once
#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;

namespace coup{
    class Player;
    class Game{
        public:
            vector<Player*>* currPlayers;
            Game();
            ~Game();
            unsigned int currTurn;
            string turn();
            vector<string> players();
            string winner();
            void addPlayer(Player *player);
            void revivePlayer(Player *player);
            bool rightTurn(Player &player);
            void killPlayer(Player &player);
            void updateTurn();
    };
}