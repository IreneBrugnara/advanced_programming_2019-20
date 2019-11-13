#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// get temperatures from file and save them in a std::vector
void get_temperatures(std::vector<double> &temp) {
  double new_temp;
  std::ifstream myfile;
  myfile.open("temperatures.txt");

  while(myfile >> new_temp)
    temp.push_back(new_temp); 
}

// print the temperatures
void print_temperatures(std::vector<double> temp) {
  for (const auto t : temp)
    std::cout << t << "\n";
}

double mean(std::vector<double> temp) {
  double mean{0};
  for (const auto t : temp)
    mean += t;
  mean /= temp.size();
  return mean;
}

double median(std::vector<double> temp) {
  std::sort( temp.begin(), temp.end() );
  std::size_t N = temp.size();
  if(N%2==0)    // even number of temperatures
    return (temp[N/2]+temp[N/2-1])/2;
  else
    return temp[N/2];
}

int main() {
// use auto loop
  std::vector<double> temp{};
  get_temperatures(temp);
  print_temperatures(temp);
  std::cout << "Mean = " << mean(temp) << "\n";
  std::cout << "Median = " << median(temp) << "\n";
  return 0;
}
