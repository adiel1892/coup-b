#include "Player.hpp"
namespace coup{
    class Ambassador : public Player{
        public:
        Ambassador(Game &game , string const &name);
        void transfer(Player from, Player to);
    };
}