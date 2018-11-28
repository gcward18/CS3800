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
    pair<vector<Folder>,vector<File>>  dir_contents;      // Files in the current directory      // Files in the current directory
    string                             cwd;             // Current Working Directory

    public:

    /**
     * Setters for the Private member variables
     */
    void set_cwd(string new_cwd)                { cwd = new_cwd;}
    void set_folders(vector<Folder> folders)    { dir_contents.first = folders; }
    void set_files(vector<File> files)          { dir_contents.second = files; }
    /**
     * Getters for Private member variables
     */
    string          get_directory();
    vector<Folder>  get_folders()   { return dir_contents.first;  }
    vector<File>    get_files()     { return dir_contents.second; }
    string          get_cwd()       { return cwd; }

    /**
     * Constructor
     */
    Directory()
    {
        cwd = "home/";
        dir_contents.first.push_back(Folder("."));
        dir_contents.first.push_back(Folder(".."));
        dir_contents.second.push_back(File("README.txt"));
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
    void make_dir(const string& dir_name);

    /**
     * Purpose: Changes directory
     */
    void change_dir(const string& dir_name);

};

#endif
