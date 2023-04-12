#include "Book.h"

Book::Book()
: Media()
{

}
Book::Book(std::string title, int releaseYear, std::string loanedID, std::string author)
	: Media(title, releaseYear, loanedID) {
			this->author = author;
}

std::string Book::getAuthor() {
	return this->author;
}

void Book::setAuthor(std::string author) {
	this->author = author;
}

std::string Book::toString() {
	return Media::getTitle() + " - " + this->author + " - " +
		std::to_string(Media::getReleaseYear());
}
