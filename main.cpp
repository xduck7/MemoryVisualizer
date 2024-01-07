#include <iostream>
#include "DirectoryReader.cpp"
#include "SizeReader.cpp"
#include "Filter.cpp"

int main() {
    std::string disk;
    std::cout << "Enter path: ";
    std::cin >> disk;
    std::vector<std::string> directories = DirReader::DirectoryReader(disk);
    for (const std::string& i : directories) {
        double size = SizeReader::DirSize(i);
        if (size >= 0)  {
            ChangeScope::Scoper(size, i);
        }
    }
}

