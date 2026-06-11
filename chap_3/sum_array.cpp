
#include <cassert>
#include <limits>
#include <vector>

int sumRecursively(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
  if (begin == end)
  {
    return 0;
  }
  return *begin + sumRecursively(++begin, end);
}

int sum(std::vector<int>& nums)
{
  return sumRecursively(nums.begin(), nums.end());
}

int main()
{
  {
    std::vector<int> nums = {1,2,3,4,5};
    assert(sum(nums) == 15);
  }
  {
    std::vector<int> nums = {1};
    assert(sum(nums) == 1);
  }
  {
    std::vector<int> nums{};
    assert(sum(nums) == 0);
  }
  {
    std::vector<int> nums = {std::numeric_limits<int>::max(), std::numeric_limits<int>::max()};
    assert(sum(nums) == -2);
  }

  return 0;
}