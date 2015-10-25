//Solution Notes: This problem has a greedy solution in which the cows follow the same order up the mountain and then back down: we start with all cows where U < D, ordered in increasing order of U, followed by all cows with U >= D, ordered in decreasing order of D. To implement this algorithm, all we essentially need to do is sort, so the coding and running time analysis are quite straightforward. The challenging aspect of this solution, as with most greedy algorithms, is convincing ourselves that this particular greedy approach is in fact always optimal.

//First, let us argue that an optimal solution can always use the same ordering of cows on the way down the mountain as on the way up. To see this, suppose that there is some optimal solution in which the orderings going up and down are different. Let 1, 2, 3, ..., n denote the ordering on the way up, and suppose the first position different between the two orderings is at index x, where cow y > x appears in the downward ordering. By moving cow x earlier in the downward ordering so it immediately precedes cow y, one can see that this can only improve the overall schedule; it can never make the climbing schedule worse (along with the rest of the arguments we make, this is reasonably clear if you plot the cows in question on a time line). Repeated moves of this sort can transform the optimal schedule into an equally good schedule where the upward and downward orderings are the same. Hence, there always exists an optimal schedule with identical upward and downward orderings.

//Next, we make another series of "exchange" arguments. Suppose that an optimal solution consists of an ordering in which there is a consecutive pair of cows (x,y) for which U(x) >= D(x) but U(y) < D(y). In this case, swapping the order of x and y can only help the overall solution. Repeated swaps of this sort show us that there is always an optimal solution in which cows with U < D precede those with U >= D. Finally, among all cows with U < D, swapping two adjacent cows (x,y) with U(x) > U(y) can only help the solution. Likewise, among the cows in the ordering with U >= D, swapping two adjacent cows (x,y) with D(x) < D(y) can only help. This tells us that there is always an optimal solution of the form produced by our greedy algorithm.
//interesting greedy solution

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <utility>

using namespace std;

int N, end1[25000], end2[25000];
pair<int, int> cows[25000];

bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.first < a.second)
    {
        if(b.first < b.second)
            return a.first < b.first;
        else
            return true;
    }
    else
    {
        if(b.first > b.second)
            return a.second > b.second;
        else
            return false;
    }
}

int main()
{
    FILE * w = fopen("climb.in", "r");
    FILE * o = fopen("climb.out", "w");

    fscanf(w, "%d", &N);
    for(int i = 0; i < N; i++)
        fscanf(w, "%d %d", &cows[i].first, &cows[i].second);
    sort(cows, cows + N, comp);
    
    for(int i = 0; i < N; i++)
        end1[i] = (i > 0 ? end1[i - 1] : 0) + cows[i].first;
    for(int i = 0; i < N; i++)
        end2[i] = max((i > 0 ? end2[i - 1] : 0), end1[i]) + cows[i].second;
    fprintf(o, "%d\n", end2[N - 1]);
    printf("%d\n", end2[N - 1]);

    return 0;
}
