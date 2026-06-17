
#include <assert.h>
#include <stdio.h>

int ackermann(int m, int n, int indentation)
{
  assert(m >= 0 && n >= 0);
  printf("%*sackermann(%d, %d)\n", indentation, "", m, n);
  if (m == 0)
  {
    return n + 1;
  }
  if (m > 0 && n == 0)
  {
    return ackermann(m - 1, 1, indentation + 1);
  }
  return ackermann(m - 1, ackermann(m, n - 1, indentation + 1), indentation + 1);
}
