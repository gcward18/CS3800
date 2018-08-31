#include "shell.h"

void Shell::run_shell()
{
    // While the user has not requested to terminate 
    // shell excecution continue
    while(!this->finished)
    {
        cout << this->cwd;
        cin >> this->command;

        if(command == "quit")
        {
            finished = true;
            continue;
        }
        if(command == "ls")
        {
            dir.print_files("home/");
        }
        else
        {
            cout << "INVALID COMMAND" << endl;
        }
        

    }
}