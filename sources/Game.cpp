#include "Game.hpp"
#include <iostream>
using namespace coup;
using namespace std;
constexpr int minPlayers = 2;


// Game::Game(){
//     this->currPlayers = new vector<Player*>[maxPlayers];   
// }
Game::~Game(){
    delete[] this->currPlayers;
}

void Game::validNumPlayers()const{
    if(this->currPlayers->size() < minPlayers || this->currPlayers->size() > maxPlayers){
        throw invalid_argument("numbers of players is between 2 - 6");
    }
}
string Game::turn()const{
    return this->currPlayers->at(this->currTurn)->name;
}
vector<string> Game::players()const{
    vector<string> listPlayers;
    for(unsigned int i = 0; i < this->currPlayers->size(); i++){
        if(this->currPlayers->at(i)->alive){
            listPlayers.push_back(this->currPlayers->at(i)->name);
        }
    }
    return listPlayers;
}

string Game::winner()const{
    this->validNumPlayers();
    if(this->players().size() != 1){
        throw invalid_argument("There can be only one winner");
    }
    return this->players().at(0);
}

void Game::addPlayer(Player *player)const{
    if(this->currPlayers->size() >= maxPlayers){
        throw invalid_argument("Maximun 6 players");
    }
    if(this->started){
        throw invalid_argument("game already started");
    }
    this->currPlayers->push_back(player);
}

void Game::updateTurn(){
    while(true){
        this->currTurn++;
        if(this->currPlayers->at(currTurn % this->currPlayers->size())->alive){
            break;
        }
    }
}


bool Game::rightTurn(Player &player)const{
    if(!player.alive){
        throw invalid_argument("The player is dead");
    }
    return this->currPlayers->at(this->currTurn % this->currPlayers->size()) == &player;
}

void Game::revivePlayer(Player *player){
    player->alive = true;
}

void Game::killPlayer(Player &player){
    this->lastKilledPlayer = &player;
    player.alive = false;
}