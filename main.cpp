#include <iostream>
#include <fstream>
#include <sstream>
#include "CSVReader.h"


int main(int argc, char *argv[])
{
    std::vector<std::string> files = {"dummy_csv1.csv",
                                      "dummy_csv2.csv",
                                      "dummy_csv3.csv",
                                      "dummy_csv4.csv",
                                      "dummy_csv5.csv",
                                      "dummy_csv6.csv"};
    
    CSVReader::fCSVFile file;

    CSVReader* reader = new CSVReader();

    reader->read_float_file("./" + files[0],true,',',&file);

    file.head(10);
    
    return EXIT_SUCCESS;
}

