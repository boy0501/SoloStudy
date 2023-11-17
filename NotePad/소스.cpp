// main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <string>
#include <stack>
#include <array>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <functional>
#include <chrono>
#include <atomic>
#include <queue>
#include <iterator>
using namespace std;
using namespace chrono;
constexpr int FAILCODE = 9999999;
#define CLIME true
#define DOWN false
int visits[101][71];
int maps[101][71];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	fill_n(visits[0], 101 * 71, -1);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			int k;
			cin >> k;
			visits[i][j] = 0;
			maps[i][j] = k;
		}
	}

	int dx[8]{ 1,0,-1,0,-1,1,-1,1 };
	int dy[8]{ 0,1,0,-1,-1,1,1,-1 };
	queue<tuple<int,int,int>> q;
	int TopCnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (maps[i][j] == 0)
				continue;
			if (visits[i][j] == true)
				continue;
			int isTop = true;
			int CurrHeight = maps[i][j];
			q.push(make_tuple(maps[i][j], j, i));
			visits[i][j] = true;
			while (!q.empty())
			{

				auto next = q.front();
				q.pop();
				int value = get<0>(next);
				int x = get<1>(next);
				int y = get<2>(next);
				for (int k = 0; k < 8; ++k)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 1) continue;
					if (ny < 1) continue;
					if (ny > N) continue;
					if (nx > M) continue;
					if (maps[ny][nx] > CurrHeight)
					{
						isTop = false;
					}
					if (visits[ny][nx] == true)
						continue;
					if (maps[ny][nx] == 0)
						continue;

					if (maps[ny][nx] == CurrHeight) {
						visits[ny][nx] = true;
						q.push(make_tuple(maps[ny][nx], nx, ny));
					}
					else if (maps[ny][nx] > CurrHeight)
					{
						isTop = false;
					}
				}
			}
			if (isTop)
				TopCnt++;
		}
	}
	

	cout << TopCnt << endl;

	return 0;
}
