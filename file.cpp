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
    for( unsigned int i = 0; i < permissions.size(); i++)
        cout << permissions[i];

    // print the file name
    cout << "\t" << this->get_file_date_time().substr(0, this->get_file_date_time().length() -1) << " " <<  this->get_file_name() << endl;
}

void File::change_permission(string change)
{
    this->file_date_permissions.first[1] = this->perm_list[change[0]-48];
    this->file_date_permissions.first[2] = this->perm_list[change[1]-48];
    this->file_date_permissions.first[3] = this->perm_list[change[2]-48];
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