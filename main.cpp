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

    CSVFile<float> *file = new CSVFile<float>();

    CSVRW<float> *rw = new CSVRW<float>(dtypes::F);

    rw->read_file("./dummy_csv1.csv",file);

    file->head(10);

    return EXIT_SUCCESS;
}

/***
 * @todo:
 * - Implement tail()
 * - Implement update()
 * - ...
 */
