#include "directory.h"

void Directory::print_files(string cwd)
{
    for(int i = 0; i < this->dir[cwd].size(); i++)
        cout << this->dir[cwd][i] << endl;
}
