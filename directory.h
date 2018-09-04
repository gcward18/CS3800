#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include "file.h"
#include "folder.h"
using namespace std;

class Directory {
    // Private memeber variables
    map     <string,pair<vector<Folder>,vector<File>>>  dir_contents;      // Files in the current directory      // Files in the current directory
    string                                              cwd;             // Current Working Directory

    public:

    /**
     * Setters for the Private member variables
     */
    void set_directory(string passed_directory, string files);

    /**
     * Getters for Private member variables
     */
    string          get_directory();
    vector<Folder>  get_folders()   { return dir_contents[cwd].first;  }
    vector<File>    get_files()     { return dir_contents[cwd].second; }
    string          get_cwd()       { return cwd; }

    /**
     * Constructor
     */
    Directory()
    {
        cwd = "home/";
        dir_contents[cwd].first.push_back(Folder("."));
        dir_contents[cwd].first.push_back(Folder(".."));
        dir_contents[cwd].second.push_back(File("README.txt"));
    }


    /**
     * MEMBER FUNCTIONS
     */

    /**
     * Purpose: Prints all the files in the directory
     */
    void print_dir_contents_without_permissions();
    
    /**
     * Purpose: Prints all the files in the directory
     */
    void print_dir_contents_with_permissions();

    /**
     * Purpose: Prints all the files in the directory
     */
    void print_dir_path(){ cout << cwd << endl; } 

    /**
     * Purpose: Makes a new directory
     */
    void make_dir(string dir_name);

    /**
     * Purpose: Changes directory
     */
    void change_dir(string dir_name);

};

#endif
