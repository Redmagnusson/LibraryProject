#pragma once
#include "media.h"

class CD : public Media {
private:
	std::string artist;

public:
	CD();
	CD(std::string title, int releaseYear, std::string loanedID, std::string artist);
	std::string getArtist();
	void setArtist(std::string artist);
	std::string toString();
};
