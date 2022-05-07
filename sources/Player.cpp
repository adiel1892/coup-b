#include "Player.hpp"
#include "Assassin.hpp"
using namespace coup;
using namespace std;
constexpr int useAssassin = 3;
constexpr int notUseAssassin = 7;
constexpr int inRangeOfAssassin = 6;


Player::Player(Game & game, const string & name, const string & job){
    this->name = name;
    this->job = job;
    this->game = &game;
    this->game->addPlayer(this);
}

int Player::coins()const{
    return this->wage;
}
string Player::role()const{
    return this->job;
}
void Player::income(){
    this->game->validNumPlayers();
    if(!this->game->rightTurn(*this)){
        throw invalid_argument("it is not this player turn");
    }
    if(this->wage >= mustCoup){
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
    if(this->wage >= mustCoup){
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
    if(!player.alive){
        throw invalid_argument("Player already dead");
    }
    if(this->job == "Assassin"){
        if(this->wage >= useAssassin && this->wage <= inRangeOfAssassin){
            this->wage -= useAssassin;
            this->last_action = "coup";
            this->assassinUsed = true;
            this->game->killPlayer(player);
            this->game->updateTurn();
        }else if(this->wage >= notUseAssassin){
            this->wage -= notUseAssassin;
            this->assassinUsed = false;
            this->game->killPlayer(player);
            this->game->updateTurn();
            this->last_action = "coup";
        }else{
            throw invalid_argument("The Assassin must have 3 coins for doing this activity");
        }
    }else if(this->wage >= notUseAssassin){
        this->wage -= notUseAssassin;
        this->game->killPlayer(player);
        this->game->updateTurn();
        this->last_action = "coup";
    }else{
        throw invalid_argument("The player must have 7 coins for doing this activity");
    }
}
