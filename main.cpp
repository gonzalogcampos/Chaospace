#include <SFML/Graphics.hpp>
#include <iostream>

#include <Game.h>

int main() {
  Game::getInstance()->inicio();
  Game::getInstance()->run();

  return EXIT_SUCCESS;
}