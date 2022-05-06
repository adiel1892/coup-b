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
    // this->lastKilledPlayer = nullptr;
}

int Player::coins(){
    return this->wage;
}
string Player::role(){
    return this->job;
}
void Player::income(){
    if(!this->game->rightTurn(*this)){
        throw invalid_argument("it is not this player turn");
    }
    this->wage++;
    this->game->updateTurn();
    this->last_action = "income";
}
void Player::foreign_aid(){
    if(!this->game->rightTurn(*this)){
        throw invalid_argument("it is not this player turn");
    }
    this->wage += 2;
    this->game->updateTurn();
    this->last_action = "foreign aid";

}
void Player::coup(Player &player){
    if(!this->game->rightTurn(*this)){
        throw invalid_argument("it is not this player turn");
    }
    if(this->job == "Assassin"){
        if(this->wage >= 3){
            this->wage -= 3;
            this->game->updateTurn();
            this->last_action = "coup";
            this->lastKilledPlayer = &player;
            this->game->killPlayer(player);
        }
    }else if(this->wage >= 7){
        this->wage -= 7;
        this->game->updateTurn();
        this->last_action = "coup";
    }else{
        throw invalid_argument("The player must have 7 coins for doing this activity");
    }
}
