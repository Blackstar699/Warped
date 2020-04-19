//
// Created by gus3000 on 02/04/2020.
//

#include "CSVReader.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <sstream>

/*
* Parses through csv file line by line and returns the data
* in vector of vector of strings.
*/
std::vector<std::vector<std::string> > CSVReader::getData() {
    std::ifstream file(fileName);
    std::vector<std::vector<std::string> > dataList;
    std::string line;
// Iterate through each line and split the content using delimiter
    while (getline(file, line)) {
        std::vector<std::string> vec = split(line);
//        boost::algorithm::split(vec, line, boost::is_any_of(delimiter));

        dataList.push_back(vec);
    }
// Close the File
    file.close();
    return dataList;
}

/**
 * taken here https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
 * @param s
 * @param delimiter
 * @return
 */
std::vector<std::string> CSVReader::split(const std::string &s) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
