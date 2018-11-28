#include "../_headers/mem.h"
#include <fstream>
#include <string>
#include <regex>

void Mem::openFile(std::string fname)
{
    std::ifstream file;
    std::string   fcontents;
    std::regex    nonDigit("[A-Za-z]*");
    bool recievedSpaceSize = false;
    // opening file
    try
    {   
        std::cout << "opening file" << std::endl;
        file.open(fname);
        while(file >> fcontents)
        {
            // first entry in the file is the space size
            if (!recievedSpaceSize)
            {
                this->block_size = stoi(fcontents);
                recievedSpaceSize = true;
            }
            else if(!std::regex_match(fcontents, nonDigit))
            {
                this->data.push(stoi(fcontents));
            }
            else if (std::regex_match(fcontents, nonDigit))
            {
                this->algorithm = fcontents;
            }
        }
    }
    catch(const std::ifstream::failure& e)
    {
        // Failed to read file, exit program
        std::cout << "exception opening/reading file..." << std::endl;
    }

    while(this->data.empty())
    {
        // std::cout << "data: "
    }
    std::cout << this->algorithm << ", " << this->block_size << std::endl;
    // closing file
    file.close();
}