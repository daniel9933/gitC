#pragma once
#include <string>

class Page
{
private:
	std::string _status;
	std::string _post;

public:

	void init();
	std::string getPosts() const;
	std::string getStatus() const;
	void clearPage();
	void setStatus(std::string status);
	void addLineToPosts(std::string new_line);
};