#include "Page.h"
#include <iostream>

void Page::init()
{
    this->_status = "";
    this->_posts = "";
}

std::string Page::getPosts() const
{
    return this->_posts;
}

std::string Page::getStatus() const
{
    return this->_status;
}

void Page::clearPage()
{
    this->_posts = "";
}

void Page::setStatus(const std::string& status)
{
    this->_status = status;
}

void Page::addLineToPosts(const std::string& new_line)
{
    if (!this->_posts.empty())
    {
        this->_posts += "\n";
    }
    this->_posts += new_line;
}
