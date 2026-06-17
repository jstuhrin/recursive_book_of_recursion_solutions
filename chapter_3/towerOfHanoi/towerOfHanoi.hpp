
#ifndef TOWEROFHANOI_HPP
#define TOWEROFHANOI_HPP

#include <vector>

class TowerOfHanoi
{
  public:
    void solve(int n);

  private:
    void populate(int n);
    void moveOneDisc(std::vector<int>& start, std::vector<int>& end);
    void solveRecursively(int n, std::vector<int>& start, std::vector<int>& temp, std::vector<int>& end);
    void printPeg(const std::vector<int>& peg) const;
    void clear();
    void checkPeg(const std::vector<int>& peg) const;
    void checkResult() const;
    void printPegs() const;

    std::vector<int> A_, B_, C_;
};

#endif