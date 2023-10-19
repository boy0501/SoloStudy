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
#include <chrono>
#include <atomic>
#include <queue>
using namespace std;
using namespace chrono;
constexpr int FAILCODE = 9999999;
deque<deque<int>> arrs;

int n, m;
int indexing;
int visit[7][7];
int arr[7][7];
/*
shape는 총 4개
1 - ┌
2 - ㄱ
3 - ㄴ
4 - ┘
*/


int dfs(int index, int shape)
{
	if (index == n * m ) return 0;

	int y = index / indexing + 1;
	int x = index % indexing + 1;
	int res = 0;

	switch (shape)
	{
	case 1:
		if (visit[y + 1][x] == -1 || visit[y + 1][x] == 1) return 0;
		if (visit[y][x + 1] == -1 || visit[y][x + 1] == 1) return 0;
		break;
	case 2:
		if (visit[y][x - 1] == -1 || visit[y][x - 1] == 1) return 0;
		if (visit[y + 1][x] == -1 || visit[y + 1][x] == 1) return 0;
		break;
	case 3:
		if (visit[y - 1][x] == -1 || visit[y - 1][x] == 1) return 0;
		if (visit[y][x + 1] == -1 || visit[y][x + 1] == 1) return 0;
		break;
	case 4:
		if (visit[y - 1][x] == -1 || visit[y - 1][x] == 1) return 0;
		if (visit[y][x - 1] == -1 || visit[y][x - 1] == 1) return 0;
		break;
	}
	res += arr[y][x] * 2;
	switch (shape)
	{
	case 1:
		visit[y + 1][x] = true;
		visit[y][x + 1] = true;
		res += arr[y + 1][x];
		res += arr[y][x + 1];
		break;
	case 2:
		visit[y][x - 1] = true;
		visit[y + 1][x] = true;
		res += arr[y][x - 1];
		res += arr[y + 1][x];
		break;
	case 3:
		visit[y - 1][x] = true;
		visit[y][x + 1] = true;
		res += arr[y - 1][x];
		res += arr[y][x + 1];
		break;
	case 4:
		visit[y - 1][x] = true;
		visit[y][x - 1] = true;
		res += arr[y - 1][x];
		res += arr[y][x - 1];
		break;
	}
	
	int dfsret = 0;

	for (int i = index + 1; i < n * m; ++i)
	{
		int ny = i / indexing + 1;
		int nx = i % indexing + 1;
		if (visit[ny][nx] == true) continue;
		int ret1 = 0;
		visit[ny][nx] = true;
		ret1 = dfs(i, 1);
		visit[ny][nx] = false;
		if (ret1 != 0)
		{
			if (visit[ny + 1][nx] == true)
				visit[ny + 1][nx] = false;
			if (visit[ny][nx + 1] == true)
				visit[ny][nx + 1] = false;
		}

		int ret2 = 0;

		visit[ny][nx] = true;
		ret2 = dfs(i, 2);
		visit[ny][nx] = false;
		if (ret2 != 0)
		{
			if (visit[ny][nx - 1] == true)
				visit[ny][nx - 1] = false;
			if (visit[ny + 1][nx] == true)
				visit[ny + 1][nx] = false;
		}


		int ret3 = 0;
		visit[ny][nx] = true;
		ret3 = dfs(i, 3);
		visit[ny][nx] = false;
		if (ret3 != 0)
		{
			if (visit[ny - 1][nx] == true)
				visit[ny - 1][nx] = false;
			if (visit[ny][nx + 1] == true)
				visit[ny][nx + 1] = false;
		}


		int ret4 = 0;
		visit[ny][nx] = true;
		ret4 = dfs(i, 4);
		visit[ny][nx] = false;
		if (ret4 != 0)
		{
			if (visit[ny - 1][nx] == true)
				visit[ny - 1][nx] = false;
			if (visit[ny][nx - 1] == true)
				visit[ny][nx - 1] = false;
		}

		dfsret = max(dfsret,max(ret1, max(ret2, max(ret3, ret4))));
		if (dfsret == 24)
			break;
	}


	return res + dfsret;

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			visit[i][j] = -1;
		}
	}
	cin >> n >> m;
	if (n <= m)
		indexing = max(n, m);
	else
		indexing = min(n, m);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			visit[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			int k;
			cin >> k;
			arr[i][j] = k;
		}
	}
	int sum=0;
	for (int i = 0; i < n * m; ++i)
	{
		int ny = i / indexing + 1;
		int nx = i % indexing + 1;
		if (visit[ny][nx] == true) continue;
		int ret1 = 0;
		visit[ny][nx] = true;
		ret1 = dfs(i, 1);
		visit[ny][nx] = false;
		if (ret1 != 0)
		{
			if (visit[ny + 1][nx] == true)
				visit[ny + 1][nx] = false;
			if (visit[ny][nx + 1] == true)
				visit[ny][nx + 1] = false;
		}

		int ret2 = 0;

		visit[ny][nx] = true;
		ret2 = dfs(i, 2);
		visit[ny][nx] = false;
		if (ret2 != 0)
		{
			if (visit[ny][nx - 1] == true)
				visit[ny][nx - 1] = false;
			if (visit[ny + 1][nx] == true)
				visit[ny + 1][nx] = false;
		}


		int ret3 = 0;
		visit[ny][nx] = true;
		ret3 = dfs(i, 3);
		visit[ny][nx] = false;
		if (ret3 != 0)
		{
			if (visit[ny - 1][nx] == true)
				visit[ny - 1][nx] = false;
			if (visit[ny][nx + 1] == true)
				visit[ny][nx + 1] = false;
		}


		int ret4 = 0;
		visit[ny][nx] = true;
		ret4 = dfs(i, 4);
		visit[ny][nx] = false;
		if (ret4 != 0)
		{
			if (visit[ny - 1][nx] == true)
				visit[ny - 1][nx] = false;
			if (visit[ny][nx - 1] == true)
				visit[ny][nx - 1] = false;
		}

		sum = max(sum, max(ret1, max(ret2, max(ret3, ret4))));

	}
	cout << sum;


	return 0;
}
