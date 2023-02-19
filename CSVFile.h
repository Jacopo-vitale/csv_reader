#pragma once

template <typename T>
class CSVFile
{
private:
    std::vector<std::string>    header;
    std::vector<std::vector<T>> data;

public:
    CSVFile(/* args */);
    ~CSVFile();

    void head(int heads = 5);
};

