#include <iostream>
#include <string>
#include <array>
#include "C:\Users\Eray\Desktop\AP_FA2\warehouse\src\include\shelf.hpp"

Shelf::Shelf(): pallets({}){
}

bool Shelf::swapPallet(int slot, int slot2)
{   
    Pallet temp = pallets[slot];
    pallets[slot] = pallets[slot2];
    pallets[slot2] = temp;
    return true;
}