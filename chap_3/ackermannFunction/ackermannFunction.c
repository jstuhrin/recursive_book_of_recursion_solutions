
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

int main(void)
{
  {
    int m = 1;
    int n = 1;
    printf("calling ackermann with m = %d and n = %d:\n", m , n);
    int result = ackermann(m, n, 0);
    printf("\nresult: %d\n\n", result);
    assert(result = 3);
  }

  {
    int m = 1;
    int n = 2;
    printf("calling ackermann with m = %d and n = %d:\n", m , n);
    int result = ackermann(m, n, 0);
    printf("\nresult: %d\n\n", result);
    assert(result = 4);
  }

  {
    int m = 2;
    int n = 2;
    printf("calling ackermann with m = %d and n = %d:\n", m , n);
    int result = ackermann(m, n, 0);
    printf("\nresult: %d\n\n", result);
    assert(result = 7);
  }

  {
    int m = 2;
    int n = 3;
    printf("\ncalling ackermann with m = %d and n = %d:\n", m , n);
    int result = ackermann(m, n, 0);
    printf("\nresult: %d\n\n", result);
    assert(result == 9);
  }

  {
    int m = 3;
    int n = 3;
    printf("\ncalling ackermann with m = %d and n = %d:\n", m , n);
    int result = ackermann(m, n, 0);
    printf("\nresult: %d\n\n", result);
    assert(result == 61);
  }

  return 0;
}