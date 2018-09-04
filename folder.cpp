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
    for(int i = 0; i < permissions.size(); i++)
        cout << permissions[i];

    // print the folder name
    cout << "\t" << this->get_folder_date_time().substr(0, this->get_folder_date_time().length() -1) << " " <<  this->get_folder_name() << endl;
}

void Folder::change_permission(string change, int index)
{
    // index 1 = read, index 2 = write, index 3 = execute
    // this->folder[this->folder_name][index] = change;
}