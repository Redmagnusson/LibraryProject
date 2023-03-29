#include "media.h"

class Film : public Media {
private:
	std::string director;

public:
	Film();
	Film(std::string title, int releaseYear, std::string director);
	void setDirector(std::string director);
	std::string getDirector();
};
