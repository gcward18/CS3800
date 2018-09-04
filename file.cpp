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