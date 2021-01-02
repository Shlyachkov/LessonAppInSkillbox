#include "field.h"

void field::InitField()
{
  for (int i = 0; i < 10; ++i)
  {
    for (int j = 0; j < 10; ++j)
    {
      _field[i][j] = status::EMPTY;
    }
  }
}

void field::SetShip(point& p)
{
  _field[p.GetX()][p.GetY()] = status::ENTIRE;
}

void field::SetShip(point& p1, point& p2)
{
  int beginPoint = 0;

  if(p1.GetX() == p2.GetX())
  {
    int dy = (p1.GetY() > p2.GetY() ? -1 : 1);
    beginPoint = p1.GetY();
    while(beginPoint != p2.GetY())
    {
      _field[p1.GetX()][beginPoint] = status::ENTIRE;
      beginPoint += dy;
    }
    _field[p1.GetX()][beginPoint] = status::ENTIRE;
  }
  else
  {
    int dx = (p1.GetX() > p2.GetX() ? -1 : 1);
    beginPoint = p1.GetX();
    while(beginPoint != p2.GetX())
    {
      _field[beginPoint][p1.GetY()] = status::ENTIRE;
      beginPoint += dx;
    }
    _field[beginPoint][p1.GetY()] = status::ENTIRE;
  }
}

bool field::CheckShip(point &p)
{
  bool result = true;
  if(_field[p.GetX()][p.GetY()] != status::EMPTY)
    return false;
  int x[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
  int y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
  for(int cnt = 0; cnt < 8; ++cnt)
  {
    if(((p.GetX() + x[cnt]) < 0 || (p.GetX() + x[cnt]) > 9) || ((p.GetY() + y[cnt]) < 0 || (p.GetY() + y[cnt]) > 9))
        continue;
    else if(_field[p.GetX() + x[cnt]][p.GetY() + y[cnt]] != status::EMPTY)
      result = false;
  }
  return result;
}

bool field::CheckShip(point& p1, point& p2)
{
  bool result = true;
  int cnt = 0;
  point dir = {0,0};
  
  if(p1.GetX() == p2.GetX())
  {
    for(cnt = p1.GetY(); cnt < p2.GetY(); ++cnt)
    {
      dir.SetPoint(p1.GetX(), cnt);
      if(!this->CheckShip(dir))
        result = false;
    }
    dir.SetPoint(p1.GetX(), cnt);
    if(!this->CheckShip(dir))
        result = false;
    return result;
  }
  else
  {
    for(cnt = p1.GetX(); cnt < p2.GetX(); ++cnt)
    {
      dir.SetPoint(cnt, p1.GetY());
      if(!this->CheckShip(dir))
        result = false;
    }
    dir.SetPoint(cnt, p1.GetY());
    if(!this->CheckShip(dir))
        result = false;
    return result;
  }
  return result;
}

status field::Get(int x, int y)
{
  return _field[x][y];
}