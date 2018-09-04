#include "directory.h"
// #include "_helper/parse_file_path.h"

void Directory::print_dir_contents_without_permissions()
{
    // loop that prints all the folders in directory
    for(int i = 0; i < this->dir_contents[this->cwd].first.size(); i++)
        cout << this->dir_contents[this->cwd].first[i].get_folder_name() << " ";
    
    // loop prints all the files in the directory
    for(int i = 0; i < dir_contents[this->cwd].second.size(); i++)
        cout << this->dir_contents[this->cwd].second[i].get_file_name() << " ";
    
    // clear to the next line
    cout << endl;
}

void Directory::print_dir_contents_with_permissions()
{
    // loop that prints all the folders in directory
    for(int i = 0; i < this->dir_contents[this->cwd].first.size(); i++)
        this->dir_contents[this->cwd].first[i].print_folder_with_permissions();
    
    // loop prints all the files in the directory
    for(int i = 0; i < dir_contents[this->cwd].second.size(); i++)
        this->dir_contents[this->cwd].second[i].print_file_with_permissions();
    
    // clear to the next line
    cout << endl;
}

void Directory::make_dir(string dir_name)
{    
    // iterate throug the folders and see if one is already in the directory
    for(int i = 0; i < this->dir_contents[this->cwd].first.size(); i++)
    {
        // if already in directory then we just print a statement and 
        // exit
        if(this->dir_contents[this->cwd].first[i].get_folder_name()     ==  dir_name)
        {
            cout << "FOLDER ALREADY EXISTS" << endl;
            return;
        }
    }
    this->dir_contents[this->cwd].first.push_back(Folder(dir_name));
}

void Directory::change_dir(string dir_name)
{
    // bool directory_found = false;

    // // if the request is just to move back to the previous directory 
    // // the move back and exit function
    // if(dir_name == ".." && this->cwd != "home/")
    // {   
    //     this->cwd = get_file_path(this->cwd);
    //     return;
    // }
    
    // // iterate through the contents in the directory and see if the request
    // // directory in linked to the current, if not then break out
    // for(int i = 0; i < this->dir_contents[this->cwd].first.size(); i++)
    // {
    //     //   current working directory,  folder list                        directory wanted
    //     if(this->dir_contents[this->cwd].first[i].get_folder_name()     ==  dir_name)
    //     {
            
    //     }
    // }
    // string new_dir = this->cwd + dir_name + "/";
    // cout << new_dir << endl;

}