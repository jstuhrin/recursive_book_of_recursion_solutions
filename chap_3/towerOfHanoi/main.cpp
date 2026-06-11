
#include <iostream>

#include "towerOfHanoi.hpp"

int main()
{
  TowerOfHanoi towerOfHanoi;

  towerOfHanoi.solve(16);

  std::cout << "\nFinal state:\n\n";
  towerOfHanoi.printPegs();

  towerOfHanoi.checkResult();

  return 0;
}