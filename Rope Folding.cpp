/*
Farmer John has a long rope of length L (1 <= L <= 10,000) that he uses for
various tasks around his farm.  The rope has N knots tied into it at
various distinct locations (1 <= N <= 100), including one knot at each of
its two endpoints.
FJ notices that there are certain locations at which he can fold the rope
back on itself such that the knots on opposite strands all line up exactly
with each-other.
Please help FJ count the number of folding points having this property. 
Folding exactly at a knot is allowed, except folding at one of the
endpoints is not allowed, and extra knots on the longer side of a fold are
not a problem (that is, knots only need to line up in the areas where there
are two strands opposite each-other).  FJ only considers making a single
fold at a time; he fortunately never makes multiple folds.
*/
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
  freopen ("folding.in", "r", stdin); freopen ("folding.out", "w", stdout);
  scanf ("%d %d", &N, &L);
  for (i=0; i<N; i++)  scanf ("%d", &knots[i]);
  qsort (knots, N, sizeof(int), intcmp); /* Sort knots */
  /* Convert knots array into successive differences */
  for (i=0; i<N-1; i++) knots[i] = knots[i+1] - knots[i];
  /* Check left palindromes */
  for (i=0; i<N-1; i++)  if (check_palindrome(0,i)) count++;
  /* Check right palindromes */
  for (i=1; i<N-1; i++) if (check_palindrome(i,N-2)) count++;
  printf ("%d\n", count);
  return 0;
}
