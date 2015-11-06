//Leo's code
//nice DP solution
#include <iostream>
#include <algorithm>

int candy[2002][2];
int dist[2002][2000];
int dp[2002][5000];

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i != N; ++i)
		cin >> candy[i][0] >> candy[i][1];
	for (int i = 0; i != N; ++i)
	{
		for (int j = 0; j != N; ++j)
			dist[i][j] = (candy[i][0] - candy[j][0])*(candy[i][0] - candy[j][0]) + (candy[i][1] - candy[j][1])*(candy[i][1] - candy[j][1]);
	}
	for (int i = 0; i != N; ++i)
		dp[i][1] = (candy[i][0] * candy[i][0]) + (candy[i][1] * candy[i][1]);

	int count = 1, tmx = 1, cont = 1;
	while (cont)
	{
		cont = 0;
		for (int i = 0; i != N; ++i)
		{
			for (int j = 0; j != N; ++j)
			{
				if (dp[i][count] > dist[i][j] && dist[i][j] != 0)
				{
					dp[j][count + 1] = max(dp[j][count + 1], dist[i][j]);
					tmx = max(tmx, count + 1);
					cont = 1;
				}
			}
		}
		++count;
	}

	for (int i = 0; i != N; ++i)
	{
		for (int j = 0; j != N; ++j)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	cout << tmx;
	return 0;
}
