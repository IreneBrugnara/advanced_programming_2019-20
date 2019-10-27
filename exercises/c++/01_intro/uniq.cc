#include <iostream>
// expect to read lines from a file

int main() {
  std::string line, current;
  bool label = 1;    // first line

  int i{0};         // counter: how many equal words in a row exist
  while(std::getline(std::cin,line)) {          // insert a new line
    if (label)     // just for the first line
      current = line;
      label = 0;
    if (line==current)      // if the new line is equal to the previous one
      i++;      // increment the counter
    else
    {
      std::cout << i << " " << current << std::endl;          // print the line
      i=1;     // reset the counter
      current = line;     // update current line
    }

  }
  std::cout << i << " " << current << std::endl;        // for the last line


  return 0;
}
