#pragma once
#include <iostream>
#include <string>
#include "field.h"
#include <ctime>

void PrintField(field* fieldPlayerA, field* fieldPlayerB);

void SetShips(field* fieldPlayer, std::string& str, point& p1, point& p2, int numDeck);

void SetRandomShips(field* fieldPlayer);

void PrepareShips(field* fieldPlayer, std::string& str);