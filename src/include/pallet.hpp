#include <iostream>
#include <string>
#include "IContrainer.hpp"

using namespace std;

#pragma once
class Pallet : IContainer
{
    public:
    int itemCount;
    int itemCapacity;
    string itemName;

    Pallet(string itemName, int itemCapacity, int itemCount);
    Pallet();
    string getItemname();
    int getItemCount();
    int getRemainingSpace();
    bool reallocateEmptyPallet(string itemName, int itemCapacity);
    bool takeOne();
    bool putOne();
    bool putItems(int itemsToPut);

    // isEmpty overerving van IContainer.
    bool isEmpty();
    // isFull overerving van IContainer.
    bool isFull();
};
