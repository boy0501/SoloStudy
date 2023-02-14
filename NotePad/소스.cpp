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
using namespace std;

int troom[1001][1001];

class Pos {
public:
	int x, y;
	Pos() {};
	Pos(int xx, int yy) : x(xx), y(yy) {}
};
int dx[4] = { 0 , 0 , 1 ,-1 };
int dy[4] = { 1 ,-1, 0,0 };
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	memset(troom, - 1, sizeof(troom));
	vector<Pos> vec;
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> troom[i][j];
			if (troom[i][j] == 1)
			{
				vec.push_back(Pos(j, i));
			}
		}
	}


	queue<pair<Pos, int>> q;
	
	for (auto v : vec)
	{
		q.push(make_pair(v, 0));
	}
	int maxstep = 0;

	while (!q.empty())
	{
		auto spot = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = spot.first.x;
			int ny = spot.first.y;
			nx += dx[i];
			ny += dy[i];

			if (troom[ny][nx] == 0)
			{
				troom[ny][nx] = 1;
				q.push(make_pair(Pos(nx, ny), spot.second + 1));
				maxstep = max(maxstep, spot.second + 1);
			}
		}
	}

	bool trig = false;
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (troom[i][j] == 0)
			{
				trig = true;
			}
		}
	}

	if (trig)
	{
		cout << -1;
	}
	else {
		cout << maxstep;
	}

	return 0;
}