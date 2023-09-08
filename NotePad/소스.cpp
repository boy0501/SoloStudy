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

int res[1001];

vector<vector<int>> d;
int N;

int dfs(int depth,int prev)
{
	if (depth == N)
	{
		return 0;
	}

	auto& vec = d[depth];

	for (auto& val : vec)
	{
		
		if (prev != val)
		{
			int k = dfs(depth + 1, val);
			if (k == 0)
			{
				res[depth] = val;
				return 0;
			}else if (k != -1)
			{
				res[depth] = k;
				return k;
			}
		}
	}

	return -1;
}

int udfs(int depth, int prev)
{
	if (depth == -1)
	{
		return 0;
	}

	auto& vec = d[depth];

	for (auto& val : vec)
	{

		if (prev != val)
		{
			int k = udfs(depth - 1, val);
			if (k == 0)
			{
				res[depth] = val;
				return 0;
			}
			else if (k != -1)
			{
				res[depth] = k;
				return k;
			}
		}
	}

	return -1;
}

void gogo(int depth, int value)
{
	auto& vec = d[depth];

	for (auto& v : vec)
	{
		if (v != value)
		{
			res[depth] = v;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N;
	unordered_map<int, int> check;
	vector<int> starts;

	int flag = false;
	for (int i = 0; i < N; ++i)
	{
		int dduck;
		cin >> dduck;
		vector<int> kindof;
		if (dduck == 1)
		{
			starts.push_back(i);
			check[i] = 1;
		}
		for (int j = 0; j < dduck; ++j)
		{
			int k;
			cin >> k;
			kindof.push_back(k);
		}

		d.push_back(kindof);
	}
	for (int i = 0; i < N; ++i)
	{
		for (auto& start : starts)
		{
			int mi = start - 1;
			int ma = min(start + 1, N - 1);
			auto& dma = d[ma];
			if(mi != -1)
				d[mi].erase(remove(d[mi].begin(), d[mi].end(), d[start][0]), d[mi].end());
			if(ma != N -1)
				dma.erase(remove(dma.begin(), dma.end(), d[start][0]), dma.end());
		}

		starts.clear();

		for (int j = 0; j < d.size(); ++j)
		{
			if (d[j].size() == 0)
			{
				cout << -1 << endl;
				return 0;
			}
			else if (d[j].size() == 1)
			{
				starts.push_back(j);
			}
		}

		if (starts.size() > 1)
		{
			//1종류만 있는게 서로 붙어있는 경우 예외
			int prev = starts[0];

			for (int i = 1; i < starts.size(); ++i)
			{
				if (prev + 1 == starts[i])
				{
					if (d[prev] == d[starts[i]])
					{
						flag = true;
					}
				}

				prev = starts[i];
			}

			if (flag)
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}


	dfs(0, 0);
	if (res[N - 1] == 0) {
		cout << -1 << endl;
	}
	else {

		for (int i = 0; i < N; ++i)
		{
			cout << res[i] << endl;
		}
	}

	return 0;
}