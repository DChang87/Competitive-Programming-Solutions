//Clever iteration

//Solution Notes: This is a somewhat interesting problem since there are several nice algorithmic ways to approach its solution. The problem can be solved in O(N log N) time due to the need to sort the cows by x coordinate as a preprocessing step. One nice method (perhaps not the simplest, but worth mentioning) is the following: we sort scan through the cows from left to right (i.e., by x coordinate) keeping track of the most recent occurrence of each ID in a data structure. For example, if we are visiting a cow at (x,ID) = (10,17), our data structure might tell us that the most recent previous occurrence of a cow with breed ID 17 was at x=3, at which point we would then update the record in the data structure to x=10 and continue scanning (for IDs that have not yet occurred, we keep track of the value -infinity). Now as we scan over a particular coordinate x, let us suppose x is the right endpoint of a photograph window; we can compute the best possible matching left endpoint by simply taking the minimum of all the "most recent occurrence" x values in our data structure, so if we use an appropriate data structure like a heap, we can determine this minimum very quickly, making the entire scan take only O(N log N) time. During the scan, we simply remember the largest window we have seen.

//A slightly simpler approach involves scanning both the left and right endpoint of the photograph window in a monotonic fashion in lock step. We start with left = right = the leftmost cow. We then advance the right pointer whenever we notice that not every type of breed ID is present in the window; otherwise we advance the left pointer (noting the size of the window in this case, so we can return the largest over the entire scan). We can tell whether every breed ID exists within our window by storing a count of each breed ID within the window in a data structure like a map or multiset (or even a simple array would work, if we first sort the IDs and then map them down to integers in the range 0...N-1 as a preprocessing step). The breed ID counts are incremented whenever we advance the right pointer and decremented whenever we advance the left pointer.



#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
using namespace std;

typedef struct {
  int loc, id;
} Cow;

int sort_cows(const void* v1, const void *v2) {
  Cow *c1 = (Cow*)v1, *c2 = (Cow*)v2;
  return c1->loc>c2->loc;
}

int main() {
  freopen("lineup.in", "r", stdin); freopen("lineup.out", "w", stdout);
  int num_IDS, N, i, num_in_map = 0, A[50000], IDS[50000], start, end, min;
  Cow cows[50000];
  map<int, int> breeds;
  set<int> ID_set;

  scanf("%d", &N);
  for(i=0; i<N; i++) {
    scanf("%d %d", &cows[i].loc, &cows[i].id);
    ID_set.insert(cows[i].id);
    breeds[cows[i].id] = 0;
  }

  qsort(cows, N, sizeof(Cow), sort_cows);

  num_IDS = ID_set.size();

  start = 0;
  end = 0;
  min = 1<<30;

  while(1) {
    while(num_in_map!=num_IDS && end<N) {
      if(breeds[cows[end].id]==0)
        num_in_map++;
      breeds[cows[end++].id]++;
    }
    if(end==N && num_in_map!=num_IDS)
      break;

    while(breeds[cows[start].id]>1)
      breeds[cows[start++].id]--;

    if(cows[end-1].loc-cows[start].loc<min) min = cows[end-1].loc-cows[start].loc;
    breeds[cows[start++].id]--;
    num_in_map--;
  }

  printf("%d\n", min);

  return 0;
}
