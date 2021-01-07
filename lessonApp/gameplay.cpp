#include "gameplay.h"

void PrintField(field* fieldPlayerA, field* fieldPlayerB)
{
    const char* alphabet = "ABCDEFGHIJABCDEFGHIJ";

    for (int j = 0; j < 22; ++j)
    {
      if (j != 0 && j != 11)
      {
        if(j > 11)
          std::cout << alphabet[j-2] << " ";
        else
          std::cout << alphabet[j-1] << " ";
      }
      else
      {
        if(j == 11)
          std::cout << "      ";
        else
          std::cout << "    ";
      }
    }
    std::cout << "\n";
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 22; ++j)
        {
            if (j != 0 && j != 11)
            {
              if(j > 11)
                std::cout << GetStatus(fieldPlayerB->Get(i, j - 12)) << " ";
              else if(j == 10)
                std::cout << GetStatus(fieldPlayerA->Get(i, j - 1)) << "   ";
              else
                std::cout << GetStatus(fieldPlayerA->Get(i, j - 1)) << " ";
            }
            else
            {
              if(i == 9)
                std::cout << i + 1 << "  ";
              else
                std::cout << i + 1 << "   ";
            }
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}


void SetShips(field* fieldPlayer, std::string& str, point& p1, point& p2, int numDeck)
{
  if(numDeck == 4)
  {
    for(size_t i = 0; i < numDeck;)
    {
      while(!CheckPointInStream(str))
      {
        std::cout << "Please, set "<< i + 1 << ", " << 5 - numDeck << "' deck ship. Input coordinate: ";
        std::cin >> str;
        TranslatePointInStreamToPoint(str, p1);
      }
      str.clear();
      if(fieldPlayer->CheckShip(p1))
      {
        fieldPlayer->SetShip(p1);
        std::cout << "The ship set!\n";
        ++i;
      }
      else
        std::cout << "The ship not set!\n";
    }
  }
  else
  {
    for(size_t i = 0; i < numDeck;)
    {
      while(CalculationlShipLenght(p1, p2) != (5 - numDeck))
      {
        while(!CheckPointInStream(str))
        {
          std::cout << "Please, set number " << i + 1 << " " << 5 - numDeck <<"'s deck ship. Input begin coordinate: ";
          std::cin >> str;
          TranslatePointInStreamToPoint(str, p1);
        }
        str.clear();
        while(!CheckPointInStream(str))
        {
          std::cout << "Input end coordinate: ";
          std::cin >> str;
          TranslatePointInStreamToPoint(str, p2);
        }
        str.clear();
        if(CalculationlShipLenght(p1, p2) == (5 - numDeck) && fieldPlayer->CheckShip(p1, p2))
        {
          fieldPlayer->SetShip(p1, p2);
          std::cout << "The ship set!\n";
          ++i;
        }
        else
          std::cout << "The ship not set!\n";
      }
      p1.SetPoint(0, 0);
      p2.SetPoint(0, 0);
    }
  }
}

void SetRandomShips(field* fieldPlayer)
{
  point p1 = {-1,-1};
  point p2 = {-1,-1};
  int x = 0;
  int y = 0;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, -1, 0, 1};
  int cntRandom = 0;
  srand(time(NULL));
  for (size_t i = 0; i < 4; ++i)
  {
    while (!fieldPlayer->CheckShip(p1))
    {
      p1.SetPoint(rand() % 10, rand() % 10);
    }
    fieldPlayer->SetShip(p1);
  }

  p1.SetPoint(-1,-1);

  for (size_t i = 0; i < 3; ++i)
  {
    while (!fieldPlayer->CheckShip(p1, p2))
    {
      x = rand() % 10;
      y = rand() % 10;
      cntRandom = rand() % 4;
      p1.SetPoint(x, y);
      p2.SetPoint(x + dx[cntRandom], y + dy[cntRandom]);
    }
    fieldPlayer->SetShip(p1, p2);
  }

  p1.SetPoint(-1,-1);
  p2.SetPoint(-1,-1);

  for (size_t i = 0; i < 2; ++i)
  {
    while (!fieldPlayer->CheckShip(p1, p2))
    {
      x = rand() % 10;
      y = rand() % 10;
      p1.SetPoint(x, y);
      p2.SetPoint(x + (dx[cntRandom]*2), y + (dy[cntRandom]*2));
    }
    fieldPlayer->SetShip(p1, p2);
  }

  p1.SetPoint(-1,-1);
  p2.SetPoint(-1,-1);

  while (!fieldPlayer->CheckShip(p1, p2))
    {
      x = rand() % 10;
      y = rand() % 10;
      p1.SetPoint(x, y);
      p2.SetPoint(x + (dx[cntRandom]*3), y + (dy[cntRandom]*3));
    }
    fieldPlayer->SetShip(p1, p2);

  p1.SetPoint(-1,-1);
  p2.SetPoint(-1,-1);
}

void PrepareShips(field* fieldPlayer, std::string& str)
{
  point buffX = {0,0};
  point buffY = {0,0};

  int oneDeck = 4;
  int twoDeck = 3;
  int threeDeck = 2;
  int forDeck = 1;

  SetShips(fieldPlayer, str, buffX, buffY, oneDeck);
  SetShips(fieldPlayer, str, buffX, buffY, twoDeck);
  SetShips(fieldPlayer, str, buffX, buffY, threeDeck);
  SetShips(fieldPlayer, str, buffX, buffY, forDeck);
}