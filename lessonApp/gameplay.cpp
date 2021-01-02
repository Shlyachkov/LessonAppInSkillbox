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


void SetShips(field* field, std::string& str, point& p1, point& p2, int numDeck)
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
      if(field->CheckShip(p1))
      {
        field->SetShip(p1);
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
        if(CalculationlShipLenght(p1, p2) == (5 - numDeck) && field->CheckShip(p1, p2))
        {
          field->SetShip(p1, p2);
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

void PrepareShips(field* field, std::string& str)
{
  point buffX = {0,0};
  point buffY = {0,0};

  int oneDeck = 4;
  int twoDeck = 3;
  int threeDeck = 2;
  int forDeck = 1;

  SetShips(field, str, buffX, buffY, oneDeck);
  SetShips(field, str, buffX, buffY, twoDeck);
  SetShips(field, str, buffX, buffY, threeDeck);
  SetShips(field, str, buffX, buffY, forDeck);
}