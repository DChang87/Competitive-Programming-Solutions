//Solution Notes: This problem is not too hard if we make the observation that 17N = 16N + N, and in binary 16N is just the binary representation of N followed by four digits of 0 (that is, N shifted right by four digits). We therefore add these two binary numbers to obtain our answer.


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char num1[1010], num2[1010], s[1010], result[1010] = {0};
  int i, L;

  freopen ("times17.in", "r", stdin);
  freopen ("times17.out", "w", stdout);

  scanf ("%s", s);
  sprintf (num1, "00000%s", s);
  sprintf (num2, "0%s0000", s);

  L = strlen(num1);
  for (i=L-1; i>0; i--) {
    result[i] += num1[i]-'0'+num2[i]-'0';
    if (result[i] >= 2) { result[i] -= 2; result[i-1] += 1; }
  }
  i = 0;
  if (result[0]==0) i = 1;
  while (i < L) 
    printf ("%d", result[i++]);
  printf ("\n");

  return 0;
}
