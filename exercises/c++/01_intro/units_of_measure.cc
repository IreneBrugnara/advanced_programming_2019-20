#include <iostream>

int main() {
  float meas;
  std::string unit;
  std::cout << "Insert measure with unit: ";
  std::cin >> meas;
  std::cin >> unit;
  if(unit=="inch")
    std::cout << 0.0254*meas << " m" << std::endl;
  else if(unit=="feet")
    std::cout << 0.3048*meas << " m" << std::endl;

  return 0;
}
