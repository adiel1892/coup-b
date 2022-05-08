#pragma once
#include "Game.hpp"
using namespace std;
constexpr int mustCoup = 10;
namespace coup{
    class Game;
    class Player{
        public:
            Player(Game & game, const string &name, const string & job){
                this->name = name;
                this->job = job;
                this->game = &game;
                this->addPlayer();
            }
            Game *game;
            string job;
            string name;
            string last_action = "";
            int wage = 0;
            bool alive = true;
            bool assassinUsed = false;
            string stolen = "";
            int coins()const;
            string role()const;
            void income();
            void foreign_aid();
            void coup(Player &player);
            void addPlayer();

    };
}