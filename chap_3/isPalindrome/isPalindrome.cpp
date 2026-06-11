
#include <string>
#include <cassert>

bool recursion(std::string::const_iterator first, std::string::const_iterator last)
{
  if (first >= last) return true;
  return *first == *last && recursion(++first, --last);
}

bool isPalindrome(std::string str)
{
  return recursion(str.begin(), str.end() - 1);
}

int main()
{
  {
    std::string str{"racecar"};
    assert(isPalindrome(str) == true);
  }
  {
    std::string str{"tacocat"};
    assert(isPalindrome(str) == true);
  }
  {
    std::string str{"palindrome"};
    assert(isPalindrome(str) == false);
  }
  {
    std::string str{"a"};
    assert(isPalindrome(str) == true);
  }
  {
    std::string str{""};
    assert(isPalindrome(str) == true);
  }
  return 0;
}