#pragma once
#include <iostream>
#include <vector>
#include <string>

/**
 * This is CSVFile class, use this calss for manage or create your CSV file.
 * This class has two attributes:
 * - header (vector<string>)   : Usually a CSV File contains an header for Columns Names
 * - data   (vector<vector<T>>): The data (numerical) contained in the file.
 *  
 * (i) Constructor: No params -> Creates empty CSVFile Object
 * (ii) Constructor Params:
 * - vector<string> header -> if you want to build CSVFile object starting from aleady existing data
 * - T**            data   -> if you have a matrix of numerical data 
 * 
 * Methods:
 * - appendToHeader -> Append element to header (kept private)
 * - appendRowToData-> Append a vector of values to data matrix (kept private)
 * 
 * --- Jacopo Vitale MSc ---
 **/

template <class T>
class CSVFile
{
private:
    std::vector<std::string> header;
    std::vector<std::vector<T>> data;

public:
    CSVFile();

    CSVFile(std::vector<std::string> header, T **data, int rows, int cols);

    ~CSVFile();

    void head(int heads = 5);

    std::vector<std::string> getHeader() { return header; }
    std::vector<std::vector<T>> getData() { return data(); }

    void appendToHeader(std::string element) { header.push_back(element); }
    void appendRowToData(std::vector<T> row) { data.push_back(row); }

    int getDataRows();
    int getDataCols();
};

template <class T>
CSVFile<T>::CSVFile()
{
}

template <class T>
CSVFile<T>::CSVFile(std::vector<std::string> header, T **data, int rows, int cols)
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

template <class T>
void CSVFile<T>::head(int heads)
{
    int depth = 0;

    if (header.empty() && data.empty())
        std::cerr << "(or empty file)" << std::endl;

    if (!header.empty())
    {
        for (auto &h : header)
            std::cout << h << "\t";

        std::cout << std::endl;
    }

    depth = data.size() <= heads ? data.size() : heads;

    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < data[0].size(); j++)
        {
            printf("%f\t", data[i][j]);
        }
        std::cout << std::endl;
    }
}

template <class T>
int CSVFile<T>::getDataRows()
{

    if (!data.empty())
        return data.size();

    else
        return 0;
}

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