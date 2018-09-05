#include "directory.h"

void Directory::print_dir_contents_without_permissions()
{
    vector<Folder> folders = this->dir_contents.first;
    vector<File>  files   = this->dir_contents.second;

    // loop that prints all the folders in directory
    for(int i = 0; i < folders.size(); i++)
        cout << folders[i].get_folder_name() << " ";
    
    // loop prints all the files in the directory
    for(int i = 0; i < files.size(); i++)
        cout << files[i].get_file_name() << " ";
    
    // clear to the next line
    cout << endl;

    this->set_folders(folders);
    this->set_files(files);
}

void Directory::print_dir_contents_with_permissions()
{
    // loop that prints all the folders in directory
    for(int i = 0; i < this->dir_contents.first.size(); i++)
        this->dir_contents.first[i].print_folder_with_permissions();
    
    // loop prints all the files in the directory
    for(int i = 0; i < dir_contents.second.size(); i++)
        this->dir_contents.second[i].print_file_with_permissions();
    
    // clear to the next line
    cout << endl;
}

void Directory::make_dir(string dir_name)
{    
    // iterate throug the folders and see if one is already in the directory
    for(int i = 0; i < this->dir_contents.first.size(); i++)
    {
        // if already in directory then we just print a statement and 
        // exit
        if(this->dir_contents.first[i].get_folder_name()     ==  dir_name)
        {
            cout << "FOLDER ALREADY EXISTS" << endl;
            return;
        }
    }
    this->dir_contents.first.push_back(Folder(dir_name));
}
