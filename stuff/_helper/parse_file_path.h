#include <iostream>
#include "string.h"
#include <cstddef>
using namespace std;

#ifndef PARSE_FILE_PATH_H
#define PARSE_FILE_PATH_H

/**
 * Function Found at URL: http://www.cplusplus.com/reference/string/string/find_last_of/
 */
string get_file_path (const std::string& str)
{
  std::size_t found = str.find_last_of("/\\");
  return str.substr(0,found);
}

string get_home_dir (const std::string& str)
{
  return str.substr(0,str.find("/"));
}

#endif