#include <iostream>
#include <array>
#include "../hpp/pallet.hpp"

class Shelf
{
public:
    std::array<Pallet, 4> pallets;
    Shelf();
    Shelf swapPallet(int slot, int slot2);
};