#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class dataFrame {

    public:

        int batchSize;

        dataFrame();
        ~dataFrame();

        std::vector<std::string> readCSVRow(const std::string &row);
        std::vector<std::vector<std::string>> readCSV(std::istream &in);
        
};
