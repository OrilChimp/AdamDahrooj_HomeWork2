#pragma once
#include <string>
#include "DeviceList.h"

class User
{
public:
    unsigned int getID() const;
    std::string getUserName() const;
    unsigned int getAge() const;
    DevicesList& getDevices();

    void init(unsigned int id, const std::string& username, unsigned int age);
    void addDevice(const Device& newDevice);
    bool checkIfDevicesAreOn() const;
    void clear();

private:
    unsigned int _id;
    std::string _username;
    unsigned int _age;
    DevicesList _devices; 
};
