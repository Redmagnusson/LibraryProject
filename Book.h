#include "media.h"

class Book : public Media {
private:
	std::string author;

public:
	Book();
	Book(std::string title, int releaseYear, std::string author);
	std::string getAuthor();
	void setAuthor(std::string author);
	std::string toString();
};
