#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "CSVFile.h"

//! F->float, D->double, I->Integer
enum dtypes {F,D,I};


/**
 * @brief
 * This is the CSVRW (CSV Read & Write)
 * This class can help to read and write CSV files just instanciating this object.
 * 
 * So this class needs to be instanciated by using this dtype flags.
 * Manual data type control can improve memory space allocation.
 *
 * @attention
 * This class can only read a file like:
 * 
 * |col1 |col2 |col3 |...|col_m | -->header
 * 
 * |val11|val12|val13|...|val_1m| -->data (numeric)
 * 
 * [...]
 * 
 * |valn1|valn2|valn3|...|val_nm|   
 * 
 * @remark 
 * Columns having categorical data types are not supported, consider to encode your data to numeric.
 **/


template <class T>
class CSVRW
{
private:

    dtypes _dt;

    std::vector<T> row(std::string line, char delimiter);

public:

    CSVRW(dtypes dt) : _dt(dt){};
    ~CSVRW(){}
    

    // Methods
    void read_file(std::string filepath, CSVFile<T> *file, bool header = true, char delim = ',');
    void write_file(std::string filename, CSVFile<T> *file, char delim = ',');
    
};


/*! 
   \brief Read a csv file 
   \param (string) filepath: path/to/file
   \param (CSVFile*) file: variable containing csv fetched data
   \param (bool) header: if the file contains an header (columns names)
*/
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

/*! 
   \brief Write a csv file 
   \param (string) filepath: path/to/write (including .csv)
   \param (CSVFile*) file: variable containing csv data to write
   \param (char) delim: custom delimiter default is comma
*/
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

/*!
 * \brief 
 * This is an helper function that aim to parse each file row and convert data to specified dtype.
 * \param string line: file line fetched from `std::getline`
 * \param char delimiter: character file delimiter
 * 
 * \returns Parsed file line into specified data type.
 * 
*/

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