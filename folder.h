#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Folder {
    // Private memeber variables
    map     <string, vector<string>>    folder;       // folder, that has specfic contents and permissions
    string                              folder_name;  // name of the folder 
    
    public:

    /**
     * Setters for the Private member variables
     */
    void set_folder(string folder_name, string folders);

    /**
     * Getters for Private member variables
     */
    string get_folder_with_permissions();
    string get_folder_without_permissions();

    /**
     * Constructor
     */
    Folder(string f_name, string permissions[])
    {
        folder_name = f_name;
        folder.insert( pair<string, vector<string>>(f_name,{"r","w","x"}));
    }

    Folder(string f_name)
    {
        folder_name = f_name;
    }

    /**
     * MEMBER FUNCTIONS
     */

    /**
     * Purpose: Prints a folder with its associated permissions
     * 
     */
    void print_folder_with_permissions();

    /**
     * Purpose: Prints a folder without its associated permissions
     * 
     */
    void print_folder_without_permissions();

    /**
     * Purpose: Modify permissions of a folder
     * 
     * @param {string} change: The new permission value
     * @param {int}    index : Index of which permission in being changed
     *                         1: read, 2: write, 3: edit
     * 
     */
    void change_permission(string change, int index);

};

#endif
