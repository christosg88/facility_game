#include "FPlayerHighest.h"
#include "FacilityGame.h"
#include "NightHawk.h"
#include "enums.h"

#include <utility>

int main() {
  FacilityGame game(10000, std::random_device()());

  std::pair<FPlayerHighest, NightHawk> players{
      Player::PLAYER_A,
      Player::PLAYER_B};

  players.first.initialize(game);
  players.second.initialize(game);

  while (true) {
    if (game.is_finished()) {
      break;
    }
    game.append_move(Player::PLAYER_A, players.first.next_move(game));
    if (game.is_finished()) {
      break;
    }
    game.append_move(Player::PLAYER_B, players.second.next_move(game));
  }
  game.print(true);
  game.print_score_calculation();

  return 0;
}
