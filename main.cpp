#include <iostream>
#include <fstream>
#include <sstream>
#include "CSVRW.h"

int main(int argc, char *argv[])
{
    std::vector<std::string> files = {"dummy_csv1.csv",
                                      "dummy_csv2.csv",
                                      "dummy_csv3.csv",
                                      "dummy_csv4.csv",
                                      "dummy_csv5.csv",
                                      "dummy_csv6.csv"};

    CSVFile<double>* file = new CSVFile<double>();

    system("cp ../*.csv .");

    CSVRW<double>* rw = CSVRW<double>::instance(dtypes::D);

    rw->read_file("./" + files[0],file,true,',');

    file->head(10);

    rw->write_file("/home/jacopo/csv_reader/csv_writer.csv", file);

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
