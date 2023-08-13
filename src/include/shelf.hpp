#include "pallet.hpp"
#include "IContrainer.hpp"
#include <iostream>
#include <array>
#pragma once
// : IContainer
class Shelf : IContainer
{
public:
    std::array<Pallet, 4> pallets;
    Shelf();
    bool swapPallet(int slot, int slot2);
    // isFull overerving van IContainer.
    bool isFull();
    // isEmpty overerving van IContainer.
    bool isEmpty();
};
