
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
  printPegs();
  checkPeg(end);
}

void TowerOfHanoi::solveRecursively(int n, std::vector<int>& start, std::vector<int>& end, std::vector<int>& temp)
{
  if (n == 1)
  {
    moveOneDisc(start, end);
    return;
  }
  solveRecursively(n - 1, start, temp, end);
  moveOneDisc(start, end);
  solveRecursively(n - 1, temp, end, start);
}

void TowerOfHanoi::checkResult() const
{
  assert(A_.size() == 0);
  assert(B_.size() == 0);
  if (C_.size() == 0) return;
  for (std::size_t i = 0; i < C_.size() - 1; ++i)
  {
    assert(C_[i] > C_[i + 1]);
  }
}

void TowerOfHanoi::printPeg(const std::vector<int>& peg) const
{
  for (size_t i = 0; i < peg.size(); ++i)
  {
    std::cout << peg[i] << ' ';
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
  for (std::size_t i = 0; i < peg.size() - 1; ++i)
  {
    assert(peg[i] > peg[i + 1]);
  }
}