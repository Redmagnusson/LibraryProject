#include "Film.h"

Film::Film()
: Media()
{

}

// Constructor
Film::Film(std::string title, int releaseYear, std::string director)
: Media(title, releaseYear)
{
	this->director = director;
}

// Change set director member function
void Film::setDirector(std::string director) {
	this->director = director;
}

// get director member function
std::string Film::getDirector() {
	return this->director;

}
