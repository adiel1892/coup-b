#include "Player.hpp"
namespace coup{
    class Contessa : public Player{
        public:
        Contessa(Game &game , const string &name);
        void block(Player &player);
    };
}