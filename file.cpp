#include "file.h"
#include <iostream>

void File::print_file_without_permissions()
{
    // List file name
    cout << this->file_name << " ";
}

void File::print_file_with_permissions()
{
    vector<string> permissions = this->get_permissions();

    // iteratate through and print the files permissions
    for(int i = 0; i < permissions.size(); i++)
        cout << permissions[i];

    // print the file name
    cout << "\t" << this->get_file_date_time().substr(0, this->get_file_date_time().length() -1) << " " <<  this->get_file_name() << endl;
}

void File::change_permission(string change, int index)
{
    // index 1 = read, index 2 = write, index 3 = execute
    // this->file[this->file_name][index] = change;
}


void File::remove_file()
{
    //set file name to nothing
    this->file_name = "";
    
    // assign permissions
    vector<string> permissions = this->file_date_permissions.first;

    // erase permissions
    permissions.erase(permissions.begin(),permissions.end());
    
    // set permissions to variable 
    this->file_date_permissions.first = permissions;

    // erase date
    this->file_date_permissions.second = "";

}