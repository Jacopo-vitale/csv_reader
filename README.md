## A very tiny simple CSV file reader/writer for C++

Not for a professional use, but for just visualize, manipulate and print your comma separated data.

## Usage:
First you need to instanciate a reader/writer, suppose you have a `float` file to read:<br>

`CSVRW<float>* rw = CSVRW::instance(dtype::F)`

`dtype::F` is an `enum` variable defined in `CSVRW.h` and it needs to manual provide the data type for a better data fetching and memory management (no more needed in C++20).

Once instanciated a reader/writer, a `CSVFile` variable needs to be constructed.<br>
Two examples are needed here.<br>
Suppose we have data to read stored in a local csv file:

`CSVFile<float>* myfile = new CSVFile<float>()` *--> empty in this case, it will work as a to-fill-container taking data from our file*

So now we can call our reader/writer ready to read:

`rw->read_file("path/to/file", myfile, true, ',')` *--> the reader/writer will fill our container*
<br>

Now, `myfile` contains your file data.

You can access to your data typing:<br>
<code>
myfile->getHeader() // Retrieve columns names as string vector <br>
myfile->getData() //And you can access like a matrix by [][] operator
</code>
***
Second Example: you have your data stored in a matrix of `float`:<br>
<code>
float my_float_data[ROWS][COLS]; // Suppose this is the filled matrix <br>
vector\<string\> col_names = {"col1","col2",..."col3"};<br>
CSVFile\<float\>* my_csv_file = new CSVFile\<float\>(&col_names, &my_float_data, ROWS, COLS)
</code>

Once built the `CSVFile<float>` object you can, for example manipulate your data and then write out to a file:<br>
<code>
rw->write_file("/path/to/file.csv",my_csv_file,',');
</code><br>
A message will confirm that output is completed.