#pragma once
#include "point.h"
#include "math.h"

class field
{
public:

  field(){};
  ~field(){};

  void InitField();
  
  void SetShip(point& p);

  void SetShip(point& p1, point& p2);

  

  bool CheckShip(point& p);

  bool CheckShip(point& p1, point& p2);

  status Get(int x, int y);

  const char* GetStatus(point& p);

  bool CheckFieldOnFullDamage();

  void SetPlayerMove(point& p);


private:

  status _field[10][10] = {};
};