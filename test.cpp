#include <iostream>
#include "stdlib.h"
#include "string.h"
#include "folder.h"
#include <map>
#include <vector>
using namespace std;

void read_list(string list[] , int num_items = 0)
{
    for(int i = 0; i < num_items; i++)
        cout << list[i] << endl;
}

int main()
{
    vector<string>  stuff;
    string          f_name = "folder";
    string          permissions[3] = {"w","r","x"};
    Folder          f1(f_name, permissions);

    f1.print_folder_with_permissions();


    return 0;
}