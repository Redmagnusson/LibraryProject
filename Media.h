#pragma once
#include <iostream>
#include <string>

class Media {
private:
	std::string title;
	int releaseYear;
	std::string loanedID;
public:
	Media();
	Media(std::string title, int releaseYear, std::string loanedID);
	std::string getTitle();
	void setTitle(std::string title);
	int getReleaseYear();
	void setReleaseYear(int releaseYear);
	std::string getLoanedID() { return this->loanedID; }
	void setLoanedID(std::string username) { this->loanedID = username; }
	virtual std::string toString();

};
