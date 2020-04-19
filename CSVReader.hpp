//
// Created by gus3000 on 02/04/2020.
//

#ifndef MINECRAFTVIZ_CSVREADER_HPP
#define MINECRAFTVIZ_CSVREADER_HPP


#include <string>
#include <vector>

/*
 * A class to read data from a csv file.
 */
class CSVReader
{
    std::string fileName;
    char delimiter;

public:
    CSVReader(std::string filename, char delm = ',') :
            fileName(filename), delimiter(delm)
    { }

    // Function to fetch data from a CSV File
    std::vector<std::vector<std::string> > getData();
    std::vector<std::string> split(const std::string& s);
};


#endif //MINECRAFTVIZ_CSVREADER_HPP
