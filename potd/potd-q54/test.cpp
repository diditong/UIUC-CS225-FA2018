#include <string>
#include <iterator>

string beiju(string input) {
    string out = "";
    unsigned index = 0;

    for (unsigned i = 0; i < input.length(); i++) {
      // We hit the home key
      if (input[i] == '[') {
        index = 0;
      }
      // We hit the end key
      else if (input[i] == ']') {
        index = out.length();
      }

      // We have a regular char
      else {
        // If the cursor is at the end of our text...
        if (index == out.length()) {
          out += input[i];
          index = out.length();
        }

        // If the cursor is at the beginning of our text...
        else if (index == 0) {
          string temp = out;
          out = input[i] + temp;
          index++;
        }

        // If the cursor is somewhere in between...
        else {
          string temp = out;
          out = temp.substr(0, index) + input[i] +
            temp.substr(index, temp.length());
          index++;
        }
      }
    }

    return out;

}
