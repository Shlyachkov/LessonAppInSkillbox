#include "point.h"
#include "gameplay.h"
#include "field.h"

int main() {
  field* playerA = new field;
  field* playerB = new field;

  int BattleResult = 0;

  playerA->InitField();
  playerB->InitField();

  std::string movePlayer = {};

  std::cout << "Welcome to battle ship!\n\n";

  PrintField(playerA, playerB);

  std::cout << "Please, input data ships for first player!\n\n";

  PrepareShips(playerA, movePlayer);
  
  /*for debugging*/
  //SetRandomShips(playerA); 

  PrintField(playerA, playerB);

  std::cout << "Please, input data ships for second player!\n\n";

  PrepareShips(playerB, movePlayer);

  /*for debugging*/
  //SetRandomShips(playerB);

  PrintField(playerA, playerB);

  std::cout << "Let's start!\n\n";
  
  BattleResult = Run(playerA, playerB, movePlayer);
  if(BattleResult == 1)
    std::cout << "Game over. Player B win!" << "\n";
  else if(BattleResult == 2)
    std::cout << "Game over. Player A win!" << "\n";

  delete playerA;
  delete playerB;
}