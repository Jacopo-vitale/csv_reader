#include "CSVFile.h"

template <typename T>
CSVFile<T>::CSVFile(/* args */)
{
}

template <typename T>
CSVFile<T>::~CSVFile()
{
}

template <typename T>
void CSVFile<T>::head(int heads = 5)
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