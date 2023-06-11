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
using namespace std;

class Node {
public:
	vector<pair<int,int>> next;
	Node(){};
};
#define inf 100000001
int visit[801];
int dp[801][801];
int ddp[801];

int DP(int start, int end, vector<Node>& vec)
{
	memcpy(ddp, dp[start], sizeof(ddp));
	ddp[start] = 0;
	fill_n(visit, sizeof(visit) / sizeof(int), 0);
	visit[start] = true;

	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(start, 0));
	while (!pq.empty())
	{
		int cur = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		if (ddp[cur] < cost) continue;
		for (int i = 0; i < vec[cur].next.size(); ++i)
		{
			int next = vec[cur].next[i].first;
			int nextcost = cost + vec[cur].next[i].second;
			if (nextcost <= ddp[next])
			{
				ddp[next] = nextcost;
				pq.push(make_pair(next, -nextcost));
			}
		}
	}
	
	return ddp[end];

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<Node> vec;
	vec.resize(n + 1);
	fill_n(dp[0], sizeof(dp) / sizeof(int), inf);
	fill_n(ddp, sizeof(ddp) / sizeof(int), inf);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].next.push_back(make_pair(b, c));
		vec[b].next.push_back(make_pair(a, c));
		dp[a][b] = c;
		dp[b][a] = c;

	}
	int mid1, mid2;
	cin >> mid1 >> mid2;

	int stm1 = DP(1, mid1, vec);
	stm1 += DP(mid2, n, vec);
	int stm2 = DP(1, mid2, vec);
	stm2 += DP(mid1, n, vec);
	int mtm = DP(mid1, mid2, vec);

	int res = min(stm1, stm2) + mtm;
	if (res >= inf)
		res = -1;
	cout << res;
	return 0;
}