#include <iostream>
#include <algorithm>
#include <vector>

// read from stdin a sequence of words
void read_words(std::vector<std::string> &words) {
  std::string new_word;
  while(std::getline(std::cin,new_word))      // keep reading from stdin
    words.push_back(new_word);                // append the new word

}

// this is an adaptation of the old exercise "uniq.cc"
void uniq_words(std::vector<std::string> &words) {
  std::sort( words.begin(), words.end() );      // sort the vector so that equal words appear together
  std::string current{words[0]};    // keep track of what set of equal words I am looking at

  for(auto w : words) {
    if(w!=current)      // if the new line is different from the previous one
    {
      std::cout << current << std::endl;          // print the line
      current = w;     // update current line
    }
  }
  std::cout << current << std::endl;        // for the last line
}


int main() {

  std::vector<std::string> words;

  read_words(words);
  std::cout << "Now print without repetitions:\n";
  uniq_words(words);


  return 0;
}
