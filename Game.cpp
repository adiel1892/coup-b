#include "Game.hpp"
#include <iostream>
using namespace coup;
using namespace std;
constexpr int maxPlayers = 6;

Game::Game(){
    this->currTurn = 0;
    this->currPlayers = new vector<Player*>[maxPlayers];   
}
Game::~Game(){
    delete[] this->currPlayers;
}

string Game::turn(){
    return this->currPlayers->at(this->currTurn)->name;
}
vector<string> Game::players(){
    vector<string> listPlayers;
    for(unsigned int i = 0; i < this->currPlayers->size(); i++){
        listPlayers.push_back(this->currPlayers->at(i)->name);
    }
    return listPlayers;
}

string Game::winner(){

    return "coup-a";
}

void Game::addPlayer(Player *player){
    if(this->currPlayers->size() >= 6){
        throw invalid_argument("Maximun 6 players");
    }
    this->currPlayers->push_back(player);
    player->pos = this->currPlayers->size();
}

void Game::updateTurn(){
    if(this->currTurn == this->currPlayers->size() - 1){
        this->currTurn = 0;
    }else{
        this->currTurn++;
    }
}

bool Game::rightTurn(Player &player){
    cout << player.name << " " << this->currTurn << endl;
    return this->currPlayers->at(this->currTurn) == &player;
}

void Game::revivePlayer(Player *player){
    this->currPlayers->insert(this->currPlayers->begin()+ (player->pos -1),player);
}

void Game::killPlayer(Player &player){
    for(unsigned int i = 0; i < this->currPlayers->size(); i++){
        if(this->currPlayers->at(i) == &player){
            this->currPlayers->erase(this->currPlayers->begin()+ i , this->currPlayers->begin() + i + 1);
        }
    }
}