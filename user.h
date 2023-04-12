#pragma once
#include <string>
#include <vector>
#include "Media.h"
class User
{
private:
	std::string username;
	std::string password;
	std::vector<Media> loanedBooks;


public:
	User(std::string username, std::string password);
	std::string getUserName() { return this->username; }
	std::string getPassword() { return this->password; }
	std::vector<Media>& getLoanedBooks() { return this->loanedBooks; }
};