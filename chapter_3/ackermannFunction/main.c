
#include <assert.h>
#include <stdio.h>

int ackermann(int m, int n, int indentation);

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