#include "Player.hpp"
namespace coup{
    class Captain : public Player{
        public:
        Captain(Game &game , const string &name);
        void steal(Player player);
        void block(Player player);
    };
}