#include "Captain.hpp"
using namespace coup;

Captain::Captain(Game &game , const string &name) : Player(game,name,"Captain"){

}
void Captain::block(Player &player){
    if(player.job == "Captain" && player.last_action == "steal"){
        if(player.wage >= 2){
            player.wage -= 2;
            this->wage += 2; 
        }
    }else{
        throw invalid_argument("Captain can block only Captain");
    }
}

void Captain::steal(Player &player){
    this->game->validNumPlayers();
    if(!game->rightTurn(*this)){
        throw invalid_argument("it is not this player turn");
    }
    if(this->wage >= 10){
        throw invalid_argument("Player has more than 10 coins. must coup");
    }
    if(player.wage >= 2){
        player.wage -= 2;
        this->wage += 2;
    }else if(player.wage == 1){
        player.wage -= 1;
        this->wage += 1;
    }
    player.stolen = "stolen";
    this->last_action = "steal";
    this->game->updateTurn();
}