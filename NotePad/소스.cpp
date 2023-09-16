// main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <functional>
using namespace std;

int visit[35][35]{};
double dir[4];
double result;
int N;
double dfs(int cnt, int x,int y,double percent)
{
	if (cnt == N) {
		result += percent;
		return percent;
	}
	double k = 0.0;
	if (visit[y+1][x] == false)
	{
		if (dir[0] > 0.0)
		{
			visit[y + 1][x] = true;
			k = dfs(cnt + 1, x, y + 1, percent * dir[0]);
			visit[y + 1][x] = false;
		}
	}
	if (visit[y - 1][x] == false)
	{
		if (dir[1] > 0.0)
		{
			visit[y - 1][x] = true;
			k = dfs(cnt + 1, x, y - 1, percent * dir[1]);
			visit[y - 1][x] = false;
		}
	}
	if (visit[y][x + 1] == false)
	{
		if (dir[2] > 0.0)
		{
			visit[y][x + 1] = true;
			k = dfs(cnt + 1, x + 1, y, percent * dir[2]);
			visit[y][x + 1] = false;
		}
	}
	if (visit[y][x - 1] == false)
	{
		if (dir[3] > 0.0)
		{
			visit[y][x - 1] = true;
			k = dfs(cnt + 1, x - 1, y, percent * dir[3]);
			visit[y][x - 1] = false;
		}
	}

	return k;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < 4; ++i)
	{
		int k;
		cin >> k;
		dir[i] = k / 100.0;
	}

	int sx = 15, sy = 15;

	visit[sy][sx] = 1;

	dfs(0, sx, sy, 1);

	cout.precision(10);
	cout << result;


	return 0;
}