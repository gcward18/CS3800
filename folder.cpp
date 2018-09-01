#include "folder.h"

void Folder::print_folder_without_permissions()
{
    cout << this->folder_name << endl;
}

void Folder::print_folder_with_permissions()
{
    for(int i = 0; i < this->folder[this->folder_name].size(); i++)
        cout << this->folder[this->folder_name][i];
    cout << "  " <<  this->folder_name << endl;
}

void Folder::change_permission(string change, int index)
{
    this->folder[this->folder_name][index] = change;
}