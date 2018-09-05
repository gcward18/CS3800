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

string go_back_one_step( const string& str,string delimiter)
{
  string new_str = str.substr(0, str[str.length()-3]);
  std::size_t found = new_str.find_last_of(delimiter);
  return str.substr(0,found);
}

string get_home_dir (const std::string& str)
{
  return str.substr(0,str.find("/"));
}

#endif