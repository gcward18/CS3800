#include <iostream>
#include "directory.h"
#include "shell.h"
#include "string.h"
using namespace std;

int main(){
    // Propt user that they are in Linux Shell
    cout << "Hello World Linux Shell Here!!!!" << endl;

    Shell myShell;

    myShell.run_shell();
    

    return 0;
}