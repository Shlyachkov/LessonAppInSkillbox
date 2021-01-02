#pragma once
#include <string>

enum status
{
  EMPTY,
  THERE_WAS_A_SHOT,
  ENTIRE,
  INJURED,
  KILLED
};

class point
{
public:

  point(){};
  ~point(){};

  point(int x, int y);

  void SetPoint(int x, int y);

  int GetX();

  int GetY();

private:
  int _x = 0;
  int _y = 0;
};

char GetStatus(status st);

bool CheckPointInStream(const std::string& std);

void TranslatePointInStreamToPoint(const std::string& std, point& p);

void TranslatePointInStreamToString(std::string& std, point& p);

int CalculationlShipLenght(point& p1, point& p2);