#include "directory.h"

void Directory::print_dir_contents_without_permissions()
{
    // Get files and folders from directory
    vector<File>    files = this->get_files();
    vector<Folder>  folders = this->get_folders();

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
    // Get files and folders from directory
    vector<File>    files = this->get_files();
    vector<Folder>  folders = this->get_folders();

    // loop that prints all the folders in directory
    for(int i = 0; i < folders.size(); i++)
        folders[i].print_folder_with_permissions();
    
    // loop prints all the files in the directory
    for(int i = 0; i < files.size(); i++)
        files[i].print_file_with_permissions();
    
    // clear to the next line
    cout << endl;

}

void Directory::make_dir(string dir_name)
{    
    vector<Folder>  folders = this->get_folders();
    // iterate throug the folders and see if one is already in the directory
    for(int i = 0; i < folders.size(); i++)
    {
        // if already in directory then we just print a statement and 
        // exit
        if(folders[i].get_folder_name()     ==  dir_name)
        {
            cout << "FOLDER ALREADY EXISTS" << endl;
            return;
        }
    }
    
    folders.push_back(Folder(dir_name));
    // now set the folders in the directory
    this->set_folders(folders);
}


void Directory::make_file(string file_name)
{    
    vector<File> files = this->get_files();
    
    // iterate throug the folders and see if one is already in the directory
    for(int i = 0; i < files.size(); i++)
    {
        // if already in directory then we just print a statement and 
        // exit
        if(files[i].get_file_name()     ==  file_name)
        {
            cout << "FOLDER ALREADY EXISTS" << endl;
            return;
        }
    }
    files.push_back(File(file_name));

    // Set the files in the directory
    this->set_files(files);
}

void Directory::map_new_dir(string new_cwd)
{
    dir_contents[new_cwd].first.push_back(Folder("."));
    dir_contents[new_cwd].first.push_back(Folder(".."));
    dir_contents[new_cwd].second.push_back(File("README.txt"));
}


/**
 * Puspose: Remove directory
 */
void Directory::remove_folder(string f_name)
{
    // Get files and folders from directory
    vector<Folder>  folders = this->get_folders();

    // find folder
    for(int i = 0; i < folders.size(); i++){
        if ( f_name == folders[i].get_folder_name() )
        {    
            folders[i].remove_folder();
            folders.erase(folders.begin() + i);
        }
    }
}

void Directory::remove_file(string f_name)
{
    vector<File>    files = this->get_files();
    int pos;
        // find file
    for(int i = 0; i < files.size(); i++){
        if ( f_name == files[i].get_file_name() )
        { 
            
            files[i].remove_file();
            files.erase(files.begin() + i);
        }
    }

}

string Directory::go_back_one_step( const std::string& str)
{
  string new_str = str.substr(0, str[str.length()-3]);
  cout << new_str << endl;
  std::size_t found = new_str.find_last_of("/\\");
  return str.substr(0,found);
}

