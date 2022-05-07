#include "Contessa.hpp"
using namespace coup;

Contessa::Contessa(Game &game , const string &name) : Player(game,name,"Contessa"){

}
void Contessa::block(Player &player){
    if(player.job == "Assassin" && player.last_action == "coup"){
        if(!this->lastKilledPlayer){
            throw invalid_argument("There is not a dead player");
        }
        cout << "got to here" << endl;
        this->game->revivePlayer(this->lastKilledPlayer , this->lastKilledIndex);
        this->lastKilledPlayer = nullptr;

    }else{
        throw invalid_argument("Contessa can block only Assassin if his last action is coup");
    }
}
