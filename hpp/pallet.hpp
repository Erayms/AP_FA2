#include <iostream>
#include <string>

class Pallet
{
public:
    int itemCount;
    std::string itenName;
    int itemCapacity;

    Pallet(std::string itemName, int itemCapacity, int itemCount);
    Pallet();
    std::string getItemName();
    Pallet getItemCount();
    Pallet getRemainingSpace();
    Pallet reallocateEmptyPallet(std::string itemName, int itemCapacity);
    Pallet takeOne();
    Pallet putOne();
};