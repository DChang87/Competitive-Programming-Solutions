//In the example below, we assume there exists a number x between 0 and n − 1, such that any number
less than x does not have certain property P, and any other number has property P. We want to binary
search the number x.

int binarySearch(){
  // want: P(lo) is always false, and P(hi) always true
  int lo, hi, mi; lo=0; hi=n-1;
  while(lo+1<hi)
  {
    mi=(lo+hi)/2;
    if(P(mi)) hi=mi; else lo=mi;
  }
  return hi;
}
