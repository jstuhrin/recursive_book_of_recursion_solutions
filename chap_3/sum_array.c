
#include <assert.h>
#include <limits.h>

int sum(int* nums, int numsSize)
{
  if (numsSize == 0)
  {
    return 0;
  }
  return nums[0] + sum(++nums, --numsSize);
}

int main(void)
{
  {
    int nums[5] = {1,2,3,4,5};
    assert(sum(nums, sizeof(nums)/sizeof(int)) == 15);
  }
  {
    int nums[1] = {1};
    assert(sum(nums, sizeof(nums)/sizeof(int)) == 1);
  }
  {
    int nums[0];
    assert(sum(nums, sizeof(nums)/sizeof(int)) == 0);
  }
  {
    int nums[4] = {1,10,100,1000};
    assert(sum(nums, sizeof(nums)/sizeof(int)) == 1111);
  }
  {
    int nums[2] = {INT_MAX, INT_MIN};
    assert(sum(nums, sizeof(nums)/sizeof(int)) == -1);
  }
  {
    int nums[2] = {INT_MAX, INT_MAX};
    assert(sum(nums, sizeof(nums)/sizeof(int)) == -2);
  }
  {
    int nums[2] = {INT_MIN, INT_MIN};
    assert(sum(nums, sizeof(nums)/sizeof(int)) == 0);
  }

  return 0;
}