/*Utilizing sorting function in C++
The cows are in a particularly mischievous mood today!  All Farmer John wants to do is take a photograph of 
the cows standing in a line, but they keep moving right before he has a chance to snap the picture.

Specifically, FJ's N (1 <= N <= 20,000) cows are tagged with ID numbers 1...N.  FJ wants to take a picture of 
the cows standing in a line in a very specific ordering, represented by the contents of an array A[1...N],
where A[j] gives the ID number of the jth cow in the ordering.  He arranges the cows in this order, but 
just before he can press the button on his camera to snap the picture, up to one cow moves to a new position in the
lineup. More precisely, either no cows move, or one cow vacates her current position in the lineup and then 
re-inserts herself at a new position in the lineup.  Frustrated but not deterred, FJ again arranges his cows according
to the ordering in A, but again, right before he can snap a picture, up to one cow (different from the first) 
moves to a new position in the lineup. 

The process above repeats for a total of five photographs before FJ gives up.  Given the contents of each 
photograph, see if you can reconstruct the original intended ordering A.  Each photograph shows an ordering of the
cows in which up to one cow has moved to a new location, starting from the initial ordering in A.  Moreover, if a 
cow opts to move herself to a new location in one of the photographs, then she does not actively move in any
of the other photographs (although she can end up at a different position due to other cows moving, of course).

//Solution Notes: There are several ways to approach this problem. Perhaps the simplest (which also solves the harder 
silver/gold variant of this problem where multiple cows can move in each photo) is just to sort, as shown in the code below. 
Sorting requires that we can compare two cows A and B to tell which should go first. Fortunately, if we look at any two cows 
A and B, they will be in the correct relative order in at least 3 of the 5 photographs, since movements of other cows 
will not change the relative ordering of A and B -- only movement of A or B can change their relative order, and A 
and B can themselves move in at most 2 of photos. We can therefore compare any pair (A,B) by taking a "majority vote" 
based on their relative order in all 5 photographs (i.e., A < B if A precedes B in at least 3 of the 5 photos). 
The code below uses a "map" to record the position in each ordering of each cow based on its ID number; this 
approach is nice because it does not need to assume the ID numbers are small consecutive integers; however, 
since we know our ID numbers are 1...N, a simple array would have worked also for this task.
//Since we know that at most one cow moves per photo in this problem, other solutions exist, some of them even more 
efficient than the O(n log n) sorting approach above. For example, the "correct" first cow must appear in one of the 
first two positions in at least 4 of the 5 photos. If there is only one cow satisfying this property, we place it first 
in the final output and continue. Otherwise, if there are two cows satisfying this property, we compare them as above and 
place the correct cow first, continuing in this fashion as we output all the cows in the correct order in only O(n) total time.

*/
#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

#define MAXN 20000

int A[MAXN];
map<int, int> pos[5];

bool cmp(int a, int b) {
  int f = 0;
  for(int i = 0; i < 5; i++) {
    f += pos[i][a] < pos[i][b];
  }
  return f > 2;
}

int main() {
  freopen("photo.in", "r", stdin);
  freopen("photo.out", "w", stdout);
  int N; cin >> N;
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < N; j++) {
      int x; cin >> x;
      pos[i][x] = j;
      A[j] = x;
    }
  }
  sort(A, A + N, cmp);
  for(int i = 0; i < N; i++) {
    cout << A[i] << '\n';
  }
}
