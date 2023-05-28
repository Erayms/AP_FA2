#include <iostream>
#include <vector>
#include "../warehouse/src/include/warehouse.hpp"
#include "../warehouse/src/include/employee.hpp"
#include "../warehouse/src/include/pallet.hpp"

Warehouse::Warehouse(){
};

void Warehouse::addEmployee(Employee employee){
    Employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    Shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf){
    for (Employee i : Employees){
        if (i.forkliftCertificate == true){
            for (int i = 0; i < shelf.pallets.size(); i++){
                for (int j = 0; j < (shelf.pallets.size() - 1); i++) {
                    int num1 = shelf.pallets[j].getItemCount();
                    int num2 = shelf.pallets[j+1].getItemCount();
                    if (num1 < num2){
                        shelf.swapPallet(j, j+1);
                    }
                }
            return true;
            }
        }
    return false;
    }
}

bool Warehouse::pickItems(std::string itemName, int itemCount)
{
    for (Shelf shelf : Shelves) {
        int items = 0;
        for (Pallet pallet : shelf.pallets) {
            if (pallet.getItemname() == itemName && pallet.getItemCount() > 0)
            {   
                items += pallet.getItemCount();
            }
        }

        if (items >= itemCount)
        {
            for (Pallet pallet : shelf.pallets) {
                if (pallet.getItemname() == itemName && pallet.getItemCount() > 0)
            {   
                pallet.takeOne();
            }
        return true;
        }
        }
    return false;
    }
}