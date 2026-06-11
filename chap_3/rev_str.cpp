
#include <cassert>
#include <string>

std::string rev_str(std::string str)
{
  if (str.size() == 0 || str.size() == 1) return str;
  return rev_str(std::string(str.begin() + 1, str.end())) + str[0];
}

int main()
{
  {
    std::string str{"abcdef"};
    assert(rev_str(str).compare("fedcba") == 0);
  }
  {
    std::string str("Hello, world!");
    assert(rev_str(str).compare("!dlrow ,olleH") == 0);
  }
  {
    std::string str{};
    assert(rev_str(str).compare("") == 0);
  }
  {
    std::string str("X");
    assert(rev_str(str).compare("X") == 0);
  }
  return 0;
}