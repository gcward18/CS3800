#include "directory.h"

void Directory::print_files(string cwd)
{
    for(int i = 0; i < this->dir_folders[cwd].size(); i++)
        this->dir_files[cwd][i].print_file_without_permissions;
}

void Directory::print_folders(string cwd)
{
    for(int i = 0; i < this->dir_folders[cwd].size(); i++)
        this->dir_folders[cwd][i].print_folder_without_permissions;

}
