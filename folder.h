#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

class Folder {
    // Private memeber variables
    pair    <vector<string>,string>    folder_date_permissions;       // folder, that has specfic contents and permissions
    string                             folder_name;  // name of the folder 
    vector  <string>                   permissions;
    string                             perm_list[8] = {"---","--x","-r-","-rx","w--","w-x","wr-","wrx"};

    public:

    /**
     * Setters for the Private member variables
     */
    void set_folder(string folder_name, string folders);

    /**
     * Getters for Private member variables
     */
    string          get_folder_name()           { return folder_name; }
    string          get_folder_date_time()      { return folder_date_permissions.second; }
    vector <string> get_permissions()           { return folder_date_permissions.first; }
    /**
     * Setters
     */
    void   set_exectuable(string change)    { folder_date_permissions.first[3] = change; }
    void   set_read(string change)          { folder_date_permissions.first[2] = change; }
    void   set_write(string change)         { folder_date_permissions.first[1] = change; }
    
    /**
     * Constructor
     */
    Folder(string f_name)
    {
        // Set file name
        folder_name = f_name;

        // set the time at which the file was created
        time_t now = time(NULL);
        string dt = ctime(&now);
        vector<string> permissions;

        // push generic permissions on the file
        permissions.push_back("d");
        permissions.push_back(perm_list[7]);
        permissions.push_back(perm_list[7]);
        permissions.push_back(perm_list[7]);

        // create pair with permission and date time
        folder_date_permissions = make_pair(permissions, dt);
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
     * Purpose: Modify permissions of a file
     * 
     * @param {string} change: The new permission value
     * 
     */
    void change_permission(string change);

    /**
     * Purpose: create a new folder
     * 
     * @parma {string} folder_name:  The title given to a folder
     */
    void make_folder(string folder_name);

    /**
     * Purpose: remove folder
     * 
     * @parma {string} folder_name:  The title given to a folder
     */
    void remove_folder();

};

#endif
