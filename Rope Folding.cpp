//create a difference array ([0,2,4,6,10] -> [2,2,2,4])
//look for palindromes within the difference array
//odd palindrome signifies a fold between knots (even number of knots involved)
//even palindrome signifies a fold on a knot (odd number of knots invovled, one must be on the fold)
//check palindrome from the left, from the right

//clever algorithm


#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100

int knots[MAX_N];

int intcmp(const void *p1, const void *p2)
{
  int *i1 = (int *)p1;
  int *i2 = (int *)p2;
  return *i1 - *i2;
}

int check_palindrome(int start, int end)
{
  int i;
  for (i=0; start+i<=end-i; i++)
    if (knots[start+i] != knots[end-i]) return 0;
  return 1;
}

int main(void)
{
  int N, L, i, count=0;

  freopen ("folding.in", "r", stdin);
  freopen ("folding.out", "w", stdout);
  
  scanf ("%d %d", &N, &L);
  for (i=0; i<N; i++)
    scanf ("%d", &knots[i]);

  /* Sort knots */
  qsort (knots, N, sizeof(int), intcmp);

  /* Convert knots array into successive differences */
  for (i=0; i<N-1; i++)
    knots[i] = knots[i+1] - knots[i];

  /* Check left palindromes */
  for (i=0; i<N-1; i++)
    if (check_palindrome(0,i)) count++;

  /* Check right palindromes */
  for (i=1; i<N-1; i++)
    if (check_palindrome(i,N-2)) count++;

  printf ("%d\n", count);

  return 0;
}
