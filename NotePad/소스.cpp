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

vector<pair<int, int>> saves;

int checking(int time, int during)
{
	int cstart = time;
	int cend = time + during;
	for (auto& save : saves)
	{
		int sstart = save.first;
		int send = save.second;

		if (send > cstart && sstart < cstart)
			return false;
		if (sstart < cend && cstart < sstart)
			return false;
		if (sstart <= cstart && cend <= send)
		{
			if(sstart != send)
				return false;
		}
		if (cstart <= sstart && send <= cend)
		{
			if (sstart != send)
				return false;
		}
	}
	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int maxtime = 0;
	int N;
	cin >> N;
	vector<pair<int, int>> objs;
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		maxtime = max(maxtime, b);
		objs.push_back(make_pair(a, b - a));
	}

	vector<pair<int, int>> objsorder{ objs };
	sort(objs.begin(), objs.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
		return a.second < b.second;	
	});

	sort(objsorder.begin(), objsorder.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first)
		{
			return a.first + a.second < b.first + b.second;
		}
		else {
			return a.first < b.first;
		}
	});

	for (auto& obj : objs)
	{
		if (checking(obj.first, obj.second))
		{
			saves.push_back(make_pair(obj.first, obj.first + obj.second));
		}
	}
	int ahigh = saves.size();
	saves.clear();
	for (auto& obj : objsorder)
	{
		if (checking(obj.first, obj.second))
		{
			saves.push_back(make_pair(obj.first, obj.first + obj.second));
		}
	}
	int bhigh = saves.size();
	cout << max(ahigh,bhigh);
	return 0;
}