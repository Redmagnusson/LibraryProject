#include "media.h"
#include <vector>

class Library {
private:
	std::vector<Media> mediaVector;

public:
	Library();
	Media* searchTitle(std::string title);

	Media* searchReleaseYear(int releaseYear);

	Media* searchDirector(std::string director);

	Media* searchAuthor(std::string author);

	Media* searchArtist(std::string artist);

	std::vector<Media>& getVector();
};

