#include "directory.h"
#include "_helper/parse_file_path.h"

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
}

void Directory::print_dir_contents_with_permissions()
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


// void Directory::change_dir(string dir_name)
// {
//     bool directory_found = false;
//     // Get files and folders from directory
//     vector<File>    files = this->get_files();
//     vector<Folder>  folders = this->get_folders();

//     // if the request is just to move back to the previous directory 
//     // the move back and exit function
//     if(dir_name == ".." && this->cwd != "home/")
//     {   
//         this->cwd = get_file_path(this->cwd) + "/";
//         return;
//     }
    
//     // iterate through the contents in the directory and see if the request
//     // directory in linked to the current, if not then break out
//     for(int i = 0; i < folders.size(); i++)
//     {
//         //   current working directory,  folder list                        directory wanted
//         if(folders[i].get_folder_name()     ==  dir_name)
//         {
//             directory_found = true;
//         }
//     }

//     if(directory_found = true)
//     {
//         string new_dir = this->cwd + dir_name + "/";
//         this->set_cwd(new_dir);
//     }
// }
