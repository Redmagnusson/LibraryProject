#pragma once
#include <string>
#include <vector>
class User
{
private:
	std::string username;
	std::string password;
	//std::vector<Media> loanedBooks


public:
	User(std::string username, std::string password);
	//std::vector<Media> getLoanedBooks();
};