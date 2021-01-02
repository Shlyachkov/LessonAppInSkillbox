#pragma once
#include <iostream>
#include <string>
#include "field.h"

void PrintField(field* fieldPlayerA, field* fieldPlayerB);

void SetShips(field* field, std::string& str, point& p1, point& p2, int numDeck);

void PrepareShips(field* field, std::string& str);