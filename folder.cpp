#include "folder.h"
#include <iostream>

void Folder::print_folder_without_permissions()
{
    // List folder name
    cout << this->folder_name << " ";
}

void Folder::print_folder_with_permissions()
{
    vector<string> permissions = this->get_permissions();

    // iteratate through and print the folders permissions
    for(unsigned int i = 0; i < permissions.size(); i++)
        cout << permissions[i];

    // print the folder name
    cout << "\t" << this->get_folder_date_time().substr(0, this->get_folder_date_time().length() -1) << " " <<  this->get_folder_name() << endl;
}

void Folder::change_permission(string change)
{
    this->folder_date_permissions.first[1] = this->perm_list[change[0]-48];
    this->folder_date_permissions.first[2] = this->perm_list[change[1]-48];
    this->folder_date_permissions.first[3] = this->perm_list[change[2]-48];
}

void Folder::remove_folder()
{
    //set folder name to nothing
    this->folder_name = "";
    
    // assign permissions
    vector<string> permissions = this->folder_date_permissions.first;

    // erase permissions
    permissions.erase(permissions.begin(),permissions.end());
    
    // set permissions to variable 
    this->folder_date_permissions.first = permissions;

    // erase date
    this->folder_date_permissions.second = "";

}
