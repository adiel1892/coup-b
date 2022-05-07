#include "Duke.hpp"
using namespace coup;
constexpr int taxFee = 3;
Duke::Duke(Game &game , const string &name) : Player(game,name,"Duke"){
    
}

void Duke::block(Player &player){
    if(player.last_action == "foreign aid"){
        player.wage -= 2;
        this->last_action = "block";
    }else{
        throw invalid_argument("it is not this player turn");
    }

}

void Duke::tax(){
    this->game->validNumPlayers();
    if(!game->rightTurn(*this)){
        throw invalid_argument("it is not this player turn");
    }
    if(this->wage >= mustCoup){
        throw invalid_argument("Player has more than 10 coins. must coup");
    }
    this->wage += taxFee;
    this->last_action = "tax";
    this->game->updateTurn();

    
}