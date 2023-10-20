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
//
//int n, m;
//int indexing;
//int visit[7][7];
//int arr[7][7];
///*
//shape´Â ÃÑ 4°³
//1 - ¦£
//2 - ¤¡
//3 - ¤¤
//4 - ¦¥
//*/

//
//int aa(int index, int shape)
//{
//	if (index == n * m ) return 0;
//
//	int y = index / indexing + 1;
//	int x = index % indexing + 1;
//	int res = 0;
//
//	switch (shape)
//	{
//	case 1:
//		if (visit[y + 1][x] == -1 || visit[y + 1][x] == 1) return 0;
//		if (visit[y][x + 1] == -1 || visit[y][x + 1] == 1) return 0;
//		break;
//	case 2:
//		if (visit[y][x - 1] == -1 || visit[y][x - 1] == 1) return 0;
//		if (visit[y + 1][x] == -1 || visit[y + 1][x] == 1) return 0;
//		break;
//	case 3:
//		if (visit[y - 1][x] == -1 || visit[y - 1][x] == 1) return 0;
//		if (visit[y][x + 1] == -1 || visit[y][x + 1] == 1) return 0;
//		break;
//	case 4:
//		if (visit[y - 1][x] == -1 || visit[y - 1][x] == 1) return 0;
//		if (visit[y][x - 1] == -1 || visit[y][x - 1] == 1) return 0;
//		break;
//	}
//	res += arr[y][x] * 2;
//	switch (shape)
//	{
//	case 1:
//		visit[y + 1][x] = true;
//		visit[y][x + 1] = true;
//		res += arr[y + 1][x];
//		res += arr[y][x + 1];
//		break;
//	case 2:
//		visit[y][x - 1] = true;
//		visit[y + 1][x] = true;
//		res += arr[y][x - 1];
//		res += arr[y + 1][x];
//		break;
//	case 3:
//		visit[y - 1][x] = true;
//		visit[y][x + 1] = true;
//		res += arr[y - 1][x];
//		res += arr[y][x + 1];
//		break;
//	case 4:
//		visit[y - 1][x] = true;
//		visit[y][x - 1] = true;
//		res += arr[y - 1][x];
//		res += arr[y][x - 1];
//		break;
//	}
//	
//	int dfsret = 0;
//
//	for (int i = index + 1; i < n * m; ++i)
//	{
//		int ny = i / indexing + 1;
//		int nx = i % indexing + 1;
//		if (visit[ny][nx] == true) continue;
//		int ret1 = 0;
//		visit[ny][nx] = true;
//		ret1 = dfs(i, 1);
//		visit[ny][nx] = false;
//		if (ret1 != 0)
//		{
//			if (visit[ny + 1][nx] == true)
//				visit[ny + 1][nx] = false;
//			if (visit[ny][nx + 1] == true)
//				visit[ny][nx + 1] = false;
//		}
//
//		int ret2 = 0;
//
//		visit[ny][nx] = true;
//		ret2 = dfs(i, 2);
//		visit[ny][nx] = false;
//		if (ret2 != 0)
//		{
//			if (visit[ny][nx - 1] == true)
//				visit[ny][nx - 1] = false;
//			if (visit[ny + 1][nx] == true)
//				visit[ny + 1][nx] = false;
//		}
//
//
//		int ret3 = 0;
//		visit[ny][nx] = true;
//		ret3 = dfs(i, 3);
//		visit[ny][nx] = false;
//		if (ret3 != 0)
//		{
//			if (visit[ny - 1][nx] == true)
//				visit[ny - 1][nx] = false;
//			if (visit[ny][nx + 1] == true)
//				visit[ny][nx + 1] = false;
//		}
//
//
//		int ret4 = 0;
//		visit[ny][nx] = true;
//		ret4 = dfs(i, 4);
//		visit[ny][nx] = false;
//		if (ret4 != 0)
//		{
//			if (visit[ny - 1][nx] == true)
//				visit[ny - 1][nx] = false;
//			if (visit[ny][nx - 1] == true)
//				visit[ny][nx - 1] = false;
//		}
//
//		dfsret = max(dfsret,max(ret1, max(ret2, max(ret3, ret4))));
//		if (dfsret == 24)
//			break;
//	}
//
//
//	return res + dfsret;
//
//}



int visit[3][100'10];
int arr[3][100'10];
int goal = 0;
int minim = FAILCODE;
int dfs(int cnt, int lane, int index,int obs[3])
{
	if (index == goal)
	{
		return cnt;
	}
	if (obs[lane] <= 0) {
		return cnt;
	}
	if (cnt > minim)
	{
		return FAILCODE;
	}
	int res = FAILCODE;
	int nx = index;

	if (arr[lane][nx + 1] == true)
	{
		if (cnt + 1 > minim)
		{
			return FAILCODE;
		}
		obs[lane]--;
		int ret1 = FAILCODE, ret2 = FAILCODE, ret3 = FAILCODE;
		if (lane == 0)
		{
			visit[1][nx + 1] = true;
			ret1 = dfs(cnt + 1, 1, index + 1, obs);
			visit[1][nx + 1] = false;

			visit[2][nx + 1] = true;
			ret1 = min(ret1, dfs(cnt + 1, 2, index + 1, obs));
			visit[2][nx + 1] = false;
		}
		else if (lane == 1)
		{
			visit[0][nx + 1] = true;
			ret2 = dfs(cnt + 1, 0, index + 1, obs);
			visit[0][nx + 1] = false;

			visit[2][nx + 1] = true;
			ret2 = min(ret2, dfs(cnt + 1, 2, index + 1, obs));
			visit[2][nx + 1] = false;

		}
		else if (lane == 2)
		{
			visit[0][nx + 1] = true;
			ret3 = dfs(cnt + 1, 0, index + 1, obs);
			visit[0][nx + 1] = false;

			visit[1][nx + 1] = true;
			ret3 = min(ret3, dfs(cnt + 1, 1, index + 1, obs));
			visit[1][nx + 1] = false;

		}
		res = min(res, min(ret1, min(ret2, ret3)));
		minim = min(minim, res);
		obs[lane]++;
	}
	else {
		visit[lane][nx + 1] = true;
		res = min(res, dfs(cnt, lane, index + 1, obs));
		visit[lane][nx + 1] = false;
	}

	return res;
}

class Obs {
public:
	int lane;
	int obstacle = 0;
	int far = 99999;
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	vector<int > obstacleLanes;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		cin >> k;
		obstacleLanes.push_back(k);
	}
	int res = 0;
	goal = obstacleLanes.size();

	//pair<int, int> obss[3]{ {0,FAILCODE },{0,FAILCODE},{0,FAILCODE} };
	int obs[3]{};
	Obs obss[3];
	obss[0].lane = 0;
	obss[1].lane = 1;
	obss[2].lane = 2;

	int nowlane = 1;
	int nowcnt = 0;
	while(true)
	{
		obss[0].lane = 0;
		obss[0].far = FAILCODE;
		obss[0].obstacle = 0;
		obss[1].lane = 1;
		obss[1].far = FAILCODE;
		obss[1].obstacle = 0;
		obss[2].lane = 2;
		obss[2].far = FAILCODE;
		obss[2].obstacle = 0;
		
		for (int i = nowcnt; i < obstacleLanes.size(); ++i)
		{

			arr[obstacleLanes[i] - 1][i + 1] = true;
			obs[obstacleLanes[i] - 1]++;
			obss[obstacleLanes[i] - 1].obstacle++;
			obss[obstacleLanes[i] - 1].far = min(obss[obstacleLanes[i] - 1].far, i + 1);
		}

		sort(begin(obss), end(obss), [](Obs a, Obs b) {
			if (a.obstacle == b.obstacle)
				return a.far > b.far;
			return a.obstacle < b.obstacle;
			});

		if (nowlane == obss[0].lane)
		{
			if (obss[0].obstacle > 0)
			{
				nowlane = obss[1].lane;
				nowcnt += obss[1].far;
				res++;
			}
			else {

				nowlane = obss[0].lane;
				nowcnt += obss[0].far;
			}
		}
		else {
			nowlane = obss[0].lane;
			nowcnt += obss[0].far;
			res++;

		}
		if (nowcnt >= obstacleLanes.size())
			break;
	}
	
	


	//res = dfs(0, 1, 0, obs);
	std::cout << res << endl;
	return 0;
}
