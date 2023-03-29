#include "Lib.h"
#include "Film.h"
#include "CD.h"
#include "Book.h"

Library::Library() {
}

Media* Library::searchTitle(std::string title) {
	for (int i = 0; i < mediaVector.size(); i++){
		if(title == mediaVector[i].getTitle()){
			return &mediaVector[i];
		}
	}
	return NULL;
}

Media* Library::searchReleaseYear(int releaseYear) {
	for (int i = 0; i < mediaVector.size(); i++) {
		if (releaseYear == mediaVector[i].getReleaseYear()) {
			return &mediaVector[i];
		}
	}
	return NULL;
}

Media* Library::searchDirector(std::string director) {
	for (int i = 0; i < mediaVector.size(); i++) {
		Film* ptr = static_cast<Film*>(&mediaVector[i]);
		    if(ptr != NULL) {
				if (director == ptr->getDirector()) {
					return &mediaVector[i];
		    }
		}
	}
	return NULL;
}

Media* Library::searchAuthor(std::string author) {
	for (int i = 0; i < mediaVector.size(); i++) {
		Book* ptr = static_cast<Book*>(&mediaVector[i]);
			if(ptr != NULL) {
				if (author == ptr->getAuthor()) {
					return &mediaVector[i];
				}
			}
		}
	return NULL;
}

Media* Library::searchArtist(std::string artist) {
	for (int i = 0; i < mediaVector.size(); i++) {
		CD* ptr = static_cast<CD*>(&mediaVector[i]);
		if(ptr != NULL){
			if (artist == ptr->getArtist()) {
				return &mediaVector[i];
			}
		}

	}
	return NULL;
}

std::vector<Media>& Library::getVector() {
	return mediaVector;
}
