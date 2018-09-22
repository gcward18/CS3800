#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

class File {
    // Private memeber variables
    pair    <vector<string>,string>    file_date_permissions;       // file, that has specfic contents and permissions
    string                             file_name;  // name of the file 
    vector  <string>                   permissions;
    string                             perm_list[8] = {"---","--x","-r-","-rx","w--","w-x","wr-","wrx"};

    public:

    /**
     * Setters for the Private member variables
     */
    void set_file(string file_name, string files);

    /**
     * Getters for Private member variables
     */
    string          get_file_name()         { return file_name; }
    string          get_file_date_time()    { return file_date_permissions.second; }
    vector <string> get_permissions()       { return file_date_permissions.first; }

    /**
     * Setters
     */
    void   set_exectuable(string change)    { file_date_permissions.first[3] = change;  }
    void   set_read(string change)          { file_date_permissions.first[2] = change;  }
    void   set_write(string change)         { file_date_permissions.first[1] = change;  }
    void   set_file_timeStamp(string time)  { file_date_permissions.second   = time;    }
    
    /**
     * Constructor
     */
    File(string f_name)
    {
        // Set file name
        file_name = f_name;

        // set the time at which the file was created
        time_t now = time(NULL);
        string dt = ctime(&now);
        vector<string> permissions;

        // push generic permissions on the file
        permissions.push_back("f");
        permissions.push_back("wrx");
        permissions.push_back("wrx");
        permissions.push_back("wrx");
        
        // create pair with permission and date time
        file_date_permissions = make_pair(permissions, dt);
    }
    /**
     * Purpose: update time stamp
     */
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
     * 
     */
    void change_permission(const string& change);

    /**
     * Purpose: create a new file
     * 
     * @parma {string} file_name:  The title given to a file
     */
    void make_file(const string& file_name);

    /**
     * Purpose: create a new file
     * 
     * @parma {string} file_name:  The title given to a file
     */
    void remove_file();

    /**
     * Purpose: update time stamp
     */
    void set_time();
};

#endif
