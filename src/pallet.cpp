#include "include\pallet.hpp"

#include <iostream>
#include <string>

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount): itemCount(itemCount), itemCapacity(itemCapacity), itemName(itemName) {
}

Pallet::Pallet(): itemCount(0), itemCapacity(0), itemName(""){
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
    if (itemCount < itemCapacity) {
    itemCount += 1;
    return true;
    }
    return false;
}

bool Pallet::putItems(int itemsToPut){
    int count = itemsToPut;
    for (int i=0; i<itemsToPut; i++){
        if (itemCount < itemCapacity) {
        itemCount += 1;
        count -= 1;
        if (count == 0){
            cout << "Added " << itemsToPut << " items." << endl;
            return true;
            }
        }
    }
    cout << "Hit itemcapacity cap" << endl;
    cout << "Added " << itemsToPut - itemCount << " items." << endl;
    return false;
}

bool Pallet::isEmpty()
{
    return false;
}

bool Pallet::isFull()
{
    return true;
}