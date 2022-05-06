#include "Contessa.hpp"
using namespace coup;

Contessa::Contessa(Game &game , const string &name) : Player(game,name,"Contessa"){

}
void Contessa::block(Player &player){
    if(player.job == "Assassin" && player.last_action == "coup"){
        if(this->lastKilledPlayer == nullptr){
            throw invalid_argument("There is not a dead player");
        }
        this->game->revivePlayer(this->lastKilledPlayer);
        this->lastKilledPlayer = nullptr;

    }else{
        throw invalid_argument("Contessa can block only Assassin");
    }
}
