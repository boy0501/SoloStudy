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

int r, c, k;

int dfs(int maxRow, int maxCol, int cnt, char order, deque<deque<int>> arr)
{
	int res = FAILCODE;
	if (cnt > 101) return FAILCODE;
	if (maxRow >= r && maxCol >= c)
	{
		if (order == 'R')
		{
			if (arr[r - 1][c - 1] == k)
				return cnt - 1;
		}
		else
		{
			if (arr[c - 1][r - 1] == k)
				return cnt - 1;
		}

	}
	if (order == 'R')
	{
		for (int i = 0; i < maxRow; ++i)
		{
			sort(begin(arr[i]), end(arr[i]));
			vector<pair<int, int>> vec(110);
			for (auto& p : arr[i])
			{
				vec[p] = make_pair(p, vec[p].second + 1);
			}

			sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
				if (a.second == b.second)
				{
					return a.first < b.first;
				}
				return a.second < b.second;
				});

			deque<int> narr;
			for (int i = 0; i < vec.size(); ++i)
			{
				if (vec[i].first == 0) continue;
				narr.push_back(vec[i].first);
				narr.push_back(vec[i].second);
			}
			arr[i].clear();
			arr[i] = narr;
		}
		int nmax = 0;
		for (int i = 0; i < maxRow; ++i)
		{
			nmax = max(nmax, (int)arr[i].size());
		}

		for (int i = 0; i < maxRow; ++i)
		{
			if (arr[i].size() != nmax)
			{
				int asize = arr[i].size();
				for (int j = 0; j < nmax - asize; ++j)
					arr[i].push_back(0);
			}
		}

		int 열의개수 = nmax;
		int 행의개수 = arr.size();
		if (행의개수 >= 열의개수)
		{
			res = dfs(행의개수, 열의개수, cnt + 1, 'R', arr);
		}
		else {
			deque<deque<int>> narr;

			for (int i = 0; i < nmax; ++i)
			{
				deque<int> tmp;
				narr.push_back(tmp);
				for (int j = 0; j < 행의개수; ++j)
				{
					narr[i].push_back(arr[j][i]);
				}
			}

			res = min(res, dfs(행의개수, 열의개수, cnt + 1, 'C', narr));

		}

	}
	else if (order == 'C')
	{
		for (int i = 0; i < maxCol; ++i)
		{
			sort(begin(arr[i]), end(arr[i]));
			vector<pair<int, int>> vec(110);
			for (auto& p : arr[i])
			{
				vec[p] = make_pair(p, vec[p].second + 1);
			}

			sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
				if (a.second == b.second)
				{
					return a.first < b.first;
				}
				return a.second < b.second;
				});

			arr[i].clear();
			deque<int> narr;
			for (int i = 0; i < vec.size(); ++i)
			{
				if (vec[i].first == 0) continue;
				narr.push_back(vec[i].first);
				narr.push_back(vec[i].second);
			}
			arr[i] = narr;
		}
		int nmax = 0;
		for (int i = 0; i < maxCol; ++i)
		{
			nmax = max(nmax, (int)arr[i].size());
		}

		int 행의개수 = nmax;
		int 열의개수;
		for (int i = 0; i < maxCol; ++i)
		{
			if (arr[i].size() != 행의개수)
			{
				int asize = arr[i].size();
				for (int j = 0; j < 행의개수 - asize; ++j)
					arr[i].push_back(0);
			}
		}
		열의개수 = arr.size();
		if (행의개수 >= 열의개수)
		{
			deque<deque<int>> narr;

			for (int i = 0; i < nmax; ++i)
			{
				deque<int> tmp;
				narr.push_back(tmp);
				for (int j = 0; j < maxCol; ++j)
				{
					narr[i].push_back(arr[j][i]);
				}
			}
			res = dfs(행의개수, 열의개수, cnt + 1, 'R', narr);
		}
		else {


			res = min(res, dfs(행의개수, 열의개수, cnt + 1, 'C', arr));

		}
	}
	return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);


	cin >> r >> c >> k;

	for (int i = 0; i < 3; ++i)
	{
		deque<int> tmp;
		arrs.push_back(tmp);
		for (int j = 0; j < 3; ++j)
		{
			int k;
			cin >> k;

			arrs[i].push_back(k);
		}
	}

	if (3 >= r && 3 >= c)
	{

		if (arrs[r - 1][c - 1] == k)
		{
			cout << "0";
		}
		else {
			int res = dfs(3, 3, 1, 'R', arrs);
			if (res == FAILCODE)
			{
				cout << -1;
			}
			else {
				cout << res;
			}
		}

	}
	else {
		int res = dfs(3, 3, 1, 'R', arrs);
		if (res == FAILCODE)
		{
			cout << -1;
		}
		else {
			cout << res;
		}
	}




	return 0;
}
