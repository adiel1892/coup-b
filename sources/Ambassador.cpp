#include "Ambassador.hpp"
using namespace coup;

Ambassador::Ambassador(Game &game , string const &name) : Player(game,name,"Ambassador"){


}
void Ambassador::block(Player &player){
    if(player.job == "Captain" && player.last_action == "steal"){
        if(player.wage >= 2){
            player.wage -= 2;
            this->wage += 2; 
        }
    }else{
        throw invalid_argument("Ambassador can block only Captain");
    }

}
void Ambassador::transfer(Player &from , Player &to){
    this->game->validNumPlayers();
    if(!game->rightTurn(*this)){
        throw invalid_argument("it is not this player turn");
    }
    if(this->wage >= 10){
        throw invalid_argument("Player has more than 10 coins. must coup");
    }
    if(from.wage >= 1){
        from.wage -= 1;
        to.wage += 1;
        this->game->updateTurn();
        this->last_action = "transfer";
    }else{
        throw invalid_argument("There are not enough coins to take from");
    }

}

