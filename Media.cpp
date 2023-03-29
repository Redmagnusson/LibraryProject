#include "media.h"

Media::Media()
{

}
// Constructor that sets the value when object is created
Media::Media(std::string title, int releaseYear){
	this->title = title;
	this->releaseYear = releaseYear;
}

// Function that returns the title
std::string Media::getTitle() {
	return this->title;
}

// Function that enables changes to the set title
void Media::setTitle(std::string title) {
	this->title = title;
}

// Function that returns the release year
int Media::getReleaseYear() {
	return this->releaseYear;
}

// Function that enables changes to the set release year
void Media::setReleaseYear(int releaseYear) {
	this->releaseYear = releaseYear;
}
