#include <iostream>
// #include <vector>
#include "file.h"
#include "_helper/parse_file_path.h"
using namespace std;

int main()
{
    File f1("a.out"); 
    f1.print_file_with_permissions();
    return 0;
}