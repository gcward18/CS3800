#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Directory {
    // Private memeber variables
    vector  <string>                    files;          // a list of files in the current directory
    map     <string, vector<string>>    directory;      // Current working directory and files in it
    string                              cwd;             // Current Working Directory

    public:

    /**
     * Setters for the Private member variables
     */
    void set_directory(string passed_directory, string files);

    /**
     * Getters for Private member variables
     */
    string get_directory();

    /**
     * Constructor
     */
    Directory()
    {
        files.push_back("..");
        files.push_back(".");
    }
    Directory(string home);  

    /**
     * MEMBER FUNCTIONS
     */

    /**
     * Purpose: Prints all the files in the directory
     */
    void print_files();

    /**
     * Purpose: Makes a new file in directory
     */
    void make_file();

    /**
     * Purpose: Makes a new directory
     */
    void make_dir();

    /**
     * Purpose: Changes directory
     */
    void change_dir();

};

#include "directory.cpp"
#endif
