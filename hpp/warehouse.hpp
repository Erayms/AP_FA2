#include <iostream>
#include <vector>
#include "../hpp/shelf.hpp"
#include "../hpp/employee.hpp"

class Warehouse
{
public:
    std::vector<Employee> Employees;
    std::vector<Shelf> Shelves;

    Warehouse();
    Warehouse addEmployee(Employee employee);
    Warehouse addShelf(Shelf shelf);
    Warehouse rearrangeShelf(Shelf& shelf);
    Warehouse pickItems(std::string itemName, int itemCount);
};