#pragma once
#include <iostream>
#include <string>

class Media {
private:
	std::string title;
	int releaseYear;

public:
	Media();
	Media(std::string title, int releaseYear);
	std::string getTitle();
	void setTitle(std::string title);
	int getReleaseYear();
	void setReleaseYear(int releaseYear);

	virtual std::string toString();

};
