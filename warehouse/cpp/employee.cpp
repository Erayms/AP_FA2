#include <iostream>
#include <string>
#include "../hpp/employee.hpp"

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

void Employee::setBusy(bool busy)
{
    bool busy = busy;
}

bool Employee::getForkliftCertificate()
{
    return forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftcertificate)
{
    bool forkliftCertificate = forkliftcertificate;
}