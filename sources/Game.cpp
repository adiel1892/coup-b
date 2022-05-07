#include "Game.hpp"
#include <iostream>
using namespace coup;
using namespace std;
constexpr int maxPlayers = 6;

Game::Game(){
    this->currTurn = 0;
    this->currPlayers = new vector<Player*>[maxPlayers];   
    this->started = false;
}
Game::~Game(){
    delete[] this->currPlayers;
}

void Game::validNumPlayers(){
    if(this->currPlayers->size() < 2 || this->currPlayers->size() > 6){
        throw invalid_argument("numbers of players is between 2 - 6");
    }
}
string Game::turn(){
    return this->currPlayers->at(this->currTurn)->name;
}
vector<string> Game::players(){
    vector<string> listPlayers;
    for(unsigned int i = 0; i < this->currPlayers->size(); i++){
        if(this->currPlayers->at(i)->alive){
            listPlayers.push_back(this->currPlayers->at(i)->name);
        }
    }
    return listPlayers;
}

string Game::winner(){
    this->validNumPlayers();
    if(this->players().size() != 1){
        throw invalid_argument("There can be only one winner");
    }
    return this->players().at(0);
}

void Game::addPlayer(Player *player){
    if(this->currPlayers->size() >= 6){
        throw invalid_argument("Maximun 6 players");
    }
    if(this->started == true){
        throw invalid_argument("game already started");
    }
    this->currPlayers->push_back(player);
    player->pos = this->currPlayers->size();
}

void Game::updateTurn(){
    while(true){
        this->currTurn++;
        if(this->currPlayers->at(currTurn % this->currPlayers->size())->alive == true){
            break;
        }
    }
}


bool Game::rightTurn(Player &player){
    // [adiel , nadav , ishay , boaz , moss]
    if(player.alive == false){
        throw invalid_argument("The player is dead");
    }
    return this->currPlayers->at(this->currTurn % this->currPlayers->size()) == &player;
}

void Game::revivePlayer(Player *player){
    player->alive = true;
}

void Game::killPlayer(Player &player){
    this->lastKilledPlay = &player;
    player.alive = false;
}