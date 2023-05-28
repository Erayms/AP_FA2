#include <iostream>
#include <string>
#include "C:\Users\Eray\Desktop\AP_FA2\warehouse\src\include\pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount): itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount) {
}

Pallet::Pallet(): itemName(""), itemCapacity(0), itemCount(0){
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
    itemCount -= 1;
    return true;
}

bool Pallet::putOne()
{   
    if (itemCount < itemCapacity) 
    {
    itemCount += 1;
    return true;
    }
    return false;
}