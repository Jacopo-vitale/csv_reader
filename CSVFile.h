#pragma once
#include <iostream>
#include <vector>
#include <string>

/**
 * This is CSVFile class, use this calss for manage or create your CSV file.
 * This class has two attributes:
 * - `header` (`vector<string>`)   : Usually a CSV File contains an header for Columns Names
 * - data   (`vector<vector<T>>`): The data (numerical) contained in the file.
 * 
 * Constructor: 
 * - No params: Creates empty CSVFile Object
 * 
 * Constructor with Parameters:
 * - `vector<string>` header: if you want to build CSVFile object starting from aleady existing data
 * - `T**`            data  : if you have a matrix of numerical data 
 * 
 * Methods:
 * - appendToHeader: Append element to header (kept private)
 * - appendRowToData: Append a vector of values to data matrix (kept private)
 * - getters      
 **/



template <class T>
class CSVFile
{
private:
    std::vector<std::string> header;
    std::vector<std::vector<T>> data;

public:
    CSVFile();

    CSVFile(std::vector<std::string>* header, T **data, int rows, int cols);

    ~CSVFile();

    void head(int heads = 5);

    std::vector<std::string>    getHeader() { return header; }
    std::vector<std::vector<T>> getData()   { return data; }

    void appendToHeader(std::string element) { header.push_back(element); }
    void appendRowToData(std::vector<T> row) { data.push_back(row); }

    int getDataRows();
    int getDataCols();
};


/*! 
   \brief Construct an empty CSVFile class object
*/
template <class T>
CSVFile<T>::CSVFile()
{
}


/*! 
   \brief Construct a CSVFile starting from local variables
   \param (vector<string>*) header: string vector containing all columns names
   \param (T**) data: variable containing numerical data e.g. a float matrix
   \param (int) rows: data matrix total number of rows
   \param (int) cols: data matrix total number of cols
*/
template <class T>
CSVFile<T>::CSVFile(std::vector<std::string>* header, T **data, int rows, int cols)
{

    // header copy
    for (const auto &h : header)
    {
        this->header.push_back(h);
    }

    // copy data
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            this->data[i][j] = data[i][j];
        }
    }
}

template <class T>
CSVFile<T>::~CSVFile()
{
}

/*! 
   \brief Print elements to stdout (default is 5 elements)
   \param (int) heads: number of elements to print 
*/
template <class T>
void CSVFile<T>::head(int heads)
{
    int depth = 0;

    if (header.empty() && data.empty())
        std::cerr << "(or empty file)" << std::endl;

    if (!header.empty())
    {
        for (int i=0; i<header.size()-1; i++)
            std::cout << header[i] << "\t";

        std::cout << header.back() << "\n";
    }

    depth = data.size() <= heads ? data.size() : heads;

    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < data[0].size()-1; j++)
        {
            std::cout << data[i][j] << "\t";
        }
        std::cout << data[i].back() << "\n";
    }
}

/*! 
   \brief Safe getter of number of rows
*/
template <class T>
int CSVFile<T>::getDataRows()
{

    if (!data.empty())
        return data.size();

    else
        return 0;
}

/*! 
   \brief Safe getter of number of cols
*/
template <class T>
int CSVFile<T>::getDataCols()
{

    if (!data.empty())
    
        if (!data[0].empty())
            return data[0].size();
        else
            return 0;
    
    else
        return 0;
}