#include "Profile.h"

void Profile::init(User owner)
{
    this->_owner = owner;
    this->_page.init(); 
    this->_friends.init(); 
}

void Profile::clear()
{
    this->_page.clearPage(); 
    this->_friends.clear(); 
}

User Profile::getOwner() const
{
    return this->_owner;
}

void Profile::setStatus(const std::string& new_status)
{
    this->_page.setStatus(new_status); 
}

void Profile::addPostToProfilePage(const std::string& post)
{
    this->_page.addLineToPosts(post); 
}

void Profile::addFriend(User friend_to_add)
{
    this->_friends.add(friend_to_add); 
}

std::string Profile::getPage() const
{
    std::string pageContent = "Status: " + this->_page.getStatus() + "\n";
    pageContent += "*******************\n";
    pageContent += "*******************\n";
    pageContent += this->_page.getPosts(); 
    return pageContent;
}

std::string Profile::getFriends() const
{
    std::string friendsList = "";
    UserNode* current = this->_friends.get_first();
    while (current != nullptr)
    {
        if (!friendsList.empty())
        {
            friendsList += ",";  
        }
        friendsList += current->get_data().getUserName(); 
        current = current->get_next();
    }
    return friendsList;
}

std::string Profile::getFriendsWithSameNameLength() const
{
    std::string friendsWithSameLength = "";
    UserNode* current = this->_friends.get_first();
    size_t ownerNameLength = this->_owner.getUserName().length();

    while (current != nullptr)
    {
        std::string friendName = current->get_data().getUserName();
        if (friendName.length() == ownerNameLength)
        {
            if (!friendsWithSameLength.empty())
            {
                friendsWithSameLength += ",";
            }
            friendsWithSameLength += friendName; 
        }
        current = current->get_next();
    }
    return friendsWithSameLength;
}
