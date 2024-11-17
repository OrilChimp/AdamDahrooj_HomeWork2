#include "SocialNetwork.h"
#include "User.h"


void SocialNetwork::init(const std::string& networkName, int minAge)
{
    this->_networkName = networkName;
    this->_minAge = minAge;
    this->_profiles.init();
}

void SocialNetwork::clear()
{
    this->_profiles.clear();
}

std::string SocialNetwork::getNetworkName() const
{
    return this->_networkName;
}

int SocialNetwork::getMinAge() const
{
    return this->_minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
    if (profile_to_add.getOwner().getAge() < this->_minAge) 
    {
        return false;
    }
    this->_profiles.add(profile_to_add);
    return true;
}

std::string SocialNetwork::getWindowsDevices() const
{
    std::string result = "";
    ProfileNode* current = this->_profiles.get_first();

    while (current != nullptr)
    {
        Profile profile = current->get_data();
        User user = profile.getOwner();
        DeviceNode* deviceNode = user.getDevices().get_first();

        while (deviceNode != nullptr)
        {
            Device device = deviceNode->get_data();
            if (device.getOS().find("Windows") != std::string::npos)
            {
                result += "[" + std::to_string(device.getID()) + ", " + device.getOS() + "], ";
            }
            deviceNode = deviceNode->get_next();
        }
        current = current->get_next();
    }

    if (!result.empty())
    {
        result.erase(result.size() - 2);
    }
    return result;
}



// TODO ; Fix this shit when schooling