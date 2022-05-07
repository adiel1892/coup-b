#include "Ambassador.hpp"
using namespace coup;


Ambassador::Ambassador(Game &game , string const &name) : Player(game,name,"Ambassador"){


}
void Ambassador::block(Player &player){
    if(player.job == "Captain" && player.last_action == "steal"){
        if(player.wage >= 2){
            player.wage -= 2;
            for(unsigned int i = 0; i < this->game->currPlayers->size(); i++){
                if(this->game->currPlayers->at(i)->stolen == "stolen" && this->game->currPlayers->at(i)->alive){
                    this->game->currPlayers->at(i)->wage += 2;
                }
            }
        }else if(player.wage == 1){
            player.wage -= 1;
            for(unsigned int i = 0; i < this->game->currPlayers->size(); i++){
                if(this->game->currPlayers->at(i)->stolen == "stolen" && this->game->currPlayers->at(i)->alive){
                    this->game->currPlayers->at(i)->wage += 1;
                }
            }
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
    if(this->wage >= mustCoup){
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

