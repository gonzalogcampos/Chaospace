#include <SFML/Graphics.hpp>
#include <iostream>

#include <Game.h>

int main() {
  
  Game nuevo;

  nuevo.inicio();
  nuevo.run();

  return EXIT_SUCCESS;
}