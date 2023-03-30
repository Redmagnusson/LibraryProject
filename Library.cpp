#include "Library.h"
#include "Film.h"
#include "CD.h"
#include "Book.h"

Library::Library() {
}

// Function that let's me search for title, release year, director, author, artist (input a string with the search term)
// and returns a vector with media pointers
std::vector<Media*> Library::searchMedia(std::string searchTerm) {
	// Vector of media pointers called returnVector
    std::vector<Media*> returnVector;
    // Search all media that contains the search term by iterating through all media objects
    for (auto iterator : this->mediaVector) {
    	// Check if the search term is present in the current field being searched
        if (iterator.toString().find(searchTerm) != std::string::npos) {
        	// Add the search term to vector as a pointer
            returnVector.push_back(&iterator);
        }
    }

    // When done with the search return returnVector
    return returnVector;
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
