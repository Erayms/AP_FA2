#include "include\shelf.hpp"

#include <iostream>
#include <string>
#include <array>

Shelf::Shelf(): pallets({}){
}

bool Shelf::swapPallet(int slot, int slot2)
{   
    Pallet temp = pallets[slot];
    pallets[slot] = pallets[slot2];
    pallets[slot2] = temp;
    return true;
}

bool Shelf::isEmpty()
{
    return false;
}

bool Shelf::isFull()
{
    return true;
}