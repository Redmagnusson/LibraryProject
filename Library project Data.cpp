//============================================================================
// Name        : Library.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>

class Data {
public:
    // Const
    Data(const std::string& userDataFilename, const std::string& libraryDataFilename)
        : userDataFile(userDataFilename), libraryDataFile(libraryDataFilename) {}


    void LoadLibrary() {
        // Load library data from libraryDataFile
    }

    void SaveLibrary() {
        // Save library data to libraryDataFile
    }

    void SaveUserData() {
        // Save user data to userDataFile
    }

    void LoadUserData() {
        // Load user data from userDataFile
    }

private:
    // Attributes
    std::string userDataFile;
    std::string libraryDataFile;
};

