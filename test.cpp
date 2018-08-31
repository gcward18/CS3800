#include <iostream>
#include "stdlib.h"
#include "string.h"
#include <map>
#include <vector>
using namespace std;

int main()
{
    vector<string>  stuff;
    string          list[3] = {"e1","e2","e3"};

    for(int i = 0; i < 3; i++){
        stuff.push_back(list[i]);
    }

    for(int i = 0; i < stuff.size() ; i++)
    {
        cout << stuff[i] << endl;
    }
    return 0;
}