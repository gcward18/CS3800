#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Directory {
    // Private memeber variables
    vector <T> files;   // a list of files in the current directory

    public:

    /**
     * Getters and Setters for the Private member variables
     */
    void set_files(vector<T> passed_files){ files = passed_files;}
    
    vector<T> get_files(){ return files; }

};

#endif
