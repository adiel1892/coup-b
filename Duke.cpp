#include "Duke.hpp"
using namespace coup;
Duke::Duke(Game &game , const string &name) : Player(game,name,"Duke"){
    
}

void Duke::block(Player player){
    if(player.last_action == "foreign aid"){
        player.wage -= 2;
        this->last_action = "block";
    }else{
        throw invalid_argument("it is not this player turn");
    }

}

void Duke::tax(){
    if(!game->rightTurn(*this)){
        throw invalid_argument("it is not this player turn");
    }
    this->wage += 3;
    game->updateTurn();
    
}