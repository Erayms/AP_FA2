#include <iostream>
#include <vector>
#include "C:\Users\Eray\Desktop\AP_FA2\warehouse\src\include\warehouse.hpp"

Warehouse::Warehouse(){
};

void Warehouse::addEmployee(Employee employee){
    Employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf)
{
    bool employeeAvailable = false;
    for (Employee employee : Employees)
    {
        if (employee.getForkliftCertificate() && !employee.getBusy())
        {
            employeeAvailable = true;
            break;
        }
    }

    if (!employeeAvailable)
    {   
        return false;
    }

    bool swapped = false;
    for (size_t i = 0; i < shelf.pallets.size() - 1; ++i)
    {
        swapped = false;
        for (size_t j = 0; j < shelf.pallets.size() - i - 1; ++j)
        {
            if (shelf.pallets[j].getItemCount() > shelf.pallets[j + 1].getItemCount())
            {
                shelf.swapPallet(j, j + 1);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break; 
        }
    }
    return true;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    int x = itemCount;
    for (Shelf shelf : shelves) {
        for (Pallet pallet : shelf.pallets) {
            if (pallet.getItemname() == itemName && pallet.getItemCount() > 0)
            {   
                int amount = pallet.getItemCount();
                for (int i = 0; i < amount; i++)
                {
                    pallet.takeOne();
                    x -= 1;
                    if (x <= 0)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}