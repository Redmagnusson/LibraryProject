#pragma once
#include "Data.h"
// Const
Data::Data(const std::string& userDataFilename, const std::string& libraryDataFilename)
    : userDataFile(userDataFilename), libraryDataFile(libraryDataFilename) {}

// Other functions ...

void Data::loadMedia(std::vector<Media*> *media) {
    std::ifstream inFile(libraryDataFile);
    std::string line;


    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string type, title, creator, loanedID;
        int releaseYear;


        //Changin this to use "tokens" instead
        //There were some issues with space in title
        std::string tempArr[5];
        for (int i = 0; i < 5; i++) {
            if (i != 4) {
                tempArr[i] = line.substr(0, line.find("   "));
                line = line.substr(line.find("   ") + 3, line.length());
            }
            else tempArr[i] = line;
        }

       // ss >> type >> title >> releaseYear >> loanedID >> creator;
        type = tempArr[0];
        title = tempArr[1];
        releaseYear = atoi(tempArr[2].c_str());
        loanedID = tempArr[3];
        creator = tempArr[4];
        if (type == "Book") {
            media->push_back(new Book(title, releaseYear, loanedID, creator));
        }
        else if (type == "CD") {
            media->push_back(new CD(title, releaseYear, loanedID, creator));
        }
        else if (type == "Film") {
            media->push_back(new Film(title, releaseYear, loanedID, creator));
        }
    }

    inFile.close();
}

void Data::loadLoanedMedia(const std::string& username, std::vector<Media*>* media) {
    std::vector<Media*> allMedia;
    loadMedia(&allMedia);

    for (int i = 0; i < allMedia.size();i++) {
        if (allMedia[i]->getLoanedID() == username) {
            media->push_back(allMedia[i]);
        }
    }
}

void Data::loadUserData(std::map<std::string, size_t> *map)
{
    std::ifstream inFile(userDataFile);
    std::string line;


    while (std::getline(inFile, line)) {
        std::string username;
        size_t hash;
        //std::cout << line << std::endl;


        //Changin this to use "tokens" instead
        //There were some issues with space in title
        username = line.substr(0, line.find("   "));
        std::string temp = line.substr(line.find("   ") + 3, line.length());
        //std::cout << temp << std::endl;
        std::stringstream test(temp);
        test >> hash;
        //hash = atoi(temp.c_str());
        map->emplace(username, hash);
    }

    inFile.close();
}
