#include <iostream>
#include <array>
#include "../include/pallet.hpp"
#pragma once

class Shelf
{
public:
    std::array<Pallet, 4> pallets;
    Shelf();
    bool swapPallet(int slot, int slot2);
};