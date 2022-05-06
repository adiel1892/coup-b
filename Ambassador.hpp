#include "Player.hpp"
namespace coup{
    class Ambassador : public Player{
        public:
        Ambassador(Game &game , string const &name);
        void block(Player &player);
        void transfer(Player &from, Player &to);
    };
}