/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;


/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    ifstream wordsFile(filename);
    vector<string> words;
    string word;
    if (wordsFile.is_open())
    {
      while (getline(wordsFile, word))
      {
        words.push_back(word);
      }
    }

    for (size_t i = 0; i < words.size(); i++)
    {
      string k = words[i];
      sort(k.begin(), k.end());
      std::map<std::string, std::vector<std::string>>::iterator lookup = dict.find(k);
      if (lookup != dict.end())
      {
        lookup->second.push_back(words[i]);
      }
      else
      {
        dict[k] = {words[i]};
      }
    }
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
  for (size_t i = 0; i < words.size(); i++)
  {
    string k = words[i];
    sort(k.begin(), k.end());
    std::map<std::string, std::vector<std::string>>::iterator lookup = dict.find(k);
    if (lookup != dict.end())
    {
      lookup->second.push_back(words[i]);
    }
    else
    {
      dict[k] = {words[i]};
    }
  }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    string k = word;
    sort(k.begin(), k.end());
    auto lookup = dict.find(k);
    if (lookup != dict.end())
      return lookup->second;
    else
      return vector<string>();
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    vector<vector<string>> ret;
    for(auto it : dict)
    {
      if (it.second.size() > 1)
      {
        ret.push_back(it.second);
      }
    }

    return ret;
}
