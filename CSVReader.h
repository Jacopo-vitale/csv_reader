#pragma once

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class CSVReader
{

protected:
    std::vector<T> row(std::string line, char delimiter);

public:
    CSVReader();

    ~CSVReader(){};

    struct CSVFile
    {
        std::vector<std::string> header;

        std::vector<std::vector<T>> data;

        void head(int heads = 5)
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
    };

    void read_file(std::string filepath, bool header = true, char delim = ',', CSVFile *file = nullptr);
};
