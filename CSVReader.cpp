#include <iostream>
#include <fstream>
#include <sstream>
#include "CSVReader.h"

template <typename T>
CSVReader<T>::CSVReader()
{
}

template <typename T>
void CSVReader<T>::read_file(std::string filepath, bool header, char delim, CSVFile *file)
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
                file->header.push_back(header_names);
            }
        }

        while (std::getline(f, line))
        {
            file->data.push_back(this->row(line, delim));
        }

        f.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return;
}

template <typename T>
std::vector<T> CSVReader<T>::row(std::string line, char delimiter)
{

    // Apro lo streaming della stringa
    std::stringstream ss(line, std::ios::in);

    std::string tmp;

    std::vector<T> row;

    while (std::getline(ss, tmp, delimiter))
    {
        if (tmp.find('.') + 1)
        { // Avoid index 0
            row.push_back(std::stof(tmp));
        }
        else
        {
            row.push_back(std::stoi(tmp));
        }
    }

    return row;
}