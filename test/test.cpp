#define CATCH_CONFIG_MAIN

#include "include\catch.hpp"
#include "..\src\include\warehouse.hpp"

#include <iostream>

using namespace std; 

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
/// \return Warehouse with include\shelf of books.
/// \details
/// Creates a Warehouse with 3 unsorted shelves with a total of 100 Books, 60 Boxes, and 60 Toy Bears.
/// \n Adds forklift certified employee Bob.
/// \n This function can be used in testcases to avoid the repeated construction of Warehouse objects.
Warehouse createMockWarehouse2(){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 30), 
        Pallet("Boxes", 100, 10), 
        Pallet("Books", 100, 10), 
        Pallet("Books", 100, 10)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Boxes", 100, 20), 
        Pallet("Books", 100, 10), 
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
    // Construct empty warehouse and add empty include\shelf and forklift certified Employee.
    Warehouse warehouse = createMockWarehouse2();

    // Er word automatisch bij pickItems gecontroleerd of er genoeg items zijn.
    // Ook word dit elke keer uitgeprint aan het begin voordat er items worden uitgehaald hoeveel items zich bevinden in de shelves.
    // Wanneer er niet genoeg items zijn word dit ook aangegeven.

    // Warehouse begint met 80 boeken in shelves. Hier worden er 50 uitgehaald.
    REQUIRE(warehouse.pickItems("Books", 50) == true);

    // Warehouse begon met 80 boeken in shelves, bij de vorige test zijn er 50 uitgehaald. Hier worden er 30 uitgehaald.
    REQUIRE(warehouse.pickItems("Books", 30) == true);

    // Er zijn nu 80 boeken uit de shelves gehaald en 10 boeken eruit halen zal niet meer lukken hierdoor.
    // Dit toont ook aan dat er nu wel daadwerkelijk uit de shelves/pallets items worden gehaald.
    REQUIRE(warehouse.pickItems("Books", 10) == false);

    // Test incorrecte naam van item.
    REQUIRE(warehouse.pickItems("Pencils", 5) == false);

    // Test boeken bijvoegen.
    REQUIRE(warehouse.shelves[0].pallets[0].putItems(30) == true);

    // Boeken bijgevoegd dus nu kan 20 boeken gepicked worden.
    REQUIRE(warehouse.pickItems("Books", 20) == true);

    // Laatste check, zouden 10 boeken moeten over zijn in de shelves.
    warehouse.countItems("Books", 0);
}
