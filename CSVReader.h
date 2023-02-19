#pragma once

#include <iostream>
#include <string>
#include <vector>

// Definisco tipi più leggibili
typedef std::vector<std::vector<float>> __fMatrix;
typedef std::vector<std::vector<int>> __iMatrix;
typedef std::vector<std::vector<double>> __dMatrix;

class CSVReader
{

protected:
    std::vector<float>  float_row (std::string line, char delimiter);
    std::vector<int>    int_row   (std::string line, char delimiter);
    std::vector<double> double_row(std::string line, char delimiter);

public:
    CSVReader();

    ~CSVReader(){};

    struct fCSVFile
    {
        std::vector<std::string> header;
        
        __fMatrix data;

        void head(int heads = 5){
            
            int depth = 0;
            
            if(header.empty() && data.empty())
                std::cerr << "(or empty file)" << std::endl;


            if(!header.empty()){
                for(auto& h : header)
                    std::cout << h << "\t";
            
            std::cout << std::endl;
            }

            depth = data.size() <= heads? data.size() : heads;

            for(int i=0; i<depth; i++){
                for(int j=0; j<data[0].size(); j++){
                    printf("%f\t",data[i][j]);
                }
                std::cout << std::endl;
            }
        }
    };

    struct iCSVFile
    {
        std::vector<std::string> header;
        __iMatrix data;
    };

    struct dCSVFile
    {
        std::vector<std::string> header;
        __dMatrix data;
    };

    void read_float_file(std::string filepath, bool header = true, char delim = ',', fCSVFile *float_file = nullptr);
    void read_int_file(std::string filepath, bool header = true, char delim = ',');
    void read_double_file(std::string filepath, bool header = true, char delim = ',');
};
