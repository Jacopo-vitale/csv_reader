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

/*     CSVFile<float> *file = new CSVFile<float>();

    system("cp ../*.csv ."); */

    CSVRW<float> *rw = CSVRW<float>::instance(dtypes::D);
/* 
    rw->read_file("./" + files[0], file, true, ',');

    file->head(10);

    rw->write_file("/home/jacopo/csv_reader/csv_writer.csv", file); */
    
    int rows = 100;
    int cols = 7;

    float **m = new float*[rows];
    
    for (int i = 0; i < rows; i++)
    {
        m[i] = new float[cols];
    }

    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            m[i][j] = float(rand())/RAND_MAX;

    std::vector<std::string> my_header = {"col1","col2","col3","col4","col5","col6","col7"};

    CSVFile<float>* from_mat = new CSVFile<float>(my_header,m,rows,cols);

    rw->write_file("/home/jacopo/csv_reader/csv_writer_from_mat.csv", from_mat);

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
