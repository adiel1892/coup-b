#pragma once
#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;
constexpr int maxPlayers = 6;

namespace coup{
    class Player;
    class Game{
        public:
            Game(){
                this->currPlayers = new vector<Player*>[maxPlayers];   
            }
            ~Game();
            vector<Player*>* currPlayers;
            unsigned int currTurn = 0;
            Player *lastKilledPlayer;
            string turn()const;
            vector<string> players()const;
            string winner()const;
            static void revivePlayer(Player *player);
            bool rightTurn(Player &player)const;
            void killPlayer(Player &player);
            void updateTurn();
            void validNumPlayers()const;
            bool started = false;
    };
}