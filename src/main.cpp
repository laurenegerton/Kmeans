/*
 * Kmeans clustering main file
 */

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

int main(int argc, char *argv[]) {

    /*
     * DEBUG
     */
    fprintf(stdout, "%d arguments.\n", argc - 1);
    for (int i = 0; i < argc - 1; i++) {
        int ct = i + 1;
        std::cout << ct << "st argument: " << argv[ct] << std::endl;
    }

    auto x = argv[2];
    auto y = argv[3];
    auto numLines = std::stoi(argv[4]);
    auto xCol = std::stoi(argv[5]);
    auto yCol = std::stoi(argv[6]);
    auto headerCount = std::stoi(argv[7]);
    
    fprintf(stdout, "%d \n", xCol);
    fprintf(stdout, "%d \n", yCol);

     /* find way to only parse x, y header columns into vectors*/

    std::vector<double> xx;
    std::vector<double> yy;
    std::ifstream inputFile(argv[1]);

    if (inputFile.is_open()){
        std::string line;
        while (std::getline(inputFile, line)){
            typedef boost::escaped_list_separator<char> Separator;
            typedef boost::tokenizer<Separator> Tokenizer;

            Tokenizer tokenizer(line);
            int count = 0;

              for (Tokenizer::iterator iter = tokenizer.begin(); (iter != tokenizer.end()) && (count < headerCount); ++iter)
            {
                if ((count == xCol) || (count == yCol))   //prints Col 0 and Col 2 when I put values 0 and 2 here?
                {
                    std::cout << *iter << "\t";
                    
                }
                ++count;
            }
            std::cout << "\n";
        }
    }

    
    // while (std::getline(inputFile, line)) {
    //     std::stringstream lineStream(line);
    //     std::string cell;

    //     while (std::getline(lineStream, cell, ',')) {

    //     }

    // }

    




    return 0;
}