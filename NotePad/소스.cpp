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

struct Node {
public:
	int others[201];
};

Node nodes[201];
int visit[201]{ 0, };

int N, M;

int calcul(int start)
{
	int count = 1;
	visit[start] = true;
	priority_queue<int> pq;

	pq.push(start);

	while (!pq.empty())
	{
		int t = pq.top();
		pq.pop();

		for (int i = 0; i < N; ++i)
		{
			int p = nodes[t].others[i];
			if (p == 1 && visit[i] == false)
			{
				visit[i] = true;
				nodes[start].others[i] = true;
				nodes[i].others[start] = true;
				count++;
				pq.push(i);
			}
		}
	}
	return count;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	unordered_map<int, int> trip;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> nodes[i].others[j];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int k;
		cin >> k;
		trip[k - 1] = 1;
	}

	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		fill_n(visit, 201, 0);
		if (visit[i] == 0)
		{
			count += calcul(i);
		}
		//if (count == N)
		//	break;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == j) continue;

			if (nodes[i].others[j] == 0)
			{
				if (trip[i] == 1 && trip[j] == 1)
				{
					cout << "NO";	//여행못감
					return 0;
				}
			}

		}

	}

	cout << "YES";
	return 0;
}