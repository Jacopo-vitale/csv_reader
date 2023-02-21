#pragma once
#include <iostream>
#include <vector>
#include <string>

template <class T>
class CSVFile
{
private:
    std::vector<std::string> header;
    std::vector<std::vector<T>> data;

public:
    CSVFile();

    ~CSVFile();

    void head(int heads = 5);

    std::vector<std::string> getHeader() { return header; }
    std::vector<std::vector<T>> getData() { return data(); }
    void appendToHeader(std::string element) { header.push_back(element); }
    void appendRowToData(std::vector<T> row) { data.push_back(row); }
};

template <class T>
CSVFile<T>::CSVFile()
{
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