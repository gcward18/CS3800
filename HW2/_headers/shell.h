#ifndef SHELL_H
#define SHELL_H
#include <iostream>
#include "directory.h"
#include "string.h"
using namespace std;

class Shell
{
    Directory       dir;
    string          command;
    string          cwd =   "home/";
    vector<string>  previous_commands;
    bool            finished = false;
    

    public:

    /**
     * Setters for Shell class
     */
    void set_dir();

    /**
     * Getters for Shell class
     */
    void get_dir();

    /**
     * Constructor for Shell class
     */
    Shell(){}

    /**********************************
     * Functions declarations for Shell
     **********************************/

    /**
     * Purpose: Run shell is the main function for running our
     *          shell program, this will bring up the shell 
     *          window and allow for users to interact with
     *          the program. 
     */
    void run_shell();



};

#endif