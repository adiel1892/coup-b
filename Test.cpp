#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

#include <iostream>
#include "doctest.h"
using namespace std;
using namespace coup;

Game game_1{};
Duke duke{game_1, "Moshe"};
Assassin assassin{game_1, "Yossi"};
Ambassador ambassador{game_1, "Meirav"};
Captain captain{game_1, "Reut"};
Contessa contessa{game_1, "Gilad"}; 
TEST_CASE("game 1"){
    cout << "starting test 1 \n";
    vector<string> players = game_1.players();
    CHECK(players.size() == 5);
    // CHECK(players.at(0) == "Moshe");
    // CHECK(players.at(1) == "Yossi");
    // CHECK(players.at(2) == "Meirav");
    // CHECK(players.at(3) == "Reut");
    // CHECK(players.at(4) == "Gilad");
    // CHECK(game_1.turn() == "Moshe");
    


}
