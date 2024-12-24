#pragma once

#include <fstream>
#include <sstream>
#include <string>

namespace sigma
{
    /*
        reads a file and returns as a ifstream
        
        @param filename: name of the file to be read
        @param content: stringstream object to store the content of the file. the object you pass will be changed
        @return: ifstream object
    */

    inline std::ifstream readFile(const std::string &filename, std::stringstream &content)
    {
        std::ifstream file(filename);
        if (file.is_open())
        {
            content << file.rdbuf();
            file.close();
        }

        std::string Line;
        while (std::getline(file, Line))
        {
            content << Line << std::endl;
        }

        return file;
    }
}