#include "User.h"

void User::init(unsigned int id, const std::string& username, unsigned int age)
{
    this->_id = id;
    this->_username = username;
    this->_age = age;
    this->_devices.init(); // Initialize the device list
}

void User::clear()
{
    this->_devices.clear(); // Clear the device list
}

unsigned int User::getID() const
{
    return this->_id;
}

std::string User::getUserName() const
{
    return this->_username;
}

unsigned int User::getAge() const
{
    return this->_age;
}

DevicesList& User::getDevices()
{
    return this->_devices;
}

void User::addDevice(const Device& newDevice)
{
    this->_devices.add(newDevice);
}

// Checks if all devices are turned on
bool User::checkIfDevicesAreOn() const
{
    DeviceNode* current = this->_devices.get_first();
    while (current != nullptr)
    {
        if (!current->get_data().isActive())
        {
            return false; // found an inactive device
        }
        current = current->get_next();
    }
    return true; // All devices are active
}
