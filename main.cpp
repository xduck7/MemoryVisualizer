#include <iostream>
#include "DirectoryReader.cpp"
#include "SizeReader.cpp"

int main() {
    char disk;
    std::cin >> disk;
    std::vector<std::string> directories = DirReader::DirectoryReader(disk);
    double bToGB = 1024*1024*1024;
    for (const std::string& i : directories) {
        double size = SizeReader::DirSize(i)/bToGB;
        if (size > 0)  {
            std::cout << i << " "<< size << " GB\n";
        }
    }
}

