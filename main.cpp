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

    CSVFile<float>* file = new CSVFile<float>();

    CSVRW<float> reader;

    system("cp ../*.csv .");

    reader.read_file("./" + files[0],file,true,',');

    file->head(10);

    return EXIT_SUCCESS;
}

/***
 * @todo:
 * - Implement tail()
 * - Implement other dtypes for better precision
 * - Implement update()
 * - Implement to_csv(delim '|')
 * - Better console printing (use pads)
 * - ...
 */
