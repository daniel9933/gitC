#include <iostream>
#include <string>
#include "Page.h"


void Page::init()
{
	this->_status = "";
	this->_post ="";
}
std::string Page::getPosts() const
{
	return this->_post;
}
std::string Page::getStatus() const
{
	return this->_status;
}
void Page::clearPage()
{
	this->_post.clear();
}
void Page::setStatus(std::string status)
{
	this->_status = status;
}
void Page::addLineToPosts(std::string new_line)
{
	this->_post = this->_post + "\n" + new_line;
}