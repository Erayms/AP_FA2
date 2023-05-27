#include <iostream>
#include <string>

class Employee
{
public:
    std::string name;
    bool busy;
    bool forkliftCertificate;

    Employee(std::string name, bool forkliftCertificate);
    Employee getName();
    Employee getBusy();
    Employee setBusy(bool busy);
    Employee egtForkliftCertificate();
    Employee setForkliftCertificate(bool forkliftcertificate);
};