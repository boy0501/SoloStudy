// main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	int res = 0;
	while (!q.empty())
	{
		auto item = q.front();
		q.pop();
		if (item.first == M)
		{
			res = item.second;
			break;
		}
		if (item.first * 2 <= M)
		{
			q.push(make_pair(item.first * 2, item.second + 1));
			q.push(make_pair(item.first + 1, item.second + 1));

		}
		else if (item.first * 3 <= M)
		{
			int a = M / 2;
			q.push(make_pair(a,item.second +  a - item.first));
		}
		else if (item.first * 4 <= M)
		{
			int a = M / 2;
			q.push(make_pair(a, item.second + a - (item.first * 2) + 1));
			//q.push(make_pair(item.first - 1, item.second + 1));
		}
		else if (item.first * 2 > M)
		{				
			if (item.first * 2 - 1 == M)
			{
				q.push(make_pair(item.first * 2 - 1, item.second + 2));
			}
			else if (item.first * 3 / 2 <= M)
			{
				int a = floor((M / 2.0) + 0.5);
				q.push(make_pair(a, item.second + item.first - a));

			}
			else {
				q.push(make_pair(item.first * 2, item.second + 1));
				q.push(make_pair(item.first + 1, item.second + 1));
				q.push(make_pair(item.first - 1, item.second + 1));
			}
		}
		else{
			q.push(make_pair(item.first * 2, item.second + 1));
			q.push(make_pair(item.first + 1, item.second + 1));
			q.push(make_pair(item.first - 1, item.second + 1));
		}
	}

	cout << res;

	return 0;
}