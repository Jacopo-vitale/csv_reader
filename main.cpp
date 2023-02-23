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

    CSVFile<float> *float_file = new CSVFile<float>();

    CSVRW<float> *float_rw = new CSVRW<float>(dtypes::F);

    float_rw->read_file("./dummy_csv1.csv",float_file);

    float_file->head(10);

    CSVFile<double> *double_file = new CSVFile<double>();

    CSVRW<double> *double_rw = new CSVRW<double>(dtypes::D);

    double_rw->read_file("./dummy_csv1.csv",double_file);

    double_file->head();

    return EXIT_SUCCESS;
}

/***
 * @todo:
 * - Implement tail()
 * - Implement update()
 * - ...
 */
