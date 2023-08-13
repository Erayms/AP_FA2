#include "shelf.hpp"
#include "employee.hpp"
#include <iostream>
#include <vector>
using namespace std;
#pragma once

class Warehouse
{
public:
    vector<Employee> Employees;
    vector<Shelf> shelves;

    Warehouse();
    void addEmployee(Employee employee);
    void addShelf(Shelf shelf);
    bool rearrangeShelf(Shelf& shelf);
    bool pickItems(string itemName, int itemCount);
    bool countItems(string itemName, int itemcount);
};
