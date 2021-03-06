#include "Contessa.hpp"
using namespace coup;

Contessa::Contessa(Game &game , const string &name) : Player(game,name,"Contessa"){

}
void Contessa::block(Player &player){
    if(player.job == "Assassin" && player.last_action == "coup" && player.assassinUsed){
        if(this->game->lastKilledPlayer == nullptr){
            throw invalid_argument("There is not a dead player");
        }
        coup::Game::revivePlayer(this->game->lastKilledPlayer);
        this->game->lastKilledPlayer = nullptr;
        this->assassinUsed = false;

    }else{
        throw invalid_argument("Contessa can block only Assassin if his last action is coup");
    }
}
