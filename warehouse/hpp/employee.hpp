#include <iostream>
#include <string>

class Employee
{
public:
    std::string name;
    bool busy;
    bool forkliftCertificate;

    Employee(std::string name, bool forkliftCertificate);
    std::string getName();
    bool getBusy();
    void setBusy(bool busy);
    bool getForkliftCertificate();
    void setForkliftCertificate(bool forkliftcertificate);
};