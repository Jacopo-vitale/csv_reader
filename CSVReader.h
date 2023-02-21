#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "CSVFile.h"

template <class T>
class CSVRW
{

protected:
    std::vector<T> row(std::string line, char delimiter);

public:
    CSVRW();

    ~CSVRW(){};

    void read_file(std::string filepath, CSVFile<T>* file,bool header = true, char delim = ',');
    void write_file(CSVFile<T>* file, char delim = ',');
};


template <class T>
CSVRW<T>::CSVRW()
{
}

template <class T>
void CSVRW<T>::read_file(std::string filepath, CSVFile<T> *file, bool header, char delim)
{
    try
    {
        // Apro lo streaming da file
        std::fstream f(filepath, std::ios::in);

        if (!f.is_open())
        {
            std::cerr << "File not found!";
            std::exit(EXIT_FAILURE);
        }

        std::string line, num_str, header_names;

        if (header)
        {
            std::getline(f, line);
            std::stringstream hs(line, std::ios::in);

            while (std::getline(hs, header_names, delim))
            {
                file->appendToHeader(header_names);
            }
        }

        while (std::getline(f, line))
        {
            file->appendRowToData(this->row(line, delim));
        }

        f.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return;
}

template <class T>
std::vector<T> CSVRW<T>::row(std::string line, char delimiter)
{
    try{
    // Apro lo streaming della stringa
    std::stringstream ss(line, std::ios::in);

    std::string tmp;

    std::vector<T> row;

    while (std::getline(ss, tmp, delimiter))
    {
        if (tmp.find('.') < tmp.size())
        {
            row.push_back(std::stof(tmp));
        }
        else
        {
            row.push_back(std::stoi(tmp));
        }
    }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\nBad File Conversion';
    }
    

    return row;
}