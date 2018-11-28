#include <iostream>
#include <string>
#include <queue>

class Mem
{
    private:
    
        int              step_unit = 1;
        int              block_size = 1024;
        bool             stepAll = false;
        std::string      algorithm;
        std::string      fname;
        std::queue<int>  data;

    public:

    // Constructor
    Mem()
    {
        step_unit   = 1;
        block_size  = 1024;
        algorithm   = "first";
        fname       = "memrun.txt";
    }

    // Purpose: reset the enviornment for a new run
    void reset();

    // Purpose: used for stepping through the simulated time
    void setStep(int units);

    // Purpose: used for stepping through the simulated time
    void setStepAll(bool seeAll){ this->stepAll = seeAll; };

    // Purpose: set block size
    void setBlockSize(int blksz);

    // Purpose: used for setting the algorithm that will be used
    void setAlgorithm(std::string alg);

    // Purpose: to read and store data from file
    void openFile(std::string fname);

    // Purpse: to display the data
    void view();

    // Different memory allocation algorithms
    //
    // bestFit(): this will find the current best fit for a page
    // nextFit(): this will find the next fit for the page
    // firstFit(): this will find the first fit for the page
    void bestFit();

    void nextFit();

    void firstFit();



};