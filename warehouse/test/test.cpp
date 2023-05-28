#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"

#include "..\src\warehouse.cpp"
#include "..\src\shelf.cpp"
#include "..\src\pallet.cpp"
#include "..\src\employee.cpp"

#include <iostream>

///////////////////////////////////////////////////////////////
//                                                           //
//                    Warehouse unittests                    //
//                                                           //
///////////////////////////////////////////////////////////////
//                                                           //
// This file contains all testcases for the Warehouse class. //
// Currently it only contains tests for the rearranging of   //
// shelves. All other Warehouse functions will also need to  //
// be tested. You will have to do this yourself.             //
//                                                           //
// For information on how to write testcases with catch2,    //
// see https://github.com/catchorg/Catch2.                   //
//                                                           //
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
//                Functions used in testcases                //
///////////////////////////////////////////////////////////////

/// \brief 
/// Creates a mock Warehouse.
/// \return Warehouse with shelf of books.
/// \details
/// Creates a Warehouse with 3 unsorted shelves with a total of 100 Books, 60 Boxes, and 60 Toy Bears.
/// \n Adds forklift certified employee Bob.
/// \n This function can be used in testcases to avoid the repeated construction of Warehouse objects.
Warehouse createMockWarehouse(){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Boxes", 100, 10), 
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 20)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 15), 
        Pallet("Boxes", 100, 20), 
        Pallet("Books", 100, 5), 
        Pallet("Boxes", 100, 30)
    };

    Shelf shelf3 = Shelf();
    shelf3.pallets = {
        Pallet("Toy Bears", 100, 20), 
        Pallet("Toy Bears", 100, 10), 
        Pallet(), 
        Pallet("Toy Bears", 100, 30)
    };
    
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addShelf(shelf3);

    warehouse.addEmployee(Employee("Bob", true));

    return warehouse;
}


///////////////////////////////////////////////////////////////
//           Warehouse::pickItems test cases            //
///////////////////////////////////////////////////////////////

TEST_CASE("Pick items", "Warehouse::pickItems"){
    // Construct empty warehouse and add empty shelf and forklift certified Employee.
    Warehouse warehouse = createMockWarehouse();

    // Test wel genoeg boeken op voorraad.
    REQUIRE(warehouse.pickItems("Books", 99) == true);

    // Test precies genoeg boeken op voorraad.
    REQUIRE(warehouse.pickItems("Books", 100) == true);

    // Test niet genoeg boeken op voorraad.
    REQUIRE(warehouse.pickItems("Books", 101) == false);

    // Test incorrecte naam van item.
    REQUIRE(warehouse.pickItems("Pencils", 101) == false);

    warehouse.pickItems("Books", 100);
    // Test 100 items uit voorraad gehaald, niet genoeg voorraad meer voor succes.
    REQUIRE(warehouse.pickItems("Books", 10) == false);
}
