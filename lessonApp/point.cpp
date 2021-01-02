#include "point.h"

point::point(int x, int y)
{
  _x = x;
  _y = y;
}
void point::SetPoint(int x, int y)
{
  _x = x;
  _y = y;
}

int point::GetX()
{
  return _x;
}

int point::GetY()
{
  return _y;
}

char GetStatus(status st)
{
char result = ' ';
  switch(st)
  {
    case status::EMPTY:
      result = ' ';
      break;
    case status::ENTIRE:
      result =  '1';
      break;
    case status::THERE_WAS_A_SHOT:
      result =  '.';
      break;
    case status::INJURED:
      result =  '*';
      break;
    case status::KILLED:
      result =  'X';
      break;
    default:
      break;
  }
  return result;
}

bool CheckPointInStream(const std::string& std)
{
  if((std.length() == 2) 
  && (std[0] > 64 && std[0] < 75) && (std[1] > 48 && std[1] < 58))
    return true;
  else if((std.length() == 3) 
  && (std[0] > 64 && std[0] < 75) && (std[1] == 49 && std[2] == 48))
    return true;
  else
    return false;
}

void TranslatePointInStreamToPoint(const std::string& std, point& p)
{
  p.SetPoint((std.length() == 3 ? 9 : std[1] - 49), std[0] - 65);
}

void TranslatePointInStreamToString(std::string& std, point& p)
{
  std.clear();
  std.push_back(p.GetY() + 65);
  if(p.GetX() == 9)
  {
    std.push_back('1');
    std.push_back('0');
  }
  else
    std.push_back(p.GetX() + 49);
}

int CalculationlShipLenght(point& p1, point& p2)
{
  int result = 0;
  int beginPoint = 0;
  if(p1.GetX() == p2.GetX())
  {
    int dy = (p1.GetY() > p2.GetY() ? -1 : 1);
    beginPoint = p1.GetY();
    while(beginPoint != p2.GetY())
    {
      ++result;
      beginPoint += dy;
    }
    ++result;
  }
  else
  {
    int dx = (p1.GetX() > p2.GetX() ? -1 : 1);
    beginPoint = p1.GetX();
    while(beginPoint != p2.GetX())
    {
      ++result;
      beginPoint += dx;
    }
    ++result;
  }
  return result;
}