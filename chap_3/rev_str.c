
#include <assert.h>
#include <string.h>
#include <stdio.h>

void reverseRecursively(char* first, char* last)
{
  if (first >= last) return;
  *first = *first ^ *last;
  *last = *first ^ *last;
  *first = *first ^ *last;
  reverseRecursively(++first, --last);
}

char* rev_str(char* str)
{
  size_t len = strlen(str);
  if (len == 0 || len == 1)
  {
    return str;
  }
  reverseRecursively(str, str + len - 1);
  return str;
}

int main(void)
{
  {
    char str[] = "abcdef";
    assert(strcmp(rev_str(str), "fedcba") == 0);
  }
  {
    char str[] = "";
    assert(strcmp(rev_str(str), "") == 0);
  }
  {
    char str[] = "X";
    assert(strcmp(rev_str(str), "X") == 0);
  }

  return 0;
}