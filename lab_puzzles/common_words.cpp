/**
 * @file common_words.cpp
 * Implementation of the CommonWords class.
 *
 * @author Zach Widder
 * @date Fall 2014
 */

#include "common_words.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;

string remove_punct(const string& str)
{
    string ret;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(ret),
                        std::ptr_fun<int, int>(&std::ispunct));
    return ret;
}

CommonWords::CommonWords(const vector<string>& filenames)
{
    // initialize all member variables
    init_file_word_maps(filenames);
    init_common();
}

void CommonWords::init_file_word_maps(const vector<string>& filenames)
{
    // make the length of file_word_maps the same as the length of filenames
    file_word_maps.resize(filenames.size());

    // go through all files
    for (size_t i = 0; i < filenames.size(); i++) {
        // get the corresponding vector of words that represents the current
        // file
        vector<string> words = file_to_vector(filenames[i]);
        map<string, unsigned int> & word_map = file_word_maps[i];

        for(vector<string>::iterator it = words.begin(); it != words.end(); it++)
        {
          map<string, unsigned int>::iterator lookup = word_map.find(*it);
          if (lookup != word_map.end())
          {
            word_map[*it]++;
          }
          else
          {
            word_map[*it] = 1;
          }
        }
    }
}

void CommonWords::init_common()
{
    for(std::pair<const string, unsigned int>&  it : file_word_maps[0])
    {
      int flag_common = 1;
      unsigned int count = it.second;
      for (size_t i = 1; i < file_word_maps.size(); i++)
      {
        map<string, unsigned int>::iterator lookup = file_word_maps[i].find(it.first);
        if (lookup == file_word_maps[i].end())
        {
          flag_common = 0;
          break;
        }
        else if (lookup->second < count)
        {
          count = lookup->second;
        }
      }

      if (flag_common == 1)
        common[it.first] = count;
    }

}

/**
 * @param n The number of times to word has to appear.
 * @return A vector of strings. The vector contains all words that appear
 * in each file >= n times.
 */
vector<string> CommonWords::get_common_words(unsigned int n) const
{
    vector<string> out;

    for(std::pair<const string, unsigned int> const it : common)
    {
      if(it.second >= n)
        out.push_back(it.first);
    }
    return out;
}

/**
 * Takes a filename and transforms it to a vector of all words in that file.
 * @param filename The name of the file that will fill the vector
 */
vector<string> CommonWords::file_to_vector(const string& filename) const
{
    ifstream words(filename);
    vector<string> out;

    if (words.is_open()) {
        std::istream_iterator<string> word_iter(words);
        while (!words.eof()) {
            out.push_back(remove_punct(*word_iter));
            ++word_iter;
        }
    }
    return out;
}
