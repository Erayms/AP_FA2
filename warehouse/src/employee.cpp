#include <iostream>
#include <string>
#include "C:\Users\Eray\Desktop\AP_FA2\warehouse\src\include\employee.hpp"

Employee::Employee(std::string name, bool forkliftCertificate): name(name), forkliftCertificate(forkliftCertificate){
}

std::string Employee::getName()
{
    return name;
}

bool Employee::getBusy()
{
    return busy;
}

// verandering gemaakt in UML staat busy, hier busy2 van gemaakt.
// Anders word de boolean niet correct overgenomen.
void Employee::setBusy(bool busy2)
{
    busy = busy2;
}

bool Employee::getForkliftCertificate()
{
    return forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftcertificate)
{
    forkliftCertificate = forkliftcertificate;
}