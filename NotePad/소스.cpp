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

int greed[120][120];
int grgreed[120][120];
int visit[120][120];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfsgreed(int x, int y, int color)
{
	if (visit[y][x] == -1) return;
	if (visit[y][x] == 1) return;
	if (greed[y][x] != color) return;
	visit[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(visit[ny][nx] == 0)
			dfsgreed(x + dx[i], y + dy[i],color);
	}
	return;
}

void dfsgrgreed(int x, int y, int color)
{
	if (visit[y][x] == -1) return;
	if (visit[y][x] == 1) return;
	if (grgreed[y][x] != color) return;
	visit[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[ny][nx] == 0)
			dfsgrgreed(x + dx[i], y + dy[i], color);
	}
	return;
}

void init(int N)
{
	for (int i = 0; i < 120; ++i)
	{
		fill_n(visit[i], sizeof(visit[i]), -1);
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			visit[i][j] = 0;
		}
	}
	return;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	cin >> N;
	init(N);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			char color;
			cin >> color;
			greed[i][j] = color;
			if (color == 'R' || color == 'G')
				grgreed[i][j] = 'R';
			else
				grgreed[i][j] = color;
		}
	}

	int cnt = 0;
	int grcnt = 0;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (visit[i][j] == 0)
			{
				dfsgreed(j, i, greed[i][j]);
				cnt++;
			}
		}
	}
	init(N);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (visit[i][j] == 0)
			{
				dfsgrgreed(j, i, grgreed[i][j]);
				grcnt++;
			}
		}
	}

	cout << cnt << " " << grcnt;


	
	return 0;
}
