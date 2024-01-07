//
// Created by Artem on 05.01.2024.
//

#include "DirectoryReader.h"

#include "Checker.cpp"
#include <iostream>
#include <vector>
#include <dirent.h>

class DirReader {
public:
    static std::vector<std::string> DirectoryReader(std::string path) {
        std::vector<std::string> AllDirectories;
        std::string directoryPath = path + "\\";
        DIR *dir;
        struct dirent *entry;
        SystemName checker;
        try {
            if ((dir = opendir(directoryPath.c_str())) != nullptr) {
                while ((entry = readdir(dir)) != nullptr) {
                    if (checker.isSystemFile(entry->d_name)) {
                    } else {
                        std::string StringPath = directoryPath + entry->d_name;
                        //std::cout << StringPath<< "\n";
                        AllDirectories.push_back(StringPath);
                    }
                }
                closedir(dir);
            };
            return AllDirectories;
        } catch (const std::exception) {
            return {"Directory not found"};
        }

    };
};

