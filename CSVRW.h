#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "CSVFile.h"

/**
 * This is the CSVRW (CSV Read & Write)
 * This class can help to read and write CSV files just instanciating one single time.
 * A Singleton design Pattern is being used to avoid multiple reader/writer instancing.
 *
*/


enum dtypes {F,D,I};

template <class T>
class CSVRW
{
private:
    CSVRW(dtypes dt) : _dt(dt){};

    dtypes _dt;

    static CSVRW *_csvrw;

    std::vector<T> row(std::string line, char delimiter);

public:
    
    CSVRW(CSVRW &other) = delete;

    void operator=(const CSVRW &) = delete;

    static CSVRW *instance(dtypes dt);

    void read_file(std::string filepath, CSVFile<T> *file, bool header = true, char delim = ',');
    void write_file(std::string filename, CSVFile<T> *file, char delim = ',');
    
};

template <class T>
CSVRW<T> *CSVRW<T>::_csvrw = nullptr;

template <class T>
CSVRW<T> *CSVRW<T>::instance(dtypes dt)
{
    if (_csvrw == nullptr)
    {
        _csvrw = new CSVRW(dt);
    }
    return _csvrw;
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

        std::cout << "Preparing for file data fetching..." << std::endl;

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

    std::cout << "All data has been fetched!" << std::endl;

    return;
}

template <class T>
void CSVRW<T>::write_file(std::string filename, CSVFile<T> *file, char delim)
{

    std::ofstream f(filename);

    if (!file)
    {
        std::cerr << "File passed error... returning";
        return;
    }

    std::cout << "Writing your file..." << std::endl;

    bool has_header = !file->getHeader().empty();

    int rows = file->getDataRows();
    int cols = file->getDataCols();

    if (has_header)
    {
        for (int i = 0; i < cols - 1; i++)
        {
            f << file->getHeader()[i] << delim;
        }

        f << file->getHeader().back() << "\n";
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            f << file->getData()[i][j] << delim;
        }

        f << (file->getData()[i]).back() << "\n";
    }

    std::cout << "File has been written to: " << filename << "\n";
}

template <class T>
std::vector<T> CSVRW<T>::row(std::string line, char delimiter)
{

    // Apro lo streaming della stringa
    std::stringstream ss(line, std::ios::in);

    std::string tmp;

    std::vector<T> row;

    while (std::getline(ss, tmp, delimiter))
    {   
        if(_dt == dtypes::F)
            row.push_back(std::stof(tmp));
        else if(_dt == dtypes::D)
            row.push_back(std::stod(tmp));
        else if(_dt == dtypes::I)
            row.push_back(std::stoi(tmp));
    }

    return row;
}