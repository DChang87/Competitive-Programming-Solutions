//sweepline 

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 1111;

int N, x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN], all_x[2 * MAXN];

int main()
{
	FILE * w = fopen("planting.in", "r");
	FILE * o = fopen("planting.out", "w");

	fscanf(w, "%d", &N);
	for(int i = 0; i < N; i++)
	{
		fscanf(w, "%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
		//store all x positions in the all_x array
		all_x[2 * i] = x1[i];
		all_x[2 * i + 1] = x2[i];
	}
	sort(all_x, all_x + 2 * N); //sort the all_x array

	// sweep the x-coordinates
	long long answer = 0;
	for(int i = 0; i < 2 * N; )
	{
	    //go through every x position (by jumping from one available x position to another)
	    //instead by going up an increment of 1 (too slow)
		int x = all_x[i]; //the ith x position available
		if(i != 0 && x == all_x[i - 1])
		{ //if x isn't identical to the previous x position
			i++;
			continue;
		}
		vector<pair<int, int> > y;
		// look for relevant rectangles
		for(int j = 0; j < N; j++) //if this x position is on a patch of grass
            //(bounded between the x1 and x2 values but not necessarily the y values)
			if(x1[j] <= x && x2[j] > x)
			{
			    //if it is, save the y values at this patch
			    //indicate y2 by marking pair.second as 1 (top boundary, sweep starts here)
			    //indicate y1 by marking pair.first as -1 (bottom boundary, sweep leaves here)
				y.push_back(make_pair(y2[j], 1));
				y.push_back(make_pair(y1[j], -1));
			}
		if(y.size() == 0)
		{ //if it is not contained within any patch
			i++;
			continue;
		}
		// sweep
		sort(y.begin(), y.end());
		long long cur_area = 0;
		int num_rectangles = 0, pos = 0;
		while(pos < y.size()) //pos indicates the pos'th value of y in the vector y
		{
			int bottom_y = y[pos].first; //marks the numerical y boundary of the patch
			num_rectangles += y[pos].second; // num_rectangles == 1
			//if this is the first boundary (entering a patch), add on to the number of rectangle counts
			while(num_rectangles > 0) 
                //start with the entering boundary of a patch, continue on until there are no more patches connected to this patch in this path
                //sweep up until there is nothing (no patch no grass)
                //this would calculate how much of the vertical strip is covered in grass (one part of the strip at a time)
                //IF THIS IS UNCLEAR WHEN YOU (ME) READ IT LATER, retrace through the program
				num_rectangles += y[++pos].second;
			int top_y = y[pos].first; //the top boundary of the y's 
			cur_area += top_y - bottom_y; //(the difference in height) for the specific x value (the length of the y-strip)
			pos++; //find the next overlapping patch by visiting the next y value (find the beginning of the next patch in this vertical strip
		}
		// find the next x-coordinate that doesnt have the same value as the current x coordinate
		int j = i + 1;
		while(all_x[j] == all_x[i])
			j++;
		answer += cur_area * (all_x[j] - x);
		//the total length of overlapping y's multipled by the number of x's it applies to
		i = j; //start calculating from the new x coordinate (ith position in all_x)
	}

	fprintf(o, "%lld\n", answer);
	printf("%lld\n", answer);

	return 0;
}
