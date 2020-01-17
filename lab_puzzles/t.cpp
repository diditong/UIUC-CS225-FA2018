
void CommonWords::init_file_word_maps(const vector<string>& filenames)
{
    // make the length of file_word_maps the same as the length of filenames
    file_word_maps.resize(filenames.size());

    // go through all files
    for (size_t i = 0; i < filenames.size(); i++) {
        // get the corresponding vector of words that represents the current
        // file
        vector<string> words = file_to_vector(filenames[i]);
        map<string, unsigned int> word_map;// = {};

        for(vector<string>::iterator it = words.begin(); it != words.end(); it++)
        {
          map<string, unsigned int>::iterator lookup = word_map.find(*it);
          if (lookup != word_map.end())
          {
            lookup->second++;
          }
          else
          {
            word_map[*it] = 1;
          }
        }
        file_word_maps.push_back(word_map);
    }
}

void CommonWords::init_common()
{
    for(std::pair<const string, unsigned int>&  it : file_word_maps[0])
    {
      bool flag_common = true;
      unsigned int count = it.second;
      for (size_t i = 1; i < file_word_maps.size(); i++)
      {
        map<string, unsigned int>::iterator lookup = file_word_maps[i].find(it.first);
        if (lookup == file_word_maps[i].end())
        {
          flag_common = false;
          break;
        }
        else if (lookup->second < count)
        {
          count = lookup->second;
        }
      }
      flag_common =true;
      if (flag_common == true)
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
