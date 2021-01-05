#include "point.h"
#include "gameplay.h"
#include "field.h"

int main() {
  field* playerA = new field;
  field* playerB = new field;

  playerA->InitField();
  playerB->InitField();

  std::string movePlayer = {};

  std::cout << "Welcome to battle ship!\n\n";

  SetRandomShips(playerA);

  PrintField(playerA, playerB);

  std::cout << "Please, input data ships for first player!\n\n";

  PrepareShips(playerA, movePlayer);

  PrintField(playerA, playerB);

  std::cout << "Please, input data ships for second player!\n\n";

  PrepareShips(playerB, movePlayer);

  PrintField(playerA, playerB);

  std::cout << "Let's start!\n\n";


  delete playerA;
  delete playerB;
}