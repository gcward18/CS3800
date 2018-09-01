#include "file.h"

void File::print_file_without_permissions()
{
    cout << this->file_name << endl;
}

void File::print_file_with_permissions()
{
    for(int i = 0; i < this->file[this->file_name].size(); i++)
        cout << this->file[this->file_name][i];
    cout << "  " <<  this->file_name << endl;
}

void File::change_permission(string change, int index)
{
    this->file[this->file_name][index] = change;
}