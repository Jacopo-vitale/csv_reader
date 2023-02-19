#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "CSVFile.h"

template <typename T>
class CSVReader
{

protected:
    std::vector<T> row(std::string line, char delimiter);

public:
    CSVReader();

    ~CSVReader(){};

    

    void read_file(std::string filepath, bool header = true, char delim = ',', CSVFile<T> *file = nullptr);
};
