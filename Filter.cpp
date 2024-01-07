//
// Created by lolo7 on 07.01.2024.
//

#include <iostream>

class ChangeScope {
public:
    static void Scoper(double size, std::string path) {
        int toKb = 1024;
        int toMb = 1024*1024;
        int toGb = 1024*1024*1024;

        if (size / toGb > 0.1) {
            std::cout << path << " " << size/toGb << " Gb\n";
        } else if (size / toMb > 1 && size / toMb < 1024) {
            std::cout << path << " " << size/toMb << " Mb \n";
        } else {
            std::cout << path << " " << size/toKb << " Kb\n";
        }
    };
};