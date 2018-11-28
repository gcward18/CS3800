#include "../_headers/shell.h"
#include <sstream>
//#include "_helper/parse_file_path.h"

void Shell::run_shell()
{
    // While the user has not requested to terminate 
    // shell excecution continue
    while(!this->finished)
    {
        bool found_file = false;
        bool found_folder = false;
        string flag;
        string file;
        bool   impoper_perm = false;
        Mem    memManagement;
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
            else if (flag == "")
            {
                cout << "INVALID COMMAND" << endl;
            }
            else
            {
                for(unsigned int i = 0; i < dir.get_folders().size(); i++)
                {
                    if(flag == dir.get_folders()[i].get_folder_name() && (flag != "." && flag != ".." ))
                    {   
                        found_folder = true;
                        string new_dir = dir.get_cwd() + flag + "/";
                        dir.set_cwd(new_dir);
                        dir.map_new_dir(new_dir);
                    }
                }
                if (!found_folder)
                    cout << "INVALID COMMAND" << endl;
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
            found_file = false;
            found_folder = false;

            for(int i = 0; i < this->dir.get_files().size(); i++)
                if( this->dir.get_files()[i].get_file_name() == flag)
                {    
                    found_file = true;
                }
            if (!found_file)
                for(int i = 0; i < this->dir.get_folders().size(); i++)
                    if( this->dir.get_folders()[i].get_folder_name() == flag)
                    {    
                        found_folder = true;
                    }
            

            this->dir.update_datetime(flag);
            if(!found_file && !found_folder)
                this->dir.make_file(flag);
            
        }
        else if (command == "memalg")
        {
            if (flag == "first" || flag == "best" || flag == "next")
            {
                memManagement.setAlgorithm(flag);
            }
            else
            {
                cout << "INVALID COMMAND" << endl;
            }
        }
        else if(command == "memload")
        {
            memManagement.openFile(flag);
        }
        else if(command == "memreset")
        {
            memManagement.reset();
        }
        else if(command == "memset")
        {
            if (stoi(flag))
            {
                memManagement.setBlockSize(stoi(flag));
            }
        }
        else if(command == "memstep")
        {
            if (stoi(flag))
            {
                memManagement.setStep(stoi(flag));
            }
            else if (flag == "all")
            {
                // memManagement.setStepAll(false);
            }
        }
        else if(command == "memview")
        {
            memManagement.view();
        }
        // not a valid command
        else
        {
            cout << "INVALID COMMAND" << endl;
        }
        

    }
}