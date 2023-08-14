#include "include\warehouse.hpp"

#include <iostream>
#include <vector>

using namespace std;

Warehouse::Warehouse(){
};

void Warehouse::addEmployee(Employee employee){
    Employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    shelves.push_back(shelf);
}

/**
 * Rearranged de meegegeven shelf op oplopend itemcount.
 *
 * @param shelf: shelf pointer dat veranderd moet worden (Shelf&)
 * @return bool (true of false)
 */
bool Warehouse::rearrangeShelf(Shelf& shelf) {
    for (Employee emp : Employees) {
        if (emp.forkliftCertificate && !emp.busy) {
            int n = shelf.pallets.size();
            bool swapped;
            
            for (int i = 0; i < n - 1; i++) {
                swapped = false;
                
                for (int j = 0; j < n - i - 1; j++) {
                    if (shelf.pallets[j].getItemCount() > shelf.pallets[j + 1].getItemCount()) {
                        shelf.swapPallet(j, j + 1);
                        swapped = true;
                    }
                }
                
                if (!swapped) break;
            }
            
            return true;
        }
    }
    
    return false;
}

/** 
 * Pakt het aantal (itemCount) van product (itemName) uit de warehouse als er genoeg items zijn.
 * 
 * @param itemname: naam van het item dat word gepickt (string)
 * @param itemcount: aantal items dat gepicked moeten worden (int)
 * @return bool (true of false)
 */
bool Warehouse::pickItems(string itemName, int itemCount) {
    if (countItems(itemName, itemCount) == true){
        for (Shelf& shelf : shelves) {
            for (Pallet& pallet : shelf.pallets) {
                if (pallet.getItemname() == itemName && pallet.getItemCount() > 0){   
                    int amount = pallet.getItemCount();
                    for (int i = 0; i < amount; i++){
                        pallet.takeOne();
                        itemCount -= 1;
                        if (itemCount <= 0){
                            return true;
                        }
                    }
                }
            }
        }
    }
    cout << "Not enough " << itemName << " can not succeed the pickItems function." << endl;
    return false;
}

/**
 * Telt het aantal items (itemName) dat zich bevind in het gehele warehouse.
 * Als het gelijk of groter is dan itemCount krijg je true anders false.
 *
 * @param itemname: naam van het item dat word geteld (string)
 * @param itemcount: aantal items dat geteld moet worden (int)
 * @return bool (true of false)
 */
bool Warehouse::countItems(string itemName, int itemcount){
    int total = 0;
    for (Shelf shelf : shelves) {
        for (Pallet pallet : shelf.pallets) {
            if (pallet.getItemname() == itemName)
            {   
                int amount = pallet.getItemCount();
                total += amount;
            }
        }
    }

    if (total >= itemcount)
    {
        cout << "Current itemcount in warehouse for " << itemName << " is " << total << endl;
        return true;
    }
    else {
        cout << "Current itemcount in warehouse for " << itemName << " is " << total << endl;
        return false;
    }
}
