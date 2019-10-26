#include <iostream>
#include <math.h>

bool is_int(double num) {
  //std::cout << "truncation " << (int)num << std::endl; 
  return fabs(num - (int)num) < 1e-15;       // compare the number with its truncation (float precision is 15 digits)

}

int get_int() {
  double i;
  while(!(std::cin >> i) || !is_int(i)) {
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Try again ";
   }
  return((int)i);
}

double get_double() {
  double i;
  while(!(std::cin >> i)) {
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Try again ";
   }
  return i;
}


int main() {
  int num;
  std::cout << "Insert integer number ";
  num = get_int();
  std::cout << "The valid number is " << num << std::endl;

  double num2;
  std::cout << "Insert floating-point number ";
  num2 = get_double();
  std::cout << "The valid number is " << num2 << std::endl;
  return 0;
}

