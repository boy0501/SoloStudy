// main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dp[2][100'001];
int ori[2][100'001];

int func(int x, int y, int delta)
{

	if (dp[y][x] >= 0) return dp[y][x];
	if (ori[y][x] < 0) return 0;

	dp[y][x] = 0;

	int res1 = func(x + 1, y + delta, -delta);
	int res2 = func(x + 2, y + delta, -delta);
	dp[y][x] += ori[y][x] + max(res1, res2);

	return dp[y][x];

}

void insert(int n)
{
	for (int j = 0; j < 2; ++j)
	{
		for (int k = 0; k < n; ++k)
		{
			cin >> ori[j][k];
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		memset(dp, -1, sizeof(dp));
		memset(ori, -1, sizeof(ori));
		int n;
		cin >> n;
		insert(n);

		int res1 = func(0, 0, 1);
		int res2 = func(0, 1, -1);
		cout << max(res1, res2) << endl;

	}


	return 0;
}

