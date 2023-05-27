#include <iostream>
#include <string>
#include <array>
#include "../hpp/shelf.hpp"

bool Shelf::swapPallet(int slot, int slot2)
{   
    Pallet temp = pallets[slot];
    pallets[slot] = pallets[slot2];
    pallets[slot2] = temp;
    return true;
}