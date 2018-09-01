#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class File {
    // Private memeber variables
    map     <string, vector<string>>    file;       // file, that has specfic contents and permissions
    string                              file_name;  // name of the file 
    
    public:

    /**
     * Setters for the Private member variables
     */
    void set_file(string file_name, string files);

    /**
     * Getters for Private member variables
     */
    string get_file_with_permissions();
    string get_file_without_permissions();

    /**
     * Constructor
     */
    File(string f_name, string permissions[])
    {
        file_name = f_name;
        file.insert( pair<string, vector<string>>(f_name,{"r","w","x"}));
    }

    File(string f_name)
    {
        file_name = f_name;
    }

    /**
     * MEMBER FUNCTIONS
     */

    /**
     * Purpose: Prints a file with its associated permissions
     * 
     */
    void print_file_with_permissions();

    /**
     * Purpose: Prints a file without its associated permissions
     * 
     */
    void print_file_without_permissions();

    /**
     * Purpose: Modify permissions of a file
     * 
     * @param {string} change: The new permission value
     * @param {int}    index : Index of which permission in being changed
     *                         1: read, 2: write, 3: edit
     * 
     */
    void change_permission(string change, int index);

};

#endif
