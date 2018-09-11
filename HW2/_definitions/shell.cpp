#include "../_headers/shell.h"
#include <sstream>
//#include "_helper/parse_file_path.h"

void Shell::run_shell()
{
    // While the user has not requested to terminate 
    // shell excecution continue
    while(!this->finished)
    {
        string flag;
        string file;
        bool   impoper_perm = false;
        cout << dir.get_cwd() << "  ";
        
        getline(cin, command);
        istringstream iss(command);
        iss >> command >> flag >> file;

        if(command == "quit")
        {
            finished = true;
            continue;
        }
        // command to list the files and folders in directory
        else if(command == "ls")
        {
            // user wants to see the permissions
            if( flag == "-l" )
                dir.print_dir_contents_with_permissions();
            // user does not want to see permissions
            else if ( flag == "")
                dir.print_dir_contents_without_permissions();
            else 
                cout << "INVALID COMMAND"<< endl;
        }
        // display the current working directory
        else if ( command == "pwd" )
        {
            dir.print_dir_path();
        }
        // change directory
        else if ( command == "cd" )
        {
            // automatically go home
            if (flag == "~")
                dir.change_to_home_dir();
            // go back directory
            else if (flag == "..")
            {
                // if not in home directory then we can back out
                if (dir.get_cwd() != "home/")
                {
                    // the directory to the previous directory
                    dir.set_cwd(dir.go_back_one_step(dir.get_cwd()));
                }
            }
            else
            {
                for(unsigned int i = 0; i < dir.get_folders().size(); i++)
                {
                    if(flag == dir.get_folders()[i].get_folder_name() && (flag != "." && flag != ".." ))
                    {
                        string new_dir = dir.get_cwd() + flag + "/";
                        dir.set_cwd(new_dir);
                        dir.map_new_dir(new_dir);
                    }
                }
                
            }
        }
        else if ( command == "chmod" )
        {
            impoper_perm = false;
            for(unsigned int i = 0; i < flag.length(); i++)
                if(flag[i]-48 > 7 || flag[i] - 48 < 0 )
                {
                    impoper_perm = true;
                }
            if(!impoper_perm)
                dir.change_permissions(flag, file);
            else
                cout << "INVALID PERMISSIONS" <<endl;
        }
        // make directory
        else if ( command == "mkdir" )
        {
            dir.make_dir(flag);
        }
        // remove directory
        else if ( command == "rmdir" && (flag != "." && flag != ".." ))
        {
            dir.remove_folder(flag);
        }
        // remove file
        else if ( command == "rm" )
        {
            dir.remove_file(flag);
        }
        // make file
        else if ( command == "touch" )
        {
            dir.make_file(flag);
            
        }

        // not a valid command
        else
        {
            cout << "INVALID COMMAND" << endl;
        }
        

    }
}