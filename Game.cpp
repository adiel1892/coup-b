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
    if(this->currPlayers->size() != 1){
        throw invalid_argument("There is only one winner");
    }
    return this->currPlayers->at(0)->name;
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
    return this->currPlayers->at(this->currTurn) == &player;
}

void Game::revivePlayer(Player *player , unsigned int pos){
    cout << pos << endl;
    cout << player->name << player->name << endl;
    this->currPlayers->insert(this->currPlayers->begin() + pos,player);
}

void Game::killPlayer(Player &player){
    cout << "killing now " << player.name << endl;
    
    for(unsigned int i = 0; i < this->currPlayers->size(); i++){
        if(this->currPlayers->at(i) == &player){
            this->currPlayers->erase(this->currPlayers->begin()+ i , this->currPlayers->begin() + i + 1);
            break;
        }
    }
}