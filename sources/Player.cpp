#include "Player.hpp"
#include "Assassin.hpp"
using namespace coup;
using namespace std;

Player::Player(Game & game, const string & name, const string & job){
    this->name = name;
    this->job = job;
    this->game = &game;
    this->game->addPlayer(this);
    this->wage = 0;
    this->last_action = "";
    this->stolen = "";
    this->alive = true;
    this->assassinUsed = false;
}

int Player::coins(){
    return this->wage;
}
string Player::role(){
    return this->job;
}
void Player::income(){
    this->game->validNumPlayers();
    if(!this->game->rightTurn(*this)){
        throw invalid_argument("it is not this player turn");
    }
    if(this->wage >= 10){
        throw invalid_argument("Player has more than 10 coins. must coup");
    }
    this->wage++;
    this->game->updateTurn();
    this->last_action = "income";
    this->game->started = true;
}
void Player::foreign_aid(){
    this->game->validNumPlayers();
    if(!this->game->rightTurn(*this)){
        throw invalid_argument("it is not this player turn");
    }
    if(this->wage >= 10){
        throw invalid_argument("Player has more than 10 coins. must coup");
    }
    this->wage += 2;
    this->game->updateTurn();
    this->last_action = "foreign aid";

}

void Player::coup(Player &player){
    this->game->validNumPlayers();
    if(!this->game->rightTurn(*this)){
        throw invalid_argument("it is not this player turn");
    }
    if(player.alive == false){
        throw invalid_argument("Player already dead");
    }
    if(this->job == "Assassin"){
        if(this->wage >= 3 && this->wage <= 6){
            this->wage -= 3;
            this->last_action = "coup";
            this->assassinUsed = true;
            this->game->killPlayer(player);
            this->game->updateTurn();
        }else if(this->wage >= 7){
            this->wage -= 7;
            this->assassinUsed = false;
            this->game->killPlayer(player);
            this->game->updateTurn();
            this->last_action = "coup";
        }else{
            throw invalid_argument("The Assassin must have 3 coins for doing this activity");
        }
    }else if(this->wage >= 7){
        this->wage -= 7;
        this->game->killPlayer(player);
        this->game->updateTurn();
        this->last_action = "coup";
    }else{
        cout << this->wage << this->name << this->job << this->pos << endl;
        throw invalid_argument("The player must have 7 coins for doing this activity");
    }
}
