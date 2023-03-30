#include "CD.h"


CD::CD()
: Media()
{

}
// CD constructor
CD::CD(std::string title, int releaseYear, std::string artist)
    : Media(title, releaseYear)
{
	this->artist = artist;
}

// Function that gets the artist
std::string CD::getArtist() {
	return this->artist;
}

// Function that changes the set artist
void CD::setArtist(std::string artist) {
	this->artist = artist;
}

std::string CD::toString() {
	return Media::toString() + " - " + this->CD;
}
