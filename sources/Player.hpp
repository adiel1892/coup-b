#pragma once
#include "Game.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace coup{
    class Game;
    class Player{
        public:
            Player();
            Player(Game & game, const string &name, const string & job);
            Game *game;
            string job;
            string name;
            string last_action;
            int wage;
            int pos;
            bool alive;
            bool assassinUsed;
            string stolen;
            int coins();
            string role();
            void income();
            void foreign_aid();
            void coup(Player &player);

    };
}