//Solution Notes: This problem has a nice recursive solution. We first write a recursive function to compute the length of S(k) (given by twice the length of S(k-1) plus the length of the middle section, k+3). Afterwards, we can figure out the nth chracter in S(k) by checking if n lies in the left copy of S(k-1) (in which case we can proceed by recursion), in the middle section, or in the right copy of S(k-1) (in which case we can again proceed by recursion).
//clever recursive counting

#include <stdio.h>

/* Compute the length of S(k) */
int len(int k)
{
  int x;
  if (k==-1) return 0; 
  x = len(k-1);
  return x + k+3 + x;
}

/* Return nth character in S(k) */
char solve(int n, int k)
{
  if (n > len(k)) return solve(n,k+1);
  if (n <= len(k-1)) return solve(n,k-1);
  n = n - len(k-1); /* Discount S(k-1) from beginning of string */
  if (n <= k+3) /* n in middle section? */
    return (n==1) ? 'm' : 'o';
  n = n - (k+3);
  return solve(n,k-1); 
}

int main(void)
{
  int n;
  freopen ("moo.in", "r", stdin);
  freopen ("moo.out", "w", stdout);
  scanf ("%d", &n);
  printf ("%c\n", solve(n,0));
  return 0;
}
