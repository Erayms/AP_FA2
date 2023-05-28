#include <iostream>
#include <string>
#pragma once

class Pallet
{
public:
    int itemCount;
    std::string itemName;
    int itemCapacity;

    Pallet(std::string itemName, int itemCapacity, int itemCount);
    Pallet();
    std::string getItemname();
    int getItemCount();
    int getRemainingSpace();
    bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
    bool takeOne();
    bool putOne();
};