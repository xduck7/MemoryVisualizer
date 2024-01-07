//
// Created by Artem on 05.01.2024.
//

#include <string>
#include <dirent.h>
#include <windows.h>

//TODO: change this

class SizeReader {
public:
    static __int64 DirSize(std::string path_name)
    {
        WIN32_FIND_DATA data_reqd;
        __int64 size = 0;
        std::string f_name = path_name + "\\*.*";
        HANDLE h1 = FindFirstFile(f_name.c_str(),&data_reqd);
        if(h1 != INVALID_HANDLE_VALUE)
        {
            do {
                if( (data_reqd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
                {
                    if( strcmp(data_reqd.cFileName,".") != 0 &&strcmp(data_reqd.cFileName,"..") != 0)
                    {
                        f_name = path_name + "\\" + data_reqd.cFileName;
                        size += DirSize(f_name);
                    }
                }
                else
                {
                    LARGE_INTEGER sz;
                    sz.LowPart = data_reqd.nFileSizeLow;
                    sz.HighPart = data_reqd.nFileSizeHigh;
                    size = size+ sz.QuadPart;
                }
            }while( FindNextFile(h1,&data_reqd) != 0);//until we reach the end i.e. no more files are left
            FindClose(h1);
        }
        return size;
    }
};