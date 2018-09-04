#include <iostream>
// #include <vector>
#include "directory.h"
#include "_helper/parse_file_path.h"
using namespace std;

int main()
{
    Directory d1; 
    d1.print_dir_contents_with_permissions();
    d1.print_dir_contents_without_permissions();
    return 0;
}