#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Directory {
    // Private memeber variables
    vector  <string>                    files;          // a list of files in the current directory
    map     <string, vector<string>>    dir;      // Current working directory and files in it
    string                              cwdir;             // Current Working Directory

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
        dir.insert( pair<string, vector<string>>("home/",files));
        this->cwdir = "home/";
    }
    Directory(string home);  

    /**
     * MEMBER FUNCTIONS
     */

    /**
     * Purpose: Prints all the files in the directory
     * 
     * @params {string} cwd: The current working directory
     */
    void print_files(string cwd);

    /**
     * Purpose: Makes a new directory
     */
    void make_dir();

    /**
     * Purpose: Changes directory
     */
    void change_dir();

};

#endif
