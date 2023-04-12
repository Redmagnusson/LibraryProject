#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include "user.h"
#include "Book.h"
#include "CD.h"
#include "Film.h"
#include <map>
class Data {
public:
    // Const
    Data(const std::string& userDataFilename, const std::string& libraryDataFilename);
    // Other functions ...
    void loadMedia(std::vector<Media*> *media);
    void loadLoanedMedia(const std::string& username, std::vector<Media*> *media);
    void loadUserData(std::map<std::string, size_t> *map);
private:
    std::string userDataFile;
    std::string libraryDataFile;
};
