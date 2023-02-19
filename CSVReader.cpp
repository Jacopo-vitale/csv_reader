#include <iostream>
#include <fstream>
#include <sstream>
#include "CSVReader.h"

CSVReader::CSVReader()
{
}

void CSVReader::read_float_file(std::string filepath, bool header, char delim, fCSVFile* float_file)
{
    try
    {
        // Apro lo streaming da file
        std::fstream f(filepath, std::ios::in);

        if(!f.is_open())
            std::cerr << "File not found!";

        std::string line, num_str, header_names;

        if (header)
        {
            std::getline(f, line);
            std::stringstream hs(line, std::ios::in);

            while (std::getline(hs, header_names, delim))
            {
                float_file->header.push_back(header_names);
            }
        }

        while (std::getline(f, line))
        {
            float_file->data.push_back(this->float_row(line, delim));
        }

        f.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return;
}

void CSVReader::read_int_file(std::string filepath, bool header, char delim)
{
    
    return;

}

void CSVReader::read_double_file(std::string filepath, bool header, char delim)
{

    return;
}


std::vector<float> CSVReader::float_row(std::string line, char delimiter)
{

    // Apro lo streaming della stringa
    std::stringstream ss(line, std::ios::in);

    std::string tmp;

    std::vector<float> row;

    while (std::getline(ss, tmp, delimiter))
    {
        row.push_back(std::stof(tmp));
    }

    return row;
}

std::vector<int> CSVReader::int_row(std::string line, char delimiter)
{

    // Apro lo streaming della stringa
    std::stringstream ss(line, std::ios::in);

    std::string tmp;

    std::vector<int> row;

    while (std::getline(ss, tmp, delimiter))
    {
        row.push_back(std::stoi(tmp));
    }

    return row;
}


std::vector<double> CSVReader::double_row(std::string line, char delimiter){
      // Apro lo streaming della stringa
    std::stringstream ss(line, std::ios::in);

    std::string tmp;

    std::vector<double> row;

    while (std::getline(ss, tmp, delimiter))
    {
        row.push_back(std::stod(tmp));
    }

    return row;
}