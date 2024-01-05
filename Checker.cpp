//
// Created by Artem on 05.01.2024.
//
#include "Checker.h"
#include <iostream>
#include <vector>
#include <algorithm>

class SystemName {
public:
    const std::vector<std::string> systemFileName = {
            "$recycle.bin",
            "desktop.ini",
            "avast! sandbox",
            "system volume information",
            "swapfile.sys",
            "recovery",
            "pagefile.sys",
            "$av_asw",
            "$windows.~bt",
            "$windows.~ws",
            "$winreagent",
            ".gamingroot",
            "config.msi",
            "documents and settings",
            "dumpstack.log",
            "dumpStack.log.tmp",
            "esd",
            "recycler",
            "hiberfil.sys",
            "intel",
            "appverifui.dll",
            "dumpstack.log.tmp",
            "onedrivetemp",
            "perflogs",
            "vfcompat.dll"

    };

    bool isSystemFile(std::string name) {

        std::transform(name.begin(),
                       name.end(),
                       name.begin(),
                       [](unsigned char c) {
            return std::tolower(c);
        });

        auto res = std::find(
                systemFileName.begin(),
                systemFileName.end(),
                name);

        if (res != systemFileName.end()) {
            return true;
        } else {
            return false;
        }
    }
};


