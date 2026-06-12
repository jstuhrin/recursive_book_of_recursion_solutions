
#include <cassert>
#include <print>

#include "towerOfHanoi.hpp"

void TowerOfHanoi::solve(int n)
{
  populate(n);
  std::print("Initial state:\n\n");
  printPegs();
  if (n < 1) return;
  std::print("Beginning to sort:\n\n");
  solveRecursively(n, A_, B_, C_);
  std::print("\nFinal state:\n\n");
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

void TowerOfHanoi::solveRecursively(int n, std::vector<int>& start, std::vector<int>& temp, std::vector<int>& end)
{
  if (n == 1)
  {
    moveOneDisc(start, end);
    printPegs();
    checkPeg(end);
    return;
  }
  solveRecursively(n - 1, start, end, temp);
  moveOneDisc(start, end);
  printPegs();
  checkPeg(end);
  solveRecursively(n - 1, temp, start, end);
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
    std::print("{} ", disc);
  }
  std::print("\n");
}

void TowerOfHanoi::printPegs() const
{
  std::print("A: ");
  printPeg(A_);
  std::print("B: ");
  printPeg(B_);
  std::print("C: ");
  printPeg(C_);
  std::print("\n");
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