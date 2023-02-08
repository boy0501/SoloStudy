// main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;

enum class type
{
	Road, Wall
};

struct tile {
	int m_Distance;
	type m_type;
	int x, y,id;
};

tile road[1002][1002];
int visit[1002][1002];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int result = 999'999;
void DFS(tile* tle,bool CanBreak,int N,int M)
{
	if (tle->x == M && tle->y == N)
	{
		result = min(result, tle->m_Distance);
		return;
	}
	if (tle->m_type == type::Wall)
	{
		if (CanBreak == false)
			return;
		else
			CanBreak = false;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (visit[tle->y + dir[i][1]][tle->x + dir[i][0]] == 0)
		{
			if (road[tle->y + dir[i][1]][tle->x + dir[i][0]].m_type == type::Road)
			{
				visit[tle->y + dir[i][1]][tle->x + dir[i][0]] = true;
				road[tle->y + dir[i][1]][tle->x + dir[i][0]].m_Distance = tle->m_Distance + 1;
				DFS(&road[tle->y + dir[i][1]][tle->x + dir[i][0]], CanBreak,N,M);
				visit[tle->y + dir[i][1]][tle->x + dir[i][0]] = false;
				road[tle->y + dir[i][1]][tle->x + dir[i][0]].m_Distance = tle->m_Distance - 1;
			}
			else {
				if (CanBreak)
				{
					visit[tle->y + dir[i][1]][tle->x + dir[i][0]] = true;
					road[tle->y + dir[i][1]][tle->x + dir[i][0]].m_Distance = tle->m_Distance + 1;
					DFS(&road[tle->y + dir[i][1]][tle->x + dir[i][0]], CanBreak,N,M);
					visit[tle->y + dir[i][1]][tle->x + dir[i][0]] = false;
					road[tle->y + dir[i][1]][tle->x + dir[i][0]].m_Distance = tle->m_Distance - 1;
				}
			}
		}
	}

}

int idSaver[1'002'002];
int getNew_id()
{
	for (int i = 0; i < 1'002'002; ++i)
	{
		if (idSaver[i] == 0)
		{
			idSaver[i] = 1;
			return i;
		}
	}

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	memset(road, -1, sizeof(road));
	memset(visit, -1, sizeof(visit));
	int N,M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= tmp.length(); ++j)
		{
			road[i][j].m_type = static_cast<type>(tmp[j-1]-'0');
			road[i][j].x = j;
			road[i][j].y = i;
			visit[i][j] = 0;
		}
	}

	queue<pair<tile*, bool>> q;	//tile값 + 부술 수 있는지
	queue <tuple<tile*, bool, unordered_map<string, int>>> aa;
	
	//튜플로 바꿔서 해볼 것.

	q.push(make_pair<tile*, bool>(&road[1][1], 1));
	road[1][1].m_Distance = 1;
	visit[1][1] = 1;
	//DFS(&road[1][1], 1,N,M);


	while (!q.empty())
	{
		auto tle = q.front().first;
		auto CanBreak = q.front().second;
		q.pop();
		int newid = 0;
		//map을 만들어서 각자 queue에 보관한다면 ? unordered매븡로다가 
		for (int i = 0; i < 4; ++i)
		{
			int nx = tle->x + dir[i][0];
			int ny = tle->y + dir[i][1];
			if (visit[ny][nx] == 0)
			{
				if (road[ny][nx].m_type == type::Road)
				{
					visit[ny][nx] = true;
					road[ny][nx].m_Distance = tle->m_Distance + 1;
					road[ny][nx].id = tle->id + newid;
					if(CanBreak)
						q.push(make_pair<tile*, bool>(&road[ny][nx], 1));
					else
						q.push(make_pair<tile*, bool>(&road[ny][nx], 0));
					newid++;
				}
				else {
					if (CanBreak)
					{
						visit[ny][nx] = true;
						road[ny][nx].m_Distance = tle->m_Distance + 1;
						road[ny][nx].id = tle->id + newid;
						q.push(make_pair<tile*, bool>(&road[ny][nx], false));
						newid++;
					}
				}
			}
		}
		
	}

	cout << road[N][M].m_Distance;
	return 0;
}

