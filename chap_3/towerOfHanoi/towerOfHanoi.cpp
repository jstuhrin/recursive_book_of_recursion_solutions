
#include <cassert>
#include <iostream>

#include "towerOfHanoi.hpp"

void TowerOfHanoi::solve(int n)
{
  populate(n);
  std::cout << "Initial state:\n\n";
  printPegs();
  if (n < 1) return;
  std::cout << "Beginning to sort:\n\n";
  solveRecursively(n, A_, C_, B_);
  std::cout << "\nFinal state:\n\n";
  printPegs();
  checkResult();
}

void TowerOfHanoi::populate(int n)
{
  clear();
  for (; n > 0; --n)
  {
    A_.push_back(n);
  }
}

void TowerOfHanoi::moveOneDisc(std::vector<int>& start, std::vector<int>& end)
{
  end.push_back(start.back());
  start.pop_back();
}

void TowerOfHanoi::solveRecursively(int n, std::vector<int>& start, std::vector<int>& end, std::vector<int>& temp)
{
  if (n == 1)
  {
    moveOneDisc(start, end);
    printPegs();
    checkPeg(end);
    return;
  }
  solveRecursively(n - 1, start, temp, end);
  moveOneDisc(start, end);
  printPegs();
  checkPeg(end);
  solveRecursively(n - 1, temp, end, start);
}

void TowerOfHanoi::checkResult() const
{
  assert(A_.size() == 0);
  assert(B_.size() == 0);
  checkPeg(C_);
}

void TowerOfHanoi::printPeg(const std::vector<int>& peg) const
{
  for (const int disc : peg)
  {
    std::cout << disc << ' ';
  }
  std::cout << "\n\n";
}

void TowerOfHanoi::printPegs() const
{
  std::cout << "A: ";
  printPeg(A_);
  std::cout << "B: ";
  printPeg(B_);
  std::cout << "C: ";
  printPeg(C_);
}

void TowerOfHanoi::clear()
{
  A_.clear();
  B_.clear();
  C_.clear();
}

void TowerOfHanoi::checkPeg(const std::vector<int>& peg) const
{
  for (std::size_t i = 1; i < peg.size(); ++i)
  {
    assert(peg[i - 1] > peg[i]);
  }
}