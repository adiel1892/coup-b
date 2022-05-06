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
    }
}

void Captain::steal(Player &player){
    if(!game->rightTurn(*this)){
        throw invalid_argument("it is not this player turn");
    }
    if(player.wage >= 2){
        player.wage -= 2;
        this->wage += 2;
        this->last_action = "steal";
    }
}