#include <Game.h>

int main() {
  Game::getInstance()->inicio();
  Game::getInstance()->run();

  return 0;
}