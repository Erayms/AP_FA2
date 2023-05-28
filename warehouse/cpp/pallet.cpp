#include <iostream>
#include <string>
#include "../warehouse/src/include/pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount): itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount) {
}

Pallet::Pallet(){
}

std::string Pallet::getItemname()
{
    return itemName;
}

int Pallet::getItemCount()
{
    return itemCount;
}

int Pallet::getRemainingSpace()
{
    return itemCapacity - Pallet::getItemCount();
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity)
{
    itemName = itemName;
    itemCapacity = itemCapacity;
    return true;
}

bool Pallet::takeOne()
{   
    if (itemCount > 0) {
    itemCount -= 1;
    return true;
    }
    return false;
}

bool Pallet::putOne()
{   
    if (itemCount < itemCapacity) {
    itemCount += 1;
    return true;
    }
    return false;
}