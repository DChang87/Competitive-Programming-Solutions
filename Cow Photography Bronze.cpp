//Solution Notes: There are several ways to approach this problem. Perhaps the simplest (which also solves the harder silver/gold variant of this problem where multiple cows can move in each photo) is just to sort, as shown in the code below. Sorting requires that we can compare two cows A and B to tell which should go first. Fortunately, if we look at any two cows A and B, they will be in the correct relative order in at least 3 of the 5 photographs, since movements of other cows will not change the relative ordering of A and B -- only movement of A or B can change their relative order, and A and B can themselves move in at most 2 of photos. We can therefore compare any pair (A,B) by taking a "majority vote" based on their relative order in all 5 photographs (i.e., A < B if A precedes B in at least 3 of the 5 photos). The code below uses a "map" to record the position in each ordering of each cow based on its ID number; this approach is nice because it does not need to assume the ID numbers are small consecutive integers; however, since we know our ID numbers are 1...N, a simple array would have worked also for this task.

//Since we know that at most one cow moves per photo in this problem, other solutions exist, some of them even more efficient than the O(n log n) sorting approach above. For example, the "correct" first cow must appear in one of the first two positions in at least 4 of the 5 photos. If there is only one cow satisfying this property, we place it first in the final output and continue. Otherwise, if there are two cows satisfying this property, we compare them as above and place the correct cow first, continuing in this fashion as we output all the cows in the correct order in only O(n) total time.


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
