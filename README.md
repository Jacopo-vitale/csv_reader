## A very tiny simple CSV file reader

Not for a professional use, but for just visualize, manipulate and print your comma separated data.

## Usage:
First you need to instanciate a reader/writer, suppose you have a `float` file to read:<br>

`CSVRW<float>* rw = CSVRW::instance(dtype::F)`

`dtype::F` is an `enum` variable defined in `CSVRW.h` and it needs to manual provide the data type for a better data fetching and memory management (no more needed in C++20).

Once instanciated a reader/writer, a `CSVFile` variable needs to be constructed.<br>
Two examples are needed here.<br>
Suppose we have data to read stored in a local csv file:

`CSVFile* myfile = new CSVFile()` *--> empty in this case, it will work as a to-fill-container taking data from our file*

So now we can call our reader/writer ready to read:

`rw->read_file("path/to/file", myfile, true, ',')` *--> the reader/writer will fill our container*
<br>
...
Work in progress
...