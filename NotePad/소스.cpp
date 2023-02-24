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
#include <algorithm>
using namespace std;

int visit[102][102];

int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };

class Node {
public:
	int H;
	int x, y;
	int road;
	int history{ 0 };
	Node* prev{nullptr};

	void calcul(int xEnd, int yEnd)
	{
		H = (x - xEnd) + (y - yEnd);
	}

	void calculA()
	{
		H += history;
	}

};
struct cmp {
public:
	bool operator()(const Node* a, const Node* b)
	{
		return a->H > b->H;
	}
};
Node nodes[102][102];
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	memset(visit, -1, sizeof(visit));
	for (int i = 1; i <= N; ++i)
	{
		string a;
		cin >> a;

		for (int j = 1; j <= M; ++j)
		{
			nodes[i][j].road = a[j-1]-'0';
			nodes[i][j].x = j;
			nodes[i][j].y = i;
			nodes[i][j].calcul(M, N);
			visit[i][j] = 0;
		}
	}

	queue<Node*> pq;
	
	nodes[1][1].history = 1;
	pq.push(&nodes[1][1]);
	visit[1][1] = true;

	while (!pq.empty())
	{
		auto node = pq.front();
		pq.pop();
		if (node->x == M && node->y == N)
			break;
		int nX, nY;
		for (int i = 0; i < 4; ++i)
		{
			nX = node->x + dx[i];
			nY = node->y + dy[i];

			if (visit[nY][nX] == 0 && nodes[nY][nX].road == 1)
			{
				nodes[nY][nX].prev = node;
				visit[nY][nX] = true;
				nodes[nY][nX].history = node->history + 1;
				nodes[nY][nX].calculA();				
				pq.push(&nodes[nY][nX]);
			}
		}

	}

	int answer = 1;
	Node* prv = &nodes[N][M];
	if (prv->prev != nullptr)
	{
		while (true)
		{
			if (prv->prev->x == 1 && prv->prev->y == 1)
			{
				answer++;
				break;
			}
			else {
				prv = prv->prev;
				answer++;
			}
		}
	}

	cout << answer;
	return 0;
}