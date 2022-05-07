#include "Player.hpp"
using namespace std;
namespace coup{
    class Duke : public Player{
        public:
        Duke(Game &game , const string & name);
        void block(Player &player);
        void tax();
    };
}