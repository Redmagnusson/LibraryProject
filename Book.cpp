#include "Book.h"

Book::Book()
: Media()
{

}
Book::Book(std::string title, int releaseYear, std::string author)
	: Media(title, releaseYear) {
			this->author = author;
}

std::string Book::getAuthor() {
	return this->author;
}

void Book::setAuthor(std::string author) {
	this->author = author;
}

