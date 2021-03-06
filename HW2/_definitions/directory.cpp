#include "../_headers/directory.h"

void Directory::print_dir_contents_without_permissions()
{
    // Get files and folders from directory
    vector<File>    files = this->get_files();
    vector<Folder>  folders = this->get_folders();

    // loop that prints all the folders in directory
    for( unsigned int i = 0; i < folders.size(); i++)
        cout << folders[i].get_folder_name() << " ";
    
    // loop prints all the files in the directory
    for( unsigned int i = 0; i < files.size(); i++)
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
    for( unsigned int i = 0; i < folders.size(); i++)
        folders[i].print_folder_with_permissions();
    
    // loop prints all the files in the directory
    for( unsigned int i = 0; i < files.size(); i++)
        files[i].print_file_with_permissions();
    
    // clear to the next line
    cout << endl;

}

void Directory::make_dir( const string& dir_name)
{    
    vector<Folder>  folders = this->get_folders();
    // iterate throug the folders and see if one is already in the directory
    for( unsigned int i = 0; i < folders.size(); i++)
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


void Directory::make_file( const string& file_name)
{    
    vector<File> files = this->get_files();
    
    // iterate throug the folders and see if one is already in the directory
    for( unsigned int i = 0; i < files.size(); i++)
    {
        // if already in directory then we just print a statement and 
        // exit
        if(files[i].get_file_name()     ==  file_name)
        {
            // get current time
            time_t now = time(NULL);
            string dt = ctime(&now);

            // set files time stamp to current datetime
            files[i].set_file_timeStamp(dt);
            return;
        }
    }
    files.push_back(File(file_name));

    // Set the files in the directory
    this->set_files(files);
}

void Directory::map_new_dir( const string& new_cwd)
{
    dir_contents[new_cwd].first.push_back(Folder("."));
    dir_contents[new_cwd].first.push_back(Folder(".."));
    dir_contents[new_cwd].second.push_back(File("README.txt"));
}


/**
 * Puspose: Remove directory
 */
void Directory::remove_folder(const string& f_name)
{
    // Get files and folders from directory
    vector<Folder>  folders = this->get_folders();

    // find folder
    for( unsigned int i = 0; i < folders.size(); i++){
        if ( f_name == folders[i].get_folder_name() )
        {    
            folders[i].remove_folder();
            folders.erase(folders.begin() + i);
        }
    }

    this->set_folders(folders);
}

void Directory::remove_file( const string& f_name)
{
    vector<File>    files = this->get_files();
    
    // find file
    for( unsigned int i = 0; i < files.size(); i++){
        if ( f_name == files[i].get_file_name() )
        { 
            
            files[i].remove_file();
            files.erase(files.begin() + i);
        }
    }

    this->set_files(files);
}

string Directory::go_back_one_step( const std::string& str)
{
    // // create a new string that is a sub string of the first path
    // string new_str = str.substr(0, str[str.length()-1]);
    string new_str = str;
    // find the position of the last "/"
    size_t found  = new_str.find_last_of("/");
    // create a new string that a subset of that 
    // Ex: home/file/ will now be home/file
    new_str       = new_str.substr(0,found);

    // find the position of the last "/"
    found  = new_str.find_last_of("/");

    // find the last "/" in the string
    // returns 4 from "home/file"
    //found         = new_str.find_last_not_of("/");

    // return "home/" from "home/file"
    return str.substr(0,found) + "/";
}

void Directory::change_permissions( const string& permission, const string& f_name)
{
    // Get files and folders from directory
    vector<File>    files = this->get_files();
    vector<Folder>  folders = this->get_folders();

    // iterate through files to see if it's a files permissions that 
    // needs to be changed
    for(unsigned int i = 0; i < files.size(); i++)
    {
        if ( f_name == files[i].get_file_name())
            files[i].change_permission(permission);
    }

    // iterate through folders to see if it's a folders permissions that 
    // needs to be changed
    for(unsigned int i = 0; i < folders.size(); i++)
    {
        if (f_name == folders[i].get_folder_name() )
            folders[i].change_permission(permission);
    }

    // set the files and folders
    this->set_files(files);
    this->set_folders(folders);
} 

void Directory::update_datetime(const string& fname)
{

    // check if file needs to update date time
    for(unsigned int i = 0; i < this->get_files().size(); i++)
    {
        if( this->get_files()[i].get_file_name() == fname)
        {
            this->dir_contents[this->get_cwd()].second[i].set_time();
        }
    }

    // check to see if folder need to update date time
    for(unsigned int i = 0; i < this->get_folders().size(); i++)
    {
        if( this->get_folders()[i].get_folder_name() == fname)
        {
            this->dir_contents[this->get_cwd()].first[i].set_time();
        }
    }
}
