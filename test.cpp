#include <iostream>
// #include <vector>
#include "string.h"
#include <cstddef>
#include "directory.h"
using namespace std;

int main()
{
    string str = "home/folder/folder2";
    cout <<  str << endl;
    cout << go_back_one_step(str,"/\\") << endl;

 return 0;
}